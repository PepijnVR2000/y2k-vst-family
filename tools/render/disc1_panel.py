"""Disc 1 panel, Browser room: first render for review (not a shipping asset).

Renders the 3D objects only. All text, values and the VFD strip are drawn on
top afterwards (docs/design/disc1-panel/index.html), exactly as JUCE will do
it later, so bloom never touches text (CLAUDE.md, GUIDELINES.md section 4).

Writes:
  <out>/disc1-panel.png   1920 x 1200 (2x the 960 x 600 logical panel)
  <out>/layout.json       logical-pixel anchors for the text overlay

Run (Blender 4.0):
  blender -b --factory-startup -P tools/render/disc1_panel.py -- <out> [samples] [percent]
"""

import json
import math
import os
import sys

import bpy
from bpy_extras.object_utils import world_to_camera_view
from mathutils import Quaternion, Vector

argv = sys.argv[sys.argv.index("--") + 1:] if "--" in sys.argv else []
OUT = os.path.abspath(argv[0] if argv else ".")
SAMPLES = int(argv[1]) if len(argv) > 1 else 128
PERCENT = int(argv[2]) if len(argv) > 2 else 100
os.makedirs(OUT, exist_ok=True)

# Logical panel: 960 x 600 px, 1 Blender unit = 100 px, origin at panel centre.
W, H, UNIT = 960, 600, 100.0


def P(px, py, z=0.0):
    return Vector((px / UNIT - W / 2 / UNIT, H / 2 / UNIT - py / UNIT, z))


# Colour helpers (hex values are sRGB; Blender wants linear) ------------------
def _lin(c):
    return c / 12.92 if c <= 0.04045 else ((c + 0.055) / 1.055) ** 2.4


def srgb(h):
    h = h.lstrip("#")
    return tuple(int(h[i:i + 2], 16) / 255 for i in (0, 2, 4))


def col(h, a=1.0):
    r, g, b = srgb(h)
    return (_lin(r), _lin(g), _lin(b), a)


def col_from_srgb(rgb, a=1.0):
    return (_lin(rgb[0]), _lin(rgb[1]), _lin(rgb[2]), a)


def gradient(stops, t):
    """Interpolate a list of hex stops in sRGB, t in 0..1."""
    t = min(max(t, 0.0), 1.0) * (len(stops) - 1)
    i = min(int(t), len(stops) - 2)
    f = t - i
    a, b = srgb(stops[i]), srgb(stops[i + 1])
    return tuple(a[k] + (b[k] - a[k]) * f for k in range(3))


# Palette (GUIDELINES.md) ------------------------------------------------------
ROOM = ("#8f9590", "#5e625a", "#272922")          # Browser room, measured
DISC1 = ("#3f4eaf", "#4d8a9f", "#38c176", "#68f877")
WARM_ACCENT = "#ff7a2f"                           # candy ball, against "liminal horror" drift

# Scene ---------------------------------------------------------------------------
bpy.ops.wm.read_factory_settings(use_empty=True)
scene = bpy.context.scene
coll = scene.collection


def link(o):
    coll.objects.link(o)
    return o


def new_mat(name):
    m = bpy.data.materials.new(name)
    m.use_nodes = True
    return m, m.node_tree.nodes["Principled BSDF"]


def set_inputs(bsdf, **values):
    for key, value in values.items():
        bsdf.inputs[key.replace("_", " ")].default_value = value


def add_grain(m, bsdf, scale=70.0, strength=0.28):
    nt = m.node_tree
    noise = nt.nodes.new("ShaderNodeTexNoise")
    noise.inputs["Scale"].default_value = scale
    noise.inputs["Detail"].default_value = 8.0
    bump = nt.nodes.new("ShaderNodeBump")
    bump.inputs["Strength"].default_value = strength
    bump.inputs["Distance"].default_value = 0.02
    nt.links.new(noise.outputs["Fac"], bump.inputs["Height"])
    nt.links.new(bump.outputs["Normal"], bsdf.inputs["Normal"])


def bevel(o, width, segments=2):
    mod = o.modifiers.new("bevel", "BEVEL")
    mod.width = width
    mod.segments = segments
    mod.limit_method = "NONE"


def active(o):
    bpy.ops.object.select_all(action="DESELECT")
    o.select_set(True)
    bpy.context.view_layer.objects.active = o


