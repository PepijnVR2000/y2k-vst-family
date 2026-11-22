# 04 — Tech Stack: Y2K / PS2-style instrument family for FL Studio

Research date: 2026-11-22. Scope: 3–4 instruments (mono arp synth, drum computer, poly synth, maybe sampler), Windows/FL Studio first, Mac later. Most development is done by AI agents in a Linux cloud container, and a solo creator tests on Windows.

> **How this was researched, and its limits.** Findings come from web search (standard plus extended modes) and direct reads of GitHub repositories. Several primary hosts could not be fetched from this container: juce.com, forum.juce.com, image-line.com and kvraudio.com are outside the network allowlist. For those I used search-result summaries of their pages. The web-search budget also ran out before the last few planned queries. Statements marked **[PK]** come from prior knowledge and were not re-verified this session. Check them before relying on them.

---

## (a) Recommendation in one paragraph

Build the family in **C++ on JUCE 9**, use **CMake** in one monorepo, and ship **VST3 + CLAP** for Windows x64. Get CLAP through the MIT-licensed `clap-juce-extensions`. Skip VST2: new developers cannot get a VST2 licence, and FL Studio hosts VST3 and CLAP natively. Develop under JUCE's free tiers: AGPLv3 while the code is private and unreleased, then the free Starter licence up to US$20k revenue, then Indie at $40/month or $800 perpetual up to $300k. For the UI, use the **hybrid approach**:
- **Pre-rendered Blender filmstrips** for every control. Blender renders headless in the Linux container, so agents can regenerate art from `.blend` files and Python.
- **One small real-time "hero" 3D viewport** per plugin, drawn by a **tiny CPU software rasterizer** at PS1/PS2 resolution (about 320×240) and upscaled with nearest-neighbour. It uses affine textures, vertex snapping, dithering, fog, chrome sphere-maps and cheap bloom. It needs no GPU context, behaves the same with 10 instances open in FL, and can be screenshot-tested in CI.

GPU rendering (JUCE OpenGL, or the MIT-licensed **Visage** library) stays an optional later upgrade. Avoid it in v1 because of known multi-instance and macOS-deprecation problems. A WebView/three.js UI is not recommended as the primary path, because every instance carries its own browser process set.

Agents build and test on Linux: unit tests, offline-render DSP golden tests, pluginval, clap-validator and editor snapshot PNGs. **GitHub Actions Windows runners** build the MSVC VST3/CLAP binaries and the Inno Setup installer. The user downloads them with a one-line PowerShell script.

Build order:
1. **Mono arp synth**: the smallest DSP surface, and it builds the framework.
2. **Drum computer**: adds multi-out, a sequencer and a sample engine, and appeals most to FL users.
3. **Poly synth**: mostly reuses the mono synth's voice code.
4. **Sampler**: reuses the drum computer's sample engine.

---

## (b) FL Studio format & host facts

### Formats hosted (FL Studio 2024 → 2026)
| Format | Windows | macOS | Notes |
|---|---|---|---|
| VST2 | Yes | Yes (64-bit) | Still hosted, but you cannot legally obtain the VST2 SDK as a new developer (see below). |
| VST3 | Yes | Yes | The main target. FL 2025.2 release notes list VST3 compatibility fixes. |
| CLAP | Yes (added in **FL Studio 2024**) | Yes | Scanned alongside VST/AU. A forum request from April 2025 asked for custom CLAP search paths, so it is safest to install to the standard `C:\Program Files\Common Files\CLAP`. |
| AU | — | Yes | Relevant only for the later Mac port. |

- **Current versions:** FL Studio 2025 shipped on 10 July 2025, with 2025.2 in the autumn. FL Studio 2026 shipped on 7 July 2026, followed by 2026.1.x point releases. FL 2026's headline changes were a rebuilt FLEX, the Transmitter plugin, FL Cloud project backup, Gopher AI and Audio Logger. Nothing material changed for third-party plugin hosting.
- **Fruity Wrapper:** FL loads every third-party plugin inside its own "Wrapper". The Wrapper draws a header and settings panel and **embeds the plugin's editor window** inside it. A Wrapper beta dated 8 Oct 2025 hosts VST, VST3, CLAP and AU. Wrapper options users will touch:
  - **Processing → "Make bridged":** runs the plugin in a separate `ilbridge.exe` process. This matters for inter-instance communication (section e).
  - **"Use fixed size buffers":** a troubleshooting option, described as about 2 ms fixed blocks.
  - **"Use maximum buffer size from host" / "Process maximum size buffers":** advanced options that can add latency.
  - **"DPI aware":** a per-plugin toggle.
- **Bridged side effects:** bridged plugins always steal keyboard focus. FL is 64-bit only since 20.9; 32-bit plugins run bridged. Ship **x64 only**. Windows ARM64 can wait.
- **FL 2025.2 added** a setting that limits the number of open plugin editors to 25, and an option to disable plugin keyboard focus by default. Both show that FL users run many editors at once, so UI cost per open editor matters.

### FL-specific gotchas for this project
1. **Multiple outputs (drum computer).** Declare extra stereo output buses through VST3/CLAP bus layouts. In FL the user must enable **Wrapper → Processing → "Auto map outputs"** (or map ports by hand) and then route them to mixer tracks. Users regularly miss that it is off by default (a GForce Oberheim DMX VST3 thread shows this). Practical advice:
   - Keep the **main stereo out fully functional on its own**: mix every voice to it unless the user routes a voice to an aux out.
   - Put a "how to multi-out in FL" page in the manual.
   - Keep the number of aux outs modest, for example main plus 8 stereo pairs.
