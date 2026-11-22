# 03: Innovation landscape for a PS2-era jungle plugin family

**Project:** a family of VST3/CLAP plugins for FL Studio: a drum computer, a mono arp synth, a poly synth and possibly a sampler. The look is Y2K / PlayStation 2 era (3D buttons, console menus). The sound is wavy jungle, breakbeat and drum & bass.
**Brief:** don't build a retro replica. Find something new, playful or quirky that sets it apart.
**Date of research:** 2026-11-22. Sources are numbered in [brackets] and listed in section (f).

> Platform note: FL Studio has supported CLAP since FL Studio 2024 (24.1, mid-2024), alongside VST3, on Windows and macOS [S1]. Shipping VST3 + CLAP covers every current FL user.

---

## (a) The vocal-tract example, identified

**Pink Trombone, by Neil Thapen (2017).** Thapen is a logic researcher at the Institute of Mathematics of the Czech Academy of Sciences. Pink Trombone is a free browser speech synthesiser that draws a cross-section of the human vocal tract. You drag the tongue, lips, soft palate and throat constriction with your mouse, and the model makes the matching sound in real time. It uses a 2D digital waveguide model of the tract, driven by a glottal source. He started it as a hobby when his daughter began to speak. The original is at dood.al/pinktrombone [S2][S3]. Researchers now also use it as a differentiable articulatory synthesiser that can be fitted to recorded audio [S2].

**It is now a plugin.** In August 2026, Steve Duda (Xfer Records, maker of Serum) released a free port as a personal side project. It comes as VST3/AU on macOS, Windows and Linux, in two versions: Instrument and FX. The FX version runs any external audio through the vocal tract, and reviewers called it the more useful of the two [S4][S5]. Duda offers no support commitment.

**Related vocal-tract and voice instruments:**
- **Antares THROAT (Evo):** a commercial physical model of the vocal tract used as a voice processor. A graphic shows five points from the vocal cords to the lips, and you can stretch, widen or constrict the tract beyond human anatomy. It also has glottal waveform editing and a breathiness control [S6].
- **xoxos Fauna:** a waveguide vocal-tract model for abstract and animal voices [S6].
- **NUSofting Dig Vox:** glottis plus vocal-tract hybrid [S6].
- **Plogue Alter/Ego (free, 2015) and chipspeech:** real-time singing and speech synthesis. You type lyrics and play them from a keyboard. chipspeech recreates speech chips up to 1984 [S7].

**Why Pink Trombone sticks in people's heads, and what we should take from it:**
1. **The UI is the object.** There are no knobs labelled "F1 formant". You grab a tongue. The controls are anatomical, so anyone understands them instantly.
2. **It is funny and expressive at the same time.** Most people laugh first and then find a musical use.
3. **A physical model gives emergent behaviour.** You get sounds nobody programmed (gurgles, whistles, half-vowels) because the model simulates a physical system rather than mapping parameters.
4. **The FX mode is what lasts.** Passing other audio through the "body" is what producers keep using.

**Lesson for us:** find the PS2-era equivalent of the throat, a physical object of that period whose parts you can grab. Section (d) suggests the CRT TV and console body, the rumble motors, the disc drive and the 3D renderer.

---

## (b) Catalogue of unusual instrument and plugin concepts (35)

