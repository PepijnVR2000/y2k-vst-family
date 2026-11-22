# 01 — UI Aesthetic Research: PS2-era / Y2K interface language for a jungle and DnB plugin family

Status: research brief v1 (2026-11-22). Audience: UI designer, art director, and the plugin/GUI engineer.

**How these sources were checked.** All findings come from web searches. Page fetching was blocked in this session for every host tried (scanlines.substack.com, creativebloq.com and killscreen.com would not resolve), and the shared web-search budget ran out near the end of the research. Each claim is therefore tagged:

- **[S]**: supported by a search result. The URL is given.
- **[M]**: from the researcher's own domain knowledge, with no source found in this session. A designer should check these against the linked videos before relying on them.

A few earlier claims were wrong and are corrected in this report. The most important: the "blades" interface belongs to the **Xbox 360 (2005)**, not the original Xbox (2001).

---

## (a) Thesis

**Present the plugins as the system software of a music console from about 2001 that never existed.** It should not read as "a Y2K skin on a synth." Each plugin is a "disc" for that console. The shared shell is the console's BIOS, and presets are "save files." Each preset has a small animated 3D icon, a four-corner gradient background and its own light rig, which is exactly how the PS2 memory-card browser built a save entry ([S] icon.sys format, below). Controls are lit 3D objects: glass and translucent plastic, with brushed aluminium where hands touch. They sit in a dark, foggy, slowly drifting void like the PS2 and PSX menus. Over that sits a graphic layer in the spirit of The Designers Republic and WipEout. It is strict, modular, iconographic and printed like packaging, and it does the labelling, so the 3D never has to.

The music link is literal. The same years produced music-making software that ran *on* the console: Jester Interactive's *Music* (1998) and *Music 2000 / MTV Music Generator* (1999–2001). The second was written by WipEout composer Tim Wright and is credited with helping shape grime. Ape Escape (1999) used Soichi Terada's jungle. "Wavy" is read as the liquid, atmospheric strand of late-90s drum & bass, not the gabber and chrome-butterfly strand of Y2K.

On the CARI taxonomy, the target sits in **Y2K Futurism (about 1997–2004)**, leaning toward the cool, soft, club-literate strand CARI calls *Gen X Soft Club* [M]. It is explicitly **not** Frutiger Aero (2005–2013 nature gloss), Vaporwave (irony), or McBling.

What makes it distinctive rather than pastiche:
1. **Presets are save files with procedural 3D icons.** A system mechanic is borrowed, not a surface look.
2. **One light rig and one material library across the whole family.** Era kitsch fails exactly here, because every element gets its own chrome.
3. **Motion is governed like a console OS, not a web page.** Depth transitions, fog and idle breathing.
4. **The graphic layer is ours.** It is a TDR-grade system, not TDR's actual vocabulary.

---

## (b) Reference catalogue

Each entry gives what it is, **what to take from it**, and sources. YouTube captures were found by search; titles are as uploaded and the uploaders are fans, not official channels.

### 1. Console system UIs, 1998–2005

**PS2 boot sequence (2000), the "towers of cubes"**
- What it is: a black void, a burst of blue-white light, then translucent crystal columns or cubes of different heights rising from a dark floor, followed by the PS2 logo [M]. The number and height of the towers reflect the save data on the inserted memory card. A fresh card gives a boot with no towers [S]. Sources disagree on whether the count tracks games or saves [S]. The music and sound are by Sony sound designer **Takafumi Fujisawa**, who also created the PS1 startup sound [S].
- What to take:
  - **The UI quietly visualises your own data.** Our idle "attract" view could be a skyline built from the user's preset library, or from pattern density in the drum machine.
  - Slow camera.
  - Translucent crystal against black.
  - Sound as a long, reverberant swell rather than a jingle.
- Sources: https://www.looper.com/245888/the-ps2-startup-screen-had-a-secret-you-probably-missed · https://www.gamesradar.com/ps2s-startup-screen-easter-egg-is-surprising-players-all-over-again · https://automaton-media.com/articles/newsjp/20220513-202324/ · Fujisawa system music on archive.org: https://archive.org/details/sony-playstation-2-system-software-2000-ost · https://digiteye.in/was-playstation-2-opening-sound-really-made-by-throwing-piano-off-a-building-fact-check/
- Video: https://www.youtube.com/watch?v=ZcQ-ldkZBRE · https://www.youtube.com/watch?v=ERpAoWxtXPg · recreated sequence: https://www.youtube.com/watch?v=w4_tdaPYmOY

**PS2 main menu (clock, "Browser", "System Configuration")**
- What it is: a black screen with slowly orbiting translucent blue prisms or orbs, and an ambient drone with occasional sparkles [M]. The orbs are driven by the system clock: if the clock battery dies, the orbs stop spinning [S].
- What to take: **idle motion tied to real state**. In our plugins, orbiting objects could be phase-locked to host tempo when the transport runs and drift freely when it stops. This is the single best "alive but calm" pattern for a plugin.
- Sources: https://www.ifixit.com/Wiki/PlayStation_2_Troubleshooting · https://forums.tomshardware.com/threads/ps2-not-keeping-track-of-time-blue-orbs-no-longer-spinning-static.2692156/ · fan recreation and roadmap: https://github.com/TYSONMediaGroup/PS2-Clock-Mod · high-resolution PS2 menu wallpapers: https://lmnt.me/blog/wallpapers/playstation-2.html
- Video: https://www.youtube.com/watch?v=cf9Ht8OFyEM (PCSX2, 1080p60, system browser and configuration) · https://www.youtube.com/watch?v=XYHoxEnt1Lk · https://www.youtube.com/watch?v=hoFy3_MfQ1g

**PS2 Browser and memory-card manager (3D save icons)**
- What it is: each save carries an `icon.sys` descriptor plus 3D model files. The browser renders the save's icon as a real-time 3D object, and developers could ship separate animated icons for "browse", "copy" and "delete" [S].
  - **The `icon.sys` file (964 bytes) defines four background corner colours, three directional lights with their colours, and an ambient colour for each save** [S].
  - A save with missing files appears as a blue box labelled "corrupted data" [S].
  - Icons showed characters or props from the game, such as the Dragon Quest VIII slime or the Blades of Chaos [S].
- What to take: **this is the core mechanic to borrow.**
  - Each preset gets a tiny procedural 3D icon (for example a crystal whose shape comes from the patch's spectrum or the kit's waveforms), a four-corner gradient tile and its own light colours.
  - The icon has three animation states: browse (idle spin), copy, and delete.
  - Presets become collectible objects.
  - A "corrupted data" blue box is a fun, era-correct error state for missing samples.
- Sources: https://www.ps2savetools.com/documents/iconsys-format/ · https://github.com/ticky/ps2iconsys · https://csclub.uwaterloo.ca/~rridge/mymc/ps2icon-0.5.pdf · https://kotaku.com/memory-card-icons-were-rad-1835331018 · https://www.vidaextra.com/juegos-retro/arte-perdido-memory-card-miticos-iconos-partida-guardada-playstation-ps2 · https://zeli.app/story/50195184 · web viewer for real icons: https://nobodxbodon.github.io/babyno.top/%E2%80%9Cps2mc%20browser%E2%80%9D%20New%20Feature%20Release.html