def box(name, size, loc, mat, rot=(0, 0, 0), bev=0.015):
    bpy.ops.mesh.primitive_cube_add(size=1, location=loc)
    o = bpy.context.object
    o.name = name
    o.scale = size
    active(o)
    bpy.ops.object.transform_apply(location=False, rotation=False, scale=True)
    o.rotation_euler = rot
    bevel(o, bev)
    o.data.materials.append(mat)
    return o


# Light pools: white light on the floor under selected objects. Painted in the
# room shader (not geometry) so they never occlude the soft shadows.
pools = []   # (centre px, centre py, radius x px, radius y px, strength)

layout = {"W": W, "H": H, "cubes": [], "rings": [], "knobs": [], "toggles": [], "candy": None,
          "stripes": None}

# Camera: orthographic, straight down. -------------------------------------------
cam_data = bpy.data.cameras.new("cam")
cam_data.type = "ORTHO"
cam_data.ortho_scale = W / UNIT
cam_data.sensor_fit = "HORIZONTAL"
cam_data.clip_end = 100.0
cam = link(bpy.data.objects.new("cam", cam_data))
cam.location = (0, 0, 30)
scene.camera = cam

scene.render.resolution_x = W * 2
scene.render.resolution_y = H * 2
scene.render.resolution_percentage = PERCENT


def to_px(world):
    v = world_to_camera_view(scene, cam, world)
    return [round(v.x * W, 1), round((1.0 - v.y) * H, 1)]


# Lights: soft world + one sun from top left (one light, GUIDELINES 6). -----------
world = bpy.data.worlds.new("world")
world.use_nodes = True
world.node_tree.nodes["Background"].inputs["Color"].default_value = (1, 1, 1, 1)
world.node_tree.nodes["Background"].inputs["Strength"].default_value = 0.55
scene.world = world

sun_data = bpy.data.lights.new("sun", "SUN")
sun_data.energy = 1.9
sun_data.angle = math.radians(28)
sun = link(bpy.data.objects.new("sun", sun_data))
d = Vector((1.0, -1.0, -2.2)).normalized()          # travels to bottom right, down
sun.rotation_euler = (-d).to_track_quat("Z", "Y").to_euler()

# Step cubes: 2 rows of 8, disc 1 gradient over the pattern (ref 02). -------------
CUBE = 0.56
REST_STEPS = {4, 8, 11, 15}
PLAY_STEP = 5
for i in range(16):
    step = i + 1
    row, column = divmod(i, 8)
    px, py = 110 + column * 88, 415 + row * 95
    rgb = gradient(DISC1, i / 15)
    is_rest = step in REST_STEPS
    is_play = step == PLAY_STEP

    m, b = new_mat(f"cube{step}")
    if is_rest:
        rgb = tuple(c * 0.55 for c in rgb)            # off: dim to ~55 %, no light pool
    set_inputs(b, Base_Color=col_from_srgb(rgb), Roughness=0.58, Subsurface_Weight=0.25,
               Subsurface_Scale=0.05)
    if is_play:                                       # playhead: glows white from inside
        set_inputs(b, Emission_Color=col_from_srgb(tuple(0.5 + 0.5 * c for c in rgb)), Emission_Strength=0.3)
    add_grain(m, b)

    z = 0.32 if is_rest else 0.45
    size = CUBE * (1.06 if is_play else 1.0)
    o = box(f"step{step}", (size, size, size), P(px, py, z + (0.08 if is_play else 0.0)), m,
            rot=(math.radians(22), math.radians(-9), 0))
    bpy.context.view_layer.update()
    face = o.matrix_world @ Vector((0, 0, size / 2))
    layout["cubes"].append({"n": step, "face": to_px(face), "centre": to_px(o.location),
                            "state": "play" if is_play else ("rest" if is_rest else "on")})
    if is_play:
        pools.append((px + 4, py + 34, 64, 40, 1.7))

# Prism rings: 12 glass hex prisms, value fills clockwise from the top (ref 03). --
GLASS = new_mat("glass")
set_inputs(GLASS[1], Base_Color=col("#a9cbe6"), Roughness=0.1, Transmission_Weight=1.0, IOR=1.45,
           Coat_Weight=0.4)
LIT = new_mat("glass_lit")
set_inputs(LIT[1], Base_Color=col("#9fdcf2"), Roughness=0.08, Transmission_Weight=0.85, IOR=1.45,
           Emission_Color=col("#7fd3ee"), Emission_Strength=0.45)

