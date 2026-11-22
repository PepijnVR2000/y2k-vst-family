# Part A — Console system UIs and game front-ends, 1998–2005 (visual references)

Every image below was downloaded, downscaled (≤1280 px wide, pillar-box bars cropped where noted) and **viewed** before being described. "Observed" only lists what is visible in the saved frame.

**Sourcing note.** Wikimedia rate-limited us (HTTP 429), YouTube video download was blocked (bot check), and mobygames was not needed. All frames therefore come from YouTube's own storyboard stills: `i.ytimg.com/vi/<ID>/maxres{default,1,2,3}.jpg` (1280×720) or `sd…` (640×480). These are real frames from the videos, not channel art, except where a note says otherwise. Emulator captures (PCSX2/DuckStation/xemu) are crisper than real hardware and render at higher resolution. Some frames are camera shots of a CRT; that is flagged on each one.

**How the palettes were measured** (PIL, `scripts/keep.py`, `accent.py`, `sample.py` in the scratchpad):
- *Palette*: median-cut quantisation to 6 colours, with the share of pixels for each.
- *Accents*: the 3 most saturated colours from a 24-colour quantisation, each covering at least 0.3% of the image.
- *Element samples*: the median of the brightest 10% of pixels inside a hand-picked box around one UI element (text, button, background). These are biased toward the lit part of each element.

---

## 01 — PS2 boot sequence, "towers" (2000)
- File: `01-ps2-boot-towers.jpg`
- Source page: https://www.youtube.com/watch?v=qBxH5Ld7n6o ("PS2 (PCSX2) Startup with Random Towers", emulator, with hex-edited tower data)
- Image URL: https://i.ytimg.com/vi/qBxH5Ld7n6o/maxres2.jpg
- Also viewed, not kept: iq03Z0pzVSM (top-down view of equal-height towers), ERpAoWxtXPg (same scene, darker).
- **Observed**
  - **Materials**: the towers are **opaque, matte, pale lavender-grey square columns**. Their faces carry a fine noisy, stippled texture, like concrete or a greebled circuit surface. They are **not translucent crystal**. A single **translucent dark-blue cube** (a glass box with visible inner edges) floats in front of them.
  - **Composition**: a wide-angle camera looks into a field of columns that converge on a vanishing point at the upper centre. The tops of the columns catch a cold white-violet key light from above and front.
  - **Depth**: created by fall-off to black and a faint blue haze (fog) in the middle distance. There is no floor.
  - **Particles**: 3–4 tiny coloured streaks (red, green, violet) cut through the space like light trails.
  - There is no text or UI.
- **Palette**: #020204 28%, #333754 20%, #171A35 16%, #5E6788 15%, #A7B5D6 11%, #0A0A1A 10%. Highest-saturation colours: #C1D1EF, #8D99BE.
- **Take for our plugins**
  1. Pattern or preset density as a **field of opaque, finely textured blocks** (a fine noise texture, not glass) lit from one cold top key, with only one glass object as the hero.
  2. Coloured hairline particle trails (1–2 px, 3–4 at a time) as the only "energy" in an otherwise grey scene.

## 02 — PS2 main menu / clock screen (2000)
- Files: `02a-ps2-clock-main.jpg` (PCSX2 1080p60), `02b-ps2-clock-teal.jpg` (real hardware)
- Source pages: https://www.youtube.com/watch?v=cf9Ht8OFyEM · https://www.youtube.com/watch?v=KlLCkzLbNm0
- Image URLs: https://i.ytimg.com/vi/cf9Ht8OFyEM/maxres1.jpg · https://i.ytimg.com/vi/KlLCkzLbNm0/maxresdefault.jpg
- **Observed**
  - **Crystals**: 12 **hexagonal-section glass prisms** radiate from a dark centre like the hours on a clock face. One prism (the current hour) is lit and **half-filled** with brighter light, like a level gauge.
  - **Crystal colour varies between captures**. It is blue-violet with lavender rims in 02a and teal-cyan in 02b. In both, the prisms are semi-transparent with a bright edge highlight.
  - **Orbs**: 6–8 small white point lights (the "orbs") sit on a ring inside the prisms, joined by faint curved orbit lines.
  - **Background**: a **mottled violet and indigo cloud texture**, not black, with a darker vignette well behind the clock centre.
  - **Text**: the date at top left and the time at top right are set in a light grey, regular-weight geometric-humanist sans with plain tabular figures, about 3.5% of screen height, sitting at the very corners. "Display" at bottom left sits next to a small pink outline square.
  - **Space**: about 70% of the frame is background.