**Mood framing for the PS2 (one essay)**
- "The PS2's Foreboding Aesthetic" describes the core as **black, dark blue, an urban feel, and "a little dash of Y2K and Techno-Futurism"**, with system screens that feel cold and haunted [S]. The full text could not be fetched.
- What to take: the darkness is the brand. The risk is that it reads as horror (see pitfalls).
- Source: https://scanlines.substack.com/p/the-ps2s-foreboding-aesthetic

**PSX DESR (Japan, December 2003): where the XMB started**
- A DVR with a PS2 inside, sold by Sony Corporation. It was the first device to ship the **XrossMediaBar**, which later moved to PSP and PS3. Credit for the XMB is disputed between SCE and SCE with Q-Games [S].
- What to take: the cross-axis navigation (categories run horizontally, items vertically), and soft glowing icons over an ambient wave background [M]. Use it for the **preset and category browser**, because it keeps the browser reachable by keyboard or controller.
- Sources: https://en.wikipedia.org/wiki/PSX_(digital_video_recorder) · https://giantbomb.com/wiki/Concepts/XrossMediaBar

**PS1 BIOS (1994)**
- What it is: a white screen with the Sony Computer Entertainment diamond, then the black "PlayStation / Licensed by" screen [M]. Fujisawa's startup sound was designed partly so the console could check that it could read the disc [S]. The memory-card manager used a blue-violet gradient, two 15-block cards, and 16×16 animated pixel icons [M].
- What to take: the two-card side-by-side copy UI, which suits an "A/B preset compare". Use the PS1 look only for an easter-egg "PS1 mode". Do not mix it into the main look (see section e).
- Sources: https://www.pushsquare.com/news/2019/12/psones_iconic_startup_sound_was_designed_to_detect_if_the_console_could_read_your_disc · https://www.youtube.com/watch?v=3gft-eH9qEI

**Dreamcast BIOS and VMU (1998–1999)**
- What it is: bright and airy. Save icons sit over **rippling water and clouds** [S]. There are translucent rounded buttons on a pale sky [M].
  - A hidden alternative **3D menu** is unlocked by a Puyo Puyo Fever save on a VMU [S].
  - The swirl logo is orange in Japan and the US and blue in PAL regions. One theory is that this avoided a clash with Tivola's red swirl [S].
  - VMU file names are 12 characters, and each file carries a 32-byte description [S].
- What to take: the "daylight" counterpart to the PS2's night. It is the best reference for direction 3. Constrained text fields (12-character preset names shown on a 48×32 LCD, the VMU's real resolution [M]) make a great secondary display.
- Sources: https://segaretro.org/Sega_Dreamcast/Boot_ROM/Hidden_content · https://www.segaretro.org/Sega_Dreamcast/Boot_ROM · https://www.timeextension.com/news/2025/02/did-you-know-that-dreamcast-has-a-hidden-menu-system · https://dreamcast.wiki/File_Types · https://new.tcrf.net/Dreamcast
- Video: https://www.youtube.com/watch?v=gkHNyiJPZtk (secret 3D BIOS) · https://www.youtube.com/watch?v=7NFQ0hvT79Q

**GameCube IPL (2001)**
- What it is: a rolling cube draws the "G". The menu is **one large translucent cube with an option on each face**, and memory-card saves appear as **floating cubes over a dark grid** [S]. Holding Z at boot changes the startup audio [S]. One analysis says the startup jingle is the Famicom Disk System fanfare slowed down; sped up 19×, it becomes recognisable [S].
- What to take:
  - **One object, many faces** as a navigation model: rotate a cube to switch the synth between OSC, FILTER, MOD and FX pages.
  - Indigo and violet palette.
  - Sound-design trick: a short era motif slowed down becomes an ambient bed.
- Sources: https://gamer.nl/artikelen/nieuws/sw-filmpje-van-gamecubes-dashboard/ · https://medium.com/@vehemently/the-gamecube-startup-a-critical-analysis-2bec019a7519 · https://avid.wiki/GameCube
- Video: https://www.youtube.com/watch?v=YjgRmgEZyJY · https://www.youtube.com/watch?v=pIktjDoLNc8

**Original Xbox dashboard (2001): green orb and pods**
- What it is: a pulsating green orb, a background of **connected, moving hexagons**, and black with neon green [S].
  - It is a full 3D Direct3D 8 application whose UI is defined in editable script files.
  - The April 2001 alpha had four "pods" (Memory, Music, Games, Settings), cut to three by May [S].
  - Navigation sounds are **distorted public-domain NASA audio** (explained by Larry Hryb in 2014) [S].
  - Boot sound by **Brian Schmidt**: nine tracks of lo-fi digitised thunderclaps, cannon and glockenspiel, filtered with white noise [S].
  - UI and brand fonts by **Steve Matteson**, briefed as "very aggressive" typography; the dashboard font files are Xbox.xtf and XBox Book.xtf [S].
  - In 2021 Microsoft brought the orb back as a dynamic background [S].
  - Correction: the "blades" UI was the Xbox 360 (2005) [M].
- What to take:
  - **UI sound built from processed found sound**, not synth beeps. Use processed break fragments and vinyl crackle for our jungle family.
  - The hex-network background as a pattern for modulation routing.
- Sources: https://stevivor.com/news/original-xboxs-menu-sounds-nasa · https://mrmilenko.github.io/UIX-History/docs/alpha-dashboard.html · https://mrmilenko.github.io/UIX-History/docs/xbox-architecture.html · https://gamedeveloper.com/audio/designing-the-boot-sound-for-the-original-xbox · https://www.gamesoundcon.com/post/creating-the-original-xbox-boot-sound-using-old-school-game-audio-techniques-in-a-modern-console · https://mattesontypographics.com/stories/game-face-fonts-for-xbox · https://xboxdevwiki.net/Xtf · https://hypebeast.com/2021/05/xbox-series-x-s-pulsating-blob-screen-background-info · reverse-engineered dashboard: https://www.windowscentral.com/gaming/xbox/the-og-xbox-lives-reverse-engineered-dashboard-brings-the-2001-console-experience-to-pc
- Video: https://www.youtube.com/watch?v=wchql2Tb4s8 (all dashboard sound effects) · https://www.youtube.com/watch?v=GlS1AQ4YpFg (ambience) · https://www.youtube.com/watch?v=tPK-8Cl-mSg

**PS2 Network Access Disc and HDD Utility**
- No sources found before the search budget ran out. Treat as **open research**.

### 2. Game front ends with jungle, DnB and electronic links

**WipEout, 2097, Wip3out and Fusion (Psygnosis, 1995–2002) with The Designers Republic**
- TDR (Sheffield, also known for Warp record sleeves) designed the box art, typography, team logos, icons, billboards and colour schemes [S]. The result is a **single unified system across manual, box, UI, signage and team marks** [S].
  - The logo is based on **Eurostile** (Aldo Novarese, 1962) and is built from "8"s [S].
  - TDR's custom **unicase** typeface ran from Pop Will Eat Itself records (1993) into WipEout (1995). It is unreleased and its name is unknown [S].
  - Wip3out's menus are "very minimalist and hard to read," per one uploader [S].
  - Soundtracks: CoLD SToRAGE (Tim Wright), Orbital, The Chemical Brothers, Leftfield, Photek; Sasha curated Wip3out [M].
- What to take:
  - The graphic layer **is a corporate identity for a fictional league**. Ours should be a fictional console maker's identity: one logotype system, numbered product codes, "team" marks for each plugin.
  - Modular type, and pictograms with strict stroke rules.
  - Do **not** copy TDR's specific tropes (Japanese pseudo-copy, smiley faces, pharmaceutical warnings). Thousands have done that.