RINGS = [("Cutoff", 130, 7, True, "1.42", "kHz"),
         ("Resonance", 300, 4, False, "34", "%"),
         ("Env mod", 470, 8, False, "66", "%"),
         ("Accent", 640, 6, False, "50", "%")]
RING_Y = 180
for label, px, lit, is_active, value, unit in RINGS:
    pivot = link(bpy.data.objects.new(f"ring_{label}", None))
    pivot.location = P(px, RING_Y, 0.55 if is_active else 0.45)
    pivot.rotation_euler = (math.radians(18), 0, 0)
    s = 1.06 if is_active else 1.0                    # selected: ~6 % larger, raised
    pivot.scale = (s, s, s)
    for k in range(12):
        a = math.radians(k * 30)
        direction = Vector((math.sin(a), math.cos(a), 0))
        bpy.ops.mesh.primitive_cylinder_add(vertices=6, radius=0.075, depth=0.34)
        o = bpy.context.object
        o.name = f"prism_{label}_{k}"
        o.parent = pivot
        o.location = direction * 0.47
        o.rotation_mode = "QUATERNION"
        o.rotation_quaternion = direction.to_track_quat("Z", "Y") @ Quaternion((0, 0, 1), math.radians(30))
        bevel(o, 0.01)
        o.data.materials.append(LIT[0] if k < lit else GLASS[0])
    bpy.context.view_layer.update()
    layout["rings"].append({"label": label, "centre": to_px(pivot.matrix_world @ Vector((0, 0, 0))),
                            "label_at": to_px(pivot.matrix_world @ Vector((0, -0.86, 0))),
                            "active": is_active, "value": value, "unit": unit, "lit": lit})
    if is_active:
        pools.append((px, RING_Y + 46, 82, 30, 0.9))  # under the lower prisms: centre value and label stay readable

# Small knobs: matte cylinders, 1 px bevel, one indicator stripe (ref 16). --------
KNOB_M = new_mat("knob")
set_inputs(KNOB_M[1], Base_Color=col("#4a4d47"), Roughness=0.72)
add_grain(*KNOB_M, scale=140, strength=0.05)
MARK_M = new_mat("mark")
set_inputs(MARK_M[1], Base_Color=col("#eef0ea"), Roughness=0.5)

for label, px, value, text in [("Decay", 745, 0.40, "320 ms"), ("Glide", 822, 0.25, "60 ms"),
                               ("Level", 899, 0.70, "-12 dB")]:
    bpy.ops.mesh.primitive_cylinder_add(vertices=64, radius=0.23, depth=0.16, location=P(px, 172, 0.42))
    knob = bpy.context.object
    knob.name = f"knob_{label}"
    knob.rotation_euler = (math.radians(22), 0, 0)
    bevel(knob, 0.012)
    knob.data.materials.append(KNOB_M[0])
    t = math.radians(-135 + 270 * value)
    bpy.ops.mesh.primitive_cube_add(size=1)
    mark = bpy.context.object
    mark.name = f"mark_{label}"
    mark.scale = (0.03, 0.15, 0.012)
    mark.parent = knob
    mark.location = (math.sin(t) * 0.12, math.cos(t) * 0.12, 0.084)
    mark.rotation_euler = (0, 0, -t)
    mark.data.materials.append(MARK_M[0])
    bpy.context.view_layer.update()
    layout["knobs"].append({"label": label, "centre": to_px(knob.matrix_world @ Vector((0, 0, 0))),
                            "label_at": to_px(knob.matrix_world @ Vector((0, -0.36, 0))), "value": text})

# Toggles: translucent keys, glow from inside when on (refs 16, 18). -------------
for label, px, on in [("Arp", 772, True), ("Hold", 872, False)]:
    m, b = new_mat(f"toggle_{label}")
    if on:
        set_inputs(b, Base_Color=col("#a8f5b0"), Roughness=0.3, Subsurface_Weight=0.6,
                   Subsurface_Scale=0.08, Emission_Color=col(DISC1[3]), Emission_Strength=1.1)
    else:
        set_inputs(b, Base_Color=col("#c9cec6"), Roughness=0.35, Subsurface_Weight=0.6,
                   Subsurface_Scale=0.08)
    o = box(f"toggle_{label}", (0.70, 0.30, 0.14), P(px, 262, 0.38), m,
            rot=(math.radians(22), 0, 0), bev=0.03)
    layout["toggles"].append({"label": label, "centre": to_px(o.location),
                              "label_at": to_px(o.location + Vector((0, -0.34, 0))), "on": on})