2. **MIDI out (arp).** VST3 plugins can emit MIDI events. FL passes them on through the Wrapper's MIDI **output port** number, and another plugin's Wrapper receives them on a matching **input port** (ports 0–255, routed like FL's MIDI Out plugin). Forum users report this is fiddly, with limits around 16 channels per port and inconsistent results in a 2024 report. Recommendation: **the arp plays the synth's own voice internally**, so it needs no MIDI routing. "Arp MIDI out" becomes an optional extra, and a "drag pattern to piano roll" (MIDI file export) feature is often more useful.
3. **Slide/porta notes.** FL's piano-roll **slide and porta flags only work with native FL instruments, not VST**. The manual confirms this. Implement your own glide:
   - legato / "slide when notes overlap" (TB-303 style),
   - a glide-time knob,
   - optionally a "slide note velocity" or "slide on accent" convention.
   Per-note length cannot be read as a slide time through VST3/CLAP. A March 2026 FL SDK forum thread shows even native-SDK developers struggling with it.
4. **Plugin delay compensation.** Instruments should report **zero latency** wherever possible. HISE developers report that `setLatencySamples` behaves inconsistently in FL, with an apparent fixed offset. Avoid look-ahead in the instruments, and if you oversample, use minimum-phase filters.
5. **Buffer sizes. [PK]** FL is known to send **variable and sometimes very small blocks**: it splits buffers at note and automation events. The "fixed size buffers" option exists as a workaround for plugins that cannot cope with this. All DSP must work with any block size from 1 sample up to the declared maximum, and must never assume `numSamples == maxBlockSize`. Make this a pluginval and unit-test requirement.
6. **Multithreaded processing. [PK]** FL can process different mixer chains and plugin instances on different threads at the same time. Any state shared between instances (section e) must be lock-free and wait-free on the audio thread.
7. **DPI scaling and resizing.** FL has its own "Main GUI scaling", which can disagree with Windows' scaling, and it has a per-plugin **"DPI aware"** Wrapper toggle. There are many reports of clipped, oversized or blurry editors, including JUCE-built ones and JUCE 8 regressions on older FL builds. An FL 2026 Beta 3 thread from April 2026 says the DPI-aware toggle does not persist for some plugins at 250%. Mitigations:
   - JUCE implements VST3 `IPlugViewContentScaleSupport`. Keep JUCE current.
   - Make the editor **resizable with a fixed aspect ratio** and offer **integer zoom presets (1×, 1.5×, 2×)**. Sprites should be authored at 2× and downsampled.
   - Pixel-art upscaling (nearest-neighbour) of the 3D viewport is DPI-robust by design.
   - Test at 100%, 150% and 200% Windows scaling, with FL GUI scaling both matching and not matching.
8. **Plugin rescans and file locks. [PK]** FL locks loaded DLLs. Replacing a `.vst3` or `.clap` requires closing FL first, and new plugins need a Plugin Manager rescan. Build this into the user's update script.

### Licensing status
- **VST3 SDK → MIT.** Steinberg released **VST 3.8.0 SDK on 2025-10-20** and announced the move to the MIT licence in a **press release dated 2025-10-29**. The `steinbergmedia/vst3sdk` README now says: *"Licensing under GPLv3 and the Steinberg proprietary license is no longer available."* No signed agreement is needed to distribute VST3 plugins. Using the "VST" **trademark or logo** is optional and governed by Steinberg's trademark rules: no "VST" in product names. 3.8 also added MIDI 2.0 interfaces. ASIO became dual GPLv3/proprietary in Oct 2025, which does not matter for plugins.
- **VST2 SDK:** Steinberg stopped licensing new VST2 developers in **October 2018** and removed the SDK from public availability. The MIT change applies to VST3 only, and no 2025/26 statement re-opens VST2. **Do not ship VST2.**
- **CLAP:** MIT. Hosts with good support are Bitwig, REAPER, FL Studio, plus Studio One (partial or newer versions), MultitrackStudio and Waveform. Ableton, Logic and Pro Tools do not support it. Cubase support is announced or partial depending on the source. Plugin vendors adding CLAP in 2026 include Stillwell and Expressive DSP. In FL, CLAP is a good extra (better polyphonic modulation, threading and note expressions), but **VST3 remains the format most FL users will pick**. Ship both.

---

## (c) Framework comparison

Legend for "AI-writability": the amount of public training code and how idiomatic agents' output tends to be. H = high, M = medium, L = low.

| Framework | License (Nov 2026) | Maturity / status | Win + FL compatibility | Custom 3D UI story | AI-writability | Win builds from Linux | Headless testing | Verdict |
|---|---|---|---|---|---|---|---|---|
| **JUCE 9** (9.0.6 current; 9.0.0 around Q3 2026) | Dual: **AGPLv3** or commercial. JUCE 9 keeps the JUCE 8 tiers and prices: **Starter free (≤$20k revenue/funding)**, **Indie $40/mo or $800 perpetual (≤$300k)**, **Pro $175/mo or $3,500 (unlimited, 12-month minimum)**, Educational free. No splash screen requirement. | Industry standard for 20 years. 9.x focuses on UI and performance: new SVG parser, variable fonts, faster software renderer, OpenGL perf/ES, WebView TypeScript npm package (9.0.1), Direct2D fixes (9.0.5). Requires CMake ≥3.22, C++17. | Excellent. Most commercial FL-tested plugins are JUCE. Known DPI quirks in FL are documented, with workarounds. | Software renderer or **Direct2D** (JUCE 8+) for 2D/sprites; `OpenGLContext` for GPU; `WebBrowserComponent` (WebView2 on Windows) for web UIs. No native Metal or Vulkan. | **H** — by far the most public plugin code. | Officially unsupported. clang-cl + xwin works with fixes (case-sensitivity, an inline-asm `jassert` macro). **Use GitHub Actions `windows-latest`** (pamplejuce does). | **pluginval** (GPLv3 tool, CLI exit codes, strictness 1–10), Catch2, offline render; `createComponentSnapshot` for UI (black with GL, empty with WebView). Linux builds run all of these in the container. | **Recommended.** |
| ↳ CLAP for JUCE | `clap-juce-extensions` (MIT). JUCE's Q3 2025 roadmap promised native CLAP authoring in JUCE 9, but the **JUCE 9 change list and README do not list CLAP**. The 9.0 announcement calls "AudioProcessor v2 incl. CLAP features" work in progress. | Mature: used by Surge, Vital forks and many others. | Fine. | n/a | M | same | clap-validator | Use the extensions now; switch if native CLAP lands. |
| **iPlug2** | zlib-like (permissive, closed source OK). | Long-lived (13.5k commits); "iPlug2OOS" is the recommended 2025 starter. **iPlug3** started 1 Jan 2026 (Skia Graphite / WebGPU) and is not production-ready. | Good. Formats: CLAP, VST2*, VST3, AUv2/v3, AAX, WAM. | IGraphics with NanoVG or Skia; WebView UI option; you can embed your own GL. | M-L | Same as JUCE (CI on Windows). | pluginval, clap-validator | Viable free alternative with a smaller ecosystem. Agents get less help from training data. |
| **nih-plug** (Rust) | Framework ISC, **but its VST3 export uses `vst3-sys` (GPLv3)**, so VST3 builds must be GPL-compatible unless the bindings are replaced. The upstream repo is in **maintenance mode**. The community fork **"nice-plug"** (Codeberg, BillyDM) is ISC, "experimental, recently went through large changes"; I could not confirm which VST3 bindings or licence it uses. | Upstream frozen; fork active but young. | VST3 + CLAP; tested on Windows and Linux. | Adapters for egui, iced and VIZIA (Slint in progress); examples with raw OpenGL, **wgpu** and softbuffer. | M (Rust is good, plugin-specific code is scarce) | **Easiest cross-compile** (`cargo xtask bundle` supports cross targets; `cargo-xwin` [PK]). | clap-validator (same author), pluginval | Attractive technically, but licence/binding uncertainty and fork churn make it riskier for a commercial family. Second choice. |
| **DPF (DISTRHO)** | ISC; its **own VST3 implementation** (no Steinberg SDK; ISC) and CLAP (MIT). | Mature in the Linux/OSS world; activity in 2025–26 including Win ARM64 CI. | Works, but is less tested in FL. | DGL (OpenGL/Cairo) plus Dear ImGui; WebView support [PK]. | L | Very good (MinGW cross-builds are routine) [PK]. | pluginval, clap-validator | Good for open-source and Linux-centric work; thin documentation and examples for agents. |
| **clap-wrapper** | MIT (you supply the MIT VST3 SDK). | Active; `main` moves at releases; Rust bindings track 0.14 (Mar 2026). | Wraps one CLAP into VST3, AUv2, AUv3, AAX and standalone. | n/a (format layer) | M | Good | clap-validator plus pluginval on the VST3 | Use it if you write "CLAP-first" without JUCE (for example plain C++ or Rust). Not needed with JUCE. |
| **Faust** (DSP language) | Compiler GPL, but **generated code takes the licence of your input**, and architecture files carry a FAUST exception. Commercial use is OK. | Very mature (GRAME). | Generates C++ that drops into JUCE. | n/a | M (good corpus of DSP examples) | n/a | Offline render via the C++ output | Optional: good for prototyping filters and effects that are then vendored as C++. Not core. |
| **Cmajor** | **GPLv3 or commercial** (commercial agreement dated 2025-04-28; a third-party blog lists Indie and Pro tiers, prices unverified). Owned by Sound Stacks / Soundwise. Developers presented at ADC26 (Nov 2026). | Alive; exports to JUCE projects, plain C++ or WebAudio. | Through JUCE export. | n/a (JS/WebView patch GUIs) | L | — | — | Not worth an extra licence and toolchain here. |
| **SOUL** | — | **Discontinued**; superseded by Cmajor. | — | — | — | — | — | Avoid. |
| **Elementary Audio** | MIT. | Small but alive (JS DSP graph, C++ engine embeddable, SRVB plugin template). Slow-moving by design. | Through its native integration / templates. | Web UI by nature. | M (JS) | — | — | Interesting for WebView-native teams; not a fit for low-overhead multi-instance instruments. |

\* VST2 in iPlug2 needs the VST2 SDK, which is unavailable to new developers.

**Verdict:** **JUCE 9 + clap-juce-extensions + CMake (start from pamplejuce, which already tracks JUCE 9 develop, C++23, Catch2, pluginval and Azure Trusted Signing).** JUCE has the most training data for agents, the best FL track record, built-in WebView, Direct2D and OpenGL options for later, and its free tiers fit a solo creator until revenue exceeds $20k. Licence notes:
- Under AGPLv3, distributing closed binaries is not allowed. Register a **Starter** licence (free) before the first public release.
- Move to Indie once revenue or funding passes $20k.
- The JUCE README now explicitly asks AI tools to flag the licence. Keep `LICENSE.md` compliance in the agents' CLAUDE.md.

---

## (d) 3D UI approach

### Options evaluated
| Option | Look achievable | Reliability in FL (10 instances) | CPU/GPU cost, 10 editors open | Agent-friendliness / testability | Notes |
|---|---|---|---|---|---|
| **(a) Pre-rendered filmstrips** (Blender → PNG strips; KnobMan for simple ones) | Excellent for 3D buttons, chrome knobs, glossy LEDs and lit panels. Static lighting only. | **Best**: plain image blits with Direct2D or the software renderer. | Near zero when idle. Redraw only dirty controls. Memory: a 128-frame 2× knob strip is about 20–40 MB decoded per unique knob type, **shared across instances** via a static image cache. | **Very high**: Blender runs `blender -b file.blend -P render.py` headless in the Linux container, so agents can regenerate art. Deterministic snapshots. | The industry-standard path (u-he, many others). |
| **(b) Real-time OpenGL in JUCE** | Full 3D, shaders, bloom. | **Risky**: a long history of JUCE forum reports of frame drops, deadlocks and host freezes with several GL editors on Windows (context switching with `wglMakeCurrent`, message-thread contention), plus a 2025 report of host freezes with multiple open UIs since JUCE 8.0.8. Some developers run 10+ instances without trouble, so results depend on host and GPU. | GPU low per instance, but driver serialisation hurts with many contexts. | Medium: snapshots of GL components come back black, so tests need FBO readback. | **Deprecated on macOS since 2018** and JUCE has no Metal backend, which hurts the Mac port. |
| **(c) bgfx / sokol / wgpu / Visage embedded** | Full 3D, shaders, post-FX. | Good if carefully done (one device per editor, child HWND). More integration work. | GPU modest. | Medium-low (more bespoke code). **Visage** (MIT, by Vital Audio): GPU UI library with D3D11/Metal/Vulkan/WebGL backends, transpiled shaders, post-process/backdrop shader effects, and plugin window embedding. Its repo even ships CLAUDE.md/AGENTS.md. It is 2D-focused and has no releases yet. | A good **upgrade path** for GPU post-FX (bloom, CRT) without OpenGL. Watch it; don't bet v1 on it. |
| **(d) WebView (JUCE 8/9 `WebBrowserComponent` → WebView2) + three.js** | Full 3D, easy to animate menus, huge web corpus for agents. | Moderate. Microsoft documents that **each WebView2 control creates its own browser/renderer/GPU process set**, so memory grows with instance count. JUCE threads report crashes when re-inserting the last instance, a freeze with WebView2 plugins open in two DAWs, and leaked WKWebView processes on macOS. Requires the WebView2 runtime (preinstalled on Win 11 [PK]). | **Highest**: [PK] roughly 80–150 MB RAM and several processes per open editor; 10 editors means about 1 GB or more, plus 10 WebGL contexts. Parameter sync goes through a JS↔C++ message bridge (async, about 1 frame). Fine for knobs, poor for 60 fps meters/scopes unless batched. | High for code, low for testing: `createComponentSnapshot` cannot capture a WebView, so you need a separate headless-browser test harness. | Proven in hobby and visualiser projects (3DVerb, react-three-fiber visualisers). One developer measured CPU similar to native in initial tests. Wrong trade-off for a family that will be multi-instanced. |
| **(e) Hybrid: sprites for controls + small real-time hero element** | 95% of the look. | Best of (a) plus a bounded risk area. | See below. | High. | **Recommended.** |

### Recommendation: (e) hybrid, with a **software-rasterised hero viewport**
- **Controls and panels:** Blender filmstrips (knobs, 3D buttons, toggles, LCD segments), 9-slice chrome frames, and bitmap or variable fonts. Use a shared, ref-counted `SpriteCache`, so 10 instances decode each strip once. Author at 2× and select 1× or 2× at runtime from the editor scale.
- **Animated menus:** use JUCE `ComponentAnimator` / `VBlankAttachment`-driven tweens on sprite layers, with PS2-style slide, zoom and glow transitions. These are cheap 2D compositing.
- **Hero 3D element** (a spinning chrome logo, rotating drum-pad "memory card", 3D oscilloscope tunnel, PS2-boot-style towers): a **~300-line CPU rasteriser** renders into a `juce::Image` at **256×192 or 320×240**, then scales it up with nearest-neighbour. PS1/PS2 artifacts come almost free:
  - affine texture warping,
  - vertex snapping to a low-resolution grid,
  - no sub-pixel precision,
  - ordered dithering to 15-bit colour,
  - per-vertex fog,
  - sphere-map "chrome" lookups,
  - a cheap low-resolution bloom (downsample, blur, add).
- **Cost estimate (engineering estimate, not measured):** 76,800 pixels × about 2 overdraw × a simple shader is about 150k fragment ops per frame. At 30 fps that is roughly 5M ops/s, or **under 1–2% of one core per open editor**, and **zero when the editor is closed or hidden**. With 10 editors open, expect about 10–15% of one core spread over the message thread, and no GPU contexts. Cap the hero at 30 fps (PS2 games often ran at 30) and pause it when the editor is not visible or the window is occluded.
- **Why not GPU first:** it avoids the multi-instance OpenGL problems in FL, the macOS OpenGL deprecation, and WebView memory. It is deterministic, so CI can produce **pixel-exact screenshot tests** on Linux. Agents can write and debug a small rasteriser easily.
- **Upgrade path:** if a later product needs heavier real-time 3D (thousands of triangles, real bloom at high resolution), put a `HeroRenderer` interface behind the viewport and add a GPU backend (Visage/D3D11 or bgfx) for that product only.

---

## (e) Family architecture sketch

```
y2k-family/                      (monorepo, CMake, JUCE 9 as submodule, CPM deps)
├─ libs/
│  ├─ y2k_dsp/        header-mostly C++: oscillators (polyBLEP/minBLEP, wavetable),
│  │                  ZDF/TPT filters (SVF, ladder, 303-ish diode), ADSR/AD envs, LFOs,
│  │                  glide/legato, voice allocator (mono/poly/drum-choke), sample player
│  │                  (resampler, start/loop), drive/bitcrush ("PS1 SPU" style 4-bit ADPCM-ish
│  │                  colour), simple FX (chorus, delay, reverb), smoothing, denormal guards.
│  │                  NO JUCE dependency → unit-testable, reusable, portable.
│  ├─ y2k_seq/        host-synced clock (ppq-based), step sequencer, arp engine, swing,
│  │                  pattern model, MIDI-file export.
│  ├─ y2k_ui/         Theme tokens, LookAndFeel, SpriteCache (shared static), FilmstripKnob,
│  │                  3D Button, LCD text, Menu/transition system, HeroViewport +
│  │                  SoftRaster (PS1/PS2 pipeline), scale/zoom manager.
│  ├─ y2k_preset/     Preset schema (JSON, versioned + migrations), factory bank loader,
│  │                  user preset folder, A/B compare, randomiser hooks, "family" tags.
│  ├─ y2k_link/       Optional inter-instance link (see below).
│  └─ y2k_plugin/     Base AudioProcessor: parameter registry → APVTS, state save/restore,
│                     bus-layout helpers, CLAP extensions glue, version/about panel.
├─ plugins/
│  ├─ monoarp/  drumcomp/  polysynth/  sampler/   (thin: params + voice + editor layout)
├─ assets/          .blend sources + render scripts → generated PNG strips (CI cached)
├─ tests/           Catch2: DSP unit, offline-render golden, preset round-trip, UI snapshots
├─ tools/           render_offline (CLI host-less renderer), make_strips.py, compare_wav.py
└─ .github/workflows/  linux-test.yml, windows-release.yml, (later) mac-release.yml
```

**Shared preset format:** use JSON with `{"format":"y2k-preset","version":N,"plugin":"monoarp","params":{id:value},"meta":{...}}`. Plugin state is the same JSON, so DAW state and preset files share one code path. Use stable string parameter IDs and never reuse them. VST3/CLAP need stable parameter IDs for automation, so give every parameter in the base class an explicit version and ID.

**Inter-plugin communication: how to do it safely**
1. **Shared clock: use the host, not IPC.** Every instance gets the same host transport (PPQ position, tempo, playing flag) each block. Deriving sequencer and arp phase from host PPQ keeps all family members sample-locked with no shared state. This covers 90% of "linking".
2. **Same plugin, many instances** (for example two Drum Computers): one DLL means one set of statics, so a `juce::SharedResourcePointer<Registry>` works. Community reports say it is reliable within one process. Use it for shared caches such as sprites and sample pools.
3. **Different plugins in the family** (mono arp ↔ drum computer, for "follow drum accents" or a shared scale/key). These are separate DLLs, so statics are **not** shared. Options:
   - **Recommended:** a small **named shared-memory segment** (Windows `CreateFileMapping` "Local\\Y2KLink-v1-<pid>"; POSIX `shm_open` on Mac) holding a fixed-layout, versioned struct. It contains:
     - a **seqlock**-protected table of up to 32 instance slots (id, type, name, colour),
     - per-slot published values (key/scale, accent bitmask per step, macro values),
     - heartbeat timestamps.
     The audio thread only does wait-free reads and writes of atomics. Discovery and UI listing run on the message thread. Including the **process ID** in the name scopes links to one FL session and prevents cross-talk between two FL instances.
   - Alternatives: OSC/UDP over localhost works across processes (it survives bridging), but adds latency, firewall prompts and complexity, so use it as a fallback only. A **shared helper DLL** loaded by all plugins also works but complicates installs and versioning; avoid.
4. **FL caveats:**
   - "Make bridged" moves an instance into `ilbridge.exe`, a different process, so the pid-scoped link will simply **not see it**. The UI must show "not linked (bridged?)" instead of failing.
   - FL can process instances on different threads in parallel, so treat link data as **advisory and last-value-wins**. Never let one instance's audio depend on another having processed first in the same block (there is no ordering guarantee).
   - Offline render and freezing run at faster than real time, but host-PPQ sync stays correct there. Wall-clock heartbeats do not, so do not use them for timing.
5. **Audio between plugins:** don't do it. Use FL's mixer and sidechain routing.

---

## (f) Dev / CI workflow (agents on Linux, user on Windows)

**In the Linux container (fast inner loop for agents):**
- Build the **Linux VST3/CLAP/Standalone plus test targets** with CMake + Ninja + clang or gcc, using a ccache-backed build directory.
- **DSP unit tests (Catch2):**
  - impulse and step responses,
  - filter cutoff accuracy,
  - aliasing checks (FFT of a 5 kHz saw at 44.1 kHz; energy below the fundamental must be under a threshold),
  - denormal/NaN checks,
  - variable block-size equivalence: render the same MIDI with block sizes {1, 7, 64, 512, random} and the outputs must match within 1e-6. This targets FL's variable buffers.
- **Offline-render golden tests:** a `render_offline` CLI instantiates the processor directly (no host), feeds a MIDI file and a preset, writes a WAV, and compares it with a golden file. Use a sample-exact or spectral tolerance, and RMS/peak/LUFS summaries for less brittle checks. Goldens are versioned and updated only with an explicit `--update-goldens`.
- **pluginval** at strictness 5–8 on the Linux VST3, plus **clap-validator** (`clap-validator validate x.clap`, runs tests out of process) on the CLAP.
- **UI snapshot tests:**
  - Create the editor offscreen at fixed scales (1×, 2×), call `createComponentSnapshot`, and save PNGs.
  - Diff them against goldens (perceptual tolerance), and also upload them as CI artifacts so the user and agents can *see* UI changes in PRs.
  - The software-rasterised hero viewport is included deterministically (use a fixed time and seed).
  - JUCE on Linux needs an X display for some components, so run under **Xvfb** [PK].
  - GL components snapshot black and WebView components cannot be captured, which is another reason for the software hero.
- **Art pipeline:** `blender -b assets/knob.blend -P tools/make_strips.py` renders filmstrips headless (Blender's Cycles/EEVEE in background mode [PK]; EEVEE needs a GPU or software GL, so use Cycles CPU at low samples in CI). Cache the outputs.
- **Optional:** a clang-cl + **xwin** Windows cross-compile for quick "does it compile on MSVC headers" checks. JUCE does not officially support this, and the known hiccups are a case-sensitive SDK and the `__asm int 3` macro. Do not ship these builds.

**GitHub Actions (authoritative Windows builds):**
- Use a `windows-latest` runner with MSVC and CMake to build VST3 + CLAP (x64 Release). Run **pluginval** and **clap-validator** on Windows too. Package with **Inno Setup** [PK: preinstalled on GitHub Windows images; otherwise `choco install innosetup`].
  - Install to `C:\Program Files\Common Files\VST3\Y2K\` and `...\Common Files\CLAP\Y2K\`.
  - Factory presets and samples go to `%PUBLICDOCUMENTS%\Y2K\` or `%APPDATA%`.
  - Inno Setup licence: since **6.5.0 (Aug 2025)** commercial users are *asked* to buy a perpetual licence. It is not strictly required by the licence text, but plan to buy one when selling.
- **Code signing (Windows):**
  - **Azure Artifact Signing** (formerly Trusted Signing) costs **$9.99/month** (Basic, 5,000 signatures) and integrates with `signtool` in CI; pamplejuce documents the setup.
  - **Individual developers are eligible only in the USA and Canada**. Organisations are eligible in more regions, the US, Canada, EU and UK at minimum.
  - Outside those regions, use an OV code-signing certificate on a cloud HSM.
  - For private beta testing, unsigned builds are fine. SmartScreen will warn on the installer, but the DLLs load in FL regardless.
- **Delivery to the user:**
  - Every push to `main` produces a zipped artifact: VST3, CLAP, installer and a `BUILD_INFO.txt` with the commit hash. Tags produce a GitHub Release.
  - The user runs `get-latest.ps1`, which (1) checks that FL Studio is closed, (2) runs `gh run download` / `gh release download`, (3) copies the bundles into the Common Files folders, and (4) prints the build hash.
  - The plugin's About panel shows the same hash, so the user and agents can confirm which build was tested.
  - Bug reports are a template: FL version, Windows scaling %, FL GUI scaling, bridged yes/no, build hash, steps to reproduce.
- **Mac later:** add a `macos-latest` job (universal binary, AU + VST3 + CLAP, notarization; pamplejuce has this). Real-device testing needs a Mac.

---

## (g) Phasing & effort (solo creator + AI agents)

These assume the creator works about 15–25 h/week reviewing, testing in FL and doing art direction, with agents writing most of the code. They are estimates, not measurements.

| Phase | Content | Calendar estimate |
|---|---|---|
| **0. Skeleton & pipeline** | Monorepo from pamplejuce; JUCE 9 + clap-juce-extensions; a "hello" instrument (sine + gain) shipping VST3/CLAP; Linux tests; Windows CI + Inno Setup; `get-latest.ps1`; confirm loading, automation, state save and DPI in FL. | **1–2 weeks** |
| **1. Framework + Mono Arp Synth MVP** | `y2k_dsp` (2 osc + sub, noise, SVF/ladder, 2 envs, LFO, drive, glide/legato), arp (up/down/updown/random/as-played, 1/4–1/32 + triplets, gate, swing, octaves, latch, host-PPQ sync), ~30 params, JSON presets + 30 factory presets, `y2k_ui` v1 (filmstrip knobs, 3D buttons, LCD, page/menu transitions, hero viewport with a low-poly chrome logo), resizable editor at 1× and 2×. Golden-audio and snapshot tests. | **6–10 weeks** |
| **2. Drum Computer** | 8–12 voices (synthesised 808/909-ish kick/snare/hat/tom/clap + sample slots), 16/32-step sequencer per voice with accent, flam and probability, host-synced pattern chaining, MIDI-note triggering (so FL's piano roll and step sequencer also work), **multi-out (main + 8 stereo aux)**, choke groups, kit/pattern presets, `y2k_seq` matured, sample engine v1, optional y2k_link (shared key/accents). | **6–10 weeks** |
| **3. Poly Synth** | Reuse mono DSP; voice allocator (8–16 voices, unison, voice stealing), per-voice mod matrix-lite, FX (chorus/delay/reverb), CPU optimisation (SIMD, voice culling). | **4–6 weeks** |
| **4. Sampler (optional)** | Reuse the sample engine; zones and keygroups, loop points, time-stretch-lite or ROM-style pitch, drag & drop, sample management and paths (the hardest UX part), PS1 "SPU" lo-fi mode. | **8–12 weeks** |
| **5. Polish & release** | Manuals, installers, signing, licensing/copy protection (if any), website, Mac port. | **4–8 weeks** (Mac adds 3–6) |

**Total:** about **7–12 months** for three instruments, and **9–15 months** with the sampler and Mac. The biggest variable is **UI art direction**. Blender assets, the PS2 look and menu motion are human-judgement work that agents can script but not taste-check. Budget creator time for it, or a contract 3D artist for the hero models.

**Why the Mono Arp Synth first:**
- It has the smallest DSP surface: a single output, no sample management and a monophonic voice.
- It still exercises **every framework layer**: parameters, presets, host sync (arp), the UI kit, the hero viewport, CI, the installer and FL quirks (glide versus FL slide notes, small blocks).
- The poly synth later reuses its voice code almost 1:1.
- The drum computer is second because it is the strongest product for FL beatmakers, and it forces the remaining framework features: multi-out, sequencer and sample engine. The sampler then reuses that sample engine.
- Alternative: if marketing matters more than framework hygiene, start with the drum computer. Expect phase 1 to take about 30% longer, because multi-out, sequencer and samples land together with the framework.

**MVP definition for one instrument (ship criteria):**
- Loads, saves and restores reliably in FL 2025/2026 (VST3 + CLAP).
- Passes pluginval at strictness ≥5 and clap-validator.
- No clicks or zipper noise on automation; handles any block size.
- Uses under 3% CPU on one core per instance at 44.1 kHz/256 (mono synth).
- Under 2% UI CPU with the editor open; 0% with it closed.
- Usable at 100%, 150% and 200% scaling.
- 30+ factory presets.
- Installer plus manual page.

---

## (h) Open risks

1. **JUCE licensing over time:** AGPL during private development is fine. Releasing closed-source builds requires registering Starter (free, ≤$20k), then Indie ($40/mo or $800 perpetual, ≤$300k). Terms can change at major versions; JUCE 9 kept JUCE 8's terms. Read the current EULA (juce.com, not reachable from this container) before release.
2. **Native CLAP in JUCE** was roadmapped for JUCE 9 but has not landed as of 9.0.6. `clap-juce-extensions` works, but it is a third-party layer that breaks JUCE abstractions on purpose. Expect a migration once native support ships.
3. **FL Studio DPI and Wrapper quirks** keep recurring (reports as recent as the FL 2026 beta). Mitigate with integer-zoom UI design and a test matrix, and treat it as a permanent support cost.
4. **FL slide/porta notes do not reach VST/CLAP.** If "FL-native slides" is a must-have, the only route is Image-Line's native FL plugin SDK, a separate format that is Windows/Delphi-flavoured and poorly documented. Recommendation: don't. Use overlapping-note legato glide.
5. **Multi-out discoverability in FL** ("Auto map outputs" is off by default). Mitigate with docs and a fully functional main out.
6. **Code signing for a non-US/Canada individual:** Azure Artifact Signing is not available, and OV certificates cost hundreds of dollars a year plus HSM requirements. Unsigned builds work for testing but hurt trust at release.
7. **Agent-written DSP quality:** aliasing, denormals, zipper noise and filter instability pass unit tests but sound bad. The golden tests and spectral/aliasing checks catch regressions, but **the creator's ears are the final gate**. Schedule listening sessions per milestone.
8. **Art pipeline:** Blender and the filmstrip memory budget. Many large 2× strips across 4 plugins can reach hundreds of MB if not shared or compressed. Mitigate with sprite atlases, fewer frames (64 is often enough), and lazy loading.
9. **Software hero renderer scope creep:** keep it under about 500 triangles at about 320×240. Anything bigger is a GPU decision.
10. **Inter-instance link:** silent failure when bridged or sandboxed, and ordering nondeterminism. Keep it optional and advisory.
11. **Visual IP:** "PS2-style" must not use Sony trademarks, the PlayStation logo, PS2 BIOS assets or console fonts. Evoke the style; don't copy the boot screen.
12. **macOS later:** the OpenGL deprecation is avoided by the software renderer. You still need Apple Developer ID ($99/yr [PK]), notarization and real-Mac testing, and WebView/WKWebView process leaks are a reason to avoid web UIs.
13. **Research gaps:** the following were not verified this session and should be checked: FL variable-block behaviour (prior knowledge), the GitHub runner image contents (Inno Setup preinstalled), the current nice-plug VST3 binding licence, and Visage's maturity.

---

## (i) Sources

**FL Studio**
- Image-Line manual, Plugin standards (formats incl. CLAP, Win/Mac): https://www.image-line.com/fl-studio-learning/fl-studio-online-manual/html/plugins_supported.htm
- FL Studio 2024 what's new (CLAP added): https://www.image-line.com/fl-studio-news/fl-studio-2024-whats-new/ ; https://image-line.com/blog/fl-studio-2024-is-here
- Wrapper beta 8 Oct 2025 (VST/VST3/CLAP/AU): https://forum.image-line.com/viewtopic.php?p=2029665
- Custom CLAP search paths request: https://forum.image-line.com/viewtopic.php?p=2039025
- FL Studio 2025 / 2025.2: https://www.image-line.com/fl-studio-news/fl-studio-2025 ; https://www.image-line.com/fl-studio-news/fl-studio-2025-2 ; https://www.image-line.com/fl-studio-learning-content/fl-studio-online-manual/html/basics_new_25.htm
- FL Studio 2026 (7 July 2026) and point releases: https://musictech.com/news/gear/fl-studio-2026-everything-you-need-to-know/ ; https://alternativeto.net/news/2026/7/fl-studio-2026-brings-rebuilt-flex-fl-cloud-project-storage-and-new-transmitter-plugin/ ; https://forum.image-line.com/viewtopic.php?p=2065228 ; https://forum.image-line.com/viewtopic.php?p=2067096
- Wrapper options (bridged, fixed buffers, DPI): https://www.image-line.com/fl-studio-learning/fl-studio-online-manual/html/plugins/wrapper.htm ; https://support.splice.com/en/articles/9824220-why-is-bridge-having-issues-in-fl-studio ; https://support.ujam.com/hc/en-us/articles/25203052903196-FL-Studio-Audio-Architecture-UJAM-Plugin-Integration
- Multi-output plugins in FL: https://www.image-line.com/fl-studio-news/multi-input-output-plugins ; https://www.image-line.com/fl-studio-learning-content/fl-studio-online-manual/html/flstudio_vst_plugin.htm ; https://www.kvraudio.com/forum/viewtopic.php?p=8939737 ; https://forum.image-line.com/viewtopic.php?p=1989671
- MIDI Out / wrapper ports: https://www.image-line.com/fl-studio-learning-content/fl-studio-online-manual/html/plugins/MIDI%20Out.htm ; https://forum.image-line.com/viewtopic.php?p=1972894
- Slide/porta native-only: https://www.image-line.com/fl-studio-learning/fl-studio-online-manual/html/pianoroll.htm ; https://forum.image-line.com/viewtopic.php?p=2051114
- PDC reports: https://forum.hise.audio/post/23173 ; https://forum.hise.audio/topic/1616/fl-studio-20-1-latency-with-delay?page=2
- DPI: https://forum.image-line.com/viewtopic.php?p=1980354 ; https://forum.image-line.com/viewtopic.php?p=1990810 ; https://forum.image-line.com/viewtopic.php?p=2055780 ; https://forum.juce.com/t/fl-studio-window-scaling-problem/31672 ; https://forum.juce.com/t/hidpi-and-flstudio/17873 ; https://support.slatedigital.com/hc/en-us/articles/4415473099283-Windows-Plugin-UI-too-small-too-big-or-blurred

**Licensing: VST / CLAP / ASIO**
- Steinberg press release 2025-10-29 (VST 3.8, MIT): https://ocl-steinberg-live.steinberg.net/_storage/asset/819253/storage/master/Press%20Release%20-%202025-10-29%20-%20VST%203.8%20-%20EN.pdf
- VST 3.8.0 SDK released (2025-10-20): https://forums.steinberg.net/t/vst-3-8-0-sdk-released/1011988
- vst3sdk README (MIT; GPLv3/proprietary no longer available; trademark rules): https://github.com/steinbergmedia/vst3sdk
- KVR: https://www.kvraudio.com/news/steinberg-moves-vst-3-sdk-to-mit-open-source-license-asio-now-gplv3-65179 ; Libre Arts: https://librearts.org/2025/11/steinberg-relicenses-vst3-and-asio/ ; heise: https://www.heise.de/en/news/Steinberg-Releases-ASIO-and-VST-Audio-Interfaces-Under-Open-Source-Licenses-10963451.html
- VST2 no new licences since Oct 2018: https://www.synthedit.com/vst2-licensing/ ; https://forum.ableton.com/viewtopic.php?t=249796
- CLAP adoption (secondary): https://spectral-colors.com/news/clap-vs-vst3-2026/ ; https://producergrid.com/blog/clap-plugin-format-everything-you-need-to-know/ ; https://www.antarestech.com/blog/vst3-au-aax-clap-plugin-formats-2026 ; https://www.stillwellaudio.com/news/linux-and-clap-available/ ; https://expressivedsp.com/blog/clap-support/

**Frameworks**
- JUCE tiers/prices: https://juce.com/get-juce/ ; https://juce.com/legal/juce-8-licence/ ; https://forum.juce.com/t/amendments-to-the-juce-end-user-licence-agreement-for-juce-8/61265
- JUCE 9 (no pricing/EULA changes; features): https://forum.juce.com/t/juce-9-no-pricing-or-eula-changes/69000 ; https://forum.juce.com/t/juce-9-is-available-now/69175 ; https://forum.juce.com/t/juce-9-0-1-is-out/69269 ; https://github.com/juce-framework/JUCE/blob/master/CHANGE_LIST.md ; https://github.com/juce-framework/JUCE ; https://www.noizefield.com/news/juce-9-ships-with-direct2d-gpu-rendering-9-0-1-patch
- JUCE roadmap Q3 2025 (CLAP planned for JUCE 9): https://juce.com/blog/juce-roadmap-update-q3-2025/
- clap-juce-extensions / JUCE CLAP FR: https://forum.juce.com/t/fr-support-clap-for-plugins-host-client/51860 ; https://git.tdem.in/free-audio/clap-juce-extensions
- iPlug2: https://github.com/iPlug2/iPlug2 ; iPlug3: https://github.com/iplug3
- nih-plug (maintenance mode, vst3-sys GPLv3): https://github.com/robbert-vdh/nih-plug ; fork notice: https://github.com/robbert-vdh/nih-plug/issues/265 ; nice-plug: https://github.com/BillyDM/nih-plug
- DPF: https://github.com/DISTRHO/DPF ; licensing table: https://git.kx.studio/DISTRHO/DPF/src/commit/4100e47d4c13dc7e5fc6b087be442ac3c1237896/LICENSING.md
- clap-wrapper: https://github.com/free-audio/clap-wrapper ; clap-validator: https://github.com/free-audio/clap-validator (also https://github.com/robbert-vdh/clap-validator)
- pluginval: https://github.com/Tracktion/pluginval
- Faust licensing FAQ: https://faustdoc.grame.fr/manual/faq ; architecture files: https://faustdoc.grame.fr/manual/architectures
- Cmajor licence: https://cmajor.dev/docs/Licence ; https://cmajor.dev/docs/assets/license/Cmajor-Commercial-License.pdf ; ADC26: https://sonicstate.com/news/2026/11/10/adc26-c-major-programming-language/
- SOUL discontinued: https://forum.juce.com/t/is-soul-still-being-actively-developed/64035 ; https://forum.hise.audio/post/67579
- Elementary Audio: https://github.com/elemaudio/elementary
- Cross-compiling: https://github.com/Jake-Shadle/xwin/ ; https://forum.juce.com/t/compilation-fails-on-windows-clang-13-due-to-inline-asm/49520 ; https://forum.juce.com/t/building-a-vst-plugin-in-linux-for-using-in-windows-is-that-possible/28252

**UI / rendering**
- JUCE OpenGL multi-instance issues: https://forum.juce.com/t/openglrenderer-massive-performance-hit-with-multiple-instances/29913 ; https://forum.juce.com/t/performance-issue-with-opengl-in-multiple-windows/23451 ; https://forum.juce.com/t/opengl-deactivatecurrentcontext-windows-cpu/50550 ; https://forum.juce.com/t/host-freezing-when-multiple-plugin-ui-instances-are-open-since-juce-8-0-8/67441/6
- macOS OpenGL deprecation: https://www.macrumors.com/2018/06/05/apple-deprecates-opengl-opencl-gaming/ ; https://forum.juce.com/t/juce-opengl-deprecated-mac-ios/31308
- WebView2 performance and process model: https://learn.microsoft.com/microsoft-edge/webview2/concepts/performance ; JUCE WebView issues: https://forum.juce.com/t/crash-when-using-webview2-plugins-in-multiple-daws-in-parallel-on-windows/64853 ; https://forum.juce.com/t/bug-macos-webbrowsercomponent-orphaned-leaking-processes/48367 ; https://forum.juce.com/t/webview-vs-juce-graphics/61156
- three.js/WebView examples: https://forum.juce.com/t/introducing-3dverb-utilizing-juce-webview-to-visualize-algorithmic-reverb-in-three-dimensions/66950
- Visage (MIT GPU UI): https://github.com/VitalAudio/visage ; https://iplug2.discourse.group/t/using-visage-graphics-in-iplug/1002
- Snapshot testing: https://forum.juce.com/t/get-screenshot-of-a-plugin-without-open-it/64464 ; https://forum.juce.com/t/component-createcomponentsnapshot-returns-black-image-if-opengl-context-attached/37565 ; https://forum.juce.com/t/direct2d-gradient-rendering-difference/67367

**Family architecture**
- SharedResourcePointer and inter-instance communication: https://forum.juce.com/t/two-instances-of-my-plugin-communicating-with-each-other-in-a-daw-project-whats-a-good-approach/62913 ; https://forum.juce.com/t/sharedresourcepointer-between-different-plugins/35662 ; https://forum.juce.com/t/singleton-instance-shared-between-plugin-instances/39867

**Workflow / distribution**
- pamplejuce: https://github.com/sudara/pamplejuce
- Inno Setup commercial licences (6.5.0, Aug 2025): https://jrsoftware.org/isorder.php ; https://jrsoftware.org/files/is6-whatsnew.htm ; https://groups.google.com/g/innosetup-announce/c/xFoxpW036-w
- Azure Artifact Signing eligibility and pricing: https://learn.microsoft.com/en-us/windows/apps/package-and-deploy/code-signing-options ; https://www.devclass.com/security/2026/01/14/code-signing-windows-apps-may-be-easier-and-more-secure-with-new-azure-artifact-service/4079554 ; https://github.com/MicrosoftDocs/azure-docs/blob/main/articles/artifact-signing/how-to-change-sku.md ; https://www.itwriting.com/blog/12462-getting-started-with-azure-artifact-signing.html