| # | Instrument / tool | Concept (one line) | Why it's memorable |
|---|---|---|---|
| 1 | **Pink Trombone** (Thapen; Xfer plugin 2026) | Drag the tongue and lips of a vocal tract to make speech sounds [S2][S4] | The anatomy is the interface, and the result is funny and expressive |
| 2 | **Antares THROAT** | Run a voice through a vocal tract you can stretch past human limits [S6] | Physical controls that go beyond nature ("throat 2x longer") |
| 3 | **Plogue Alter/Ego / chipspeech** | Type lyrics and play them; vintage speech chips as instruments [S7] | Voice as a synth source; nostalgia for robot voices |
| 4 | **Baby Audio Atoms** | Mass-spring network excited by a bow, reduced to 6 knobs (Chaos, Force, Order, Overtones) [S8] | Deep physics hidden behind six friendly controls; chorus and vibrato come from the model itself |
| 5 | **Sonic Charge Synplant / Synplant 2** | Patches are "seeds" that grow branches of mutations; Genopatch grows a patch that imitates a recording [S9] | Sound design by gardening, not by parameters |
| 6 | **Sonic Charge Patternarium** (Microtonic) | Server breeds generations of 1,000 drum patterns; patterns with more user votes become parents [S10] | Crowd-sourced evolution of beats |
| 7 | **TE OP-1 Tombola** | Notes are balls bouncing in a rotating hexagon; collisions trigger sounds [S11] | Physics as a sequencer; feels like a toy |
| 8 | **TE OP-1 Finger sequencer** | A different pattern on every key; combine two at once [S11] | Patterns played like an instrument |
| 9 | **TE OP-1 tape / Pocket Operators / EP-133 "punch-in" FX** | 4-track virtual tape; hold a button to punch in a glitch effect [S12] | Performance FX tied to one gesture |
| 10 | **Torso T-1** | Euclidean pulses and steps plus a repeater that turns hits into arps and rolls [S13] | Generative but still controllable; whole rhythms from three knobs |
| 11 | **Elektron conditional trigs** | Each step can have %, A:B cycle, FILL, 1ST or neighbour-based conditions [S14] | Patterns that change over 8 or 16 bars without automation |
| 12 | **Polyend Play** | Fill and Randomize algorithms create and mangle patterns per track [S14] | One-button variation |
| 13 | **Bitwig Ricochet / Ableton Bouncy Notes / Rozeta Particles / bloqs / Droplets / BounceBud** | Physics note generators: bouncing balls, falling drops, collisions [S15][S16] | Shows how common physics sequencers are now, though none is a full drum engine |
| 14 | **PolyPin (Max for Live)** | Sequencing logic inspired by pinball [S16] | Even here, no actual flippers trigger notes |
| 15 | **Audiomodern Playbeat 4** | Algorithmic/AI groove generator; Infinity mode makes a new pattern every loop [S17] | Endless beat lottery |
| 16 | **XLN Audio XO** | Every drum sample is a dot on a 2D map, with similar sounds clustered; swap a whole kit to similar sounds at once [S18] | Browsing becomes navigation |
| 17 | **Audialab Emergent Drums 2** | A neural net generates new drum hits from scratch; "Crunchy" vs "Creamy" models [S19] | Infinite one-off, royalty-free samples |
| 18 | **Qosmo Neutone FX / Morpho** | Real-time neural timbre transfer inside the DAW [S20] | Turn your beatbox into a violin |
| 19 | **Tracktion / Dawesome MYTH** | ML resynthesis of any sample; no traditional oscillators. (Correction: it works from audio, not images.) [S21] | "Paint" with sounds you analyse |
| 20 | **Moog Animoog Z** | 3D Wave Cube of timbres; "Comets" travel paths and orbits through it [S22] | Timbre as a moving 3D object |
| 21 | **Minimal Audio Current 2** | Play View with dual XY pads driving four macros [S23] | Simple performance layer over a deep engine |
| 22 | **Output Portal / Arcade** | Granular FX with drawable rhythmic modulation; Arcade plays loops from keys [S24] | Makes a complex technique feel playable |
| 23 | **Unfiltered Audio BYOME / Glitchmachines Quadrant** | Build-your-own modular FX chain from about 40 algorithms [S25] | Glitch as a construction kit |
| 24 | **Orca (Hundred Rabbits)** | 2D grid live-coding: every letter is an operator, and "bangs" travel the grid [S26] | Programming that looks like a game map |
| 25 | **Tim Exile's Flow Machine / Endlesss** | Reaktor live-looping performance rig, which became a collaborative jam app. Endlesss shut down in 2024 [S27][S28] | Social, always-on jamming. Its closure is a warning about server dependence |
| 26 | **mi.mu gloves (Imogen Heap)** | Programmable gesture gloves for performing music [S29] | The body as a controller |
| 27 | **Electroplankton (Toshio Iwai, DS 2005)** | 10 "species" of plankton that make music when you poke, rub or draw on them [S30] | Musical creatures; a toy rather than a game |
| 28 | **Toshio Iwai's Tenori-on / Otocky** | Light-grid instrument; a 1987 musical shoot-'em-up [S30] | Game and instrument merged |
| 29 | **KORG DS-10 (Nintendo DS)** | Touch-screen MS-10-style analog synth plus 16-step sequencer and drums on a handheld [S31] | Serious synth on a toy console |
| 30 | **Mario Paint Composer (SNES)** | Stamp-based music composer adopted by experimental artists [S31] | Simplicity became a cult |
| 31 | **Vib-Ribbon (PS1, 1999)** | Insert any music CD; the game analyses it and builds obstacle levels about 8 s ahead [S32] | Your music becomes the level |
| 32 | **Rez (PS2/DC, Mizuguchi)** | Shooting makes the music; synaesthesia design; Japan-only "Trance Vibrator" [S33] | Rhythm, visuals and haptics fused |
| 33 | **Fluid / "Depth" (PS1, Sony/Opus)** | You swim as a dolphin collecting samples, then mix them in a Groove Editor [S34] | A sampler hidden inside a world |
| 34 | **MTV Music Generator / Music 2000 (PS1/PS2)** | 24-channel riff and sample sequencer on a console; famously used to make jungle [S35] | Jungle on a PlayStation, directly in our niche |
| 35 | **Ape Escape (PS1) + Soichi Terada** | First PS game to require dual analog sticks; right stick controls gadgets (spin it to fly). Terada's jungle and D&B score [S36] | Shows the dual-stick-plus-jungle pairing in a real PS-era game |
| 36 | **UwU Virtual Pet Buffer (pedal, 2024)** | A Tamagotchi-style pet in a guitar pedal that gains XP as you play; it does not change the sound [S37] | Proves people want this, but no plugin pet actually affects the music |
| 37 | **PULSE MODS (studio vivi, PS2 homebrew)** | Real-time noise synth running on real PS2 hardware, with visuals on the Graphics Synthesizer tied to the sound [S38] | Proves the PS2 itself is a credible instrument |
| 38 | **Ciat-Lonbarde (Peter Blasser)** | Paper-circuit, chaotic "organic" instruments (Plumbutter, Cocoquantus) [S22] | Anti-menu, tactile, unpredictable |
| 39 | **Paulstretch / Akaizer** | Extreme time-stretch (Paulstretch); Akaizer copies Akai S950/S1000 "cyclic" stretching [S39] | Stretch artefacts as an aesthetic. Akai cyclic stretching IS the wavy jungle sound |

Patterns across these:
- **(i) A physical or creature metaphor beats parameter lists:** Pink Trombone, Atoms, Synplant, Electroplankton, Tombola.
- **(ii) Constrained generativity with one-button variation:** T-1, Elektron trigs, Play, Playbeat.
- **(iii) Your own media becomes the game:** Vib-Ribbon, Genopatch, Fluid.
- **(iv) Physics sequencers are common now.** Novelty only comes from what the physics is attached to.

---

## (c) Market landscape and gaps

