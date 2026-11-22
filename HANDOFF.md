# Handoff

Laatst bijgewerkt: 22 november 2026. Deze sectie is de actuele waarheid; houd hem kort.

## Waar staan we

- **Fase 1 (onderzoek) afgerond.** Vier onderzoeksrapporten in `docs/research/`,
  synthese in `docs/vision/fase1-synthese.html`.
- **Nog geen code**, geen build, geen CI.
- Het project is gestart vanuit een sessie op de G02-repo; dat is een ander,
  ongerelateerd project. Niets van dit project hoort daar.

## Art direction: System Browser (beeldonderzoek, 22 nov)

Vastgelegd in `docs/design/GUIDELINES.md`, moodboard in `docs/design/moodboard.html`
(ook: https://claude.ai/artifact/FVmLbZqHbTq3nEriabxqxm). Gebaseerd op 48 bekeken beelden.
Plugin = ruimte in het systeemmenu van een verzonnen console: Browser (warmgrijs, spelen),
Systeem (violette wolken, instellingen + Render Engine), Memory card (presets). Stappen als
zwevende kubussen, hoofdknoppen als prisma-ring, selectie = lichtpoel, sentence-case tekst,
waarden in een VFD-strook. **Vervangt** de onderstaande, op tekst gebaseerde eerste richting.

### Verouderd: eerste richting uit tekstonderzoek
- *Riff Console* als systeem: strakke identiteit van een verzonnen consolemerk uit ~2001,
  eigen lettertype, pictogrammen, productcodes, één accentkleur per plugin,
  voorgerenderde 3D-bediening (geborsteld aluminium, gel, glas), waarden in LCD-stroken.
- *BIOS Nocturne* als schil: donkere mistige void, kristallen torens, presets als
  memory-card-saves met procedureel 3D-icoon (vier-hoek-gradiënt + eigen lichtkleuren,
  zoals het PS2 `icon.sys`-formaat).
- *Wet Tech* alleen selectief: proximity-wake knoppen, gel-toggles, vloeibare sample-bewerking.
- Standaardlook is strak PS2. PS1-artefacten verschijnen alleen als de Render
  Engine-settings omlaag gaan.

**Kerninnovatie: Render Engine.** Zes "graphics settings" die beeld én geluid tegelijk
sturen: Polygon/LOD, Vertex Jitter, Affine Warp, Fog/Draw Distance, Interlace/FPS, Memory.
System Link: één globale "drop naar PS1" over alle instanties. Daaronder: CRT Trombone
(manipuleerbare 3D-tv/console, ook als effect), Break Pet (deterministisch, sluit nooit
functies af), gedeelde Memory Card.

**Stack (advies):** JUCE 9 + CMake (pamplejuce-template), VST3 + CLAP
(clap-juce-extensions), Windows x64 eerst. Controls als Blender-filmstrips; 3D-hero als
kleine CPU-softwarerasterizer (~320×240, pixel-upscaled). CI op GitHub Actions
Windows-runners, Inno Setup-installer, pluginval + clap-validator, audio-golden-tests.

**Volgorde (advies):** 0 skelet + CI → 1 visueel systeem (parallel) → mono arp MVP →
drum computer → poly synth → sampler + System Link + Mac.

## Open beslissingen (gebruiker)

1. Art direction System Browser (moodboard): akkoord?
2. Render Engine als ruggengraat: akkoord?
3. Eerste instrument: mono arp (advies) of drum computer?
4. Naam van merk / verzonnen console ("Lowpoly System" is werktitel).

## Eerst te verifiëren vóór bouwen

- GuyEngine V2 (UltimaDSP), de enige gevonden "PS2-inspired" plugin: UI bekijken.
- PS1 SPU-reverb: registerformule en presets, en de licentie van PsxReverb.
  Clean-room bouwen vanuit openbare documentatie, geen GPL-emulatorcode kopiëren.
- Claims gemarkeerd met [M] of [K] in de rapporten.

## Bekende risico's

- Windows code signing: Azure Artifact Signing is alleen voor individuen in VS/Canada.
- FL Studio: slide-noten bereiken plugins niet (eigen glide), multi-out vraagt
  "Auto map outputs", DPI-schaling, "Make bridged" breekt inter-instance links.
- Content: geen originele breaks of ROM-samples meeleveren; breaks opnieuw laten inspelen.