# Candy ball: one playful action (randomize), ref 20. -----------------------------
m, b = new_mat("candy")
set_inputs(b, Base_Color=col(WARM_ACCENT), Roughness=0.12, Coat_Weight=1.0, Subsurface_Weight=0.3,
           Subsurface_Scale=0.05)
bpy.ops.mesh.primitive_uv_sphere_add(segments=64, ring_count=32, radius=0.27, location=P(862, 455, 0.45))
candy = bpy.context.object
bpy.ops.object.shade_smooth()
candy.data.materials.append(m)
layout["candy"] = {"label": "Random", "centre": to_px(candy.location),
                   "label_at": to_px(candy.location + Vector((0, -0.42, 0)))}

# Mark: stack of colour stripes in the disc gradient (ref 11). --------------------
for k, h in enumerate(DISC1):
    m, b = new_mat(f"stripe{k}")
    set_inputs(b, Base_Color=col(h), Roughness=0.5)
    box(f"stripe{k}", (0.30, 0.055, 0.03), P(54, 24 + k * 9, 0.2), m, bev=0.006)
layout["stripes"] = {"left": 39, "top": 21, "right": 69, "bottom": 53}

# Room: warm grey radial gradient (measured), soft shadow from AO, light pools. ---
bpy.ops.mesh.primitive_plane_add(size=1, location=(0, 0, 0))
room = bpy.context.object
room.name = "room"
room.scale = (14, 10, 1)
m = bpy.data.materials.new("room")
m.use_nodes = True
nt = m.node_tree
nt.nodes.clear()
out = nt.nodes.new("ShaderNodeOutputMaterial")
geo = nt.nodes.new("ShaderNodeNewGeometry")
sep = nt.nodes.new("ShaderNodeSeparateXYZ")
nt.links.new(geo.outputs["Position"], sep.inputs["Vector"])


def op(kind, a, b=None):
    n = nt.nodes.new("ShaderNodeMath")
    n.operation = kind
    for idx, v in enumerate((a, b)):
        if v is None:
            continue
        if isinstance(v, (int, float)):
            n.inputs[idx].default_value = v
        else:
            nt.links.new(v, n.inputs[idx])
    return n.outputs[0]


def ellipse_distance(cx_px, cy_px, rx_px, ry_px):
    c = P(cx_px, cy_px)
    dx = op("DIVIDE", op("SUBTRACT", sep.outputs["X"], c.x), rx_px / UNIT)
    dy = op("DIVIDE", op("SUBTRACT", sep.outputs["Y"], c.y), ry_px / UNIT)
    return op("SQRT", op("ADD", op("MULTIPLY", dx, dx), op("MULTIPLY", dy, dy)))


# Same ellipse as the moodboard CSS: radial-gradient(90% 70% at 50% 18%, ...)
ramp = nt.nodes.new("ShaderNodeValToRGB")
nt.links.new(ellipse_distance(480, 108, 864, 420), ramp.inputs["Fac"])
ramp.color_ramp.elements[0].position = 0.0
ramp.color_ramp.elements[0].color = col(ROOM[0])
ramp.color_ramp.elements[1].position = 1.0
ramp.color_ramp.elements[1].color = col(ROOM[2])
ramp.color_ramp.elements.new(0.45).color = col(ROOM[1])

ao = nt.nodes.new("ShaderNodeAmbientOcclusion")
ao.samples = 16
ao.inputs["Distance"].default_value = 1.4
shade = op("ADD", 0.58, op("MULTIPLY", op("POWER", ao.outputs["AO"], 1.4), 0.42))

shaded = nt.nodes.new("ShaderNodeVectorMath")
shaded.operation = "SCALE"
nt.links.new(ramp.outputs["Color"], shaded.inputs[0])
nt.links.new(shade, shaded.inputs["Scale"])
colour = shaded.outputs["Vector"]

for cx, cy, rx, ry, strength in pools:
    f = op("MAXIMUM", op("SUBTRACT", 1.0, ellipse_distance(cx, cy, rx, ry)), 0.0)
    f = op("MULTIPLY", op("POWER", f, 2.2), strength)
    add = nt.nodes.new("ShaderNodeVectorMath")
    add.operation = "ADD"
    nt.links.new(colour, add.inputs[0])
    comb = nt.nodes.new("ShaderNodeCombineXYZ")
    for axis in ("X", "Y", "Z"):
        nt.links.new(f, comb.inputs[axis])
    nt.links.new(comb.outputs["Vector"], add.inputs[1])
    colour = add.outputs["Vector"]