| Segment | Existing products (examples) | Crowding | What's missing / our opening |
|---|---|---|---|
| **8/16-bit console chip emulation** | Plogue chipsynth MD/SFC/C64/OPMZ/PortaFM, chipsounds [S40]; Inphonik RYM2612; Impact Soundworks Super Audio Cart 2 (Kontakt; 19 platforms, includes some "PSX" content) [S41] | **Very crowded** | Nothing new to add at 8/16-bit |
| **32/128-bit console (PS1/PS2) sound hardware as an instrument** | Only reverbs: SPS ($9.99, itch.io, PS1 SPU emulation), Impact Soundworks GameVerb ($49, 9 PSX presets) and SNESVerb, foo_dsp_prvb (foobar only) [S42]. PULSE MODS runs only on real PS2 hardware [S38] | **Nearly empty** | No synth or sampler emulates SPU/SPU2 voice behaviour: 48 ADPCM voices, 2 MB sound RAM, 48 kHz, PS1-identical reverb [S43]. **Clear gap** |
| **Vintage sampler colour (AD/DA, filters)** | SP950 (SP-1200 plus S950 filter), RX950 (S950), TAL-Sampler (DAC modes), Arturia Emulator II V, Beatskillz SampleX, D16 Decimort 2 [S44][S45] | **Crowded** | Colour is solved. Behaviour (stretch, loop modes, memory limits) is much less covered |
| **Akai "cyclic" time-stretch (the wavy jungle sound)** | Akaizer: Windows-only donationware app, file-based [S39]; scattered forum DIY [S39] | **Thin** | We found no cross-platform, real-time, playable plugin built around it. Verify before claiming "first". **Core gap for our drum computer** |
| **Break slicers / jungle tools** | AmenBreak VST (Infinite Digits/Zeptocore, free and paid, Dec 2025, active 2026) [S46]; BR3AK (Producer School, Nov 2026, Jungle mode, 100+ breaks) [S47]; Amen Machine (Kreuzberg Audio); Jungle Tool (open source, felixxwu); Chop-R; Xfer Nerve; Serato Sample 2 (stems) [S48]; FL's own Slicex, Fruity Slicer, FPC; iZotope BreakTweaker (**discontinued 2022**) [S49] | **Crowded, and growing fast in 2025–26** | Slicing alone is a commodity. Differentiate on character (SPU + Akai stretch), play (game layer) and cross-instrument linking |
| **Step-sequenced glitch FX** | Sugar Bytes Effectrix 2 / Looperator, dblue Glitch 2, iZotope Stutter Edit 2, Cableguys ShaperBox [S50] | **Crowded** | Don't compete head-on. Fold glitch into the drum computer as era-specific "disc error" FX |
| **Generative / AI drums** | Playbeat 4, Emergent Drums 2, XLN XO, Microtonic + Patternarium [S17][S18][S19][S10] | Moderate | None has a personality or creature. All are "dice" buttons |
| **Physical / anatomical modelling** | Pink Trombone (free, 2026), Atoms, THROAT, Fauna [S4][S8][S6] | Moderate | Nothing models an object from this era (CRT, console body, rumble motor, disc drive) |
| **Physics sequencers** | Tombola, Ricochet, Bouncy Notes, Rozeta Particles, bloqs, Droplets, BounceBud, PolyPin [S11][S15][S16] | **Crowded as MIDI toys** | None is attached to a break engine. No "pinball with flippers" or "racing line" exists |
| **Y2K aesthetic products** | Frutiger Aero VST (5 UI skins, 200 sounds), SourceLab "Y2K Club" skins, many Y2K/pluggnb sample packs; MusicTech "PS2-era house beat with free plugins" tutorial [S51][S52] | Skins and packs are crowded; **deep instruments are empty** | Nobody turns the PS2 interface (dual sticks, pressure buttons, memory card, boot, rumble) into real controls. Demand is visible in tutorials and forum threads ("PS2-era pads?") [S52] |
| **Game / pet / progression layer inside plugins** | Hardware only: UwU pedal (cosmetic) [S37]; game music toys (Electroplankton, DS-10) on consoles | **Empty in plugins** | A creature or game that changes the music is unclaimed |
| **Plugin families with shared state** | iZotope Inter-Plugin Communication (mixing context); Kilohearts Snapins (host-based); vendor preset browsers | Rare for instruments | "System link" between instruments (shared clock, groove, key, intensity and save file) is largely open |

**Summary of gaps:**
1. **PS1/PS2-era sound hardware as an instrument** (SPU2 voices, ADPCM, 2 MB RAM limit, its reverb). Today only reverbs exist.
2. **A real-time, cross-platform Akai cyclic time-stretch** built as the main engine of a jungle instrument.
3. **A working PS2-style interface** (dual analog, 256-level pressure buttons, memory card, rumble) rather than a skin.
4. **Play and personality** (a pet or game layer) that actually changes the music.
5. **Instrument families that talk to each other.**

The crowded areas are break slicing as such, step-glitch FX, 8/16-bit chips, AD/DA colour, Y2K preset packs and MIDI-only physics toys.

---

## (d) Brainstorm: 33 concept ideas

Scales: **Novelty** and **Usefulness** run 1–5 (5 = best). **Difficulty** runs 1–5 (5 = hardest). **Gimmick risk** is Low, Med or High.
Instruments: **DC** = drum computer, **MA** = mono arp synth, **PS** = poly synth, **SM** = sampler, **ALL** = family-wide.

### Interaction (controller and console-menu ideas)

| # | Idea | One-line pitch | Fits | Nov | Use | Diff | Gimmick risk |
|---|---|---|---|---|---|---|---|
| 1 | **Dual-Stick Morph** | Two virtual analog sticks (left = timbre XY, right = FX XY). Clicking a stick (L3/R3) stores a snapshot. Spinning a stick like Ape Escape's propeller sets LFO rate from rotation speed. Maps to real gamepads (XInput/HID) and to MIDI CC | ALL | 3 | 5 | 2 | Low |
| 2 | **Pressure Face Buttons** | Four face buttons with 256-level pressure (as on the DualShock 2 [S53]). Pressure comes from MIDI velocity/aftertouch/MPE or mouse-drag depth; each button is a macro whose depth = pressure ("hold triangle harder = more roll") | DC, SM | 4 | 4 | 2 | Low |
| 3 | **Cheat Codes** | Enter button combos on pads or keys to unlock performance modes ("Big Head" = +12 pitch on all slices; "Turbo" = 2x rolls; "Mirror Mode" = reverse pattern). Codes can be sequenced as MIDI | ALL | 4 | 3 | 1 | High, unless each mode is a real performance move. Codes must never lock paid features |
| 4 | **Memory Card Browser** | Presets are save files with 3D icons that spin when selected. The icon is generated from the sound's features (bright = spiky mesh, long tail = tall mesh). Shows "blocks" used and copy/delete animations, after real PS2 icon.sys conventions [S54] | ALL | 3 | 3 | 3 | Med (only nostalgia unless the icons are generated from the sound) |
| 5 | **Boot Sequence Generator** | The startup animation and "chime" is synthesised from the current patch. Renders 4–8 s ident/riser sounds; the BIOS "towers" screen doubles as a step-velocity view | ALL, SM | 4 | 2 | 2 | High |
| 6 | **Insert Disc: Level-from-Audio** | Like Vib-Ribbon: drop any audio file in and the drum computer analyses it (onsets, spectral changes) to generate a matching break pattern and slice map [S32] | DC, SM | 4 | 4 | 3 | Low–Med |
| 7 | **Rumble Channel** | A "rumble" output. A big-motor/small-motor model is driven by the transients and becomes a modulation source (ducking, sub throb), plus an optional sub layer | DC, PS | 4 | 3 | 2 | Med |

### Generative and play