- **Palette (02a)**: #312455 25%, #070619 19%, #241B47 19%, #1B1032 16%, #120B26 15%, #474478 6%. Element samples: lit crystal #62A0F7, unlit crystal #6372DA, background #3E2C66, text #A9A1B4.
- **Palette (02b)**: #1B1428 20%, #403765 18%, #3A2C57 18%, #2F2346 18%, #2A1E3D 17%, #3C718A 9%. Accent: #66A8C6.
- **Take for our plugins**
  1. A **fill-level inside a glass prism** as a value display: the lit, partly filled crystal among unlit ones (for example a step or bar position).
  2. A **violet-indigo mottled background (#2A1E3D–#453C73)** instead of navy-black.
  3. Small, plain grey corner text for status (BPM, bar, time), out of the way of the hero object.

## 03 — PS2 Browser: memory card contents (2000)
- Files: `03a-ps2-memcard-browser.jpg` (PCSX2), `03b-ps2-memcard-browser-full.jpg` (real hardware, camera on a CRT, cropped to the UI)
- Source pages: https://www.youtube.com/watch?v=cf9Ht8OFyEM · https://www.youtube.com/watch?v=O3S1ZL6ZOuU
- Image URLs: https://i.ytimg.com/vi/cf9Ht8OFyEM/maxres2.jpg · https://i.ytimg.com/vi/O3S1ZL6ZOuU/maxres3.jpg
- Also viewed: HUyRfqJew1A, XYHoxEnt1Lk, h3H3XvkgVSc and hoFy3_MfQ1g show the same layout with other saves.
- **Observed**
  - **Background**: a **light, warm-grey studio backdrop**, a smooth diagonal gradient from pale grey at top left to dark olive-grey at bottom right. It is not dark.
  - **Save icons**: real-time 3D objects (a floppy disk, a typewriter, guns, badges, characters, a CD) floating **with no tile, frame or background card**, in a loose 5-column grid. Each is lit by the scene light. Icon sizes vary.
  - **Header**: at top left, a small black memory-card glyph plus "Memory Card (PS2)/1" in a light grey sans, with "5,330 KB Free" below in smaller text. At top right, the selected save's title is in **yellow-green**.
  - **Text style**: medium weight, sentence case, normal tracking, with a dark soft drop shadow.
  - **Selection**: a **soft white light-bloom (a point light) behind and under the selected icon**. There is no box, outline or scaling.
  - **Scrolling**: a small blue down-triangle under the grid shows more rows.
  - **Footer**: button legends at the bottom (glyph plus word, about 3.5% of screen height).
  - **Space**: with few saves, about 60% of the backdrop is empty.
- **Palette (03a)**: #181811 20%, #4C4C46 19%, #2D2D25 18%, #62635E 17%, #393831 16%, #7D7F79 11%. Element samples: title #BBCB45, header text #A7A8A3, background top-left #787974, background bottom-right #595851.
- **Palette (03b)**: #5F635A 19%, #252720 18%, #404236 18%, #757A73 17%, #4E4D43 16%, #929791 11%.
- **Take for our plugins**
  1. **Preset browser = bare 3D objects on a neutral warm-grey gradient backdrop.** No cards and no frames. Selection is a **light that turns on under the object**.
  2. A two-line header (location plus "free space") at top left, with the selected item's name at top right in one accent colour.
  3. Let the save icons supply all the colour; keep the chrome neutral.

## 04 — PS2 Browser: audio CD track view (2000)
- File: `04-ps2-audio-cd-browser.jpg` (real hardware capture)
- Source page: https://www.youtube.com/watch?v=qwKGhc5euYY
- Image URL: https://i.ytimg.com/vi/qwKGhc5euYY/maxres2.jpg
- **Observed**
  - **Cubes**: one cube per track on the same light-grey gradient backdrop as 03. The cubes have a lumpy, stucco-like texture, and **track numbers sit on the front face** in a white sans with a dark outline.
  - **Colour**: cube hue steps along the track order, **violet → blue → teal → green** (track 2 is #724FF3, track 17 is #66EA36).
  - **Layout**: a 5-column grid seen in slight perspective, so the rows lean.
  - **Selection**: track 16 has the same **white bloom light** under it.
  - **Text**: "PlayStation® DISC" in light grey at top left; "Track 16" in yellow-green at top right.
- **Palette**: #5F6163 24%, #4D4F57 23%, #797B7B 20%, #667073 13%, #999F99 12%, #5DAB7F 8%. Title sample: #C5DA59.
- **Take for our plugins**
  1. **Drum pads or pattern slots as numbered, textured cubes whose hue steps through an ordered ramp** (violet to green), so position reads as colour.
  2. Light-under-object selection, reused from 03, so the family has one selection language.

## 05 — PS2 System Configuration (2000)
- File: `05-ps2-system-config.jpg` (real hardware, SCPH-39003)
- Source page: https://www.youtube.com/watch?v=hoFy3_MfQ1g
- Image URL: https://i.ytimg.com/vi/hoFy3_MfQ1g/maxres2.jpg
- Also viewed (camera on a CRT, watermarked, not kept): gbXzMBc1MXk. It shows the "Browser / System Configuration" top menu on pure black with 6 glowing dots in a ring: the selected item is bright and bold, the other is greyer and thinner.
- **Observed**
  - **Layout**: the menu text is set **directly over the clock crystals** with no panel behind it.
  - **Text hierarchy**:
    - Section title "Options" in **pale yellow** (#E4F17C).
    - Selected value "Daylight Savings Time (Summer Time)" **larger** (about 5% of screen height), in **light cyan** (#6BC7E3).
    - Unselected value "Standard (Winter Time)" smaller (about 3.5%), in off-white (#B0C7C9).
  - **Text style**: all lines centred on one axis, in a medium-weight humanist sans, sentence case, with a **dark outline/shadow** for legibility.
  - **Crystals**: teal here, with a lit lavender-white "hour" prism.
- **Palette**: #070A17 23%, #1C1931 22%, #353B62 17%, #212945 16%, #352F57 14%, #4B8495 8%. Background sample: #453C73.
- **Take for our plugins**
  1. Show **selection by size plus hue (cyan) only**, with no highlight bar. Unselected options stay visible, smaller and paler, in the same column.
  2. **Yellow-green for headings, cyan for the active choice, off-white for the rest**: a three-colour text system.
  3. Outline text over 3D, never a panel.

## 06 — PS1 memory card manager (1994 / later models)
- Files: `06a-ps1-memcard-jp.jpg` (Japanese BIOS, real hardware), `06b-ps1-memcard-scph102.jpg` (redesigned PAL PSone SCPH-102 BIOS, 640×480)
- Source pages: https://www.youtube.com/watch?v=44SAFhT7AOw · https://www.youtube.com/watch?v=JTJzUEM6RPM
- Image URLs: https://i.ytimg.com/vi/44SAFhT7AOw/maxresdefault.jpg · https://i.ytimg.com/vi/JTJzUEM6RPM/sd2.jpg
- **Observed (06a)**
  - **Background**: a deep blue-violet **radial gradient** (centre #0D71EC, edge #05003F).
  - **Cards**: two card columns of 3×5 pixel-art save icons, sitting on a faint grid of small dots.
  - **Labels**: "CARD1", "CARD2" and the centre actions EXIT / COPY / COPY ALL / DELETE are white text on **rainbow spray-paint splats**. The current action (DELETE) has bright white text; the others have dimmed, darker text.
  - **Cursor**: a pink arrow.
  - **Info line**: a condensed monospaced-looking sans on a darker bar at the bottom.
- **Observed (06b)**
  - **Grid**: a flat grid of **light-grey bevelled square tiles** fills the screen, like a 1990s office UI.
  - **Card slots**: black wells hold the icons. Slot badges are "1" in green and "2" in yellow.
  - **Buttons**: grey bevelled bars for COPY / COPY ALL / DELETE. YES / NO / EXIT are small red, red and blue squares.
  - **Text**: the game name is in a **condensed sans on a black strip**.
- **Palette (06a)**: #00001E 25%, #1E1659 22%, #575E8E 21%, #01002C 15%, #160341 11%, #01010F 7%.
- **Palette (06b)**: #010102 25%, #B0B2B0 21%, #878B88 18%, #09090A 16%, #D1D0C3 12%, #3F3334 8%.
- **Take for our plugins**
  1. **A/B compare as two mirrored 3×5 slot grids with the verbs in the middle column.**
  2. The 06b bevelled-tile grid is an honest, cheap "PS1 mode" skin for the Render-Engine setting. **Do not use** the rainbow splats (they read as clip-art).

## 07 — Dreamcast BIOS: main menu and file manager (1998)
- Files: `07a-dreamcast-bios-main.jpg`, `07b-dreamcast-file-select.jpg` (real hardware, 640×480)
- Source page: https://www.youtube.com/watch?v=oinDIgrmlbw
- Image URLs: https://i.ytimg.com/vi/oinDIgrmlbw/sd1.jpg · https://i.ytimg.com/vi/oinDIgrmlbw/sd3.jpg
- **Observed**
  - **Background**: a **pale sky-blue gradient with soft white clouds and a hazy horizon**, bright and daytime.
  - **Header bar**: a light-grey strip across the top, with "Dreamcast" at left and the date/time at right in a thin dark sans.
  - **Main menu (07a)**: four soft 3D icons in a 2×2 grid: a controller, a VMU, a purple note and a red alarm clock. Each sits over a **colour-coded rounded pill label**: Play salmon/brown #A17E6B, File mint #61C495, Music blue #2D84C0, Settings violet #9769C5. The label text is a narrow, slightly condensed sans in white.
  - **File screen (07b)**:
    - A translucent slate-blue rounded panel at the top holds the prompt.
    - Port tabs **A B C D** are bold green letters on dark tabs.
    - Empty slots are **ghosted translucent rounded rectangles**; the filled slot shows a VMU icon.
    - The "1" and "2" sockets are green ellipse badges.
    - A "200 Free" counter sits in a blue box.
- **Palette (07a)**: #6E8CC0 24%, #5660A9 21%, #AEAEB3 17%, #7AA0C4 14%, #88AFCD 14%, #ACBDC6 10%.
- **Palette (07b)**: #6D8ABF 24%, #454E76 23%, #4262B7 18%, #B2CDCC 14%, #80ACBC 11%, #596FA2 10%.
- **Take for our plugins**
  1. **Empty preset or sample slots as ghosted translucent placeholders** that keep the grid's shape.
  2. A daylight variant: a cloud-sky gradient with one colour-coded pill per section (four hues).
  3. A thin grey status strip across the top with the product name at left and live info at right.

## 08 — GameCube IPL: menu cube, memory card, calendar (2001)
- Files: `08a-gamecube-menu-cube.jpg` (cropped from a thumbnail; the right half had the uploader's flag graphics), `08b-gamecube-memcard.jpg` (Nintendont on Wii, real output), `08c-gamecube-calendar.jpg` (real hardware, 640×480)
- Source pages: https://www.youtube.com/watch?v=pIktjDoLNc8 · https://www.youtube.com/watch?v=iJ843KCaRTU · https://www.youtube.com/watch?v=T-6kIhUsMTk
- Image URLs: https://i.ytimg.com/vi/pIktjDoLNc8/maxresdefault.jpg · https://i.ytimg.com/vi/iJ843KCaRTU/maxresdefault.jpg · https://i.ytimg.com/vi/T-6kIhUsMTk/sd1.jpg
- **Observed (08a)**: one large **smoked-glass cube** seen face-on and slightly rotated.
  - **Material**: a dark grey-green interior and a **thick bevelled rim with iridescent green/purple fringes**, like chromatic dispersion in glass.
  - **Labels**: one per edge (Game Play, Calendar, Memory Card, Options), each rotated to follow its edge, in a **bold rounded sans, white, sentence case**, about 5% of screen height.
  - **Background**: black.
- **Observed (08b)**:
  - **Grid and tiles**: on a black background with a thin grey grid, saves sit on **deep-blue glossy cube tiles** (#02126E), in two 4×4 blocks headed by large white letters "A" and "B" with "Open [131]" counters in outline boxes.
  - **Selection**: the selected save **pops out of the grid**, larger and tilted, as a **pale ice-blue translucent cube** (#63A6DE).
  - **Empty slots**: plain dark-blue tiles.
  - **Info panel**: a blue gradient bar at the bottom.
- **Observed (08c)**: date and time shown in big **amber/orange dot-matrix LED digits** (blocky 5×7 cells) on a black background with a faint grid. The labels "Date" and "Time" are yellow, and the instruction text is a small white sans.
- **Palette (08a)**: #0A0A0A 38%, #363E4C 34%, #7F8F8C 17%, #171921 7%.
- **Palette (08b)**: #000000 58%, #150153 16%, #3F395F 9%, #8A9B94 8%, #01013C 5%, #110E3A 5%.
- **Palette (08c)**: #000000 61%, #786028 8%. Accents: #C0A956, #81601F.
- **Take for our plugins**
  1. **Selection = the item lifts out of its slot, grows and changes material** (from opaque blue to ice glass).
  2. **Labels running along the edges of one glass object** for page or section navigation.
  3. **Amber dot-matrix digits on a fine grid** for BPM and time values: this is the warm accent.

## 09 — Original Xbox dashboard (2001)
- Files: `09a-xbox-dashboard.jpg` (1080p render, likely an emulator or recreation-quality capture), `09b-xbox-memory.jpg` (real capture, 4:3)
- Source pages: https://www.youtube.com/watch?v=GlS1AQ4YpFg · https://www.youtube.com/watch?v=VH2V5cBoK-U
- Image URLs: https://i.ytimg.com/vi/GlS1AQ4YpFg/maxresdefault.jpg · https://i.ytimg.com/vi/VH2V5cBoK-U/maxres2.jpg
- **Observed**
  - **Orb**: a **translucent yellow-green gel orb** with an embossed X sits left of centre, wrapped in green ribbon-like membranes. Four small green ring "pods" link by thin wiring to four **chamfered-corner label plates**.
  - **Labels**: MEMORY / MUSIC / XBOX LIVE / SETTINGS in a **squared, blocky techno face, all caps, wide**, green text on dark-green plates.
  - **Selection**: **selected = a solid yellow-green plate with dark text** (an inversion).
  - **Background**: an **irregular polygonal web** (cells of mixed 4–7 sides, not regular hexagons) wrapped around a curved tunnel or sphere, in thin green lines on near-black green.
  - **Memory screen (09b)**: a wire-framed sphere with an X-shaped 3D emblem, and an info plate "XBOX HARD DISK / TOTAL: 50000+ blocks".
  - **Button hints**: B / BACK and A / SELECT sit in green rings at the sides.
- **Palette (09a)**: #052603 26%, #021201 20%, #001D00 17%, #11380B 15%, #031D02 12%, #609120 10%. Element samples: selected plate #739507, label text #88C155, orb #A7BF0C, mesh #153C11.
- **Palette (09b)**: #071F02 25%, #041401 23%, #0B2404 17%, #041901 14%, #081A02 12%, #17360C 8%.
- **Take for our plugins**
  1. Chamfered label plates with **inverted fill on selection**, as a fallback for flat lists.
  2. An irregular curved polygon mesh (Voronoi-like, not hex) as a faint background layer for modulation routing.
  3. The monochrome discipline: one hue in 5 values for the whole screen.

## 10 — Wip3out (Psygnosis / The Designers Republic, 1999)
- Files: `10a-wip3out-team-select.jpg`, `10b-wip3out-options.jpg` (emulator captures; 10b has a small "GODGAMES" watermark at bottom right)
- Source pages: https://www.youtube.com/watch?v=tvcpBL_bsQw · https://www.youtube.com/watch?v=WkF8qI0v-ZA
- Image URLs: https://i.ytimg.com/vi/tvcpBL_bsQw/maxresdefault.jpg · https://i.ytimg.com/vi/WkF8qI0v-ZA/maxres1.jpg
- **Observed (10a)**
  - **Background**: a **flat warm taupe-grey** (#6A6158, 69% of pixels). No 3D apart from the ship render.
  - **Title**: "team / auricom ind" in a **unicase geometric display face** built from straight strokes and circles, with open counters and squared terminals. The first line is black and the second off-white, very large (about 9% of screen height).
  - **Team swatches**: each team is **2–3 stacked flat colour bars** with a small flag cut into the right end. The name sits below in tiny bold caps with a black bullet-tab.
  - **Stats box**: a thin black outline box with a dog-eared corner holds stats (THRUST / SPEED / SHIELD / HANDLING with [03] values) next to a top-down ship.
  - **Footer**: small caps footer text, divided by a vertical rule.
- **Observed (10b)**
  - **Menu**: the pause options are set in the same unicase face, very large (about 5% of screen height per line) and left-aligned over the dimmed game. Values sit right-aligned in [brackets].
  - **Selection**: **only a colour change from off-white #D8D7CD to amber #F2A70D**. There is no box or cursor.
- **Palette (10a)**: #6A6158 69%, #5E323D 13%, #94907D 9%. Accents: #E00516, #E01D68, #D69E62.
- **Palette (10b)**: #171D32 23%, #181519 23%, #0E1017 21%, #2B2A2F 20%, #222126 8%, #70685A 5%.
- **Take for our plugins**
  1. **Each plugin or preset family as 2–3 stacked flat colour bars**, like a team livery: a cheap, strong identity mark.
  2. **Bracketed values `[07]`** and **selection by colour change only** (off-white to amber) in text menus.
  3. A warm mid-grey flat background for "spec" pages: it proves this era was not all black.

## 11 — WipEout Fusion pilot/ship select (2002, PS2)
- File: `11-wipeout-fusion-pilot.jpg` (PCSX2)
- Source page: https://www.youtube.com/watch?v=ocGv95YG6LQ
- Image URL: https://i.ytimg.com/vi/ocGv95YG6LQ/maxres1.jpg
- **Observed**
  - **Background**: deep navy-black with a faint square grid. A ghosted team logo (FEISAR, rounded-square blocks) sits large at top left at about 20% opacity, with repeated "wipeout fusion / ag league" text as a faint texture.
  - **Hero renders**: a pilot head and a ship.
  - **Stats**: listed in a **lowercase, very widely tracked geometric face** with **dotted leaders** to right-aligned values ("top speed.........1058 kph").
  - **Meters**: each stat has a **segmented bar meter of 5–6 blue rectangles** to its left. The "mass" meter is red.
  - **Credits and footer**: "credits :0" sits below; the footer legends (accept / customize / go back) are lowercase.
  - **Team mark**: a yellow ring with a gap, the team emblem, sits at bottom left.
- **Palette**: #00000E 26%, #010010 22%, #050415 19%, #1B1C2A 16%, #80705B 9%, #050014 8%.
- **Take for our plugins**
  1. A **spec sheet with dotted leaders and segmented 5–6 cell meters**, for preset "showroom" info (CPU, character, author).
  2. **A giant ghosted logo plus a repeated wordmark texture at 10–20% opacity** as background, not chrome.
  3. Lowercase plus wide tracking for secondary info.

## 12 — R4: Ridge Racer Type 4 (Namco, 1998)
- File: `12-r4-comment-mode.jpg` (emulator capture)
- Source page: https://www.youtube.com/watch?v=A24adSjYp2Q
- Image URL: https://i.ytimg.com/vi/A24adSjYp2Q/maxres2.jpg
- Also viewed: F928bcGgaYs shows the title screen in black type on the same yellow.
- **Observed**
  - **Frame**: the whole screen is framed in **flat signal yellow** (#FAC306). Black hairline rules sit under the header and above the footer.
  - **Header**: "*Mode : Comment" in a **bold condensed grotesk**, in black with an asterisk prefix.
  - **Content**: a sepia/duotone photograph of a garage with a pop-art yellow portrait card inset. Below it, a **flat mid-grey panel** (#4B4B4B) with a white-outlined tab reading "*Message".
  - **Footer**: control legends divided by vertical bars, the last in orange ("Please").
  - No gradients, no 3D and no glass.
- **Palette**: #F7C30D 30%, #4B4B4B 27%, #FEFEF9 17%, #EBE1B7 10%, #A38A4D 9%, #35261A 8%.
- **Take for our plugins**
  1. **One flood colour framing the whole window** (R4 yellow #FAC306) for the drum machine, with mid-grey working panels inside.
  2. **Asterisk-prefixed bold condensed section heads** ("*Kit", "*Pattern") with hairline rules.
  3. Footer key hints divided by vertical bars.

## 13 — Music 2000 (PS1, 1999) and MTV Music Generator 2 (PS2, 2001)
- Files: `13a-music2000-arrange.jpg` (ePSXe, 720p; the PlayStation logo at top left is the uploader's overlay), `13b-mtv-mg2-editor.jpg` (cropped; the source frame was already cut to 16:9 and had a "3000yosef" watermark, removed in the crop)
- Source pages: https://www.youtube.com/watch?v=AL_7ocmy2Nc · https://www.youtube.com/watch?v=gSCfSNHuc98
- Image URLs: https://i.ytimg.com/vi/AL_7ocmy2Nc/maxresdefault.jpg · https://i.ytimg.com/vi/gSCfSNHuc98/maxres2.jpg
- **Observed (13a)**: the song arrangement screen.
  - **Toolbar**: icon buttons in dark bevelled slate housings. The active one (a TV icon) is lit cyan-blue.
  - **Readouts**: a separate LCD-like box shows "120" (BPM) under a red segment bar. The song name "Back Again", "001" and two timecodes sit in a rounded panel. A mini level-meter of 4 bars is at the right.
  - **Grid**: rows numbered 01–04 plus video and other track icons, each with a red/purple header tab. **Riff blocks are bevelled tiles in strongly coloured rows**: dark green #0B7124, red #700000, cyan-green #08D5A2, purple, olive. A small 3D icon (a red, white and blue cube, a camera) marks where each clip starts.
  - **Empty area**: bevelled dark tiles.
  - **Preview**: an inset box shows the cyan light-streak video.
  - **Type**: a chunky, bold, rounded bitmap sans, white, partly in caps.
  - Density is high: almost no empty space.
- **Observed (13b)**: the MG2 editor in a **pale teal/grey-green** palette.
  - **Columns**: numbered rows 107–118 down the left; notes and riffs are **vertical coloured bars** (maroon, slate blue, mustard, orange) in columns headed by a row of small instrument icons (note, drums, guitar, lips, mic…).
  - **Buttons**: a left column of **yellow bevelled buttons with black line icons**; transport buttons are bevelled slate-teal.
  - **Pointer**: a 3D white jet-plane cursor.
  - **Clock**: a timecode in white at top right.
- **Palette (13a)**: #030B10 32%, #2F4045 18%, #163421 17%, #340B13 13%, #275E37 10%, #67B69F 9%. Panel text sample: #DEE4E6.
- **Palette (13b)**: #92B6B5 33%, #263138 25%, #718968 18%, #82B2A7 12%, #DBDF93 10%.
- **Take for our plugins**
  1. **Pattern chain = rows of bevelled colour blocks, one hue per track family**, with a tiny 3D marker where a clip starts.
  2. A **dedicated BPM box** (big digits plus a segment bar) separate from the song info panel.
  3. A 3D object as the mouse cursor in fun or easter-egg modes only.
  - Note: this busy, bevelled software look is the **opposite** of the minimal PS2 system UI. Pick one per screen.

## 14 — Vib-Ribbon (NanaOn-Sha, 1999)
- File: `14-vib-ribbon-menu.jpg` (DuckStation HD)
- Source page: https://www.youtube.com/watch?v=AtX6_HtSfGY
- Image URL: https://i.ytimg.com/vi/AtX6_HtSfGY/maxres1.jpg
- **Observed**
  - **Lines**: pure black background (89% of pixels) with **only white 1–2 px vector lines**.
  - **Menu**: a hub-and-spoke diagram. A central polygon "vib-ribbon disc" links by straight spokes to irregular polygon "bubbles" (Back, Highscores, Gold (hard), Silver (normal)).
  - **Selection**: the **selected option is drawn as a much larger bubble** ("Bronze (easy)") with bigger letters.
  - **Lettering**: hand-drawn from straight segments, wobbly and slightly uneven.
  - **Mascot**: the line-art rabbit Vibri sits at bottom right.
- **Palette**: #000000 89%, white #FEFEFE about 2%, plus anti-aliasing greys.
- **Take for our plugins**
  1. **Selection = the chosen node grows into a big outline bubble on a radial menu**. Ideal for a mode or algorithm selector.
  2. A 1-line white-on-black vector style for the scope, and as a "minimal / low CPU" render mode.

## 15 — Frequency (Harmonix, 2001, PS2)
- File: `15-frequency-hud.jpg` (PCSX2, widescreen)
- Source page: https://www.youtube.com/watch?v=6JKLFhj8dtY
- Image URL: https://i.ytimg.com/vi/6JKLFhj8dtY/maxres3.jpg
- **Observed**
  - **Lane**: the player flies down a lane on the floor of a **tunnel walled in flat violet/purple graphic panels**. Neon-green lane edges converge to a glowing vanishing point. Note gems are green, and floating blue wireframe dodecahedra line the tunnel.
  - **Lane label**: a **pill-shaped plate with orange caps text ("SYNTH") and a pale outline**.
  - **Score**: in a navy pill at top left, next to a pixel-art green avatar.
  - **Meters**: a **vertical stack of hexagonal cells** at right (a progress meter, one cell lit white), and a capsule-shaped energy gauge with a yellow fill at left.
- **Palette**: #151A39 22%, #030114 22%, #541B7A 16%, #4B6199 14%, #2F014C 14%, #78BFAC 13%. Accents: #36D89E, #721687.
- **Take for our plugins**
  1. **Track labels in pill plates** (navy fill, pale outline, warm text).
  2. A **stacked-hex-cell vertical meter** for macro or pattern position.
  3. Converging lanes as an optional "flight" view of a step sequence. Keep it out of the default UI, because it is very loud.

---

## Cross-cutting observations

**1. Backgrounds are rarely black, and never "navy void".** The measured base colours are:

| Reference | Base colour(s) |
|---|---|
| PS2 clock and System Config | violet-indigo mottled cloud, #2A1E3D–#453C73 |
| PS2 browser and audio CD | **light warm grey** gradient, #787974 → #595851 |
| Wip3out | flat taupe #6A6158 |
| R4 | flood yellow #FAC306 with mid-grey #4B4B4B |
| Dreamcast | sky blue, #6E8CC0–#88AFCD |
| Xbox | near-black green, #021201–#052603 |
| GameCube | true black |
| Vib-Ribbon | true black |

Only the PS2 boot and the GameCube use true black as the field. The PS2 never uses #030409-style navy-black in its menus.

**2. How depth is made:**
- **Vignette wells.** A darker centre behind the hero object (the PS2 clock), or a diagonal light gradient across a backdrop (the PS2 browser).
- **Perspective rows** (audio-CD cubes, Frequency tunnel).
- **Fall-off to black with faint haze** (boot towers).
- There is very little volumetric fog. Glass shows up as **bright edge highlights on semi-transparent prisms** (PS2 clock) or **thick iridescent bevels** (GameCube cube), never as chrome.

**3. Selection: six patterns seen.** None uses a rectangle highlight on a 3D scene.
1. A **point light or bloom under the object** (PS2 browser, audio CD).
2. **Size plus hue change** of text (PS2 System Config: larger and cyan).
3. **Colour change only** (Wip3out: off-white to amber).
4. **Inverted fill plate** (Xbox).
5. **Object lifts out, grows and changes material** (GameCube memory card).
6. **Node becomes the big bubble** (Vib-Ribbon).

The PS1 dims the unselected labels instead.

**4. Type is big, plain, and mostly sentence case:**
- **Sizes.** Measured relative to screen height: header and info text 3–3.5%, selected menu text about 5%, footer legends about 3.5%, display titles up to 9% (Wip3out). In a 600 px plugin that is roughly **18–30 px** for primary labels.
- **Style.** The PS2, GameCube and Dreamcast system UIs use regular-to-medium humanist or rounded sans in **sentence case with normal tracking**, plus a dark outline or drop shadow when the text sits over 3D.
- **The exceptions.** All-caps, squared or wide-tracked styles appear only in the Xbox (squared techno caps), WipEout (unicase / lowercase wide-tracked) and R4 (bold condensed).

**5. Negative space varies by role.** The system menus are 60–90% empty: PS2 top menu about 80%, PS2 clock about 70%, Vib-Ribbon 89% black. Editors are dense with no empty space: Music 2000, MTV MG2, and the PS1 SCPH-102 tile grid. The best references keep one hero object plus 2–3 text lines per screen.

**6. Real accent colours measured:**
- PS2: text yellow-green #BBCB45 / #E4F17C, cyan #6BC7E3, crystal teal #66A8C6 or blue-violet #6372DA/#62A0F7.
- Xbox: yellow-green #739507 / #A7BF0C, label green #88C155.
- R4: yellow #FAC306.
- Wip3out: amber #F2A70D.
- GameCube: amber digits #C0A956 / #81601F, tile blue #02126E, ice #63A6DE.
- Dreamcast pills: #A17E6B, #61C495, #2D84C0, #9769C5.
- Music 2000 riffs: #0B7124, #700000, #08D5A2.

Warm accents (yellow, amber, orange) recur as **text and selection colours** across PS2, Wip3out, R4, GameCube and Frequency. This is useful against the "liminal horror" drift.

**7. Materials actually seen:**
- matte, noise-textured opaque blocks (PS2 boot)
- lumpy, stucco-textured cubes (PS2 audio CD)
- semi-transparent glass prisms (PS2 clock)
- smoked iridescent glass (GameCube cube)
- green gel/membrane (Xbox orb)
- glossy deep-blue tiles (GameCube memory card)
- bevelled flat tiles (PS1 SCPH-102, Music 2000)
- dot-matrix LED (GameCube calendar)
- flat print colour (Wip3out, R4)

**Brushed aluminium and sphere-mapped chrome do not appear in any of the 15 references.**

### Where what we saw contradicts `01-ui-aesthetic.md`

1. **PS2 boot towers are not "translucent crystal columns".** They are opaque, matte, noise-textured lavender-grey blocks with one translucent blue cube among them (ref 01).
2. **PS2 menu palette is wrong in 01.** The "Void" base (#030409–#12204A navy-black) does not match:
   - the PS2 clock and System Config sit on a **violet-indigo mottled cloud (#2A1E3D–#453C73)**;
   - the browser sits on a **light warm grey (#787974→#595851)**.
   - "PS2 cobalt #2E5BFF" does not appear. The real PS2 hues are teal #66A8C6, cyan #6BC7E3 and yellow-green #E4F17C.
3. **"Translucent blue orbs/prisms orbiting".** The orbs are tiny white point lights. The prisms are 12 static hour-crystals with a fill-level on the current hour; their colour is teal or blue-violet depending on the capture.
4. **The PS2 browser is not a "dark foggy void".** It is bright and studio-lit. Save icons float bare with **no tiles or four-corner gradient cards** in the grid view. The icon.sys background colours were **not visible** in any browse-view frame we saw (it may only appear in the per-save detail view, which we did not capture). Selection is a light **under** the object, not a scale spring or a glint sweep.
5. **Xbox "connected hexagons" is wrong.** The background is an irregular polygonal (Voronoi-like) web on a curved surface.
6. **Typography rules in 01 contradict the PS2, GameCube and Dreamcast system UIs.**
   - "Labels in caps, tracked +6–10%, 9–11 px" is wrong for them: they use sentence case, normal tracking and large sizes (3–5% of screen height), with an outline or shadow.
   - "Thin, slightly rounded sans" for the PS2 is not what we saw: it is medium weight.
   - Eurostile/Orbitron-style faces fit only the Xbox, WipEout and R4.
7. **Materials list in 01:** brushed aluminium and chrome have **no basis** in these UIs. Matte textured blocks, dot-matrix LED and flat print colour do, and 01 is missing them.
8. **Confirmed by the images:**
   - R4's signature yellow: measured #FAC306, close to 01's #F5C400.
   - The Dreamcast's bright cloud-sky look.
   - GameCube saves on cubes over a dark grid, though the tiles are deep blue #02126E rather than "indigo/violet".
   - Vib-Ribbon's single white line on black.
   - The PS1 blue-violet gradient with two 15-slot (3×5) cards. The rainbow paint-splat labels on the Japanese BIOS are not mentioned in 01.
9. **Not verified visually** (no usable frame found): PSX DESR XMB icon row (only DVR and settings screens with blue-wave backgrounds were seen), Jet Set Radio Future menus (only the title screen), Ape Escape, SSX Tricky, Rez menus, Gran Turismo 3 menus (only 480×360 frames, not kept). The Kingdom Hearts pause menu was seen only as a camera shot of a TV and was not kept: dark pills, with the selected item as a red gradient pill.
