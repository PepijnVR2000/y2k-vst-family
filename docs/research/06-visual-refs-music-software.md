# Visual references B: era music software and hardware, Y2K desktop and web, and the plugins we compete with

Every entry below was downloaded and **viewed** before it was written up. Palettes are measured: PIL median-cut quantisation into 6 colours on a 300 px thumbnail, with the share of pixels for each. Where a "spot" colour is given, it was sampled from a named region of the saved file, either as a box mean or as the brightest 4% of pixels.

Files are in this folder (`refs/B/`). Raw downloads, including rejects, are in `refs/B/raw/`.

There are 16 numbered references (24 image files). Modern competitors come first, then era software and hardware, then era desktop and web.

---

## 01 GuyEngine V2 (UltimaDSP / SoundFontGuy, 2025)

- **Files:**
  - `01a-guyengine-v2-timbres.png` (purple "PS2" background theme, Timbres page)
  - `01b-guyengine-v2-sampler.png` (Sampler page)
  - `01c-guyengine-v2-arp-grey-theme.png` (grey theme, Arp page)
- **Source pages:** https://soundfontguy.itch.io/guyengine (screenshots) and https://ultimadsp.gumroad.com/l/guyengine-v2 (store; it shows only cover art, a blurred render of abstract 3D blocks with a "GuyEngine V2" title).
- **Image URLs:**
  - https://img.itch.zone/aW1hZ2UvMzE2MjMyNS8yNjExMjUwMi5wbmc=/original/1guCnh.png
  - https://img.itch.zone/aW1hZ2UvMzE2MjMyNS8yNjExMjQ5OS5wbmc=/original/TYBBl6.png
  - https://img.itch.zone/aW1hZ2UvMzE2MjMyNS8yNjExMjUwMy5wbmc=/original/%2FzVImJ.png

**Observed**
- About 1050×700. A keyboard strip takes the bottom 15%.
- The header holds:
  - a large white "GuyEngine V2" wordmark in a squarish techno sans (in one theme it is set in a heavy Arial-like bold);
  - a pixel-art mascot;
  - a row of five **game-controller silhouettes** (black, grey, white, indigo, white). These are the theme selector, and each controller recolours the UI;
  - a long dark "Select a preset." field with a 1 px light outline and rounded corners;
  - browser-like tabs (Timbres / Sampler / Effects / Arp / General) with rounded tops.
- **"PS2-inspired" means only the background**:
  - In the purple theme, a blurred, low-contrast render of tilted translucent slabs and blue light streaks sits behind everything.
  - In the grey theme, big faint outline circles (controller shapes) appear behind the panels.
- **Every control is flat.**
  - Knobs are the generic arc-ring type: a grey track with a thick coloured value arc (red, green or pink per timbre), a black centre disc and a short white pointer. There is no bevel, no light and no shadow.
  - Toggles are flat, semi-transparent coloured rectangles with a dot "LED".
  - Dropdowns are dark boxes with up/down chevrons, and the dropdown text is small red.
  - The one 3D-looking object is a blue rocker power switch with a glossy bevel. It is the only lit object on screen.
- **Type** is a system-default sans (Arial/Helvetica-like) at four or five sizes with no tracking. The labels ("Gain", "Delay", "Attack") are large, about 16 px, and in mixed case.
- **Density** is high and even. The 3 timbres are identical rows of 6+6+3+4 knobs.
- **Colour**:
  - The red, green and pink timbre colours are saturated, and each is used for a whole row (knobs, toggles and fill bar).
  - The waveform view (01b) is pure white with a cyan edge on dark navy.
  - The Arp page (01c) fills large step blocks with flat pink #cd74a7.

**Measured palette**
- 01a: #211f38 26%, #09091d 23%, #2c334c 18%, #787a81 14%, #d7ece1 11%, #6e4a5a 8%
- 01b: #272433 27%, #fbfdfe 17%, #413c64 16%, #2e2f43 16%, #0f0d1c 15%, #8a9fb6 9%
- 01c: #cd74a7 31%, #2c2c2d 20%, #474748 17%, #655c61 16%, #e5e6e6 11%

**Critique**
- *What works:*
  - Timbre colour-coding makes three layers readable at a glance.
  - The waveform display is bold and legible.
  - The controller-icon theme picker is a charming, immediately "console" gesture.
- *What looks cheap:*
  - It is a stock-widget plugin with a wallpaper. The arc knobs, system font and default dropdowns are framework defaults.
  - The PS2 reference lives only in a blurred background image that competes with the controls (text over busy imagery).
  - There is no light model, so nothing feels like an object.
  - Theme switching recolours, but it adds no material, no motion grammar and no "OS".
- *How we must differ:*
  - Ours is a *system* (BIOS shell, memory-card presets, one light rig), not a skin over generic widgets.
  - Never put controls over a busy background render.
  - Never use console controller silhouettes, because that is exactly GuyEngine's (and GameVerb's) shorthand.
  - **Visual threat level: low.** It occupies the *words* "PS2-inspired UI", not the look.

---

## 02 GameVerb (Impact Soundworks, 2023)

- **File:** `02-gameverb-impact-soundworks.png`
- **Source page:** https://impactsoundworks.com/product/gameverb/
- **Image URL:** https://impactsoundworks.com/wp-content/uploads/2023/11/GameVerb-Main-UI-Init.png (also viewed: GameVerb-PSX-Mode-Controls.png)

**Observed**
- **This is the real nearest visual competitor.** The whole plugin body is a **game-controller-shaped housing**:
  - a dark charcoal upper shell with two "grip" pods holding Sample Rate and BRR Filter;
  - a light grey lower shell with a vent-slot grille at the bottom edge;
  - a centre **blue LCD screen** with a thick black rounded bezel and a soft drop shadow.