| # | Idea | One-line pitch | Fits | Nov | Use | Diff | Gimmick risk |
|---|---|---|---|---|---|---|---|
| 8 | **Break Pet** | A creature lives in the drum computer and "eats" the breaks you feed it. Its mood, hunger and age drive variation: hungry = sparser, hyper = rolls and ghost notes, sleepy = half-time. It evolves over sessions into forms with different default grooves. A "Freeze" control and a deterministic seed per project keep renders reproducible | DC | 5 | 3 | 3 | High, unless state is deterministic and the pet's moods are useful variation presets. Plugin space is empty here [S37] |
| 9 | **Racing Line Sequencer** | Draw a WipEout-style anti-grav track. A ship laps it once per bar: curve = pitch/filter bend, speed pads = ratchets, weapon pickups = one-shot FX, banking = pan | MA | 5 | 3 | 4 | Med |
| 10 | **Break Level Editor** | The break becomes a side-scrolling level. Slices are blocks and a character runs at tempo. Gaps = rests, springs = retriggers, pipes = reverse, ? blocks = random slices | DC | 5 | 3 | 4 | Med–High |
| 11 | **Pinball Chopper** | Slices are bumpers and targets on a table. Flippers are fired by MIDI notes; the ball's collisions trigger slices, quantised to the grid; "Tilt" = randomise. Physics is common but flippers are new [S16] | DC, SM | 4 | 3 | 4 | Med |
| 12 | **Arcade Daily Challenge** | Patternarium-style crowd evolution of breaks, with a daily seed break and votes [S10] | DC | 3 | 3 | 5 | Med (server dependence: see Endlesss closure [S28]) |
| 13 | **Rhythm-Game Record Mode** | Notes scroll like in Frequency or Guitar Hero. As you play them in, the PERFECT/GOOD/MISS timing offsets are kept as your personal groove template | DC, MA | 4 | 3 | 3 | Med |
| 14 | **Combo Meter** | Continuous performance builds a combo multiplier that drives an "intensity" macro; it drops when you stop | ALL | 3 | 2 | 1 | High |
| 15 | **Discoveries / achievements** | Using the instrument reveals new waveforms or kits. Everything is also reachable instantly through cheat codes, so nothing is paywalled | ALL | 3 | 2 | 2 | High (paying users resent locks) |

### Synthesis and DSP

| # | Idea | One-line pitch | Fits | Nov | Use | Diff | Gimmick risk |
|---|---|---|---|---|---|---|---|
| 16 | **Vertex Jitter / Affine Wobble engine** | PS1/PS2 rendering artefacts translated to audio [S55]. **Jitter** snaps pitch/time modulation to an integer "pixel" grid, giving stepped, shaky vibrato. **Affine** interpolates between wavetable frames without "perspective correction", so the timbre "swims" in a wavy, unstable way. **No-mipmap shimmer** adds controlled aliasing on bright notes | PS, MA | 5 | 4 | 3 | Low–Med (it produces musically useful "wavy" movement) |
| 17 | **Polygon / LOD knob** | The waveform is drawn as a polygon with N vertices. Lowering LOD removes vertices: faceted, crunchy, band-limited-by-geometry. **Distance Fog** = low-pass + pre-delay + reverb send in one "camera distance" control | PS, MA, DC | 4 | 4 | 2 | Low |
| 18 | **Disc Read Error engine** | Models optical read errors: C1/C2 error concealment (hold, interpolate, mute), tempo-aware skips, seek "chirps", spin-up pitch ramp, "scratched disc" amount | SM, DC | 4 | 4 | 3 | Low |
| 19 | **SPU-2 Voice Core** | Clean-room emulation of PS2-style voice behaviour: 4-bit ADPCM ("VAG") encoding artefacts, loop-point quirks, pitch-step quantisation, hardware ADSR curves, and the PS1/PS2 reverb [S43] | SM, DC | 4 | 5 | 4 | Low (it is the core sound and the market is empty) |
| 20 | **Cyclic "Wavy" Stretch** | Real-time Akai S950/S1000-style cyclic time-stretch with cycle length, crossfade and an "Intelligent" grain-length modulation emulation [S39]. This gives the wavy jungle signature | DC, SM | 3 | 5 | 3 | Low (table stakes for the genre, and under-served) |
| 21 | **Console Body Model ("CRT Trombone")** | Our Pink Trombone. A grabbable 3D CRT TV + console. Push the speaker cone (excursion/resonance), knock the cabinet (body resonances), bend the AV/RF cable (crosstalk, hum, ghosting), add 15.7 kHz flyback whine and a degauss "thunk". Works as an insert FX and as a per-voice body | ALL (FX) | 5 | 4 | 4 | Low–Med |
| 22 | **Rumble Motor Oscillator** | A physical model of the eccentric-mass vibration motor as an oscillator: spin-up/down inertia gives organic glides, load wobble, rattle. Good for reese and wobble bass | MA | 5 | 3 | 2 | Med |
| 23 | **Disc Spin Oscillator** | Sample playback as a spinning disc. CLV vs CAV modes; "seek" scratching; laser-sled glides | SM | 4 | 3 | 3 | Med |
| 24 | **Interlace FX** | The signal is split into odd and even "fields" (alternating micro-blocks) with separate processing. Bob/weave deinterlace modes give combing and stutter colour | FX, DC | 4 | 3 | 2 | Med |
| 25 | **2 MB Sound RAM budget** | Sound memory is limited like the PS2's 2 MB [S43]. Load more samples and the engine automatically trades sample rate and bit depth to fit, so the memory meter is a character control. Can be turned off | SM, DC | 4 | 4 | 2 | Low–Med |
| 26 | **Loading Screen transitions** | Switching patterns or scenes plays a generated "loading" riser or fill built from the next pattern, giving automatic build-ups | DC | 4 | 3 | 2 | Med |
| 27 | **Announcer Voice (era-specific vocal tract)** | A small Pink-Trombone-like tract tuned for hype MC / fighting-game announcer shouts ("ROUND ONE", "SELECTA", "REWIND"), typed and articulated, all synthesised so no sample-clearance issues | SM, PS | 4 | 3 | 4 | Med |

### Cross-plugin family features