emit = nt.nodes.new("ShaderNodeEmission")
nt.links.new(colour, emit.inputs["Color"])
emit.inputs["Strength"].default_value = 1.0
nt.links.new(emit.outputs["Emission"], out.inputs["Surface"])
room.data.materials.append(m)

# Render settings -------------------------------------------------------------------
scene.render.engine = "CYCLES"
scene.cycles.samples = SAMPLES
scene.cycles.use_denoising = True
scene.cycles.denoiser = "OPENIMAGEDENOISE"
scene.cycles.max_bounces = 16
scene.cycles.transmission_bounces = 16
scene.cycles.glossy_bounces = 8
scene.view_settings.view_transform = "Standard"
scene.view_settings.look = "None"
scene.render.image_settings.file_format = "PNG"
scene.render.image_settings.color_mode = "RGB"
scene.render.filepath = os.path.join(OUT, "disc1-panel.png")

try:
    prefs = bpy.context.preferences.addons["cycles"].preferences
    for kind in ("OPTIX", "CUDA", "HIP", "ONEAPI"):
        try:
            prefs.compute_device_type = kind
        except TypeError:
            continue
        prefs.get_devices()
        devices = [dv for dv in prefs.devices if dv.type == kind]
        if devices:
            for dv in prefs.devices:
                dv.use = dv.type == kind
            scene.cycles.device = "GPU"
            print("LP render device:", kind, [dv.name for dv in devices])
            break
    else:
        print("LP render device: CPU")
except Exception as exc:  # noqa: BLE001
    print("LP render device: CPU (", exc, ")")

# Bloom only on what is bright (light pools, playhead), never on text: text is
# not in this image at all.
scene.use_nodes = True
ct = scene.node_tree
ct.nodes.clear()
rl = ct.nodes.new("CompositorNodeRLayers")
glare = ct.nodes.new("CompositorNodeGlare")
glare.glare_type = "FOG_GLOW"
glare.quality = "HIGH"
glare.threshold = 1.0
glare.size = 8
glare.mix = -0.55
ct.links.new(rl.outputs["Image"], glare.inputs["Image"])


def mix(blend, fac, a, b):
    n = ct.nodes.new("CompositorNodeMixRGB")
    n.blend_type = blend
    n.inputs[0].default_value = fac
    ct.links.new(a, n.inputs[1])
    if isinstance(b, tuple):
        n.inputs[2].default_value = b
    else:
        ct.links.new(b, n.inputs[2])
    return n.outputs[0]


# Haze (v2, user feedback): the soft, slightly milky look of a 2001 console on a
# CRT. A wide blur screened over the image, plus a thin layer of room-coloured
# mist. Image layer only: the text layer stays sharp (CLAUDE.md).
blur = ct.nodes.new("CompositorNodeBlur")
blur.filter_type = "GAUSS"
blur.size_x = blur.size_y = 28
ct.links.new(glare.outputs["Image"], blur.inputs["Image"])
img = mix("SCREEN", 0.32, glare.outputs["Image"], blur.outputs["Image"])
img = mix("MIX", 0.07, img, col(ROOM[0]))

# Grain: per-pixel noise, overlaid lightly. In JUCE this becomes an animated
# grain layer under the text (idle <= 30 fps).
grain_tex = bpy.data.textures.new("grain", "NOISE")
grain = ct.nodes.new("CompositorNodeTexture")
grain.texture = grain_tex
img = mix("OVERLAY", 0.16, img, grain.outputs["Color"])

comp = ct.nodes.new("CompositorNodeComposite")
ct.links.new(img, comp.inputs["Image"])

with open(os.path.join(OUT, "layout.json"), "w", encoding="utf-8") as fh:
    json.dump(layout, fh, indent=1)

# Keep the review page in sync: replace the layout between its markers.
page = os.path.join(OUT, "index.html")
if os.path.exists(page):
    import re
    with open(page, encoding="utf-8") as fh:
        html = fh.read()
    html = re.sub(r"/\*LAYOUT\*/.*?/\*END\*/", lambda _: "/*LAYOUT*/" + json.dumps(layout) + "/*END*/",
                  html, count=1, flags=re.S)
    with open(page, "w", encoding="utf-8", newline="\n") as fh:
        fh.write(html)

bpy.ops.render.render(write_still=True)
print("LP render written:", scene.render.filepath)