- Sources: https://www.bfi.org.uk/features/wipeout-psygnosis-sony-playstation · https://www.creativebloq.com/news/wipeout-design-inspiration · https://www.creativeboom.com/the-edit/wipeout-futurism/ · https://fontsinuse.com/typefaces/246221/amalgamation · https://www.pushsquare.com/news/2022/10/random-did-you-know-wipeouts-iconic-logo-was-made-up-of-a-bunch-of-8s · https://en.wikipedia.org/wiki/Wipeout_3 · https://www.thesixthaxis.com/?p=145394
- Video: https://www.youtube.com/watch?v=xOYY7w5VUN0 (intro and menus) · https://www.youtube.com/watch?v=URohvi2D_sU (upscaled intro) · https://www.youtube.com/watch?v=h4lFmtEBBi4 (team-logo sequence)

**R4: Ridge Racer Type 4 (Namco, 1998)**
- Minimalist menus with bold type, lots of negative space and a **signature yellow** used as a background colour [S]. Opening theme: "Urban Fragments" by Kohta Takahashi [S]. A UX Collective critique calls the menu an "aesthetic identity crisis" of schematics and rock-style type [S]. One search summary also credited TDR here; that looks like WipEout confused with R4 [S, likely wrong].
- What to take:
  - **One flood colour per product**, so each plugin owns a hue.
  - Generous negative space.
  - Lounge-jazz-meets-house as the tone of the UI sounds.
- Sources: https://uxdesign.cc/ui-breakdown-ridge-racer-type-4-3df11df52aa6 · https://feedme.design/why-does-ridge-racer-type-4 · https://digitalchumps.com/ridge-racer-type-4-retrospective
- Video: https://www.youtube.com/watch?v=tX2AHTEMTTE · https://www.youtube.com/watch?v=PMZ872rsa90

**Gran Turismo 1–4 menus**
- GT3's race-menu loop, fan-titled "Slipstream", is credited to Daiki Kasho and Isamu Ohira [S]. The GT menus are clean, light grey and white, use car photography, and have a "dealer showroom" feel [M].
- What to take: a **showroom presentation for presets**. Turntable-rotate a 3D preset icon while showing a spec sheet (character, CPU cost, author).
- Video: https://www.youtube.com/watch?v=YAtGV2tZ-Uk · https://www.youtube.com/watch?v=O4gHo0-5VJc

**Jet Set Radio (Dreamcast, 2000) and JSRF (Xbox, 2002)**
- Cel-shaded, with a **built-in graffiti editor** [S]. The cover typography is a graffiti-derived logotype with stencilled secondary type, credited to lead designer **Ryuta Ueda** [S]. Music by Hideki Naganuma [M]. The modern successor, **Bomb Rush Cyberfunk** (Team Reptile, 2023), has menus "as if inspired by lava lamps and old computers" [S].
- What to take:
  - Stencil type for **status labels only**.
  - Let users "tag" their presets: a small user-drawn sticker on the save icon.
  - Avoid full graffiti. It belongs to JSR.
- Sources: https://peoplesgdarchive.org/item/22729/jet-set-radio-future-andnbsp-north-american-xbox-cover-art · https://en.wikipedia.org/wiki/Jet_Set_Radio_Future · https://nintendoeverything.com/review-bomb-rush-cyberfunk-nintendo-switch

**Ape Escape (1999): Soichi Terada's jungle**
- The producers chose Terada after hearing "Sumo Jungle". The soundtrack is frenetic drum & bass, later reissued as *Apes in the Net* [S].
- What to take: playful, bright, toy-like jungle, the counterweight to the PS2's darkness. It is the tonal reference for the **drum machine's** personality.
- Sources: https://daily.redbullmusicacademy.com/2017/10/soichi-terada-interview · https://ra.co/reviews/35954 · https://www.timeextension.com/features/the-making-of-ape-escape-sonys-groundbreaking-platformer-that-unlocked-the-dualshocks-potential · overview: https://www.ujam.com/tutorials/the-forgotten-history-of-drum-bass-in-video-games/

**Vib-Ribbon (1999, NanaOn-Sha, Masaya Matsuura)**
- Simple vector lines on pure black. It was both an artistic choice (Matsuura loved early computer graphics) and a memory constraint, and it is now in the **MoMA collection** [S].
- What to take: **one continuous wireframe line as the waveform and envelope display.** The line *is* the audio. This is a strong, ownable idea for the mono arp synth's scope.
- Sources: https://en.wikipedia.org/wiki/Vib-Ribbon · https://www.moma.org/collection/works/162460 · https://www.timeextension.com/news/2026/10/sony-wasnt-quite-allowing-it-but-we-made-it-happen-vib-ribbon-creative-team-reflect-on-their-sublime-musical-marvel

**PaRappa (1996), Um Jammer Lammy (1999), Bust a Groove (1998), Mad Maestro (2001)**
- Rodney Greenblat's flat paper-cutout characters for PaRappa [S]. Matsuura's "music is everything" philosophy [S]. Bust a Groove and Mad Maestro: rhythm-meter UI and on-beat button prompts [M].
- What to take: **beat-synchronised UI feedback**. Prompts pulse on the downbeat, and a "COOL / GOOD / BAD"-style rating idea could become a humanize or quantize indicator.
- Sources: https://en.wikipedia.org/wiki/Vib-Ribbon · https://techraptor.net/originals/gaming-obscura-vib-ribbon

**Rez (2001)**
- Wireframe level design inspired by **Kandinsky**, plus rave culture and synaesthesia [S].
- What to take: **wireframe and glow as the "inactive" state** of controls. Disabled modules render as wire; enabled ones fill with glass.
- Sources: https://en.wikipedia.org/wiki/Rez_(video_game) · https://newstatesman.com/culture/2017/07/how-tetsuya-mizuguchi-reinvented-video-games-his-love-synaesthesia

**FantaVision (2000)**
- A PS2 launch title built entirely on additive particle fireworks [M]. It is the canonical demonstration of the PS2's fill-rate and additive blending.
- What to take: **additive particle bursts on note-on and trigger**, kept small.

**Frequency (2001) and Amplitude (2003), Harmonix**
- Each instrument is a lane on the face of an octagonal tunnel [M]. No search hits; video verification still needed.
- What to take: the tunnel as a **step-sequencer topology**. Sixteen steps wrap around an octagon, and the camera "flies" along the pattern.

**MGS2 codec, Kingdom Hearts, Silent Hill 2**
- [M] MGS2's codec: green-tinted framed portraits with scanlines and frequency numerals, a strong "radio display" reference. Kingdom Hearts menus: stacked, rounded translucent blue-green panels. Silent Hill 2: grain, fog, sparse type.
- What to take: the codec frequency readout as a **tempo, frequency and cutoff display style**. Silent Hill fog belongs to direction 1's background only.

**SSX and SSX Tricky (EA Canada, 2000–2001)**
- [S] for the basics; little on the UI. [M]: an MC voice (DJ Atomika) and an energetic "boost" UI.
- What to take: little. Low priority.