- **Inside the screen**:
  - Everything is rendered as a monochrome pixel UI: pixel-font tabs "SNES / PSX / N64", where the selected tab is filled light blue (#b9d6ff) on screen blue (#2758b8);
  - outline-drawn pixel knobs (just a circle and a pointer line), a floppy-disk save icon and pixel chevrons;
  - a "Studio Small" preset field in an inverted bar.
- **Lower shell**: four large knobs with **coloured rings** (red, green, blue, yellow, the familiar four-button controller colours) around black caps with a white pointer.
  - Small tick dots in the ring colour sit at the min and max positions.
  - A soft outer glow surrounds each ring.
  - A link button and a lock button sit between Dry and Wet with bracket lines.
- **Top bar**: modern flat app chrome (pill dropdowns, A/B, gear), in a geometric sans.
- **Light**: a soft top-down studio light; the shells have a gentle vertical gradient and a lit top edge.

**Measured palette:** #1b263c 25%, #abadb8 24%, #3261b9 23%, #324164 10%, #959aa9 10%, #b8bece 9%. Spot: screen #2758b8, selected tab #b9d6ff.

**Critique**
- *What works:*
  - The "device with a screen" split, with precise values in a pixel LCD and performance knobs on the body, is exactly right.
  - The screen is crisp and readable.
- *What looks cheap:*
  - It mixes three idioms: a modern SaaS top bar, a toy controller body and a pixel screen.
  - The knob rings lean on borrowed controller colours.
  - The body reads as a plastic toy, not a precision instrument.
- *How we must differ:*
  - No controller-shaped body, and no four-colour face-button colouring.
  - Our "device" must be a fictional console *system* (menus, memory card, boot), not a gamepad.
  - The blue pixel-screen-with-tabs is now taken, so our LCD strips need a different look: a VFD or MPC-style teal (see 12a and 13).

---

## 03 RYM2612 (Inphonik, 2018)

- **File:** `03-inphonik-rym2612.jpg`
- **Source page:** https://www.inphonik.com/products/rym2612-iconic-fm-synthesizer/
- **Image URL:** https://www.inphonik.com/img/RYM2612-panelfront.jpg (also viewed: RYM2612-render.png, a 3D rack render of the same panel)

**Observed**
- A wide charcoal rack panel (#2b2d32 / #343841) with four operator "rails": light grey rounded capsules that run across the panel like pipes and carry the controls.
- **Knobs**:
  - About 20 px white/silver cylinders seen from slightly above, each with a black indicator line, a hard lit top face and a short shadow down-right.
  - The big TL knob is black with a white line.
  - The values are small dark **blue LCD windows** (measured #1c396d in the preset bar) with white "3,00" / "OFF" text in a sans, not a segment font.
- **Other elements**:
  - An algorithm display (blue LCD with an operator-graph drawing) and an 8-key algorithm keypad, whose selected key is blue-lit.
  - A tilted envelope diagram with AR/DR/SL/SR/RR labels.
  - A vertical "The Icon" tape label (a cream paper strip with handwriting).
  - A logo in an outlined squarish wordmark.
- Labels are white all-caps condensed sans, about 9 px, and the density is high.

**Measured palette:** #343841 26%, #2b2d32 24%, #a5a5a5 18%, #3d4552 14%, #bbbbba 11%, #75797e 8%

**Critique**
- *What works:*
  - A coherent hardware fiction with one light direction (upper-left).
  - The paper-label strip is a lovely human touch.
- *What looks cheap:*
  - The rail capsules are flat-shaded.
  - Tiny 9 px labels on dark grey are hard to read.
  - Pure-blue LCDs with sans text feel like a web widget, not a display.
- *How we must differ:*
  - It is "rack hardware", not "console OS", so there is no overlap in metaphor.
  - Steal the paper label. Avoid the blue mini-LCDs.

---

## 04 chipsynth MD (Plogue, 2019)

- **File:** `04-plogue-chipsynth-md.jpg`
- **Source page:** https://www.musicradar.com/reviews/plogue-chipsynth-md
- **Image URL:** https://cdn.mos.cms.futurecdn.net/BZNVSJZyfPD2QzzdD67qfQ-1200-80.jpg
- **Not used:** the MusicRadar PortaFM image turned out to be a GForce Prophet-5 screenshot and was discarded.

**Observed**
- **Header and layout**:
  - A near-black flat UI (#181818).
  - The header wordmark "chipsynth" is set in a thin outlined rounded techno face, followed by a hand-drawn red and green "MD" logo.
  - A full-width **dusty-pink strip** (measured #ac415b) reads "INTELLIGENT TERMINAL HIGH GRADE MUSIC USE". This is a hardware-label pastiche.
  - Square tabs run along the strip, with the active one black.
- **Operator cards**:
  - The four FM operators are dark rounded cards laid out as the algorithm graph and joined by pink lines. A feedback loop is drawn as a pink bracket.
  - Each card holds a vertical level bar (pink), a dark envelope display with a pink curve and blue handles, a huge grey operator number and blue "SSG Mode" text.
- **Knobs**:
  - Small knobs are black discs with a pink value arc and a small pink dot.
  - Larger knobs have a subtle radial gradient, which is the only "3D" on screen.
  - The type is a clean grotesque, about 12 px.
- No bevels and no texture: matte flat design with one accent.

**Measured palette:** #181818 36%, #141313 20%, #2d2a2b 20%, #8e797f 14%, #161818 5%, #281a1b 4%

**Critique**
- *What works:*
  - The algorithm topology *is* the layout, which makes it highly informative.
  - One accent colour.
- *What looks cheap:* not cheap, but anonymous. Apart from the pink label strip it could be any modern dark synth.
- *How we must differ:*
  - Chip-emulation vendors invest in accuracy, not in era *look*. This confirms the text research's "open space".
  - The silk-screen pastiche strip is a good, cheap world-building device.

---

## 05 Y2K Club skin for SourceLab (Initial Audio, 2026)

- **File:** `05-initial-audio-y2k-club.jpg`
- **Source page:** https://initialaudio.com/y2k-club-early-2000s-presets-sourcelab/
- **Image URL:** https://initialaudio.com/wp-content/uploads/2026/04/y2kclub_skin1-1024x700.webp (also viewed: skin2 to skin4)

**Observed**
- The skin sits on the stock SourceLab layout (top toolbar with icons, browser, Envelope, Macro and Master boxes, keyboard).
- **Skin 1**:
  - The background is a **purple-tinted photo of a circuit board**.
  - The panels are translucent purple glass rectangles with a thin bright violet outline and a glow.
  - The browser sits in a glowing violet frame.
  - "Y2K CLUB" is set in a white-to-ice-blue chrome-gradient bold sans with sparkle stars.
- **Knobs** are dark discs with a yellow pointer, a tick-dot scale and a slight top highlight.
- **The other skins** are recolours of the *same* layout:
  - skin 2: red, with paint drips on the browser frame;
  - skin 3: aged cream paper with a green LCD browser;
  - skin 4: brushed silver with "SourceLab" in chrome.

**Measured palette:** #0f1324 26%, #2d2d50 20%, #232139 17%, #919296 13%, #45336e 13%, #595377 11%

**Critique**
- *What works:* nothing structural. It is a texture swap.
- *What looks cheap:*
  - A circuit-board photo behind the controls.
  - Glow outlines on every box.
  - Chrome-gradient type with sparkles.
  - Identical layout across "eras".
- *How we must differ:*
  - This is the textbook "Y2K skin". It is what our reviewers will compare us to if we use purple glow, PCB textures or sparkle chrome. Ban all three.

---

## 06 Baby Audio product family (2019–2025)

- **File:** `06-baby-audio-family.jpg` (cropped from the bundle hero image)
- **Source page:** https://babyaud.io/super-vhs (bundle hero served on the product pages)
- **Image URL:** https://cdn.prod.website-files.com/687ee2fa7f073e59ed93f259/68db51f4b1e92e9776d46894_Baby%2BAudio%2BComplete%2BBundle%2B2025%2B1-p-2000.webp

**Observed**
- **About 14 plugin UIs side by side.** Each has its own concept, yet they read as one family because of:
  - the same thin grotesque labels;
  - the same black or light-grey matte bases;
  - one or two neon accents each, used as a *light source* (Parallel Aggressor's blue and orange glowing half-discs, IHNY-2's yellow sun, TAIP's orange-lit reels);
  - generous empty space.
- **Super VHS**:
  - A black panel with a red inverted-triangle logo badge.
  - Three large grey knobs with a soft top highlight, joined by thin teal/orange V-lines.
  - Tick-mark meters at the edges.
- **BA-1**:
  - Grey hardware with an oscilloscope screen showing a cyan sine.
  - A big "BA-1" set in outlined LCD-blue letters.
  - A wall of slim fader slots.
- **TAIP**: two orange glowing tape hubs in dark recessed wells.
- **Light**: highlights come from glow (emissive accents), not from a key light. There are almost no bevels.

**Measured palette:** #0e0e0e 24%, #282726 22%, #3f4040 16%, #b9bab4 15%, #524e4e 14%, #8b8786 9%

**Critique**
- *What works:* the clarity benchmark.
  - One idea per plugin.
  - Huge targets.
  - Accent colour used as *light*, not as fill.
  - A family consistency built from type and spacing rather than identical layouts.
- *What looks cheap:* nothing. The risk is the opposite: everything looks like 2020s product design.
- *How we must differ:*
  - Copy the *discipline*: large controls, one accent, emissive light.
  - Not the minimal-modern aesthetic. Our family consistency should come from the shared light rig and materials, as Baby Audio's comes from type and space.

---

## 07 Winamp 2.x base skin, plus three user skins (1998–2003)

- **File:** `07-winamp-classic-and-skins.png` (2×2 grid, main window and EQ of each, scaled ×2 nearest-neighbour)
  - top left: base 2.91
  - top right: "ChromeAMP"
  - bottom left: "Silvert"
  - bottom right: "ginger_silver"
- **Source page:** https://skins.webamp.org/ (Winamp Skin Museum)
- **Image URLs:** `https://r2.webampskins.org/screenshots/<md5>.png` with md5
  - 5e4f10275dcb1fb211d4a8b4f1bda236 (base)
  - 47b0627f2774bb2cd71cc287a95e4d12 (ChromeAMP)
  - c7807a699b5f7356845e9bbfaee21466 (Silvert)
  - 6219da5bc13db278a58211fecb860a22 (ginger_silver)
  - Also viewed: about 20 more skins found by searching "silver", "techno" and "metal".

**Observed**
- **Base skin**:
  - Native window 275×116 px.
  - Slate-navy panels (#343448).
  - Transport buttons about 23×18 px, light grey, with a **1 px light top-left edge and a 1 px dark bottom-right edge**. That is all the 3D there is (bevel ≈5% of button height).
  - The display is pure black with **pure-green #00f700 7-segment-style time digits**, a green/yellow/red spectrum analyser, and a song title in green pixel caps.
  - The EQ has 10 sliders with **gradient-coloured tracks** (yellow → orange → red → green according to value) and small bevelled grey "≡" thumbs; the frequency labels are in yellow-on-navy pixel font.
- **ChromeAMP**: black and **mirror chrome** everywhere. A script "Chrome" logo with a star glint, chrome bezels around a dark LCD and grey 7-seg digits.
- **Silvert**:
  - Silver brushed-metal body with **pill-shaped recessed LCD wells** in grey-green (#9aa495-ish) and white bar-graph EQ.
  - A round knurled chrome volume knob.
  - A speaker-grille circle.
  - Strong top-left light.
- **ginger_silver**: copper/orange airbrushed chrome stripes in a 1990s-airbrush look.
- **Fonts** are bitmap: Winamp's own 5×6 pixel font for the title and the "kbps/kHz" labels.

**Measured palette:** #343448 21%, #1a1a22 20%, #9aa495 20%, #787668 14%, #dcd9cd 13%, #484246 13%. Spot: Winamp LCD green #00f700 on #000000.

**Take for our plugins**
1. A **pill-shaped recessed LCD well** (Silvert) is a stronger era shape than a rectangle. Use it for our value strips.
2. 1 px light/dark edges are enough for era-authentic buttons. Don't over-bevel.
3. Warning: full-chrome skins (ChromeAMP) show how fast chrome becomes noise. The 2% chrome rule is right.

---

## 08 ReBirth RB-338 v2.0 (Propellerhead / Steinberg, 1998, Mac version)

- **File:** `08-rebirth-rb338-v2-mac.jpg` (460×395, the largest era capture found)
- **Source page:** https://www.vintagesynth.com/propellerhead-software/rebirth-rb-338
- **Image URL:** https://www.vintagesynth.com/sites/default/files/2017-05/rb338.jpg
- **Also viewed:** Wikipedia's 338 px Windows capture of the "G-Spot by Dreadzone" mod, which uses dark brown/cream panel art and was too small to keep (`raw/wp_Rebirth_rb-338_screenshot.png`).

**Observed**
- One window, everything visible:
  - two **light-grey/white 303 panels**, each with a mini white-and-black piano-key step editor;
  - an 808 with dark brown wood-like panel and a **row of orange/yellow/red step keys**;
  - a 909 with a cream panel;
  - a teal-grey mixer/FX column on the right (PCF, Delay, Dist, Comp) with **blue header bars**.
- **Wood end-cheeks** frame the left and right.
- The **pattern section on the left** has red 7-segment LED readouts (pattern numbers "16") and small lit square keys.
- **Knobs** are about 20 px silver caps with a ring of black tick dots, a darker lower-right half and a drop shadow down-right, so the light comes from the upper-left.
- **Labels** are tiny black all-caps in a bold condensed sans directly on the panel ("WAVEFORM TUNE CUTOFF RESO ENV.MOD DECAY ACCENT").
- The "ReBirth RB-338" logo is in an extended outlined sans.
- Very dense: almost no empty pixels.

**Measured palette:** #62696c 23%, #3a3938 21%, #9b9a96 16%, #d5d5d1 15%, #f2f0ee 14%, #67514f 11%

**Take for our plugins**
1. One-screen "whole studio" density was the era norm. Our drum machine can be dense if the light model is consistent.
2. The red 7-seg pattern number beside lit keys is the canonical drum-machine readout.
3. Warning: photoreal replicas of named hardware are what ReBirth did. We invent the console, so no 303/808 trade dress.

---

## 09 Reason 1.0 (Propellerhead, November 2000)

- **Files:**
  - `09a-reason1-rack-back-cables.jpg` (rack flipped, cables visible)
  - `09b-reason1-redrum-front.jpg` (Redrum drum computer front)
- **Source page:** https://www.soundonsound.com/reviews/propellerhead-software-reason (SOS, March 2001)
- **Image URLs:**
  - https://dt7v1i9vyp3mf.cloudfront.net/styles/news_large/s3/imagelibrary/2/2001-03-propellorhead-8-o25Wb07xPdCB5bcxQcyepqhVfow8dj8Z.jpg
  - https://dt7v1i9vyp3mf.cloudfront.net/styles/news_large/s3/imagelibrary/2/2001-03-propellorhead-5-JHpPzO1dHrxo0jF0AbasEZ91B1eRYSdq.jpg
  - Also viewed: the other 11 SOS images (mixer, Subtractor, NN-19, Dr.Rex, Matrix, sequencer).

**Observed**
- **09a, the back of the rack**:
  - Dark navy-slate rear panels (#2e313a) with printed white "CAUTION", "PATENTS" and "WARNING" boxes, serial labels and the "reMIX" logo.
  - Rows of round jacks.
  - **Cables in red, green and light grey/white** hang in sagging catenary curves with a highlight line along each cable and a darker edge. They overlap freely and cover the panels.
  - The FX units behind are dark red with cream label strips.
  - The transport bar at the bottom shows grey Mac platinum-style controls and an LED-style tempo readout.
- **09b, Redrum front**:
  - A **dark olive-green panel** (#495f49 / #4b584e) with 10 channel strips.
  - Black knobs about 16 px have a red pointer line, a white tick scale around them and a soft drop shadow.
  - At the top of each channel is a small red-on-black LCD with the sample name in a dot-matrix font ("Bd_RiteHe").
  - Labels are **white bold condensed caps with a pixel-ish feel** ("L-PAN-R", "LEVEL", "PITCH").
  - A big vertical "REDRUM" logo is set in outlined italic.
  - The step row is **16 big rounded square step buttons, cream/white with an orange-red lit core** (lit ones glow orange; yellow for accent steps).
  - Small red LEDs, a red "RUN" button with a bevel, and screw heads in the corners.

**Measured palette**
- 09a: #2e313a 25%, #15191d 19%, #524d4c 15%, #63746e 15%, #672620 14%, #9fafa5 11%
- 09b: #495f49 25%, #272e2b 21%, #c3c8c6 14%, #514f43 14%, #636c61 14%, #919891 11%

**Take for our plugins**
1. The back-of-device view is where routing and modulation live. Era-proven, and FL users know it from Reason.
2. Step keys that **glow from inside** (orange core in a white cap) beat flat lit squares.
3. Cables need a single specular line plus a darker edge, which is cheap to draw and reads as 3D.

---

## 10 FruityLoops 3.5 (Image-Line, 2002)

- **File:** `10-fruityloops-3-5-step-sequencer.jpg` (cropped 4:3 from a video frame)
- **Source page:** https://www.youtube.com/watch?v=GzHPua3ob5I ("FruityLoops 3.5.5 Demo Song")
- **Image URL:** https://i.ytimg.com/vi/GzHPua3ob5I/maxresdefault.jpg
- **Also viewed:** Image-Line's 240 px FruityLoops 1.0 screenshot (`raw/fl1.png`). It shows a grey Win95 dialog with dark-red/grey step buttons and a "FruityLoops" splash in orange italic, too small to keep.

**Observed**
- **Overall**: a slate grey-blue UI (#475057 / #5f656b). The desktop is tiled with a faint embossed "FRUITYLOOPS 3" watermark logo.
- **Step sequencer**:
  - Each channel has two tiny round knobs (pan/vol), a small green LED, a grey **bevelled name button** with a ribbed "grip" end, and 16 steps.
  - **The steps are dark rounded rectangles, about 16×20 px, with a 1 px top highlight**. They alternate **grey and maroon in groups of 4** to mark beats.
  - The top channels are overlaid by a large dithered pink/green fruit logo.
- **Fruity Big Clock**: **dark red 7-segment LED digits (#c05c43 bright / #621912 body) on a dark maroon LCD**, with ghost segments visible.
- **Filter plugin window**: small black knobs, with values in pale grey-green LCD boxes ("5482 Hz", "5.8 dB").
- **Top bar**: a tiny pixel-sans menu ("FILE EDIT CHANNELS…"), the transport, an LCD tempo and dense icon buttons.
- **Browser**: lavender/pink text on dark grey.
- **Light**: everything is lit from the top-left with 1 px highlights; the overall look is matte.

**Measured palette:** #475057 31%, #48484e 19%, #5f656b 19%, #23292c 17%, #939798 8%, #50555b 7%

**Take for our plugins**
1. **The 4-step colour alternation of FL's channel rack is the heritage cue FL users will feel.** Keep it in our step row.
2. Use red-LED 7-seg (not amber) for tempo and position in drum products: it is what FL users saw.
3. Warning: FL's own look is slate grey and matte. Our 3D must not end up as a "FL skin".

---

## 11 Korg Electribe EA-1 and ER-1 (1999)

- **Files:**
  - `11a-korg-electribe-ea1-er1.jpg` (both units, studio photo)
  - `11b-korg-electribe-ea1-panel-detail.jpg` (EA-1 panel close-up)
- **Source page:** https://www.soundonsound.com/reviews/korg-electribe-ea1-er1 (SOS, July 1999)
- **Image URLs:**
  - https://dt7v1i9vyp3mf.cloudfront.net/styles/news_large/s3/imagelibrary/1/1999-07-korgelec-1-m_TvBZ3Qktis7DcWu849H.mRwtxRHTuq.jpg
  - https://dt7v1i9vyp3mf.cloudfront.net/styles/news_large/s3/imagelibrary/1/1999-07-korgelec-2-z_m00i0gQXrZcvrgHTtdl4YSAfbkRijb.jpg

**Observed**
- **Body**: **brushed grey aluminium-look** (#82807d to #90908d) with a curved, wave-shaped darker grey plastic frame.
- **Coloured field**: a large printed field sits behind the display and the main keys: **EA-1 blue (#5491c2)** and **ER-1 hot pink/red (#da516c)**. The rest is grey.
- **Display**: **red 7-segment LED** ("A.01"), next to a big black jog dial.
- **Knobs**: black, knurled, with a white pointer line. Each has a ring of small black dots printed around it.
- **Buttons**: **pale grey-white rubber keys with soft rounded corners**. The step keys **glow pinkish-white from inside** when lit (#faeee8), and on the ER-1 the lit pattern looks like a row of warm lamps.
- **Distortion key**: red-lit from within.
- **LEDs**: small red LEDs sit next to the wave-shape icons.
- **Section headers**: white caps in **black bars** ("OSCILLATOR", "FILTER", "AMP", "EFFECT").
- **Labels are set in a serif (Times-like)**: "Portamento", "OSC Balance", "Cutoff". There is a small signal-flow diagram printed in thin black lines at the bottom.

**Measured palette**
- 11a: #fef579 26% and #fdf265 25% (yellow backdrop), #7a898f 25%, #6f5e66 16%, #b7b383 4%, #edeebb 4%
- 11b: #898885 23%, #90908d 20%, #4a4547 19%, #83817d 15%, #777674 15%, #b7bab6 7%

**Take for our plugins**
1. **One coloured printed field per product on a shared grey-metal body** is the family system. Electribe did per-product colour exactly the way our accent plan wants.
2. Step keys lit *through* a translucent cap (warm white glow), not coloured LEDs beside keys.
3. Black section-header bars with white caps, plus a printed signal-flow diagram, make an honest, readable information layer.

---

## 12 Yamaha SU700 (1998) and RM1x (1999) displays

- **Files:**
  - `12a-yamaha-su700-vfd.jpg` (SU700 control surface and VFD)
  - `12b-yamaha-rm1x-lcd.jpg` (RM1x LCD and function knobs)
- **Source pages:**
  - https://www.soundonsound.com/reviews/yamaha-su700 (SOS, April 1999)
  - https://www.soundonsound.com/reviews/yamaha-rm1x (SOS, February 1999)
- **Image URLs:**
  - https://dt7v1i9vyp3mf.cloudfront.net/styles/news_large/s3/imagelibrary/1/1999-04-yamahasu700-2-tHxzxEmI5Q9PTgYq.pFUhLT8B5296VZV.jpg
  - https://dt7v1i9vyp3mf.cloudfront.net/styles/news_large/s3/imagelibrary/1/1999-02-yamaharm1x-2-U6VLaGbcslaeIlSFH7ibn9yWmzEDRwXz.jpg

**Observed**
- **SU700 body and controls**:
  - A dark steel-blue body (#304a68 / #3b5872).
  - Light-grey printed label tiles ("SOUND", "GROOVE", "LFO", "EQ") hold small dark-glossy rectangular keys.
  - A grid of black oval keys sits under white label boxes.
  - **Transport keys** are big cream keycaps with a black icon and a red dot for record.
  - The bottom row has knobs with **coloured caps: orange, white and lilac**, matching the display colours.
- **SU700 VFD**:
  - A **black glass window (#0f1814)** holds a **vacuum-fluorescent display**.
  - **Cyan-white 14-segment characters (#f2fdfb at the brightest)** read "01 SONG001" and "001:1 / 120.0".
  - **Unlit segments are visible as faint ghosts.**
  - A row of **segmented bar meters in three colours: orange (#fccb66), white and blue (#aed5fb)**.
  - Small red legends sit at the right edge ("MEASURE", "BPM", "NOTE").
  - The glyphs glow slightly.
- **RM1x**:
  - A teal-blue body (#3e5d73) with **a large yellow-green backlit LCD (#b5d109)** and dark segment-style characters ("P28 | 074 | RND4 | 180.0").
  - Each value field sits above a black knurled knob in a white ring collar, joined by a **striped "ladder" leader** graphic.
  - Thin orange printed lines link the knobs.
  - A small red LED beside each F-key.

**Measured palette**
- 12a: #192a37 22%, #35475d 21%, #3b5872 21%, #4b6279 14%, #d8dcde 13%, #86949c 9%
- 12b: #246384 30%, #b4d108 26%, #196385 21%, #2a4458 13%, #d4df5d 7%, #4e8174 4%

**Take for our plugins**
1. **The VFD look (cyan-white glyphs, ghost segments, multi-colour bar segments) is the strongest "precise and gorgeous" display idea found.** It is a better fit for our LCD strips than amber.
2. The RM1x pattern ties one LCD field to the knob below it with a printed leader. This solves the "value directly above its knob" layout.
3. Coloured knob caps keyed to display colours give family accents without painting panels.

---

## 13 Akai MPC2000XL (1999)

- **File:** `13-akai-mpc2000xl.jpg`
- **Source page:** https://www.soundonsound.com/reviews/akai-mpc2000xl (SOS, December 1999)
- **Image URL:** https://dt7v1i9vyp3mf.cloudfront.net/styles/news_large/s3/imagelibrary/1/1999-12-akaimpc2000-2-o3smKeu6OCnbknj4NC1b3XGjhxgSALKn.jpg

**Observed**
- **Body**: **warm cream/beige plastic (#e6ddc1)** with a grey-green pad area (#938e6f-ish pads in a #a9a98d field).
- **Pads**: 16 dark grey square pads, each labelled "PAD 13" etc. in small caps above.
- **Logo**: the "AKAI professional" logo in red serif italic, and "MPC2000XL" in an outlined extended face.
- **LCD**:
  - It sits in a black bezel that leans back, with a printed strapline "INTEGRATED RHYTHM MACHINE 16 BIT DRUM SAMPLER / MIDI SEQUENCER".
  - The screen is **teal/aqua backlit (#48b3a8, #2d937e)** with dark blue-black text in a small fixed-width LCD font ("Sq:01-Sequence01", "Now:001.04.28", "J:120.0(SEQ)").
  - The **selected field and the six soft-key tabs are inverted** (light text on dark bars: STEP | EDIT | TrMUTE | SOLO | Tr- | Tr+).
- **Keys**: grey rubber buttons, an orange "OPEN WINDOW" key, **red REC and OVERDUB keys**, and cream transport keys.
- **Data wheel**: a big black data wheel with a finger dimple.
- **Light**: diffuse studio photo light; the keys have soft rounded top bevels.

**Measured palette:** #ede2c1 24%, #8b9378 19%, #675c44 17%, #e4dab7 14%, #a9a98d 13%, #f1e8ce 12%. Spot: LCD #48b3a8 (bright), #2d937e (body).

**Take for our plugins**
1. **The jungle sampler's screen is teal-backlit with inverted soft-key tabs, not grey-green.** Use this exact grammar (inverted selection bar plus a soft-key tab row) for our sampler and drum machine LCDs.
2. Cream and beige bodies are a warm, non-"liminal" counterweight to the cold PS2 blue. A candidate housing for the sampler.

---

## 14 Kai Krause software: Kai's Power Goo (1995), KPT 3 Texture Explorer (1995), Bryce 5 (2001)

- **Files:** `14a-kais-power-goo.jpg`, `14b-kpt3-texture-explorer.jpg`, `14c-bryce5.jpg`
- **Source pages:**
  - https://mprove.de/script/99/kai/2Software.html (Goo, KPT)
  - https://en.wikipedia.org/wiki/Bryce_(software)
- **Image URLs:**
  - https://mprove.de/script/99/kai/_media/high/GOO.jpg
  - https://mprove.de/script/99/kai/_media/high/KPT3TextureExplorer.jpg
  - https://upload.wikimedia.org/wikipedia/en/0/01/Bryce5screenshot.jpg
  - Also viewed: KPT Spheroid Designer, Convolver, KPT Lens, Photo Soap rooms and Bryce full.

**Observed**
- **Goo**:
  - A full-screen dark teal "room" (#214146) with a rounded inner frame and embossed relief icons (camera, ABC).
  - **Tool buttons are glossy spheres**: magenta, purple, pink, red, orange, yellow. Each has white bold label text with a dark drop shadow, a **specular highlight upper-left** and a darker lower-right, and some have a "bite" taken out (a dark chip) to show state.
  - Big red "GOO" and "MetaTools" wordmarks in a chunky rounded italic with a 3D extrusion.
  - "IN" and "OUT" in teal outline letters.
- **Texture Explorer**:
  - A mid-grey (#9c9c9c) room.
  - **Thick black drop shadows** (offset down-right, about 6–8 px, soft) under every tile and panel.
  - The title is set in white italic bold on a black-to-chrome gradient bar.
  - Small coloured balls are placed along a curve as the "mutation" control.
  - A row of round dark radio dots for Hue / Saturation / Brightness.
- **Bryce 5**:
  - A light grey (#d2d2d2) UI with a bead-blasted texture.
  - The left column has **grey chrome-ish spheres and arrow-crosses with blue glossy cores**, sitting on soft cast shadows directly below them (top light).
  - A shelf of 3D primitive icons (blue spheres, cones, torus) runs along the top, rendered as real 3D with reflections.
  - Text is small grey sans.

**Measured palette**
- 14a: #214146 28%, #01191e 24%, #75293d 15%, #97635a 14%, #cebaae 12%, #1a1c23 8%
- 14b: #9c9c9c 36%, #24141c 24%, #696168 22%, #bdbeb3 9%, #75a797 7%, #a7988d 3%
- 14c: #d2d2d2 27%, #d5d5d5 19%, #bfbfc0 17%, #87858e 15%, #e7e7e7 13%, #d0cccc 9%

**Take for our plugins**
1. The sphere-as-button with the label *on* the sphere, plus a "bite" to show state, is a good model for preset and mod-source orbs. But it must keep 1:1 parameter feedback.
2. Era 3D UI lived on **light and mid-grey** grounds with **heavy soft drop shadows down-right** (KPT) or cast shadows straight below (Bryce). Shadows did most of the depth work.
3. Warning: Goo's saturated rainbow spheres on teal read as a toy. Pick one accent per plugin.

---

## 15 Mac OS X 10.0 Aqua (2001) and iMac G3 Bondi Blue (1998)

- **Files:** `15a-macosx-10-0-aqua.png` (800×600 desktop) and `15b-imac-g3-bondi.jpg` (product photo on white)
- **Source pages:** https://en.wikipedia.org/wiki/Mac_OS_X_10.0 and https://en.wikipedia.org/wiki/IMac_G3
- **Image URLs:**
  - https://upload.wikimedia.org/wikipedia/en/d/d8/MacOSX10-0screenshot.png
  - https://upload.wikimedia.org/wikipedia/commons/d/db/IMac_G3_Bondi_Blue%2C_three-quarters_view.png
  - Also viewed: Macosxpb.png (10.0 public beta).

**Observed**
- **Aqua window chrome**:
  - White windows with **fine horizontal pinstripes** in the title bars and backgrounds.
  - **Traffic-light buttons about 13 px**: red, amber and green gel spheres with a **white elliptical specular across the top ~40%** and a darker rim at the bottom, which reads as an inner glow.
  - Toolbar icons are large and photoreal (a CRT "Computer", a house, a heart, an "A" for Applications).
  - Segmented view control: three adjoining rounded cells, with the selected one filled **gel blue** and a top highlight.
  - Menus are translucent white with a **blue highlight bar (#3f629c to lighter)**; the system type is a smooth, slightly rounded humanist sans.
  - The desktop is a blue gradient with soft curves.
  - The Dock is a translucent shelf of reflective icons.
- **iMac G3**:
  - Translucent **Bondi blue** shell, dark teal-navy in shadow (#061b2e at the centre) and lighter at the edges, **with internal parts (vent grid, brackets) visible through the plastic**.
  - A milky white/clear frosted front bezel with fine vertical ribs.
  - Bondi-blue speaker grilles.

**Measured palette**
- 15a: #ffffff 31%, #f3f3f4 26%, #3f629c 26%, #c1c8d1 15%
- 15b: #0c1926 31%, #ffffff 29%, #c0babd 22%, #47535d 14%

**Take for our plugins**
1. Gel buttons are small (about 13 px) with **two highlight layers**: a top specular ellipse plus a bottom inner glow. That is the recipe for on/off lamps.
2. Translucent housing with visible internal structure (iMac) is better than a "transparent" UI. Show a few internal shapes, not the background.
3. Pinstripe texture is very Aqua-specific. Avoid it, or it will read as a Mac pastiche.

---

## 16 2Advanced Studios v3 "Expansions" (2001 design; 2024 Rive rebuild)

- **File:** `16-2advanced-v3-expansions-rive-reboot.jpg`
- **Source page:** https://v3.2advanced.com/ (redirects to /v3expansionsreboot/)
- **Image URL:** https://v3.2advanced.com/v3expansionsreboot/og/v3-expansions.jpg
- **Note:** this is the 2024 rebuild's share image. The layout reproduces v3, but the text items are from 2024. webdesignmuseum.org and web.archive.org were not reachable from this session.

**Observed**
- **A monochrome steel-blue system** (#1d2e49 to #8291a9). The only other hue is one small purple thumbnail in the Updates box.
- **Hero and nav**:
  - A desaturated blue-tinted photo of curving concrete flyover ramps against sky.
  - A **tiny dot-grid halftone overlay** and HUD fragments: thin rules, small square glyphs, concentric-ring "dial" graphics on the right, double chevrons «.
  - The nav is a bar of **trapezoid/chamfered tabs** separated by angled cuts.
- **Type**:
  - The labels use **extended all-caps sans with dot separators**: "2A.VTHREE.EXPANSIONS", "NEW.METHODS.OF.TRANSPORTATION", "SCROLL.EXTENDED.CONTENT", "AMBIENCE.MUTE".
  - Section headers have a small **inverted letter box** (F / S / U) plus a dot-grid fill.
  - The logo is a rounded-rectangle "2" mark with an extended-sans wordmark.

**Measured palette:** #1d2e49 23%, #3a4964 22%, #4a5a73 18%, #8291a9 18%, #5c6a81 12%, #728097 7%

**Take for our plugins**
1. **Monochrome blue-grey plus one accent** is the real 2001 "techno" palette, far calmer than neon.
2. Dot-separated caps labels ("FILTER.CUTOFF") and inverted single-letter section badges are cheap, era-exact typographic devices.
3. Warning: photo plus halftone hero imagery behind controls would repeat GuyEngine's mistake. Keep it on the boot or splash screen only.

---

## Candidates checked and rejected (viewed, not kept)

- **Sonique 1.95** (Wikipedia, 384 px): viewed. A dark navy rounded body with lime-green text, round "orb" mid mode and chrome rings. Too small to sample reliably.
- **Sony Ericsson T68i** photo: viewed. The screen was off, showing only the silver/blue body, so it was not useful.
- **Nokia 3310** photo (303 px): viewed. The LCD carries an operator logo, and the image is too small.
- **Sonic Foundry ACID** (SOS 1998, 3 images): viewed. A standard Win98 grey UI with coloured track icons (green, purple, red) and purple waveforms. No distinctive material.
- **FruityLoops 1.0** (240 px): viewed, too small.
- **GuyEngine store art**: viewed. It is only a blurred "abstract blocks" cover.

**Not obtained:**
- Kaliber10000 and Praystation captures, because web.archive.org and webdesignmuseum.org were unreachable or 403.
- Native Instruments Pro-52, Battery 1 and Reaktor 3 (the SOS review pages return 410).
- Hammerhead (no image found).
- PsxReverb/PsxSampler: the GitHub README has no screenshot.
- Sugar Bytes and Baby Audio single-product hi-res shots (not attempted or not exposed), and KVR (403).

---

## Cross-cutting observations

### How era software rendered 3D controls

- **Light direction is upper-left in every era screen viewed.** This holds for Winamp, ReBirth, Reason, FruityLoops, KPT, Goo and RYM2612 (a modern homage). Bryce and Aqua use a near-vertical top light. No era UI showed a coloured rim light from behind. Rim/backlight exists only in today's plugins (Baby Audio, GameVerb glows).
- **Bevels were tiny relative to control size.**
  - Winamp buttons are 23×18 px with 1 px light and 1 px dark edges (≈5%).
  - FL steps are about 16×20 px with a 1 px top highlight.
  - Reason and ReBirth knobs (16–20 px) have no bevel at all. Depth comes from a darker lower-right half plus a 1–2 px drop shadow down-right.
  - **Depth came mainly from shadows**, not edges: KPT has heavy 6–8 px soft drop shadows down-right, Bryce casts shadows below spheres, and Reason drops shadows under knobs and cables.
- **Highlight layers**:
  - Pixel-era widgets (Winamp, FL, Reason): **1 layer** (edge highlight).
  - Gel and sphere controls (Aqua, Goo, Bryce): **2 layers**, a top specular ellipse or spot plus a lower inner glow or reflected light.
  - Nobody used three or more layers. Glint sweeps and fresnel rims are a modern idea.
- **Knob construction**: a cap with a pointer *line* (never a dot) plus a **printed tick-dot ring on the panel** (ReBirth, Reason, Electribe, RYM2612, Y2K Club). Value arcs around knobs appear only in modern plugins (GuyEngine, chipsynth, GameVerb).
- **Lit keys glow from inside a translucent cap** (Electribe, Redrum steps, ReBirth 808 row). Separate LEDs are used for small state indicators.

### How LCD and value displays looked

- **Four distinct families were seen:**
  1. red 7-seg LED for tempo, pattern and position (Electribe, ReBirth, FL Big Clock);
  2. cyan-white VFD with ghost segments and multi-colour bar meters (SU700);
  3. backlit dot-matrix LCD with dark text: teal on MPC2000XL, yellow-green on RM1x, red-on-black mini LCD on Redrum;
  4. software black + green #00f700 (Winamp).
- **Common grammar:**
  - Unlit segments are visible.
  - Selected fields and soft-key tabs are **inverted bars** (MPC).
  - The display sits in a **recessed, dark-bezelled well**, often angled (MPC) or pill-shaped (Silvert).
  - Small printed legends sit *outside* the glass.
  - None of the real displays had bloom over text. The VFD has only a slight glyph glow.

### Where what I SAW contradicts 01-ui-aesthetic.md

1. **"MPC green LCD #9DB08A / #B4C59B, pixels #1F2A1C" is wrong for the MPC2000XL**, which the doc calls *the* jungle sampler screen.
   - The 1999 SOS photo shows a **teal/aqua backlight (#48b3a8 / #2d937e)** with dark text and inverted soft-key tabs.
   - The doc's grey-green belongs to older units and was not verified here.
2. **"Amber VFD, glyphs #FFB000" is not what the era sampler and groovebox VFD looked like.** The SU700's VFD is **cyan-white (#f2fdfb)** with orange (#fccb66), white and blue (#aed5fb) bar segments. Amber appears only as one of the bar colours.
3. **Electribe EA-1**: the doc says "silver finish; blue not confirmed". The photo confirms **both**: a grey brushed body *with* a large **blue (#5491c2) printed field** on the EA-1 and **pink-red (#da516c)** on the ER-1.
   - The doc's "LED step keys" are actually **translucent keys that glow warm white from inside**.
   - Its "playful printed graphic language" is **serif (Times-like) labels and black header bars**, not techno type.
4. **The "void black / deep navy" family base is not era-typical for music tools.**
   - Every era music application and device viewed sits on **light-to-mid grey, cream or steel blue**: ReBirth, FL, Reason Redrum (olive), Bryce, KPT, Aqua, MPC, SU700, Electribe.
   - **Dark navy with glow is exactly where today's competitors cluster**: GuyEngine, Y2K Club, chipsynth, Baby Audio, RYM2612.
   - A void-black base will make us look like them, not like 2000.
5. **Typography**: the doc centres Eurostile/Michroma/Orbitron. What was actually on the era panels was:
   - bold condensed grotesk caps (Yamaha, ReBirth, Reason);
   - **Times-like serif** (Korg);
   - bitmap pixel fonts (Winamp, FL, MPC LCD);
   - extended caps with dot separators (2Advanced, which is the closest to the doc's Eurostile idea);
   - extended outlined wordmarks only for logos (MPC2000XL, ReBirth, RYM2612).
   - Eurostile-style faces were not seen on any of these labels.
6. **The lighting rig "cool key upper-left plus coloured rim from behind"**: the upper-left key is confirmed. **The coloured rim light is not era-authentic.** No era control had one; it is a modern plugin look (GameVerb, Baby Audio). If we keep it, it should be a deliberate modern addition, not cited as era.
7. **"Nobody ships a coherent console metaphor; only GuyEngine occupies the PS2 lane."** This is only half true.
   - **GuyEngine V2 is visually generic.** It uses flat arc knobs and a system font; the PS2 part is a blurred background render plus controller-icon theme buttons. Its threat is the *claim*, not the look.
   - **Impact Soundworks GameVerb (2023)** already ships a **controller-shaped device with a blue pixel-font LCD**, SNES/PSX/N64 tabs and four-colour knob rings.
   - The open space is narrower: a console **operating system** (boot, BIOS menus, memory-card presets, one light rig) is still unclaimed. The "device with a pixel screen" is not.
8. **Chrome at most 2%**: confirmed as a good *design* rule, but it is not how the era behaved. Winamp chrome skins, Bryce and KPT used chrome or metal as the main surface. Keep the rule as our choice, and don't cite it as era fidelity.
9. **Reason cable colours**: the doc gives red audio, green effects, yellow CV. The 2001 screenshot shows **red, green and light grey/white** cables, and **no yellow** was visible in the capture viewed.
