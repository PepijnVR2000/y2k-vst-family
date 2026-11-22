# 02 — Sound Palette: Y2K / PS-era "wavy" jungle, breakbeat & DnB

Research brief for a VST3/CLAP family (drum computer, mono arp synth, poly synth, sampler/ROMpler) aimed at FL Studio users.

> **Method and confidence.** Built from web searches (standard + extended). Full-page fetches were blocked by the session's network policy (psx-spx.consoledev.net, problemkaputt.de, wiki.pcsx2.net, wikipedia.org, simplesoundbank.com could not be opened), and the session's web-search budget ran out before the tape wow/flutter query. Claims that come from sources are marked with **[S#]** (see section f). Claims marked **[K]** come from general domain knowledge and should be checked against primary docs (mainly psx-spx and emulator source) before they are locked into DSP specs.

---

## (a) Sonic thesis

The target sound is **1990s sampler culture heard through a 2020s nostalgia lens**. On one side is the grit and motion of 1992–2002 jungle/DnB: breakbeats pitched up through 12/16-bit samplers (not time-stretched), chopped and re-sequenced into rolls and edits, with aliasing, crunchy converters and Akai "cyclic" time-stretch warble left in on purpose. Under that sit sine or Reese basses, hoover/rave stabs, and the lush "intelligent" layer of Juno/ROMpler pads, DX/Rhodes electric pianos, strings and choirs washed in reverb. On the other side is the console/Y2K patina: the dark, low-rate, slightly metallic **PS1/PS2 SPU reverb**, ADPCM-compressed samples with Gaussian-interpolated pitch, and the glossy supersaw/M1-organ/eurodance palette of 1997–2002. **"Wavy"** is the glue between them. It is not a filter preset but **constant slow movement**: pitch wobble (tape wow, VHS drift, chorus/BBD modulation, detuned unison), spectral softening (low sample rates, lowpass), long modulated reverb/delay tails, and vocal chops pitched and smeared until they turn into texture. The revival (Sewerslvt, Nia Archives, PinkPantheress, Tim Reaper/Dwarde, Coco Bryce, Djrum) sets this ultra-fast, edited breakwork against dreamy, melancholic, slightly lo-fi harmony. Our DSP should make **"degradation + motion + space"** first-class parameters on every instrument, not an afterthought FX rack.

---

## (b) Genre / era map with key listening

Years are release years as best known. "Listen for" says what the DSP has to reproduce.

### 1. Hardcore / rave → darkcore (1990–1993)
| Artist – Title – Year | Listen for |
|---|---|
| Second Phase – *Mentasm* – 1991 | The "hoover"/Mentasm: the Alpha Juno "What The" patch, sampled into a Casio FZ-1 and sequenced **[S14][S15]** |
| Joey Beltram – *Energy Flash* – 1990 | Minimal rave stabs, acid-ish movement |
| The Prodigy – *Charly* – 1991 | Pitched-up breaks, piano stabs, cartoon vocal sample |
| Rufige Kru (Goldie) – *Terminator* – 1992 | Often cited as an early showcase of **time-stretched/phased breaks** **[K]** |
| 4hero – *Mr Kirk's Nightmare* – 1990 | Dark sub, stretched speech, early break chopping |
| Origin Unknown – *Valley of the Shadows* – 1993 | Pitched, stretched vocal ("long dark tunnel"), droning sub, break rolls **[K]** |
| Doc Scott / Foul Play / Omni Trio (*Renegade Snares*, 1993; Foul Play remix 1994) | Snare rolls, piano/strings over darkcore breaks |

### 2. Jungle (1993–1996)
| Artist – Title – Year | Listen for |
|---|---|
| Kevin Saunderson (as Reese) – *Just Want Another Chance* – 1988 | The **Reese** bass source: Casio CZ phase distortion (CZ-1000 vs CZ-5000 disputed) **[S3][S4]** |
| Renegade (Ray Keith) – *Terrorist* – 1994 | Built on a sample of the Reese bass **[S5]** |
| Shy FX & UK Apache – *Original Nuttah* – 1994 | Ragga vocals, Amen edits, 808-style sub |
| M-Beat ft. General Levy – *Incredible* – 1994 | Ragga jungle, rolling Amen, sub drops |
| Goldie pres. Metalheadz – *Inner City Life* – 1994 | "Timestretched soul", strings and vocals over hard breaks; Rob Playford programming **[S22][S23]** |
| Goldie – *Timeless* – 1995 | E-mu Vintage Keys strings on 3 MIDI channels, desk distortion, Notator limits **[S23]** |
| DJ Trace / Dom & Roland | The **Tramen** break (Amen + other material, metallic rides) **[S20]** |
| Remarc – *R.I.P.* – 1994 | Extreme Amen chopping, ragga chops, re-triggered snares |
| Dillinja – *The Angels Fell* – 1995 | Huge pitched sub-bass, Reese-ish mid bass |
| Krome & Time – *The Slammer* – 1993 | Hardcore-to-jungle transition, chipmunk vocals |

### 3. Intelligent / atmospheric / jazzy (1993–1998)
| Artist – Title – Year | Listen for |
|---|---|
| LTJ Bukem – *Atmospherical Jubilancy* (dub 1993), *Music* (1993), *Horizons* (1995) | Lightly delayed **Rhodes** chords, soaring strings, swooping pads, pan-pipe samples, ~160 BPM **[S24]** |
| Good Looking / Looking Good roster (Blame, PFM, Seba) | Smooth time-stretched breaks, flute and pad washes |
| Photek – *The Hidden Camera* (1996), *Ni Ten Ichi Ryu* (1997) | Surgical edits, dry ride/snare articulation, near-silence as dynamics |
| Source Direct – *Stonekiller* / *Call & Response* (c. 1996–97) | Dark, filtered, cinematic; breaks at microscopic edit resolution |
| Adam F – *Circles* – 1995 | Rhodes/jazz chords, soft Reese; sampled in PinkPantheress's *Break It Off* (2021) **[S26]** |
| Alex Reece – *Pulp Fiction* – 1995 | The "Pulp Fiction" two-step break: minimalist, swung |
| Roni Size / Reprazent – *Brown Paper Bag* – 1997 | Upright double-bass samples, live-feel breaks, jazz |

### 4. Drill 'n' bass / IDM (1995–2005)
| Artist – Title – Year | Listen for |
|---|---|
| Squarepusher – *Hard Normal Daddy* (1997); *Come On My Selector* (1997) | Hyper-edited breaks, fretless/jazz bass, 32nd/64th-note drill rolls |
| Aphex Twin – *Girl/Boy Song* (1996); *Vordhosbn* (2001) | Breaks chopped below single-hit length, sweet melodies on top **[S27]** |
| µ-Ziq – *Lunatic Harness* – 1997 | Melodic drill, toy-like synth melodies |
| Venetian Snares (later, 2000s) – Amen edits | Breaks sliced and **resampled repeatedly** (reportedly in Renoise), odd meters **[S27][S28]** |
| Bogdan Raczynski (late 1990s) | Cute melodies + savage break edits |

### 5. Techstep / neurofunk (1996–2000)
| Artist – Title – Year | Listen for |
|---|---|
| Ed Rush & Optical – *Wormhole* – 1998 | Seen as the start of techstep/neurofunk; tense, distorted, moving bass **[S29]**. E4 Z-plane filters reportedly used (unverified) **[S30]** |
| Bad Company – *The Nine* – 1998 | Distorted Reese, two-step breaks, metallic FX |
| Trace / Nico / Dom & Roland | Tramen, dark reese, sci-fi FX |

### 6. UK garage / 2-step (1997–2002)
| Artist – Title – Year | Listen for |
|---|---|
| Robin S – *Show Me Love* (StoneBridge mix) – 1993 | **Korg M1 "Organ 2"** bass, the template for garage organ bass **[S16]** |
| Artful Dodger ft. Craig David – *Re-Rewind* – 1999 | Swung 2-step, chopped vocals, organ/bass stabs **[S31]** |
| Sweet Female Attitude – *Flowers* (Sunship mix) – 2000 | Organ, vocal warmth, swung rhythm **[S31]**. Sampled by PinkPantheress in *Pain* (2021) **[K]** |
| MJ Cole – *Sincere* – 1998 | Jazzy chords, pitched/clipped vocal chops |
| (general) | Late (swung) 16ths, broken kick on steps 1 and 11, 2nd/4th kicks removed; organ doubling bass; sine sub 2 octaves down **[S31][S32]** |

### 7. Y2K trance / eurodance (1997–2002)
| Artist – Title – Year | Listen for |
|---|---|
| Darude – *Sandstorm* – 1999 | JP-8080 **supersaw** **[S17]** |
| ATB – *9 PM (Till I Come)* – 1998 | Gated supersaw/pluck, guitar-like lead |
| Alice Deejay – *Better Off Alone* – 1999 | Supersaw pluck, sidechain-ish pump, vocal |
| Eiffel 65 – *Blue* – 1999 | Vocoder/autotune, eurodance piano/bass |
| (general) | JP-8000/8080 supersaw, Access Virus (VA; later "Hypersaw" on TI), Nord Lead, ROMpler (JV-1080/Triton) pads and plucks **[S17][S18]** |

### 8. Console / game soundtracks (1995–2002), central to the "PS2-core" angle
| Composer – Game – Year | Listen for |
|---|---|
| CoLD SToRAGE (Tim Wright) – *Wipeout* (1995), *Wipeout 2097* (1996) | Rave/techno/breaks in a PlayStation game, alongside licensed Leftfield/Chemical Brothers/Orbital; ex-Amiga demoscene **[S33]** |
| Soichi Terada – *Ape Escape* (1999) | Jungle/DnB in a PS1 game. The director was "really into bass music" and felt jungle suited the pace **[S34]** |
| Hideki Naganuma – *Jet Set Radio* (Dreamcast, 2000), *JSR Future* (2002) | Breakbeat, elastic basslines, voices cut and rearranged until nonsensical **[S35]** |
| (general) | Menu "blips", glassy FM/PCM bells, sampled choirs through SPU reverb, 22–32 kHz sample sets |

### 9. 2020s revival: "wavy", dreamy and new-gen jungle
| Artist – Release – Year | Listen for |
|---|---|
| Sewerslvt – *Draining Love Story* (album) – c. 2020 | "Dreamy atmospheric jungle/breakcore": lush pads, very fast chopped Amens, sad melodies **[S36]** |
| Nia Archives – *Sorrow* (2022), *Silence Is Loud* (2024) | Emotional jungle, soul vocals, Amen and Think breaks **[S37]** |
| PinkPantheress – *Break It Off*, *Pain* (2021) | Pop vocals over sampled DnB/UKG; "new nostalgic" **[S26][S38]** |
| Tim Reaper, Dwarde, Coco Bryce, Kloke, FFF | Lush but hard 1993–95-style jungle and breakbeat hardcore **[S39]** |
| Sully; Djrum (*Portrait With Firewood*, 2018) | Garage/jungle hybrids, cinematic sampling |
| [IVY], digicore/hyperpop crossovers | Hyperpop aesthetics over DnB **[S40]** |
| "Y2K jungle" / low-poly breaks playlists | Explicitly "reminiscent of the video game soundtracks of the same era" **[S41]** |

**What "wavy" means sonically (working definition for the DSP team):**
1. **Pitch instability.** Slow wow (≈0.2–2 Hz, a few cents to ~±30 cents), faster flutter (≈4–15 Hz, small depth), random drift. Applied to pads, keys and whole mixes ("VHS tape") **[K]**.
2. **Chorus/ensemble.** Juno-style BBD chorus (I / II / I+II) and multi-voice detune (supersaw, Reese) **[S19]**.
3. **Soft-focus spectrum.** Low sample rate (22 kHz SPU reverb, 26 kHz SP-1200, ~32 kHz game sample sets), gentle lowpass, tape HF loss, hiss **[S1][S8][K]**.
4. **Space.** Long, dark, slightly grainy reverbs (PS1 "Hall/Space Echo"), ping-pong and tape delays, reverse-reverb swells.
5. **Detuned keys.** DX7 E.PIANO 1 / Rhodes with chorus and wow, slightly out of tune with the pads.
6. **Vocal chops.** Pitched up or down via resampling (formant shift), stretched with cyclic/granular artifacts, washed in reverb.
7. **Sidechain-free breathing.** Pads ducking only through arrangement and filter movement rather than modern pumping (an aesthetic choice, not a rule).

---

## (c) Per-instrument sound specification

### C1. Drum computer ("break machine")

**Design principle:** a jungle drum computer is a **break sampler + slice sequencer** first and an 808/909-style kit second. The difference from standard 808/909 clones is that the main unit of sound is a *slice of a performed break* with pitch, envelope and degradation per slice.

**Must-have sounds / content**
- **Break library** (legally clean; see section e) covering the canonical feels: Amen-style (ride-led, ghosted snare, 4-bar with crash), Think-style (tight, "yeah-woo" feel, 2nd most sampled) **[S12]**, Funky Drummer-style (Stubblefield ghost notes) **[S12]**, Apache-style (bongo/percussion-heavy) **[S12]**, Hot Pants-style (Bobby Byrd) **[S11][S12]**, Soul Pride, Sesame Street, Tramen-style composite (Amen + "Tighten Up" live break + metallic rides) **[S20]**, Pulp Fiction two-step, plus Impeach the President, Synthetic Substitution, Skull Snaps (*It's a New Day*), Sweet Pea **[S12][S13]**.
- **One-shot kit layer:** 808-style sine sub-kick and long boom (for the sub layer under breaks), 909 hats/rides, rave/ragga FX (air horn, rewinds, gunshot zaps), reverse cymbals, sub drops, "rewind" spinbacks.
- **Ghost-note pool:** quiet snare drags and flams for round-robin.
- **Console percussion set:** SPU-style ADPCM kit (crunchy 22/32 kHz hits).

**Core features (beyond 808/909 clones)**
1. **Slice engine:** transient-detect slicing (ReCycle-style **[S21]**), grid slicing (8/16/32), manual markers, snap-to-zero-crossing, "chop to grid" that forces slice starts onto steps.
2. **Per-slice parameters:** pitch (semitones and cents), reverse, start offset, length/gate, amp envelope (attack/decay/hold, fast "choke"), filter, pan, sample-rate/bit-depth, timestretch mode, send levels.
3. **Pitch by resampling (the classic method)**, not time-stretch, as the default. "Fit to tempo by pitch" calculator: the break plays at project BPM by changing playback rate (e.g. 33⅓→45 rpm ≈ +5.2 st; a tutorial used +5 st +33 cents to fit a bar) **[S10]**. A selectable alternative is **Akai-cyclic stretch** (see section d).
4. **Rolls and ratchets:** per-step ratchet 2/3/4/6/8 with velocity ramp (up or down) and pitch ramp (rising snare rolls), plus drill mode (1/32–1/128) **[S27]**.
5. **Stutter/beat-repeat:** buffer capture, repeat length, decay, pitch per repeat.
6. **Swing per lane** (UKG-style late 16ths **[S31]**) and **per-step micro-timing** (±, in ticks).
7. **Round-robin and probability:** ghost-note lanes with random choice among slices, velocity randomisation, trig conditions (1:2, 3:4, fill, "not previous", Elektron-style).
8. **Amen-edit generator:** a pattern generator that re-orders slices with musical rules (keep kick on 1, end-of-phrase fills, snare rolls every 4/8 bars, reverse the last snare, half-time drops), with a "chaos" knob that scales from jungle to Venetian Snares-style breakcore. Seeded, so results can be recalled.
9. **Resample/bounce-in-place:** render the edited pattern to a new break, then slice again. This is how drill/breakcore was made **[S27]**.
10. **Per-voice degradation:** 8/10/12/16-bit, sample rate 4–48 kHz with or without an anti-alias filter, an S950/SP-1200/S1000/E-mu "converter" model per voice.
11. **Layering:** sub-kick and 808 boom triggered alongside break kicks; sidechain-free layer volume.
12. **Choke groups** (open/closed hats, break slices cutting each other: essential for monophonic "chopped" feel).
13. **Output routing:** multi-out to FL mixer (kick, snare, hats, break bus, FX).
14. **Pattern length** up to 64 steps per lane, polymeter per lane, pattern chaining, song mode; MIDI-note-per-slice export so FL's piano roll can edit chops.

**DSP building blocks:** high-quality and *deliberately bad* resamplers (drop-sample, linear, 4-point Hermite, Gaussian SPU, windowed-sinc); transient detector; per-voice SVF/ladder filter; bitcrusher with selectable dither; Akai cyclic and "intelligent" stretch; buffer-repeat; per-voice drive; envelope with fast click-free choke.

**Signature artifacts:** chipmunked snare formants from pitch-up; aliasing "fizz" on rides when pitched up without AA; metallic grain-buzz of cyclic stretch; hard truncation clicks (optional "click" knob); reverse-snare swells; tail cuts from choke.

---

### C2. Mono arp synth

**Role:** acid lines, rave arps, hoover riffs, Reese/sub basslines, trance gates, 2-step organ-stab riffs.

**Must-have sounds**
1. **Reese bass**: two (or more) saws detuned ±~0.3 st (≈±30 cents) or a few Hz, lowpass, slow drift, optional distortion and phaser/comb for techstep **[S5][S6]**.
2. **Sub bass**: pure sine with optional 2nd-harmonic drive; 808-style pitch-drop envelope; mono, phase-reset per note.
3. **Hoover / Mentasm**: Alpha Juno-style **PWM'd sawtooth** with fast LFO on PW, sub oscillator, Roland-style chorus, downward pitch-bend/portamento dives **[S7][S14]** (bend detail is [K]).
4. **303 acid**: saw/square into an 18 dB/oct-style ladder lowpass **[S42]**, accent and slide per step.
5. **Rave arp / stab**: square/pulse with short env, filter env, chorus, arpeggiated over chords.
6. **M1-style organ bass**: organ (triangle + square 3 octaves up as a synth approximation) with short decay **[S16]**.
7. **Trance gate lead**: supersaw or saw through a step-gate.
8. **FM "wobble"/mentasm-ish growl**: 2-op FM with LFO on index (techstep/neuro) **[K]**.

**Sequencer / arp features (from the gear these lines rely on)**
- **SH-101-style arp:** Up / Down / Up&Down, Hold, real-time Transpose, 1–2 octave range (we extend to 4 and add Random, As-Played, Converge) **[S43]**.
- **100-step SH-101-style / MC-202-style sequencer** with per-step note, gate (incl. tie), **slide** (portamento per step), **accent** **[S43][K]**.
- **303 behaviour:** accent shortens the filter-env decay to minimum and drives a separate accent envelope. Successive accents **accumulate charge** (the "wow" sweep), which must be modelled as an RC that does not fully discharge between notes **[S42][S44]**. Slide begins from the tied note **[S45]**. Glide time is constant (~60 ms, [K]) rather than scaled to the interval.
- **Elektron-style parameter locks:** any parameter can be locked per step (cutoff, decay, pitch, FX send); trig conditions; micro-timing; per-step probability.
- **Gate / trance-gate** sequencer for volume or filter (16/32 steps, smoothing).
- **Swing**, shared with the drum computer via host sync.
- **Scale/chord memory:** play rave chord stabs from one key (Juno/Poly-chord memory).
- **Mono/legato/retrigger modes**, last/low/high note priority.

**DSP building blocks**
- Oscillators: PolyBLEP/BLEP saw, square/pulse with PWM, **PWM-saw** (Alpha Juno-type), triangle, sine, sub (−1/−2 oct square), noise. Hard sync. 2-op FM. Detune/unison 1–7 voices (Reese/supersaw).
- Filters: **diode/transistor ladder** (303/Moog-ish, 18 and 24 dB modes), **OTA 4-pole** (Juno IR3109-like), SVF (LP/BP/HP/notch) for 2-step organ and techstep; drive inside the loop.
- Envelopes: analog-style exponential, 303 accent model, MEG/pitch env.
- FX: BBD chorus (Juno I/II/I+II), distortion/waveshaper, phaser/comb, tape delay, PS1 reverb send.

**Signature artifacts:** the 303 "squelch" from resonance plus accent accumulation; Reese beating/phasing; hoover pitch dive; slightly unstable analog pitch (drift); chorus "swirl".

---

### C3. Poly synth ("normal" poly, the pad and keys machine)

**Role:** intelligent-DnB pads, strings, choir washes, Rhodes/DX EPs, supersaw chords, rave stabs, eurodance plucks, Juno pads.

**Must-have sounds**
1. **Juno pad / strings**: 1 DCO (saw + pulse PWM + sub) → HPF → 4-pole OTA LPF → **BBD chorus**. The chorus does much of the thickening **[S19]**.
2. **Supersaw**: 7 detuned saws with a mix/detune curve, JP-8000-style, plus HPF **[S17]**.
3. **DX7 E.PIANO 1-style tine EP**: algorithm 5-type stacks, high-ratio (≈11–14) modulator for the tine "ping", velocity → mod index **[S46]**.
4. **Rhodes (detuned/wavy)**: FM or modal/physical EP with tremolo, chorus and wow.
5. **String ensemble / Solina-ish**: divide-down or multi-saw with ensemble chorus.
6. **Choir "ahh"**: formant-filtered saw/pulse or wavetable vowels (sampler alternative in C4).
7. **Rave stabs / M1 piano-house**: bright saw/pulse stabs, chord memory.
8. **Hoover poly**: the C2 hoover engine, polyphonic.
9. **Glassy Y2K FM bells / menu chimes**: 2–4-op FM with inharmonic ratios.
10. **Virus-style trance pads/plucks**: VA plus unison, plus filter-env pluck.

**DSP building blocks**
- **Hybrid VA + 4-op FM engine** per voice (VA oscillators with unison/supersaw; FM operators with ratios and feedback). DX7 6-op is overkill; 4-op with selectable algorithms covers EPs, bells and basses.
- Optional **wavetable/ROM oscillator** that plays single-cycle and short looped samples (shared with C4), which gives JD-800/JV-1080 hybrid PCM-attack + loop pads.
- Filters: OTA 4-pole (Juno), SVF, a formant filter (choirs), HPF.
- Modulation: 2+ LFOs (with delay/fade), per-voice drift, mod-matrix, poly aftertouch / MPE (FL supports MPE).
- FX: **BBD chorus** (Juno modes), ensemble, phaser, stereo tape delay, **PS1/PS2 SPU reverb** (signature), hall/plate algorithmic reverb, **tape/VHS wow-flutter**, bit/sample-rate reducer.
- Voice: 8–16 voices, mono/legato option, chord memory, unison per voice.

**Signature artifacts:** chorus swirl; supersaw beating; slow wow on held chords; FM "clank" on EP attack; dark, grainy console reverb tails.

---

### C4. Sampler / ROMpler

**Role:** where the "Y2K ROM" and "PS1 sample set" world lives. It plays (a) our own legally clean multisamples designed to *evoke* JV-1080/Triton/M1/E-mu Proteus-era ROM presets, and (b) user samples through period-accurate sampler engines.

**Must-have content (recreated in-house, see section e)**
- **Organ 2-style house organ** (short, truncated attack: the original was a DSS-1 organ with its attack cut off) **[S16]**.
- **Piano-house piano**, M1-ish; **"Fantasia"-style bell pad**; **"Pizzicato"-style plucks**; nylon/steel guitar; slap bass; fretless bass (Squarepusher/jazzy DnB); upright bass (Reprazent).
- **Strings** (Vintage Keys/Emulator-style 12-bit string sections, cf. Goldie's *Timeless*) **[S23]**; **choir "ahh"/"ooh"**; pan pipes and flutes (Bukem) **[S24]**; orchestra hits; vibes/marimba; music-box; kalimba.
- **Vocal chop banks**: original recorded soul/ragga/R&B-style phrases (cleared), "yeah", "come on", rewinds.
- **Console-flavoured sets**: 22–32 kHz ADPCM-encoded instruments (SPU-style), Game-Boy/FM menu blips, glassy Dreamcast/PS2-era PCM.

**Engine features**
1. **Sampler "models"** (converter/DAC + interpolation + filter character):
   - *S950 mode*: 12-bit, variable SR 7.5–48 kHz, 6th-order Butterworth-type LPF, preamp drive **[S8][S47][S48]**.
   - *SP-1200 mode*: 12-bit, 26.04 kHz, drop-sample (non-interpolated) pitching, SSM2044-style 4-pole non-resonant LPF on selected outputs **[S8][S47]**.
   - *S1000/S3000 mode*: 16-bit, 44.1 kHz, interpolated pitch, digital LPF, cyclic/intelligent timestretch **[S2][S9][K]**.
   - *E-mu mode*: Emax-ish 12-bit crunch, or E4-style **Z-plane-type morphing filters** (morph between resonant models) **[S30]**.
   - *PS1 SPU mode*: 4-bit ADPCM re-encode on load, Gaussian 4-tap interpolation, 44.1 kHz ceiling (rates above skip samples), SPU ADSR, pitch-mod between adjacent voices, noise voice **[S1][S49]**.
   - *Clean mode*: modern sinc.
2. **Keygroups/multisample zones**, velocity layers, round-robin, loop modes (forward, ping-pong, release), crossfade loops.
3. **Timestretch modes**: off (repitch), Akai cyclic, Akai intelligent, granular, modern (for vocals).
4. **Slice mode** (shared engine with C1) and **"rex-like" MIDI export**.
5. **Filters**: SVF, ladder, Z-plane-style morph, formant.
6. **Mod matrix**, 2+ LFOs, 3+ envelopes, per-zone tune/pan.
7. **Built-in FX**: shared FX rack (PS1 reverb, BBD chorus, tape/VHS, bitcrush, delay).
8. **Import**: WAV/AIFF, SFZ, optional legacy formats (Akai S1000/S3000 disk images, SoundFont .sf2) for users' own libraries.

**Signature artifacts:** 12-bit quantisation noise and "grain", aliasing when pitched, ADPCM noise and transient smear, loop clicks and buzz, Gaussian-interp dulling (SPU), Z-plane resonant morph sweeps.

---

## (d) Signature effects list: what it is and how to implement

### D1. PS1 / PS2 SPU reverb, the headline effect
- **What:** The PS1 SPU (24 voices **[S49]**, 512 KB SPU RAM) has a hardware reverb configured by registers at 1F801DC0h–1F801DFFh, with its work area at the end of SPU RAM **[S1][S50]**. It is a **Schroeder-style** reverberator (input IIR, comb-ish taps, all-passes) **[S50]**, and it runs at **half rate (22.05 kHz)**, which explains its dark, grainy, slightly aliased character **[S1][S50]**. The PS2 SPU2 reverb is "practically identical" (two cores, 48 voices, 2 MB RAM) **[S50][S51]**.
- **Presets (SDK):** psx-spx lists example settings with fixed work-area sizes: Room, Studio Small (1F40h bytes = 8000), Studio Medium, Studio Large, Hall, Half Echo (3C00h), Space Echo (F6C0h) **[S1][S52]**, plus (per the SDK/libsnd list and psx-spx, [K]) Chaos Echo and Delay. GameVerb markets "all 9 original PS1 DSP algorithms" **[S53]**. Approximate sizes: Studio S/M/L ≈ 8/18/28 KB, Half Echo ≈ 15 KB, Space Echo ≈ 62 KB **[S52]**. SDK naming ([K]): OFF, ROOM, STUDIO_A/B/C, HALL, SPACE, ECHO, DELAY, PIPE; Echo/Delay expose delay time and feedback.
- **Structure ([K], verify with the psx-spx "Reverb Formula" section and the MAME `spureverb.h` / Mednafen `spu.cpp` sources **[S54]**):**
  1. Downsample L/R input to 22.05 kHz (Mednafen/psx-spx describe a FIR resampler; replicate the band-limiting).
  2. Apply input volume, then **same-side reflection** (mLSAME/mRSAME) and **different-side (cross) reflection** (mLDIFF/mRDIFF), each through a one-pole IIR (vIIR) with wall attenuation (vWALL), written back into the ring buffer.
  3. Sum **4 comb taps** (mLCOMB1–4 × vCOMB1–4).
  4. Two **series all-pass** stages (dAPF1/2, vAPF1/2).
  5. Output volume, upsample to 44.1 kHz, mix.
  6. Everything is 16-bit fixed-point with saturation. Keep an "accurate integer" mode (part of the grit) and a "clean float" mode.
- **Implementation:** clean-room from the public spec (psx-spx). Ship the 9–10 SDK preset tables, plus a **"Size" knob that interpolates delay offsets**, damping (vIIR), feedback (vWALL/comb gains), a "rate" switch (22.05 kHz authentic / 44.1 / 48), and "PS2 mode" (48 kHz host, per-core). References for validation: BodbDearg's free **PsxReverb** VST3 (ships all PsyQ SDK reverb types), foo_dsp_prvb (P.E.Op.S.-derived, SDK presets), SPS plugin, Impact Soundworks GameVerb **[S53][S55][S56]**. **Licensing:** Mednafen/DuckStation/PCSX2 are GPL. Do not copy their code into a closed-source plugin. Use them only for black-box A/B comparison.

### D2. SPU voice path (ADPCM + Gaussian interpolation)
- **ADPCM:** 16-byte blocks: header (shift + filter index), flags (loop start/end/repeat), then 14 data bytes = **28 4-bit samples**. Filters are fixed 2-pole predictors (5 sets) **[S49][S57]** (28/block confirmed by FFmpeg's decoder and the PCSX2 forum; filter count [K]).
- **Interpolation:** 4-tap **Gaussian** on the 4 most recent samples, indexed by 8 bits of the pitch counter **[S49]**. It gives a soft, slightly dull top end.
- **Pitch ceiling:** rates above 44.1 kHz skip samples (aliasing when pitched up past ~+12 st from a 44.1 k source) **[S49]**.
- **Implementation:** an encoder that runs on sample load (brute-force best filter/shift per block, as in psxavenc-style encoders), a decoder, a Gaussian table, voice ADSR (linear/exponential modes [K]), noise LFSR voice, pitch-modulation from the previous voice [K]. Expose an "SPU-ify" toggle on every sampler zone.

### D3. Vintage sampler converter emulation (S950 / SP-1200 / S1000 / E-mu)
- **What:** lower bit depth and sample rate bring out "character and crunch" **[S47]**. The SP-1200's grit comes from 26.04 kHz / 12-bit linear plus SSM2044 filters (no resonance) **[S8]**. The S950 is 12-bit with a variable 7.5–48 kHz rate and a 6th-order Butterworth-type LPF; much of its character is the filtering and preamp drive, and the AA filter could not be disabled **[S47][S48]**. Pitching down on a variable-rate sampler drops the effective SR, so aliasing becomes evident **[S9]**.
- **Implementation per model:** input AA filter (model-specific order/cutoff, optional) → SR reduction (sample-and-hold at model rate, or variable) → quantiser (12/16-bit, optional non-linear) → playback: pitch by **rate change** with model interpolation (none/drop-sample for SP-1200, linear/[K] for Akai) → reconstruction filter (or none) → analog filter model (SSM2044 4-pole, Butterworth 6-pole) → mild preamp saturation. Oversample internally so that only *intended* aliasing remains.

### D4. Akai-style "cyclic" time-stretch (deliberate artifact)
- **What:** Akai offered **Cyclic** (fixed cycle/grain time) and **Intelligent** (decides cycle boundaries itself, slow) modes **[S2][S58]**. Quality falls off beyond about ±5–10 % **[S2][S59]**. Cyclic mode chops audio into **constant-size grains and spreads them over the target length with crossfades** (repeating grains when stretching, skipping when compressing). Intelligent mode extracts single waveform cycles at positive-going zero crossings **[S60]**. The sound is all over early jungle and 90s DnB **[S2]**. Akaizer (free, offline) and TAL-Sampler emulate it **[S2][S61]**.
- **Implementation:**
  - *Cyclic:* grain length L (≈5–100 ms, user-set, with "auto" from tempo), crossfade X (0–50 % of L, linear/equal-power), read pointer advancing at `L/stretch` per grain. Grain repetition produces a periodic **buzz at 1/L Hz**, which is the signature metallic warble. Add "grain slide" (shift each repeat slightly), as the JUCE community found the original sounds smoother than a naive loop-repeat **[S60]**.
  - *Intelligent:* pitch-synchronous (PSOLA-like) using zero-crossing cycle detection.
  - *Real-time:* both are cheap. Offer per-slice stretch and a whole-break "stretch to tempo" with the artifact intensity exposed as a knob.

### D5. Pitch-by-resampling with selectable interpolation ("33 → 45" mode)
- Playback-rate change shifts pitch, tempo and formants together (chipmunk vocals, tighter, brighter breaks). Provide interpolation choices (drop-sample → sinc) and the "+5 st +33 c fits a bar" helper **[S10]**. A "vinyl rpm" switch (33/45/78) gives fast UX.

### D6. Tape / VHS wow & flutter ("wavy")
- **Implementation [K]** (the web-search budget ran out before this could be sourced): modulated fractional delay line (3–20 ms base, high-quality interpolation). Wow: 0.2–2 Hz sine plus random-walk LFO, depth up to ~±30 cents. Flutter: 4–15 Hz, ±1–5 cents with some noise. Then add head-bump EQ, HF roll-off (tape speed / "VHS" preset at ~10–12 kHz LP), soft saturation, hiss, dropouts (random brief gain dips with LPF), stereo skew (L/R slightly different modulation). Presets: Cassette, VHS-SP, VHS-EP (worse), DAT (clean), Walkman (eaten).

### D7. BBD chorus (Juno-style)
- Two out-of-phase triangle-modulated BBD delays. Mode I slower/shallower, II deeper, I+II fast vibrato-ish **[S19]**. Model BBD bandwidth (LPF ~8–10 kHz), companding noise and clock-rate pitch artifacts **[K]**.

### D8. Bit-crush / decimate
- Bit depth 1–24 (with or without dither; "unsigned" vs two's-complement truncation flavours), SR reduction with and without AA, plus optional μ-law/8-bit "Amiga/MOD" mode (OctaMED/tracker heritage **[S62]**).

### D9. Reverse, rewind, tape-stop, spinback
- Reverse-reverb swells (render reverb of reversed slice, reverse back), DJ rewind (buffer played backwards with accelerating rate), tape-stop (rate → 0 with curve).

### D10. Stutter / buffer-repeat / drill
- Captures the last N ms, repeats with decay, pitch steps per repeat, and lengths down to 1/128. Shared engine for C1's ratchets.

### D11. Morphing / resonant filters
- Z-plane-style morphing filter: interpolate between two (or 4, on an XY pad) multi-pole/zero resonant configurations **[S30]**. Plus classic ladder, OTA and SVF sweeps (Mentasm and Reese filter motion).

### D12. Distortion palette
- Desk-style soft clip (Playford: "desk distortion is part of his sound" **[S23]**), tube/tape saturation, waveshaper and fold (techstep Reese), bit-distortion.

### D13. Delay
- Tape/dub delay with feedback filtering and wow, ping-pong, tempo sync including dotted and triplet (Bukem's lightly delayed Rhodes **[S24]**).

### D14. Trance gate
- Step-gate on volume or filter with attack/release smoothing, 16/32 steps, swing.

### D15. Console texture bus ("PS2-core master")
- One-knob macro: SPU-ify (ADPCM + Gaussian) → 22/32 kHz SR → PS1 reverb send → light VHS wow → gentle LPF. This is likely the product's most marketable single effect.

---

## (e) Legal notes on content (not legal advice)

1. **Original break recordings are copyrighted** (sound recording + composition). "Breakbeats enjoy no dispensation from copyright", and a full break is likely to be "substantial". Disguising a sample lowers the chance of detection but not liability **[S63]**. The Amen's owner was Richard L. Spencer; neither he nor Gregory Coleman was paid **[S11]**. **Do not ship the original Amen, Think, Funky Drummer, Apache or other masters**, or anything ripped from Ultimate Breaks & Beats vinyl.
2. **Safe content routes:**
   - **Commission session drummers** to record *new* breaks in the classic idioms (ride-led 4-bar with ghosted snares, etc.). The new recording is our master. Avoid note-for-note copies of iconic fills and *name* the content generically ("A-Break 69", not "Amen"). Some original funk drummers made legal replay sample CDs **[S63]** (anecdotal).
   - **Synthesise** kicks, subs, hats and toms (a strength of the drum computer anyway).
   - License **royalty-free packs** only where the license explicitly allows **redistribution inside a commercial instrument** (most "royalty-free" sample licenses permit use in music, *not* resale as samples) **[S63][S64]**.
   - **CC0 recordings** (e.g. Freesound CC0 only). Freesound bans material taken from commercial recordings **[S63]**.
3. **ROM sounds** (M1, JV-1080, Triton, E-mu Proteus, PS1 SDK banks) are sample recordings owned by their makers. Buying the instrument licenses use in compositions, not resale of the samples **[S64]**. A forum report says Roland sued over copied Sound Canvas samples (unverified). **Recreate by synthesis or fresh multisampling of instruments we own the rights to** (e.g. our own organ, Rhodes, strings).
4. **Preset names and trademarks:** do not use "Korg M1", "Alpha Juno", "JP-8000", "PlayStation", "PS1/PS2", "SPU" or Sony/Roland/Korg logos as product or preset names, or in UI branding. Descriptive comparisons in docs ("inspired by late-90s consoles") are lower risk. The Y2K/PS2 *look* must not copy Sony UI assets, fonts, boot sounds or logos.
5. **Algorithms vs code:** implementing the PS1 reverb or Akai stretch from **public reverse-engineering docs** is ordinary practice. Copying GPL emulator code (Mednafen, DuckStation, PCSX2) into a closed product is not acceptable. SDK preset tables are numeric parameter data; get a short legal review before shipping them verbatim.
6. **Users' own content:** importing user samples (including old Akai disks) is fine; responsibility for clearance sits with the user.

---

## (f) Sources

| # | Source |
|---|---|
| S1 | psx-spx SPU documentation (mirror): https://forge.chapril.org/ABelliqueux/psx-spx.github.io/src/commit/654d8bc74ce5fc533aa05cb5506389f25ec2dddb/soundprocessingunitspu.md ; canonical: https://psx-spx.consoledev.net/soundprocessingunitspu/ |
| S2 | MusicRadar: authentic timestretched jungle breaks with Akaizer — https://www.musicradar.com/tuition/tech/how-to-create-authentic-timestretched-jungle-breaks-with-akaizer-611255 ; Akai S2000/S3000XL manuals (manualslib); Akai S1000 (Wikipedia); CreativeLive Akaizer lesson |
| S3 | Mixmag: Kevin Saunderson's Reese bassline — https://mixmag.net/feature/kevin-saunderson-reese-bassline-transformed-uk-dance-music-jungle-speed-garage-drum-n-bass |
| S4 | Attack Magazine: Reese – Just Want Another Chance deconstructed — https://www.attackmagazine.com/technique/deconstructed/reese-just-want-another-chance/ |
| S5 | Native Instruments blog: Reese bass — https://www.native-instruments.com/blogs/blog/reese-bass |
| S6 | MusicRadar: classic Reese like Renegade's Terrorist — https://www.musicradar.com/how-to/classic-reese-bass-renegade-terrorist |
| S7 | Hoover sound (Wikipedia) — https://en.wikipedia.org/wiki/Hoover_sound ; Attack Magazine liquid hoover — https://www.attackmagazine.com/technique/synth-secrets/liquid-hoover-bass/ |
| S8 | E-mu SP-1200 (Wikipedia) — https://www.wikipedia.org/wiki/SP-1200 ; Rossum SP-1200 — https://www.rossum-electro.com/products/sp-1200/ |
| S9 | Akai S950 references: MusicRadar review — https://musicradar.com/news/akai-s950-review ; muzines S950 — https://www.muzines.co.uk/articles/akai-s950/1372 |
| S10 | MusicRadar: old-skool jungle style breaks — https://www.musicradar.com/tuition/tech/how-to-make-old-skool-jungle-style-breaks-464788 ; Reason Studios Jungle 101 — https://www.reasonstudios.com/news/post/jungle-101-the-beat |
| S11 | Amen break (Wikipedia) — https://en.wikipedia.org/wiki/Amen_break |
| S12 | Red Bull: most sampled songs — https://www.redbull.com/int-en/these-are-the-most-sampled-artists-and-songs-in-music ; RouteNote 20 most sampled — https://routenote.com/blog/the-20-most-sampled-songs-of-all-time/ ; Attack: 2nd most sampled track — https://www.attackmagazine.com/features/long-read/the-2nd-most-sampled-track-in-history/ |
| S13 | Reverb.com: samplers and breakbeats behind 90s jungle — https://reverb.com/news/the-samplers-behind-90s-jungle-and-drum-and-bass ; TrenchTrenchTrench: building blocks of jungle — https://trenchtrenchtrench.com/features/the-building-blocks-of-jungle-10-samples-that-sculpted-the-sound |
| S14 | RBMA: Mundo Muzique on Mentasm — https://daily.redbullmusicacademy.com/2014/05/key-tracks-mundo-muzique-on-mentasm |
| S15 | Gearnews: Alpha Juno / Dominator — https://www.gearnews.com/tag/alpha-juno ; Laughing Squid hoover — https://laughingsquid.com/hoover-rave-music-sound-1990s/ |
| S16 | The legendary Korg M1 "Organ 2" — https://gijs.substack.com/p/the-legendary-korg-m1-organ-2-preset ; MusicRadar M1 organ bass — https://www.musicradar.com/tuition/tech/how-to-create-a-korg-m1-style-organ-bass-sound-642650 ; Guitar Center M1 history — https://www.guitarcenter.com/riffs/gear-tips/keyboards--midi/korg-m1-sounds-history |
| S17 | Roland JP-8000 / Supersaw (Wikipedia) — https://en.wikipedia.org/wiki/Roland_JP-8000 ; Perfect Circuit supersaw history — https://www.perfectcircuit.com/signal/super-saw-history |
| S18 | Roland JV-1080 (Wikipedia) — https://en.Wikipedia.com/wiki/Roland_JV-1080 ; MusicRadar JV-1080 — https://musicradar.com/news/blast-from-the-past-roland-jv-1080 |
| S19 | Roland Icon Series Juno-106 — https://www.roland.com/uk/blog/roland-icon-series-juno-106-synthesizer/ ; Roland Juno-106 Chorus ref — https://static.roland.com/manuals/SPD-SX_PRO_reference_v200/en-US/561177355.html ; Attack Overmono-style Juno pads — https://www.attackmagazine.com/technique/tutorials/overmono-style-pads-with-roland-cloud-juno-106/ |
| S20 | Tramen: Dogs On Acid thread — https://www.dogsonacid.com/threads/tramen-break.794648/ ; en-academic Tramen — https://en-academic.com/dic.nsf/enwiki/939410 ; WhoSampled top-10 DnB breaks — https://www.whosampled.com/news/2015/03/05/top-10-iconic-drum-bass-jungle-breakbeats/ |
| S21 | ReCycle (Wikipedia) — https://en.wikipedia.org/wiki/ReCycle ; MusicRadar ReCycle — https://www.musicradar.com/news/blast-from-the-past-propellerhead-software-recycle |
| S22 | Inner City Life (Wikipedia) — https://en.wikipedia.org/wiki/Inner_City_Life ; Nick Abadzis blog — https://nickabadzis.com/blog/2019/3/14/a-weekly-song-episode-11-goldie-presents-metalheads-or-is-that-metalheadz |
| S23 | Sound On Sound: Rob Playford – Producing Goldie — https://www.soundonsound.com/people/rob-playford-producing-goldie ; SOS 25 productions — https://www.soundonsound.com/techniques/25-productions-made-history |
| S24 | The Vinyl Factory: LTJ Bukem in 10 records — https://www.thevinylfactory.com/features/an-introduction-to-ltj-bukem-in-10-records ; Loopcloud DnB tricks — https://loopcloud.com/cloud/blog/4978-Tricks-of-the-Trade-Drum-Bass ; Isotonik ambient jungle — https://isotonikstudios.com/how-to-make-ambient-jungle-in-ableton-live/ |
| S26 | Rolling Stone: DnB revival — https://www.rollingstone.com/music/music-features/drum-and-bass-revival-1371796/ |
| S27 | Drill 'n' bass (Wikipedia) — https://wikipedia.com/wiki/Drill_and_bass ; Breakcore (Wikipedia) — https://www.wikipedia.org/wiki/Breakcore ; Ableton forum drill breaks — https://forum.ableton.com/viewtopic.php?p=782567 |
| S28 | UAL student blog on breakcore workflow — https://25031938.myblog.arts.ac.uk/?p=41 ; Renoise forum — https://forum.renoise.com/t/samples-venetian/38673 |
| S29 | Wormhole (album) (Wikipedia) — https://en.wikipedia.org/wiki/Wormhole_(album) ; Kmag Ed Rush & Optical — https://kmag.co.uk/essential-ed-rush-optical/ |
| S30 | Sound On Sound E-mu E4X review — https://www.soundonsound.com/reviews/emu-e4x ; Equipboard E-mu Emulator IV — https://equipboard.com/items/emu-emulator-iv ; Sweetwater Z-plane — https://www.sweetwater.com/insync/z-plane-synthesis/ |
| S31 | Native Instruments: UK garage — https://www.native-instruments.com/blogs/blog/uk-garage-music ; 2-step garage (Wikipedia) — https://en.wikipedia.org/wiki/2-step_garage ; Jack Righteous UKG — https://jackrighteous.com/blogs/news/artists-who-defined-uk-garage-2-step |
| S32 | MusicRadar UK garage tutorial — https://musicradar.com/how-to/uk-garage-tutorial ; MasterClass UKG — https://www.masterclass.com/articles/uk-garage-music-guide |
| S33 | Tim Wright (Wikipedia) — https://en.wikipedia.org/wiki/Tim_Wright_(Welsh_musician) ; Bandcamp Daily CoLD SToRAGE interview — https://daily.bandcamp.com/features/cold-storage-wipeout-the-zero-gravity-collection-interview ; Beatportal Wipeout legacy — https://www.beatportal.com/articles/122239-the-rave-video-game-legacy-of-cold-storages-wipeout-soundtrack |
| S34 | RBMA Soichi Terada interview — https://daily.redbullmusicacademy.com/2017/10/soichi-terada-interview ; RA review Apes In The Net — https://ra.co/reviews/35954 |
| S35 | Hideki Naganuma (Wikipedia) — https://en.wikipedia.org/wiki/Hideki_Naganuma ; SuperJump — https://www.superjumpmagazine.com/hideki-naganuma-the-funky-uncle-of-video-game-music/ |
| S36 | Loopmasters Jungle Breakcore pack (dreamy atmospheric jungle: Sewerslvt, TOKYOPILL etc.) — https://www.loopmasters.com/genres/15-Drum-and-Bass/products/20844-Jungle-Breakcore |
| S37 | Crack Magazine: Nia Archives — https://crackmagazine.net/article/profiles/nia-archives-is-at-the-forefront-of-the-jungle-revival ; Grammy.com new UK jungle — https://grammy.com/news/new-uk-jungle-artists-to-know-nia-archives-pink-pantheress-videos |
| S38 | inkl/Guardian: TikTok made DnB hot again — https://inkl.com/news/it-s-just-good-energy-how-tiktok-and-covid-made-drum-n-bass-hot-again |
| S39 | Miami New Times jungle revival timeline — https://www.miaminewtimes.com/music/jungle-revival-timeline-from-sully-and-tim-reaper-to-sherelle-and-nia-archives-17639564 ; Crack: SHERELLE x Tim Reaper — https://crackmagazine.net/article/long-reads/sherelle-in-conversation-with-tim-reaper/ ; Nina Protocol newschool jungle — https://ninaprotocol.com/articles/newschool-jungle-sounds-a-lot-like-old-school-jungleand-many-of-its-most-celebrated-figures-arent-exactly-new-either |
| S40 | SoundCloud: New era jungle — https://soundcloud.com/stories/post/new-era-jungle |
| S41 | Between Music and Gaming: Y2K gaming music — https://betweenmusicandgaming.substack.com/p/the-unseen-legacy-of-y2k-gaming-music ; Aesthetics Wiki Y2K Futurism — https://aesthetics.fandom.com/wiki/Y2K_Futurism |
| S42 | Roland TB-3 (ACB, −18 dB/oct ladder) — https://www.roland.com/us/products/tb-3/support/ ; Patreon "Patch ideas from studying the TB-303" — https://www.patreon.com/posts/patch-ideas-i-tb-41917616 |
| S43 | Roland SH-101 (Wikipedia) — https://Www.wikipedia.org/wiki/SH-101 ; SOS SH-101 Retrozone — https://www.soundonsound.com/reviews/roland-sh101-retrozone ; Roland SH-01A — https://www.roland.com/global/products/SH-01a/ |
| S44 | KVR Open303 thread — https://www.kvraudio.com/forum/viewtopic.php?p=3761614 |
| S45 | Matrixsynth: Avalon / TB-303 long-note slide behaviour — https://www.matrixsynth.com/2015/08/avalon-and-tb-303-behavior-on-long.html |
| S46 | Yamaha FM 101 part 5 — https://yamahasynth.com/learn/synth-programming/fm-101-part-five-expanding-your-sound/ ; muzines Practically FM — https://www.muzines.co.uk/articles/practically-fm/3945 ; musicproductionwiki DX7 EP — https://musicproductionwiki.com/articles/how-to-recreate-the-dx7-electric-piano |
| S47 | Attack Magazine: Character crunch, vintage samplers — https://www.attackmagazine.com/technique/character-crunch-replicating-the-sound-of-vintage-samplers/ ; MusicRadar SP950 — https://www.musicradar.com/news/sp950-emulates-the-gritty-sound-of-the-e-mu-sp-1200-sampler-in-a-plugin ; Attack RX1200 — https://www.attackmagazine.com/news/inphonik-release-the-rx1200-an-e-mu-sp-1200-emulation/ |
| S48 | KVR RX950 thread — https://www.kvraudio.com/forum/viewtopic.php?p=7523118 ; KVR SP950 thread — https://www.kvraudio.com/forum/viewtopic.php?p=7781547 |
| S49 | psx-spx SPU (mirror, S1) ; PS2 voice counts via Mix Online — https://www.mixonline.com/sfp/sound-playstation2-369087 |
| S50 | PCSX2 Documentation: Reverb Engine — https://wiki.pcsx2.net/PCSX2_Documentation/Reverb_Engine |
| S51 | PlayStation 2 technical specifications (Wikipedia) ; Sega Retro AICA — https://segaretro.org/Yamaha_Super_Intelligent_Sound_Processor ; AICA datasheet — https://segaretro.org/images/d/de/AICA_E.pdf |
| S52 | psx-spx SPU overview — https://problemkaputt.de/psxspx-spu-overview.htm ; libsnd definition — https://www.lawinsider.com/dictionary/libsnd ; simpleSoundbank PS1 reverb guide — https://simplesoundbank.com/guides/ps1-reverb/ |
| S53 | Impact Soundworks GameVerb — https://impactsoundworks.com/deal/gameverb/ ; MusicRadar GameVerb — https://musicradar.com/news/gameverb-reverb-plugin |
| S54 | MAME spureverb.h — https://git.redump.net/mame/tree/src/devices/sound/spureverb.h?h=xtal ; Mednafen/Beetle PSX spu.cpp — https://rust-digger.code-maven.com/src/apollo-hyper-libretro-core-beetle-ngb-0.1.0/beetle-psx-libretro/mednafen/psx/spu.cpp ; DuckStation commit — https://repo.retrodeck.net/Xargon/Duckstation/commit/8769a55298cb059f8f9005f864defd0b7b391c80 |
| S55 | BodbDearg PlayStation1Vsts (PsxReverb) — https://github.com/BodbDearg/PlayStation1Vsts/releases/tag/releases%2F1.3.0 |
| S56 | foo_dsp_prvb — https://www.foobar2000.org/components/view/foo_dsp_prvb ; SPS plugin — https://soundfontguy.itch.io/sps ; Electro-Smith PSXVerb — https://forum.electro-smith.com/t/psxverb-playstation-1-reverb-for-hothouse/8837 |
| S57 | FFmpeg adpcm.c — https://ffmpeg.org/doxygen/4.4/adpcm_8c_source.html ; PCSX2 forum SPU ADPCM — https://forums.pcsx2.net/Thread-SPU-ADPCM-question ; nyanpasu64 gist — https://gist.github.com/nyanpasu64/a0d916ce6924912a7116682bf778e9a0 |
| S58 | Akai S3000XL manual p.147 — https://www.manualslib.com/manual/797868/Akai-S3000xl.html?page=147 ; Akai S2000 manual p.165 — https://www.manualslib.com/manual/1181831/Akai-S2000.html?page=165 |
| S59 | Sound On Sound Akai S2000 review — https://www.soundonsound.com/reviews/akai-s2000 ; Akai S6000 manual — https://www.manualslib.com/manual/629022/Akai-S6000.html?page=175 |
| S60 | electro-music.com cyclic/intelligent explanation — https://electro-music.com/forum/viewtopic.php?p=147329 ; JUCE: Akai-style time stretch — https://forum.juce.com/t/resources-and-techniques-for-tsm-cycle-based-akai-style-time-stretch/59766 ; https://forum.juce.com/t/a-lightweight-akai-style-time-stretch-algorithm-realtime/60514 |
| S61 | Akaizer intro — https://chilloutwithbeats.com/en/akaizer-intro/ ; Elektronauts Pete Cannon thread — https://elektronauts.com/t/retro-jungle-production-with-pete-cannon-akai-atari-amiga/135866 |
| S62 | SOS Retro Jungle Production with Pete Cannon — https://www.soundonsound.com/techniques/retro-jungle-production-pete-cannon ; SOS OctaMED — https://www.soundonsound.com/techniques/octamed |
| S63 | Red Bull: sampling history and how not to get sued — https://www.redbull.com/us-en/sampling-history-and-how-to-not-get-sued ; MusicRadar: when sampling ruled — https://www.musicradar.com/drums/it-was-deemed-that-an-artist-could-sample-an-unrecognisable-portion-of-a-work-without-the-need-to-declare-the-sample-or-indeed-pay-the-original-artist-when-sampling-ruled-the-world-and-drummers-didnt-get-paid ; KVR thread — https://www.kvraudio.com/forum/viewtopic.php?p=7621845 ; Freesound forum — https://freesound.org/forum/sample-requests/40181/88955 |
| S64 | KVR: Legality of distributing sampled synths — https://www.kvraudio.com/forum/viewtopic.php?p=4590845 ; Freesound legal forum — https://freesound.org/forum/legal-help-and-attribution-questions/47/8290 |

### Research gaps / to verify next
- Exact PS1 reverb register formula and preset tables (open psx-spx "SPU Reverb Formula/Examples" once `psx-spx.consoledev.net` / `problemkaputt.de` are reachable). Also verify Chaos Echo/Delay sizes and the half-rate FIR resampler.
- PsxReverb (BodbDearg) license and source.
- Measured analysis of S1000/S3000 cyclic grain lengths (Akaizer docs).
- Wow/flutter numeric ranges (not web-sourced because the search budget ran out; values are standard engineering practice).
- Specific gear of Photek, Source Direct, and the revival producers (interviews not found).