**Music making on the console: the most important game references**
- ***Music* (1998, Jester and Codemasters, PS1)**: sequel *Music 2000* (Europe), called *MTV Music Generator* in North America (1999). The main screen has **24 channels** (up from 16), and "riffs" are layered on a timeline [S].
  - Lead developer **Tim Wright** (WipEout's CoLD SToRAGE) set the goal: load a riff, play with it, build a song [S].
  - **MTV Music Generator 2** (PS2, 2001) [S]. **Music 3000** supported an optional **USB sampler** [S].
  - Back Market's feature: **"It inspired grime"** [S].
  - Take: **controller-first, block-based arrangement**. The pattern-chain UI of our drum machine should feel like stacking riff blocks, and must be fully keyboard-navigable.
  - Sources: https://timeextension.com/features/the-making-of-music-the-playstation-audio-creation-tool-from-wipeouts-tim-wright · https://backmarket.com/en-us/c/technology/music-2000-game · https://archive.org/stream/music-2000-europe-en-fr-de-es-it/Music2000_Manual_djvu.txt · https://en.audiofanzine.com/dvd-drive/sony/Playstation-2/editorial/articles/instruction/was-the-first-consumer-grade-music-production-software-on-the-playstation.html
  - Video: https://www.youtube.com/watch?v=5-tddsxHZ3g (MTV MG2 preview) · https://www.youtube.com/watch?v=kU1eCU7DD0o (sampled beat on MG2) · https://www.youtube.com/watch?v=SkWum2lnaeY
- **eJay (Dance eJay 1997, Dance eJay 2 1998, Techno eJay 1999, PXD/eJay GmbH)**: **drag-and-drop loop blocks on 8 tracks**, with a Groove Generator and an Effect Studio [S]. Take: the colour-coded loop-family blocks. Sources: https://discmaster.textfiles.com/file/7977/eJay_SC2CD5.iso/eJay/eJayDemo/DANCE2/DANCE2.HLP/DANCE2.pdf · https://www.wikiwand.com/en/articles/EJay

### 3. Y2K desktop, web and media aesthetics

**Kai Krause: Kai's Power Tools, Kai's Power Goo, Bryce, Convolver, Photo Soap (MetaTools, 1993–1999)**
- **"Rooms"**: full-screen, purpose-built environments. Goo's room is only for pushing pixels, and file tasks live in other rooms [S].
  - **Buttons and balls "sleep" and "awaken" only when the cursor comes close**, a behaviour the user can turn off in Style Setup [S].
  - A **reward mechanic** reveals bonus functions as the user goes deeper [S].
  - Complex algorithms are hidden behind playful surfaces [S].
  - Criticism: "interface dictatorship" and long load times for screen elements [S].
  - Bryce's ideas passed to Poser 3 through Phil Clevenger [S].
- What to take: this is **the most relevant non-game reference.**
  - Proximity-wake controls: secondary knobs dim at rest and brighten as the cursor approaches.
  - Rooms are the plugin pages.
  - Spherical preview "lenses" and Goo's direct manipulation for **wavetable and sample warping**.
  - Do **not** take: hiding core functions, or full-screen takeover.
- Sources: https://www.mprove.de/script/99/kai/ · https://mprove.de/script/99/kai/2Software.html · https://handwiki.org/wiki/Software:Kai%27s_Power_Tools · https://www.macworld.com/article/159150/kpt-3.html · https://www.atpm.com/5.04/kpt.shtml · https://mjtsai.com/blog/2015/11/24/an-ode-to-kais-power-goo

**Winamp, Sonique and K-Jöfol skins**
- **Sonique** (Mediascience, sold to Lycos in 1999 for US$38.8M): **windowless, irregular skins and fully animated menu systems**, a 20-band EQ, and new visualisations [S]. Winamp: compact, fast and practical, made personal by skins [S]. K-Jöfol is mentioned alongside Sonique as a "free-form" skin player [S].
- What to take:
  - The non-rectangular silhouette *inside* the rectangular plugin window. A plugin must stay rectangular, so put the shaped "device" on a void background.
  - Animated menu morphs.
  - The **EQ and visualiser as a hero element**.
- Sources: https://en.wikipedia.org/wiki/Sonique_(media_player) · https://skinbase.org/news/sonique-beautiful-mp3-player-almost-changed-everything · https://danq.me/2022/12/07/old-music-player-design/ · https://multimedia.cx/eggs/winamp-and-the-march-of-gui/

**Mac OS X Aqua (shown January 2000) and iMac G3**
- Jobs at Macworld 2000: a design goal was that "when you saw it you wanted to lick it". Reports differ on the exact wording [S].
- What to take: **gel and candy translucency** for *buttons only*, with a strong top highlight and a coloured inner glow. iMac G3 translucent plastic (Bondi Blue 1998, the fruit colours 1999 [M]) is the material reference for direction 3's housings.
- Sources: https://en.wikipedia.org/wiki/Aqua_(user_interface) · https://www.salon.com/2000/01/26/aqua/ · https://babich.biz/blog/apple-aqua-exploring-the-legacy-of-macos-x-user-interface/ · https://pxlnv.com/linklog/aqua-turns-20/

**Flash-era sites**
- **2Advanced Studios v3 "Expansions" (2001)**: FWA "Most influential Flash site of the decade". It was rebuilt in 2024 with **Rive and React** at https://v3.2advanced.com [S]. Founded November 1999 by Eric Jordan, Tony Novak and John Carrol [S].
- What to take:
  - Sci-fi HUD framing: thin rules, corner brackets, tiny all-caps labels, loading-bar choreography.
  - **The Rive rebuild proves this motion language can run live and vector-sharp today.** Rive's runtime is a candidate for animated overlays.
- Sources: https://v3.2advanced.com · https://www.webdesignmuseum.org/exhibitions/2advanced-studios-v2-2001 · https://webdesignerdepot.com/blast-from-the-past-2advanced-com/ · https://flashmuseum.org/2advanced-studios-v1/
- Also [M]: Praystation (Joshua Davis, generative and code-driven), Kaliber10000 (k10k, pixel fonts and dense iconography), Hi-Res! (cinematic, dark and textural). The Web Design Museum's "futuristic / techno, 2000–2001, Flash" filter is a good mood source: https://www.webdesignmuseum.org/gallery/style-collage-or-futuristic/year-2000-or-2001/tag-flash

**Nokia and Sony Ericsson phones [M]**
- Monochrome green-backlit 84×48 LCDs (Nokia 3310, 2000). Early colour phones (Sony Ericsson T68i, 2002) used small isometric icons.
- What to take: the **pixel-font secondary display** (the "VMU / phone LCD" strip on every plugin).

**CARI taxonomy (Consumer Aesthetics Research Institute)**
- Co-founded by Evan Collins, Sofi Xian and Froyo Tam. Collins coined "Y2K aesthetic" [S]. Fan wikis date Y2K Futurism to about 1997–2004 and Frutiger Aero to about 2004/5–2013 [S]. "Cybercore" is used inconsistently [S].
- Where we sit: see the thesis. Y2K Futurism core plus Gen X Soft Club softness [M: CARI term, verify at cari.institute]. Stay out of Frutiger Aero (grass, bubbles, bokeh), Vaporwave (statues, irony), and McBling (pink rhinestones).
- Sources: https://cari.institute/aesthetics/y2k-aesthetic · https://en.wikipedia.org/wiki/Consumer_Aesthetics_Research_Institute · https://en.wikipedia.org/wiki/Y2K_aesthetic · https://www.itsnicethat.com/features/the-consumer-aesthetics-research-institute-spotlight-creative-industry-121125

### 4. Music software and hardware of the era

**ReBirth RB-338 (Propellerhead, 1997)**
- Photorealistic 303/303/808/909 on one screen [S]. **Mods** let users replace graphics and samples, and Propellerhead released a mod tool with v2.0 [S].
- **OpenRB-338**, an open-source reimplementation, plays .rbm mods [S]. A free clone was reported in November 2026 [S].
- What to take: **a mod and skin system as a community feature** (ReBirth had one, and Winamp lived on one). Our save-icon presets plus user "tags" are a lighter version.
- Sources: https://en.wikipedia.org/wiki/ReBirth_RB-338 · https://www.soundonsound.com/reviews/steinbergpropellerheads-rebirth-rb338-techno-micro-composer · https://www.synthtopia.com/?p=155927 · https://sonicstate.com/news/2026/11/09/free-rebirth-rb-338-clone-released-/ · https://www.peff.com/journal/page/33

**Reason 1.0 (22 November 2000)**
- A rack metaphor. Tab **flips the rack** to show the patch cables, and the hardware interface is "riveted" at the top [S].
- What to take: a **front/back flip** as a real 3D rotation. The front holds the performance controls and the back holds routing and modulation. It is very PS2-cube-friendly.
- Source: https://www.soundonsound.com/reviews/propellerhead-software-reason

**Fruity Loops 1.0 (December 1997 / 1998, Didier Dambrin)**
- A 4-channel MIDI drum step sequencer. Dambrin, a game developer, made it after trying **Hammerhead and ReBirth**. It was renamed FL Studio with v4 in 2003 [S].
- What to take: **FL's own heritage is the step sequencer.** The drum machine should honour the channel-rack grid but render it as lit 3D cells. That is a direct nod FL users will feel.
- Sources: https://en.wikipedia.org/wiki/FL_Studio · https://daily.redbullmusicacademy.com/2015/05/fruity-loops-feature · https://reverb.com/news/how-generations-of-beatmakers-evolved-with-fruity-loops-and-fl-studio · https://www.image-line.com/company-history

**Hammerhead Rhythm Station (Bram Bos, 1997/98, freeware)**
- 808/909-style. **It shipped with breaks for "hip-hop, jungle, and every genre between"** [S]. It got an iOS remake in 2021 [S].
- What to take: the sample-pack culture, and a compact one-screen layout.
- Sources: https://cdm.link/2021/06/hammerhead-for-ios-brings-back-a-90s-drum-computer-legend-for-a-new-generation/ · https://musictech.net/news/bram-bos-free-hammerhead-rhythm-station-update-after-24-years/

**Korg Electribe (1999–2000): EA-1, ER-1, ES-1**
- The EA-1 has a **silver** finish [S]. A blue finish could not be confirmed for the first generation [S]. [M]: dense knob rows, step keys with red LEDs, a playful printed graphic language.
- What to take: **brushed silver plus one accent colour, and LED step keys**. The physical feel of our drum machine's step row.
- Sources: https://www.perfectcircuit.com/signal/korg-electribe-history · https://www.soundonsound.com/reviews/korg-electribe-ea1-er1

**Not verified this session [M], noted for the designer**
- Yamaha SU700 (1998): silver, a ribbon controller and big sliders.
- Yamaha RM1x (1999): large LCD sequencer.
- Roland MC-303 (1996) and MC-505 (1998) Grooveboxes: grey bodies, coloured knobs, LCD, and a D-Beam on the 505.
- Akai MPC2000XL (1999): grey-green STN LCD, *the* jungle sampler screen.
- Akai S-series samplers: tiny LCDs.
- Native Instruments early UIs: Pro-52 (2000) as a Prophet-5 replica; Battery 1 (2001) as a cell grid; Reaktor 3 as a module panel.
- Steinberg LM-4 (Cubase VST drum module).
- Sonic Foundry ACID (1998): loop stretching in coloured blocks.
- What to take: **the LCD as the information layer** (see the palette and type sections). Real era hardware put the precise information on small, low-resolution screens and the *feel* on the knobs. Do the same.

### 5. Rendering techniques
See section (e). Key references:
- PS1 artifact list and shader recipe: https://pikuma.com/blog/how-to-make-ps1-graphics · https://github.com/MenacingMecha/godot-psx-style-demo
- PS2 interlace and field rendering: https://emulation.gametechwiki.com/index.php/Deinterlacing · https://www.libretro.com/?p=50686
- Bloom as a chain of framebuffer copies (GameCube example): https://www.ppsspp.org/docs/troubleshooting/the-bloom-problem
- Retro 3D art FAQ with texture budgets (PS2 typically 128×128 to 256×256): https://polycount.com/discussion/226167/retro-3d-art-faq-everything-you-need-to-know-to-create-ps1-n64-dreamcast-etc-3d-art
- Interactive ray-traced plugin GUIs (AES paper): https://www.aes.org/e-lib/browse.cfm?elib=16076

### 6. Contemporary revival, 2020–2026, and the competitive gap
- **GuyEngine V2** (UltimaDSP, VST/AU): "streamlined, **PS2 inspired UI** (artwork by iirien)" [S]. It is the closest existing competitor on the visual brief. Its release date and screenshots were not verified. **Check it before committing to a direction.** https://ultimadsp.gumroad.com/l/guyengine-v2
- **Initial Audio "Y2K Club"** for SourceLab: four neon and chrome skins [S]. It is a skin, not a system. https://initialaudio.com/y2k-club-early-2000s-presets-sourcelab/
- **PS1 SPU plugins**:
  - BodbDearg's open-source **PsxSampler and PsxReverb** (VST3, all PsyQ reverb types) [S].
  - SoundFontGuy's **SPS** [S].
  - Impact Soundworks **GameVerb** (SNES, N64 and PS1 reverbs, all 9 PS1 algorithms) [S].
  - foo_dsp_prvb notes that the SPU2 reverb is almost identical to the PS1's [S].
  - These prove demand for console *sound*, but their UIs are utilitarian.
  - Links: https://github.com/BodbDearg/PlayStation1Vsts/releases/tag/releases%2F1.3.0 · https://soundfontguy.itch.io/sps · https://impactsoundworks.com/product/gameverb/ · https://wiki.pcsx2.net/PCSX2_Documentation/Reverb_Engine
- **Inphonik RYM2612** (Mega Drive FM): a straightforward 2D layout, and users call the UI awkward [S]. Console *emulation* plugins do not invest in console-*OS* visual language. **This is the open space.** https://www.musicradar.com/news/sega-mega-drives-iconic-fm-synth-soundchip-is-now-available-as-a-vst-plugin
- **Baby Audio**: famous for simple, opinionated UIs and "more Mac than PC". They spend a great deal of time on UI [S]. The benchmark for *clarity* in a stylised plugin. https://musicradar.com/news/baby-audio-interview · https://babyaud.io/blog/the-mac-vs-pc-of-plugin-design
- **Plugin design trend piece**: "people wanting everything fast". Clients still send Teenage Engineering OP-1 photos as the brief for "modern" [S]. https://www.musicradar.com/music-tech/plugins/the-biggest-driver-right-now-is-people-wanting-everything-fast-predicting-the-future-evolution-of-plugin-design
- **MusicTech tutorial "PlayStation 2 era house beat with free plugins"** [S]. The *sound* is a recognised micro-genre that people are searching for. https://musictech.com/tutorials/y2k-video-game-sound-in-10-minutes-with-free-plugins/
- **Games**:
  - Bomb Rush Cyberfunk (2023), the JSR successor [S].
  - Indie retro 3D is mostly PS1 horror, with developers just starting to aim at PS2 [S]. PC Gamer quotes Toni Kortelahti: a game sold as "PS1 styled" should carry the hardware's real quirks, not a pixelation filter [S].
  - https://www.pcgamer.com/inside-the-next-indie-frontier-ps1-style-horror-games · https://pcgamer.com/retro-horror-games-are-preparing-to-go-beyond-the-ps1 · https://news.xbox.com/en-us/2025/09/12/lo-fi-visuals-in-modern-horror-gaming/
- **Not verified, check before relying on [M]**: Sugar Bytes (bold colourful flat, not Y2K), Glitchmachines (dark sci-fi), Cymatics (marketing-led Y2K-adjacent), and Plogue chipsynth (accurate hardware renders of chip consoles). Revival mood sources: Are.na channels for "Y2K", "PS2 UI" and "Gen X Soft Club", and Chris Lemke's Y2K Futurism reference page (https://chrislemke.github.io/website_designs/examples/Y2K_Futurism.html).

**Where the space is open:** nobody found ships a *coherent console-OS metaphor*: BIOS shell, memory-card presets with 3D icons, controller-style navigation, and UI sound design. Existing work is either emulation with plain UIs or a "Y2K skin". The PS2 lane is barely occupied; the only hit is GuyEngine.

---

## (c) Visual vocabulary

### Materials (one shared library for the family)
| Material | Use | Notes |
|---|---|---|
| **Smoked crystal / glass** (PS2 towers and orbs) | Hero objects, pads, preset icons, mod sources | Fresnel rim and thin bright edge. The interior is mostly dark with a coloured core glow. Never fully opaque. |
| **Translucent coloured polycarbonate** (iMac G3, GameCube, Game Boy Color clear) | Device housings in direction 3, button caps | Visible internal parts (fake "PCB" or "speaker" shapes) under the plastic. |
| **Brushed or bead-blasted aluminium** (Electribe, PS2 slim-era silver) | Knob caps, rails, the "touch" surfaces | Anisotropic highlight. A *soft* sheen, not mirror chrome. |
| **Chrome (sphere-mapped)** | **Max 2 percent of pixels**: logo marks, the single selected item's glint | Sphere-map or matcap, true to the era. Chrome is the spice, not the meal. |
| **Gel / candy (Aqua)** | Toggle buttons and on/off lamps | Hard top highlight, inner colour glow, slight refraction of the label. |
| **LCD** | All precise numeric information | Pixel font, faint unlit "ghost" segments, subtle backlight gradient. |
| **Void** (fog plus particles) | Background of every plugin | Exponential fog to the background colour, sparse drifting motes. |

### Lighting (single rig, family-wide)
- **Key**: cool white-blue, upper-left, about 35° elevation. Matches the PS2 menu's cold key [M].
- **Rim**: coloured by plugin (see accents), from behind and right. It gives every object its plugin identity.
- **Ambient**: very low, tinted by the background colour.
- **Per-preset override**: like `icon.sys`, each preset may define its own three light colours and four corner gradient colours [S], *only inside its icon tile*.
- One global light direction across all pre-rendered filmstrips. Inconsistent light is the number-one tell of cheap retro UI.

### Palette ranges (hex)
Shared "Void" base (all directions):
- Void black `#030409` to `#070A14`
- Deep navy `#0B1430` to `#12204A`
- Fog / mid navy `#1B2B5E` to `#26407F`
- Ice glint `#BFDFFF`, highlight white `#F2F7FF`
- Text primary `#E6EEFF`, text secondary `#8EA3C8`, text disabled `#4A5878`

Era-derived accent families. Each plugin "owns" one, R4 style:
- **PS2 cobalt**: `#2E5BFF` / `#3D7BFF` / `#6FA4FF` (core glow)
- **Xbox acid**: `#9BE200` / `#7CFC00`, dark `#1E4D0F`
- **R4 yellow**: `#F5C400` / `#FFD83A`
- **Dreamcast orange**: `#FF6A13`. **PAL Dreamcast blue**: `#1E5BC6`
- **GameCube indigo**: `#3E2F8C` / `#6A5ACD`
- **Bondi / Aqua**: `#0095B6` (Bondi, commonly cited [M]) / `#3B9CFF` (gel)
- **Jungle / "wavy" (ours)**:
  - deep jungle teal `#0E3B36`
  - liquid mint `#3DFFC5`
  - sodium-lamp amber `#FFB347` (pirate-radio and night-bus warmth)
  - signal red `#FF3B30` (only for record, arm and clip)

LCD palettes:
- **MPC green LCD**: background `#9DB08A` / `#B4C59B`, pixels `#1F2A1C`
- **Blue backlit LCD**: background `#1D4ED8` to `#2B6CF0`, pixels `#DDEBFF`
- **Amber VFD**: background `#120A02`, glyphs `#FFB000` with bloom

Suggested product mapping:
- Drum machine: R4 yellow plus amber LCD (warm, Terada-playful).
- Mono arp: acid green plus Vib-Ribbon line.
- Poly synth: cobalt plus crystal.
- Sampler: Dreamcast orange plus green LCD.

### Typography
| Role | Era face | Licence status | Modern equivalent (licence) |
|---|---|---|---|
| Wordmarks, headers | Eurostile / Microgramma (Novarese) | Commercial (Linotype/Monotype) | **Michroma** (OFL) [S], **Orbitron** (OFL) [S], **Saira** (OFL) [M] |
| TDR-style unicase display | TDR custom WipEout unicase (unreleased) [S] | Not available | **Unica One** (OFL) [M]. Better: **commission a custom unicase display face** for the brand. This is the single biggest anti-pastiche lever. |
| Sci-fi display, sparing use | Xbox dashboard faces (Steve Matteson, custom) [S] | Proprietary | **Zen Dots** (OFL) [S], **Tomorrow** (OFL, Just in Type, 2019) [S] |
| UI labels | PS2 menu: thin, slightly rounded sans [M, not identified] | n/a | **M PLUS 1 / M PLUS Rounded 1c** (OFL, includes kana if ever needed) [M], **Barlow / Barlow Semi Condensed** (OFL, DIN-like) [M] |
| LCD and numeric | Hardware LCD fonts | n/a | **DSEG7 / DSEG14** (OFL, segment) [M], **Silkscreen** (OFL, by Jason Kottke, 1999, era-authentic) [M], **VT323** (OFL) [M] |
| Codec / readouts | MGS2-style monospace | n/a | **IBM Plex Mono** (OFL) or **JetBrains Mono** (OFL) [M] |

Rules:
- At most 3 faces per plugin: display, label and LCD.
- Labels in caps, tracked +6 to +10 percent, size 9–11 px at 100 percent scale.
- Never apply the bevel or chrome effect to labels. Only the logotype gets material treatment.
- Verify every licence file before shipping. Google Fonts faces are generally OFL [S].

### Iconography
- **Pictogram system**: 24-unit grid, 2-unit strokes, 45° and 90° angles only, square terminals. This is the TDR *discipline* without TDR motifs.
- **Save-icon objects**: low-poly (200–800 triangles), one 64×64 or 128×128 texture, vertex colour allowed. Three animation states (browse, copy, delete) as in PS2 icons [S].
- **Product codes**: a fictional console part-number scheme (for example `SLPM-`-style catalogue codes [M]) on every plugin's corner, like the code printed on a disc. It is world-building for free.
- **Error states**: a blue "CORRUPTED DATA" box for missing samples [S], and a "memory card full" metaphor for preset banks.

### Motion and transition rules
1. **Depth, not slide.** Pages move along Z through the fog. The outgoing page recedes and fades into the fog colour over 450–650 ms, ease-in-out (cubic). This is the PS2 browser grammar [M].
2. **Everything idles, nothing loops visibly.**
   - Hero objects rotate one turn every 8–14 s.
   - Particles drift at 2–6 px/s.
   - Idle loops sync to host tempo when the transport runs (bars as the period) and free-run when it stops. This follows the PS2 clock-driven orbs [S].
3. **Selection**: scale 1.00 to 1.06 with a spring that overshoots about 8 percent and settles in about 220 ms. A specular **glint sweep** crosses the object in 250 ms, once per selection and never on repeat.
4. **Proximity wake** (KPT [S]): secondary controls rest at 55–65 percent brightness and wake to 100 percent within about 120 px of the cursor, over 150 ms. Always provide a setting to disable it.
5. **Confirm**: a 1-frame white flash on the object, then a bloom pulse that decays over 300 ms. **Cancel**: the object retreats 10 percent in Z and desaturates for 200 ms.
6. **Note and trigger feedback**: small additive particle bursts (FantaVision [M]) capped at about 24 particles, with brightness mapped to velocity.
7. **Parameter interaction is never animated with lag.** Knobs track the mouse 1:1, and only the decoration moves.
8. **Frame rate**: 60 fps UI. An optional "30 / interlaced" authenticity toggle. A reduced-motion mode removes idle rotation, fog drift and particles.
9. **Boot sequence**: at most 1.2 s on first open of a session, skippable by any click, never on every editor reopen. FL users open and close plugin windows constantly.

### UI sound design
- Concept: era system sounds were **long-tailed, reverberant and made from processed sources** (Xbox used NASA recordings [S]; Brian Schmidt filtered thunder, cannon and glockenspiel [S]). PS2 and PS1 used Fujisawa's slow crystalline swells [S].
- Kit:
  - **Cursor move**: a 25–40 ms soft tick. A sine or FM ping at 1.8–3 kHz, random pitch ±3 percent, with a short PS1/PS2 SPU-style reverb tail. Model it with PsxReverb [S].
  - **Confirm**: a two-note rising interval (a fifth), 120 ms, with a glassy FM bell.
  - **Cancel / back**: a falling minor third, darker and filtered.
  - **Page change**: a 300–500 ms filtered whoosh made from a time-stretched breakbeat fragment. This is the jungle signature: a processed Amen ghost, not a synth swoosh.
  - **Error**: a low two-pulse buzz at about 110 Hz.
  - **Boot**: a 1 s crystalline swell plus a sub thump. Keep it optional.
- **The plugin constraint (important).** A VST3/CLAP plugin can only make sound through its own audio output. UI sounds would be recorded and bounced with the music. Rules:
  - **Off by default.**
  - Audible only in standalone builds, or in a "preview" mode while the host transport is stopped.
  - Never mixed into the output while recording.
  - Alternatively, use them only as a demo and marketing asset.
  - Decide this before the sound designer starts.

---

## (d) Three art directions

### Direction 1: "BIOS NOCTURNE" (the system void)
- **Description**: the plugin *is* the PS2 browser at 2 a.m.
  - A near-black navy void with fog and drifting motes.
  - Every control is a smoked-crystal object lit by the cold key light plus the plugin's coloured rim.
  - Drum pads are glass cubes that light from the inside. The step sequencer is a row of small crystal towers whose height is velocity, recalling the boot-screen towers [S].
  - The preset browser is a memory-card grid of rotating 3D save icons.
  - Type is minimal, thin and white. Precise values live in a blue backlit LCD strip.
- **Jungle link**: liquid and atmospheric DnB (Bukem and Good Looking era [M]): night, space, reverb.
- **Refs**: PS2 boot and browser, PS2 clock menu, PSX XMB, Xbox orb and NASA sounds, Rez wireframes, Vib-Ribbon line, FantaVision particles, Silent Hill fog (background only), MGS2 codec readouts.
- **Risks**:
  - Dark-on-dark legibility.
  - Reads as "liminal horror" or vaporwave if the fog takes over.
  - The GPU cost of fog and particles across many instances.
  - Least differentiated from GuyEngine, which also claims PS2. Check it.
  - Cold rather than fun, so it suits the poly synth more than the drum machine.

### Direction 2: "RIFF CONSOLE" (graphic system over hardware)
- **Description**: a fictional 2001 console maker's *product identity* applied to music hardware.
  - Flat, strict TDR-grade graphics: own unicase face, pictograms, product codes and one flood colour per plugin (R4 style [S]) frame chunky pre-rendered 3D controls.
  - Controls are brushed-silver Electribe knobs, LED step keys, gel buttons, and green or amber LCDs carrying all the numbers.
  - The 3D is "product photography": a studio-lit hero render of each module.
  - Arrangement and pattern UI borrow MTV Music Generator's riff blocks and FL's channel-rack grid [S].
  - Presets are still memory-card save files, shown in a GT-style "showroom" with a turntable icon and spec sheet.
- **Jungle link**: the drum machine is the hero, a break-slicing grid where slices are coloured riff blocks. Terada and Ape Escape set the playfulness, and WipEout sets the club-poster confidence.
- **Refs**: WipEout and TDR, R4, GT showroom, MTV Music Generator and Music 2000, eJay blocks, Fruity Loops 1.0 and Hammerhead, Electribe, SU700 and MPC LCDs, ReBirth mods, Reason flip, 2Advanced HUD framing.
- **Risks**:
  - TDR pastiche (katakana, smileys, warning labels). It needs a **real graphic designer** and a custom face.
  - Can drift toward "generic hardware skeuomorph".
  - Flat graphics against 3D renders need careful integration through shared light direction and shared accent.
  - Most work up front (identity system), cheapest at runtime (mostly filmstrips).

### Direction 3: "WET TECH" (Kai Krause meets Dreamcast)
- **Description**: daylight Y2K.
  - Pale sky-to-water gradients with caustics (Dreamcast VMU screens [S]).
  - Translucent candy polycarbonate housings with visible fake internals (iMac G3 and GameCube clear).
  - Gel buttons with Aqua highlights [S].
  - Irregular "windowless" device silhouettes floating in the plugin rect (Sonique [S]).
  - Controls sleep and wake by proximity, and pages are KPT "rooms" [S].
  - "Wavy" is literal: liquid deformation (Goo-style direct manipulation of wavetables and sample start), ripples on note-on, and water as the material of modulation.
- **Jungle link**: playful and sunny jungle (Terada, Ape Escape), and the "liquid" in liquid funk.
- **Refs**: KPT, Goo, Bryce, Sonique and K-Jöfol, Aqua and iMac G3, Dreamcast BIOS and hidden 3D menu, GameCube clear-cube menu, Ape Escape, JSR colour, Bomb Rush Cyberfunk's lava-lamp menus [S].
- **Risks**:
  - Slides into **Frutiger Aero** (2005–2013) and generic "Y2K Instagram".
  - Irregular shapes are hard to make resizable and accessible.
  - KPT's "interface dictatorship" critique [S]: discoverability suffers.
  - Bright backgrounds clash with FL Studio's dark workspace.
  - The furthest from the user's literal "PS2" request.

**Recommendation (for discussion)**: use **direction 2 as the system** (identity, layout, LCD information layer, riff-block UX) with **direction 1's void and crystal as the shared shell**: background, preset memory card and boot. Use direction 3's ideas *selectively*: proximity wake, gel toggles, and liquid deformation for sample and wavetable editing. Each plugin then owns one accent and one hero material:
- Drum machine: silver and yellow (Terada and Electribe).
- Mono arp: acid line (Vib-Ribbon).
- Poly synth: crystal and cobalt (PS2).
- Sampler: orange and green LCD (Dreamcast and MPC).

---

## (e) Technical rendering notes for a plugin UI

**Which artifacts read as which console**
| Artifact | Reads as | Use? |
|---|---|---|
| Affine texture warping, vertex snapping or jitter, no texture filtering, no Z-buffer sorting glitches, 15-bit dithering at 320×240 [S] | **PS1** | Avoid in the main UI. Fine in a hidden "PS1 mode". |
| Bilinear-filtered textures, Gouraud shading, **heavy alpha-blended particles**, fog, 640×448 **interlaced field rendering** blended by the CRT [S], 16-bit framebuffer banding and dither, full-screen blur or bloom passes [M], sphere-mapped chrome, low-res textures (128–256 px) [S] | **PS2** | **Yes**, carefully. |
| Very clean 640×480 progressive VGA, saturated bright colours, clean translucency (PowerVR) [M] | **Dreamcast** | Direction 3. |
| EFB-copy bloom [S], indirect-texture heat haze, indigo palettes [M] | **GameCube** | Accents only. |
| Per-pixel bump and specular "shiny plastic", glow [M] | **Original Xbox** | Accents only. |

**Pipeline**
1. **Pre-rendered filmstrips for all controls** (the reliability layer).
   - Model in Blender. Render with **one shared studio rig** that matches the lighting spec, plus a custom low-key HDRI.
   - Knobs: 128 frames. Buttons: 4–6 states (off, hover, on, on-hover, disabled, pressed).
   - Render at 1×, 2× and 3× (HiDPI). Export PNG or WebP strips.
   - Render **glint and specular as separate additive passes** so motion code can sweep them.
   - KnobMan suits 2D-ish knobs; Blender suits true 3D.
   - Filmstrips are deterministic, cheap on CPU and readable at every scale.
2. **Real-time layer, small and optional.** The background void, fog, particles, the rotating preset icons and the crystal step towers run on a GPU canvas.
   - Options: JUCE `OpenGLContext` (OpenGL is deprecated on macOS; plan a Metal path or use an abstraction such as bgfx), or Visage, the open-source GUI library from Vital's author [M].
   - Alternatively, a WebView UI (JUCE 8 WebView; CLAP and VST3 hosts are fine) with WebGL and **Rive** for vector motion. 2Advanced's 2024 rebuild uses Rive [S].
   - Provide a **static fallback image** whenever the GPU path fails.
3. **PS2-authentic post stack, on the 3D layer only, never on text**:
   - Render the 3D at 50–75 percent resolution, then upscale bilinearly. The soft PS2 look.
   - Quantise to RGB555 or RGB565 with **4×4 Bayer ordered dither**. This gives the era signature *and* removes banding in the dark navy gradients.
   - Exponential fog to the background colour, density 0.035–0.06 per unit.
   - Bloom: brightness threshold, 2–3 downsampled blur passes, additive at 0.3–0.6.
   - "PS2 smear": frame-feedback persistence of 0.6–0.8 on **particles only**.
   - Optional "interlace" toggle: alternate-line brightness offset at about 3 percent per field, at 60 Hz. Off by default.
   - Chrome via **sphere-map or matcap**, the era-correct technique.
4. **Text and LCDs are rendered last, crisp, at native resolution.** Use vector text, or pixel fonts snapped to integer scales (100, 200 and 300 percent) so pixels stay square.
5. **Performance in FL Studio**:
   - Users run many instances.
   - Throttle idle animation to 30 fps when not interacting, pause rendering when the window is hidden or minimised, and share textures and atlases across instances in-process.
   - Target less than 1 percent of a CPU core per open editor at idle. Keep the GPU path off the audio thread entirely.
   - Never allocate in paint.
6. **Scaling**: support 75–200 percent window scaling. Design on a 4 px grid at 100 percent. FL wraps plugin windows, so test inside FL's wrapper for focus and keyboard handling.
7. **Procedural preset icons**:
   - Generate each preset's icon from its parameters: crystal shape from oscillator mix, colour from filter cutoff, spin rate from LFO rate.
   - Save the four-corner gradient and light colours with the preset, mirroring `icon.sys` [S].
   - Cache rendered thumbnails.
8. **Accessibility**: text contrast of at least 4.5:1 against the *actual* fogged background (test with fog at maximum). Reduced-motion mode. Keyboard and controller navigation (XMB cross-axis) throughout the browser.

---

## (f) Pitfalls: what makes Y2K look cheap or clichéd

1. **Chrome on everything.** Era UIs used chrome as a highlight, not a material for whole panels. Without hierarchy, chrome turns into noise.
2. **Lens flares, butterflies, tribal and barbed-wire motifs, bubble fonts.** This is the "Canva Y2K template" kit (Creative Market and similar [S]). It reads as a costume.
3. **Fake Japanese and TDR clichés** (random katakana, smileys, warning labels, "SUPERDELUX™"). TDR's power was *system consistency*, not motifs [S].
4. **Mixing eras.** PS1 vertex wobble with PS2 bloom, Frutiger Aero grass and bubbles, and vaporwave statues together read as "internet nostalgia soup". Pick PS2 / Y2K Futurism and hold the line.
5. **Inconsistent lighting across sprites.** Every pre-render needs one rig. Mixed light directions are the most common amateur tell.
6. **Post-processing over text.** CRT, scanline, bloom or dither effects on labels destroy legibility. Effects belong to the 3D layer only.
7. **Raster art that blurs at HiDPI.** Low-res is a *stylistic choice for the 3D layer*, not for the UI chrome.
8. **Dark navy on black with no contrast plan.** The PS2 look depends on darkness, and accessibility fails silently.
9. **Idle animations that cost CPU or GPU.** With 20 instances in an FL project, the "alive" UI becomes the reason people uninstall.
10. **Animation lag on parameters.** Era transitions were slow, but parameter feedback must be instant.
11. **UI sounds leaking into renders** (see the sound section). Ship them off by default.
12. **Over-literal console cosplay** (PS2 logo shapes, controller-button glyphs ✕○△□, Sony or Xbox trade dress). It risks trademark trouble and makes the plugins feel like fan art. **Invent the console.** Reference the grammar, never the marks.
13. **Horror drift.** Fog plus dark plus slow ambience equals "liminal / analog horror", which is a crowded 2020s genre [S]. Counter it with warm accents (amber, yellow), playful particles and Terada-style bounce.
14. **Novelty over usability** (the KPT critique [S]). Hidden functions, irregular hit areas and full-screen takeovers frustrate producers mid-session. Core controls must always be visible and labelled.

---

### Open questions and next research steps
- **Check GuyEngine V2's actual UI** (the only known "PS2-inspired" plugin) and look for others. The search budget ran out before this could be done.
- Verify the [M] items against the linked videos: PS2 menu font, Dreamcast swirl colours, Xbox 360 blades date, the Yamaha and Roland hardware finishes, and CARI's "Gen X Soft Club" definition.
- Not covered: PS2 Network Access Disc and HDD Utility UI, Frequency and Amplitude visuals, Kingdom Hearts menu specifics, k10k, Praystation and Hi-Res! captures.
- Fetching was blocked for scanlines.substack.com, creativebloq.com and killscreen.com. Allowing them would deepen the PS2 aesthetic essay and the PlayStation startup-design article.