| # | Idea | One-line pitch | Fits | Nov | Use | Diff | Gimmick risk |
|---|---|---|---|---|---|---|---|
| 28 | **System Link / Multitap** | Every instance in a project joins a shared "link": common key/scale, groove template, global intensity, scene changes. Instruments can send events to each other: drum fills tell the arp to roll; the kick accents or ducks the pad without sidechain routing | ALL | 4 | 5 | 4 | Low |
| 29 | **Shared Memory Card** | One "card" file holds your kits, patterns, macros, the pet and achievements across all instruments. Slot 1 and Slot 2 = two project moods to swap or morph | ALL | 3 | 4 | 3 | Low |
| 30 | **Player 2: Press Start** | A second controller, MIDI device or instance "joins" and takes half the parameters; call-and-response "versus" mode | ALL | 4 | 2 | 4 | High |
| 31 | **Ghost Replay** | Like time-trial ghosts: record a gesture pass (knob/stick moves) as a translucent ghost that replays; play against it or morph between ghost and live | ALL | 4 | 4 | 2 | Low |
| 32 | **Save States + Rewind** | Emulator-style instant save states (including random seeds and the pet's state) plus a 30-second parameter rewind | ALL | 3 | 5 | 2 | Low |
| 33 | **Demo Disc** | Each plugin ships a playable "demo disc" of mini-songs that teach features, like magazine cover discs; updates add "bonus discs" | ALL | 3 | 3 | 2 | Med (good for marketing and onboarding) |

---

## (e) Shortlist: the five strongest ideas

The bar: (1) genuinely new in plugins, (2) useful in a real jungle/D&B session after the novelty wears off, (3) the PS2-era theme does real work rather than decorating, (4) buildable by a small team.

### 1. SPU-2 Voice Core + Cyclic "Wavy" Stretch + 2 MB budget (#19 + #20 + #25): the sound
- **Why:** this is the authentic sonic core, and it sits in the least crowded part of the market. Only PS1 reverbs exist; nobody offers PS1/PS2 sound-hardware behaviour as a playable sampler or drum engine [S42][S43]. The Akai cyclic stretch defines the wavy jungle sound, and the only dedicated tool is a Windows-only offline app [S39].
- **Musical value:** high on every track. Breaks get the stretched, phasey, metallic wobble of the S1000 era. ADPCM and the memory budget add a crunch that is specific to the period, distinct from SP-1200 / S950 colour, which is already well covered.
- **Risks:** this is "authentic" but not by itself innovative, so it must ship with the ideas below. Do clean-room DSP only: no Sony firmware or BIOS, no ripped game samples.

### 2. Console Body Model, the "CRT Trombone" (#21): the direct answer to the user's example
- **Why:** it applies the Pink Trombone lesson (a grabbable physical object, emergent sound, FX mode most useful) to an object from our era. Pink Trombone's new plugin release (Aug 2026) puts the idea fresh in producers' minds [S4]. A TV/console body is not yet a modelled "throat".
- **Musical value:** an insert FX for any bus that does lo-fi speaker colour, body resonance, hum and ghosting. Pushing the cone or knocking the cabinet gives tactile, performable changes. Per voice, it gives each drum kit a "room": the TV in a bedroom in 2001.
- **Risks:** modelling depth. Start with a modal speaker plus cabinet plus a few non-linearities, the same scope as Pink Trombone, which is about 1,000 lines of DSP.

### 3. Vertex Jitter / Affine Wobble + Polygon LOD (#16 + #17): a new synthesis vocabulary
- **Why:** it turns the period's visual artefacts (vertex snapping, affine texture swim, no mipmaps [S55]) into audio. That gives the poly and mono synths a family of wavy, unstable, faceted modulations nobody else offers, with controls everyone recognises from the games ("make it more PS1").
- **Musical value:** jungle pads and reese basses that wobble, shimmer and fall apart musically. LOD works as a crunch/band-limit macro and Fog as a depth macro. The UI can render at the same LOD, so what you see matches what you hear.
- **Risks:** low. Each control is ordinary DSP (quantised modulation, non-normalised frame interpolation, aliasing control) behind period names.

### 4. Break Pet (#8): the playful hook
- **Why:** it is the most memorable idea and the market is empty: the only "music pet" we found is a guitar-pedal Tamagotchi that doesn't change the sound [S37]. It merges Synplant's "grow, don't program" idea [S9], Electroplankton's creatures [S30] and Patternarium's evolution [S10] in one character.
- **Musical value:** the pet's moods are a generative variation engine with a face: hungry, hyper, sleepy and so on are interpretable variation presets. Feeding it particular breaks steers its "diet" and so its groove style.
- **Guardrails, so it isn't a gimmick:** state is deterministic and saved per project, so renders are reproducible. Provide a "Freeze/Pause". Nothing is ever locked behind the pet. Musicians must be able to ignore it (it lives in a corner of the drum computer screen).
- **Marketing:** the pet is the shareable screenshot and the social-video hook.

### 5. System Link + Shared Memory Card (#28 + #29): the family glue
- **Why:** it turns a set of separate plugins into one console. Instruments rarely share state today; iZotope's IPC covers mixing, not performance. Linking makes buying the bundle worthwhile.
- **Musical value:** a shared key, groove and intensity means the arp, poly and drums stay musically coherent. Event passing (fill → arp roll, kick → pad accent) gives "band" behaviour without routing. The memory card makes your kits and pet portable across projects.
- **Technical note:** FL runs plugins in-process by default, so instances of one shared binary can use a process-wide singleton. Fall back to OS shared memory or a localhost socket when plugins are bridged. Keep the link purely local: no server dependency (see the Endlesss closure [S28]).

**Honourable mentions:** Dual-Stick Morph + Pressure Buttons (#1/#2) is the UI layer; it should ship anyway, as the default performance view and with MIDI/MPE and gamepad mapping. Others: Insert Disc level-from-audio (#6), Disc Read Error (#18), Ghost Replay (#31) and Save States (#32).

---

### Recommended signature innovation: **"Render Engine: what you see is what you hear"**

**One shared, real-time 3D "render" layer runs through every plugin in the family. Its graphics settings are also the sound's character controls.**

Each instrument shows its sound as a low-poly 3D scene: the break as a level, the arp as a racing line, the pad as a rotating crystal, the sampler as a spinning disc. Every plugin has the same six "graphics settings" on a PS2-style options screen:

| Graphics setting | What happens on screen | What happens to the sound (varies by instrument) |
|---|---|---|
| **Polygon count / LOD** | Meshes lose vertices | Waveform faceting; fewer slices/partials; ADPCM bit budget |
| **Vertex Jitter** | Geometry snaps and shakes | Pitch/time modulation snaps to a coarse grid; slice-start jitter |
| **Affine Warp** | Textures swim | Wavetable/frame "swim"; cyclic-stretch cycle drift (the wavy part) |
| **Fog / Draw Distance** | Distance fog closes in | Low-pass + pre-delay + SPU-style reverb send |
| **Interlace / Frame rate** | Combing; choppy frame rate | Field-split FX; sample-and-hold "frame rate" of modulation; stutter |
| **Memory (VRAM/SPU RAM)** | Textures blur as memory fills | Sample-rate/bit-depth trade-off (2 MB budget) |

**Why this should be the signature:**
1. **It fits the brief.** It is not a replica of a 2001 device. It takes that period's visual language and makes it a new synthesis and control concept, as Pink Trombone did with anatomy: the picture is the control, and the control is the sound.
2. **It unifies the family.** The same six controls on every plugin, linked through System Link, give one "Render" macro set for the whole project. Turn the global LOD down and the whole track "drops to PS1".
3. **It is musically serious.** Each control maps to familiar DSP (quantised modulation, band-limiting, frame-interpolation drift, filter/reverb distance, bit/sample-rate budgets), so it is useful every day, not only as a novelty.
4. **It shows on screen.** The UI visibly degrades and wobbles as the sound does. That is unique in plugins, works well in screenshots and short videos, and makes the Y2K 3D look functional.
5. **It hosts the other ideas.** The Break Pet lives inside the rendered level. The CRT Body is the "display device" the render is shown on. The Memory Card stores render presets. Dual sticks fly the camera, and camera distance is the Fog parameter.

**Tagline idea:** "Lower the graphics. Raise the vibe."

**Practical and legal notes:**
- Avoid Sony trademarks and trade dress: "PlayStation", "DualShock", and the exact △○×□ glyphs and colours. Use an original controller design and glyph set, and "inspired by early-2000s consoles" wording.
- Emulate behaviour clean-room; ship no BIOS, firmware or game assets.
- If any Pink Trombone code is reused, check its licence first. The safer path is an original waveguide model.

---

## (f) Sources

- [S1] FL Studio CLAP support: [Image-Line plugin standards manual](https://www.image-line.com/fl-studio-learning/fl-studio-online-manual/html/plugins_supported.htm), [Image-Line: FL Studio 2024 is here](https://image-line.com/blog/fl-studio-2024-is-here), [KVR news](https://www.kvraudio.com/news/image-line-releases-fl-studio-2024---plugins-to-fl-cloud-new-ai-features-effects-workflow-improvements-clap-support-61173)
- [S2] Pink Trombone: [MIT Docubase](https://docubase.mit.edu/?p=20543), [Digital Trends](https://digitaltrends.com/cool-tech/pink-trombone), [arXiv 2406.14379](https://arxiv.org/html/2406.14379v1), [IMAGINARY](https://hub.imaginary.org/node/1520), [Language Log](https://languagelog.ldc.upenn.edu/nll/?p=31723)
- [S3] [pink-trombone GitHub (evykassirer)](https://www.github.com/evykassirer/pink-trombone), [Rust crate](https://lib.rs/crates/pink-trombone)
- [S4] Duda / Xfer plugin port: [Synth Anatomy](https://synthanatomy.com/2026/08/xfer-records-ports-legendary-pink-trombone-browser-speech-synth-into-a-free-plugin.html), [gearnews](https://www.gearnews.com/pink-trombone-plugin-free/), [Bedroom Producers Blog](https://bedroomproducersblog.com/2026/08/24/steve-duda-the-pink-trombone/)
- [S5] [imseankim blog: "5 catches"](https://blog.imseankim.com/steve-duda-pink-trombone-free-plugin-vst3-au-linux-instrument-fx-5-catches/)
- [S6] Antares THROAT: [Plugin Boutique](https://www.pluginboutique.com/products/2209-THROAT), [KVR](https://www.kvraudio.com/product/throat-by-antares-audio-technologies); [xoxos Fauna (KVR)](https://www.kvraudio.com/news/xoxos_releases_fauna_8662); [Dig Vox (KVR)](https://www.kvraudio.com/product/dig-vox-by-nusofting)
- [S7] Plogue: [Alter/Ego](https://plogue.com/products/alterego), [MusicRadar](https://musicradar.com/news/tech/plogue-releases-alter-ego-free-realtime-singing-synth-plugin-627684), [Chipspeech (Wikipedia)](https://en.wikipedia.org/wiki/Chipspeech)
- [S8] Baby Audio Atoms: [CDM](https://cdm.link/2024/02/baby-audio-atoms-tested/), [MusicRadar](https://www.musicradar.com/news/baby-audio-atoms-synth-plugin), [Sound On Sound](https://www.soundonsound.com/news/atoms-physical-modelling-virtual-instrument-baby-audio)
- [S9] Synplant 2: [Sound On Sound](https://www.soundonsound.com/reviews/sonic-charge-synplant-2?amp), [MusicTech](https://www.musictech.net/reviews/plug-ins/sonic-charges-synplant-2-review/), [CDM](https://cdm.link/2023/10/synplant-2-hands-on/)
- [S10] Patternarium: [Sonic Charge forum](https://cdn.soniccharge.com/forum/topic/1336), [Ask.Audio](https://ask.audio/articles/review-patternarium-by-sonic-charge-how-your-vote-can-change-beats-around-the-world)
- [S11] OP-1 sequencers: [Teenage Engineering guide](https://teenage.engineering/guides/op-1/original/sequencers), [Critter & Guitari forum](https://forum.critterandguitari.com/t/tombola-sequencer/3558), [MusicRadar OP-1 Field tips](https://musicradar.com/news/8-things-op-1-field)
- [S12] [SOS: EP-133 KO II](https://www.soundonsound.com/reviews/teenage-engineering-ep-133-ko-ii?amp), [MusicRadar EP-133](https://www.musicradar.com/news/teenage-engineering-ep-133-ko-2)
- [S13] Torso T-1: [MusicRadar review](https://www.musicradar.com/reviews/torso-electronics-t-1-algorithmic-sequencer), [Perfect Circuit](https://www.perfectcircuit.com/signal/torso-t-1), [Juno review](https://www.juno.co.uk/junodaily/2024/09/06/torso-electronics-t-1-review)
- [S14] [Elektronauts trig conditions](https://www.elektronauts.com/t/ot-trig-conditions-trc-thread/44828?page=18), [SOS Polyend Play](https://www.soundonsound.com/reviews/polyend-play?amp), [Polyend forum](https://backstage.polyend.com/t/a-b-conditions-for-each-sequencer-pass/909)
- [S15] [Bitwig Note FX](https://www.bitwig.com/userguide/bws44-504/note_fx), [CDM Bitwig 4.1](https://cdm.link/2021/11/bitwig-studio-4-1-color-palettes-note-fx-with-physics-and-more-sampler-release-chaining/), [Rozeta (App Store)](https://apps.apple.com/app/id1292546479), [Ableton Probability Pack](https://www.ableton.com/es/blog/probability-pack-sonic-faction-new-live-10-suite)
- [S16] [bloqs](http://bloqs.co.uk/), [Droplets (Gearspace)](https://gearspace.com/threads/droplets-a-physics-based-sequencer-plugin-is-out-now.1429821/page-2), [BounceBud](https://keybudapp.com/bouncebud), [PolyPin](https://isotonikstudios.com/product/polypin/)
- [S17] [MusicRadar: Playbeat 4](https://www.musicradar.com/music-tech/no-two-beats-will-ever-be-the-same-audiomoderns-playbeat-4-is-an-ai-powered-infinite-groove-generator)
- [S18] XLN XO: [XLN support](https://support.xlnaudio.com/hc/en-us/articles/16920363887645-Interface-Overview), [MusicRadar](https://musicradar.com/reviews/xln-audio-xo), [Attack](https://www.attackmagazine.com/reviews/gear-software/xln-audio-xo/)
- [S19] Emergent Drums: [MusicRadar](https://www.musicradar.com/news/audialab-emergent-drums-public-release), [Native Instruments](https://www.native-instruments.com/products/emergent-drums-2)
- [S20] Neutone: [arXiv 2508.09126](https://arxiv.org/abs/2508.09126v1), [Qosmo timbre transfer](https://qosmo.jp/en/products/timbre-transfer), [KVR](https://www.kvraudio.com/product/neutone-by-qosmo)
- [S21] MYTH: [KVR news](https://kvraudio.com/news/tracktion-and-dawesome-release-myth-resynthesis-synthesizer-60591), [MusicRadar review](https://musicradar.com/music-tech/soft-synths/tracktion-dawesome-myth-review)
- [S22] Animoog Z: [Attack Magazine](https://www.attackmagazine.com/technique/synth-secrets/programming-an-evolving-pad-with-moog-animoog-z/), [gearnews](https://www.gearnews.com/moog-animoog-z-classic-ios-synth-evolves-to-a-new-plane-of-waveshaping/); Ciat-Lonbarde: [MATRIXSYNTH](https://www.matrixsynth.com/search/label/Ciat-Lonbarde)
- [S23] Minimal Audio Current: [Sound On Sound](https://www.soundonsound.com/reviews/minimal-audio-current), [KVR](https://www.kvraudio.com/product/current-by-minimal-audio/details)
- [S24] Output Portal: [gearnews](https://www.gearnews.com/output-portal-a-granular-fx-plug-in-with-heaps-of-modulation/), [MusicRadar](https://www.musicradar.com/reviews/output-portal)
- [S25] [MusicRadar: BYOME](https://www.musicradar.com/reviews/unfiltered-audio-byome), [Plugin Alliance BYOME](https://www.plugin-alliance.com/en/products/unfiltered_audio_byome.html), [Synth Anatomy: Quadrant](https://synthanatomy.com/tag/glitchmachines-qudrant)
- [S26] [Orca README](https://raw.githubusercontent.com/hundredrabbits/Orca/main/README.md), [itch.io](https://hundredrabbits.itch.io/orca)
- [S27] Tim Exile: [Wikipedia](https://en.wikipedia.org/wiki/Tim_Exile), [FACT: Flow Machine](https://factmag.com/2015/07/03/tim-exile-flow-machine), [NI: Flesh developer feature](https://native-instruments.com/en/products/komplete/synths/flesh/developer-feature)
- [S28] [CDM: Endlesss discontinued](https://cdm.link/endlesss-discontinued/)
- [S29] [mi.mu about](https://mimugloves.com/about/), [Univ. of Brighton](https://research.brighton.ac.uk/en/publications/mimu-gloves/)
- [S30] [Electroplankton (Wikipedia)](https://en.wikipedia.org/wiki/Electroplankton), [Engadget/Joystiq review](https://www.engadget.com/2006-01-24-joystiq-review-electroplankton-nintendo-ds.html)
- [S31] [KORG DS-10 (Wikipedia)](https://en.wikipedia.org/wiki/KORG_DS-10), [MusicRadar](https://musicradar.com/news/tech/musikmesse-08-ds-10-puts-a-korg-synth-in-your-nintendo-ds-142712), [TechRadar](https://www.techradar.com/news/handhelds/gaming/vintage-korg-synthesizer-hits-ds-462525)
- [S32] [Vib-Ribbon (Wikipedia)](https://en.wikipedia.org/wiki/Vib-Ribbon), [Giant Bomb: Music Generated Content](https://giantbomb.com/wiki/Concepts/Music_Generated_Content), [MoMA](https://www.moma.org/collection/works/162460?locale=en)
- [S33] [New Statesman on Mizuguchi](https://www.newstatesman.com/culture/2017/07/how-tetsuya-mizuguchi-reinvented-video-games-his-love-synaesthesia), [Rez Infinite Synesthesia Suit](https://rezinfinite.com/synesthesia-suit/), [PlayStation Blog](https://blog.eu.playstation.com/2017/10/20/classic-levels-deconstructed-tetsuya-mizuguchi-musician-adam-freeland-dissect-rez-infinites-area-5)
- [S34] [Fluid (Wikipedia)](https://en.wikipedia.org/wiki/Fluid_(video_game)), [Time Extension](https://timeextension.com/news/2022/09/flashback-remember-fluid-the-psychedelic-game-about-a-beat-making-dolphin)
- [S35] [Music 2000 (Wikipedia)](https://en.wikipedia.org/wiki/Music_2000), [MTV Music Generator 2 (Wikipedia)](https://en.wikipedia.org/wiki/MTV_Music_Generator_2), [Time Extension: making of Music](https://timeextension.com/features/the-making-of-music-the-playstation-audio-creation-tool-from-wipeouts-tim-wright)
- [S36] [Soichi Terada (Wikipedia)](https://en.wikipedia.org/wiki/Soichi_Terada), [RBMA interview](https://daily.redbullmusicacademy.com/2017/10/soichi-terada-interview), [RA review](https://ra.co/reviews/35954)
- [S37] UwU Virtual Pet Buffer: [Engadget](https://www.engadget.com/the-uwu-virtual-pet-buffer-is-a-tamagotchi-in-a-guitar-pedal-193633790.html), [Time Extension](https://www.timeextension.com/news/2024/02/random-this-guitar-pedal-doubles-as-a-tamagotchi-style-virtual-pet)
- [S38] [MusicTech: PULSE MODS PS2 noise synth](https://musictech.com/news/gear/this-programme-turns-the-sony-playstation-2-into-a-real-time-experimental-noise-synthesiser/), [MusicRadar: consoles repurposed for music](https://www.musicradar.com/music-tech/gear-gadgets/i-hope-granular-synthesis-becomes-the-new-doom-something-people-try-to-run-on-all-kinds-of-musical-devices-we-speak-to-the-industrious-innovators-who-have-repurposed-long-dead-video-game-consoles-to-make-music)
- [S39] Akai stretch: [Akaizer intro](https://chilloutwithbeats.com/en/akaizer-intro/), [MusicRadar Akaizer tutorial](https://www.musicradar.com/tuition/tech/how-to-create-authentic-timestretched-jungle-breaks-with-akaizer-611255), [Renoise forum](https://forum.renoise.com/t/fao-dblue-regarding-the-timestretch/20421), [JUCE forum](https://forum.juce.com/t/a-lightweight-akai-style-time-stretch-algorithm-realtime/60514), [Image-Line forum](https://forum.image-line.com/viewtopic.php?p=1966636), [Polyend forum](https://backstage.polyend.com/t/polyend-vs-akai-time-stretching/14868)
- [S40] Plogue: [chipsynth MD](https://plogue.com/products/chipsynth-md.html), [chipsounds](https://www.plogue.com/products/chipsounds/), [MusicRadar chipsynth C64](https://musicradar.com/news/plogue-chipsynth-c64-sid-plugin)
- [S41] [Super Audio Cart 2](https://impactsoundworks.com/product/super-audio-cart-2/)
- [S42] PS1 reverbs: [SPS (itch.io)](https://soundfontguy.itch.io/sps), [GameVerb](https://impactsoundworks.com/product/gameverb/), [SNESVerb](https://impactsoundworks.com/product/snesverb/), [foo_dsp_prvb](https://www.foobar2000.org/components/view/foo_dsp_prvb)
- [S43] PS2 SPU2: [psdevwiki SPU2](https://www.psdevwiki.com/ps2/SPU2), [PCSX2 Reverb Engine](https://wiki.pcsx2.net/PCSX2_Documentation/Reverb_Engine), [Mix: sound on PlayStation2](https://www.mixonline.com/sfp/sound-playstation2-369087), [Copetti PS2 architecture](https://www.copetti.org/writings/consoles/playstation-2)
- [S44] [MusicRadar: SP950](https://musicradar.com/news/sp950-emulates-the-gritty-sound-of-the-e-mu-sp-1200-sampler-in-a-plugin), [KVR RX950](https://www.kvraudio.com/product/rx950-classic-ad-da-converter-by-inphonik), [SOS SampleX](https://www.soundonsound.com/reviews/beatskillz-samplex)
- [S45] [Arturia Emulator II V](https://www.arturia.com/products/analog-classics/emulator-ii-v/overview), [KVR forum: emulating classic samplers](https://www.kvraudio.com/forum/viewtopic.php?p=9150242), [D16 (pluginfox)](https://pluginfox.com/collections/d16?aff=183)
- [S46] AmenBreak VST: [MusicRadar](https://www.musicradar.com/music-tech/amenbreak-vst-is-a-break-slicing-sample-mangling-junglist-powerhouse-and-theres-a-free-version), [Synth Anatomy](https://synthanatomy.com/2025/12/infinitedigits-amenbreak-vst-the-hardware-breakbeat-mangling-sampler-is-now-a-plugin.html), [amenbreakvst.com](https://amenbreakvst.com/)
- [S47] [BR3AK overview](https://theproducerschool.com/blogs/featured-blogs/br3ak-breakbeat-plugin-overview), [BR3AK product](https://theproducerschool.com/products/br3ak); [Jungle Tool (GitHub)](https://github.com/felixxwu/Jungle-Tool/releases/tag/plugin-v0.1.3); [Amen Machine (KVR)](https://www.kvraudio.com/product/amen-machine-by-kreuzberg-audio); [Chop-R (KVR)](https://www.kvraudio.com/product/chop-r-by-lobith-audio)
- [S48] [Sweetwater: Serato Sample 2.0](https://www.sweetwater.com/insync/cutting-edge-3d-sampling-with-serato-sample-2-0/)
- [S49] [iZotope support notice](https://support.izotope.com/hc/en-us/articles/7394969418653), [MusicRadar](https://musicradar.com/news/izotope-plugins-discontinued)
- [S50] [MusicRadar Effectrix2](https://musicradar.com/reviews/sugar-bytes-effectrix2-review), [MusicRadar Glitch 2](https://musicradar.com/reviews/tech/illformed-glitch-2-581491)
- [S51] [Frutiger Aero VST](https://www.lowkeylabs.shop/products/frutiger-aero-vst), [Initial Audio Y2K Club](https://initialaudio.com/y2k-club-early-2000s-presets-sourcelab/)
- [S52] [MusicTech: "PlayStation 2 era" house beat](https://musictech.com/tutorials/y2k-video-game-sound-in-10-minutes-with-free-plugins/), [KVR: PS2-era pad sounds?](https://www.kvraudio.com/forum/viewtopic.php?t=605886)
- [S53] [DualShock (Wikipedia)](https://en.wikipedia.org/wiki/DualShock), [PlayStation 2 accessories (Wikipedia)](https://en.wikipedia.org/wiki/PlayStation_2_accessories)
- [S54] [ps2iconsys (GitHub)](https://github.com/ticky/ps2iconsys), [icon.sys format](https://www.ps2savetools.com/documents/iconsys-format/), [mymc](https://csclub.uwaterloo.ca/~rridge/mymc/index.html)
- [S55] [Hackaday: why PlayStation graphics wobble (2026)](https://hackaday.com/2026/02/06/why-playstation-graphics-wobble-flicker-and-twitch), [Pikuma: how to make PS1 graphics](https://pikuma.com/blog/how-to-make-ps1-graphics)

*Research caveats:* most product facts come from search-result summaries of vendor and press pages. Prices, versions and feature claims may be out of date. Direct page fetches were blocked in this session for some hosts, including bedroomproducersblog.com. "No product found" claims (PS2 SPU synth, real-time cross-platform Akai stretch, a pet that affects the sound, flipper-triggered pinball sequencer) are based on several searches and should be checked again on KVR before any public "first" claim.
