# Handoff

Laatst bijgewerkt: 22 november 2026 (avond), na de FL-test en het opzetten van lokaal
bouwen op Windows. Dit bestand is de actuele waarheid; houd het kort en werk het bij in
dezelfde commit als je werk.

## Begin hier (nieuwe sessie)

1. Lees dit bestand, dan `CLAUDE.md` (werkregels), dan `docs/design/GUIDELINES.md` (UI).
2. Dit project staat **los van G02**. Niets uit `C:\Users\pepij\Claude Code` (G02/G01) hoort
   hier, en niets van hier hoort daar.
3. Het eerstvolgende wat de gebruiker wil: zijn **oordeel over het moodboard** geven en daarna
   het **eerste echte UI-paneel van disc 1** (zie "Volgende stappen"). FL-test en lokaal
   bouwen zijn klaar.

## Wat het project is

Een familie VST3/CLAP-instrumenten voor FL Studio (Windows eerst) met een PS2-tijdperk
UI en een wavy jungle / breakbeat / drum & bass sound. Vier "discs": 1 mono arp synth,
2 drumcomputer (vlaggenschip), 3 poly synth, 4 sampler (later). Namen zijn nog niet
vastgelegd: werktitel "Lowpoly System", codenamen "LP" / `lp_disc1`. De gebruiker vond
"Lowpoly System" niet sterk; de naam komt later.

**Kerninnovatie: Render Engine.** Zes "graphics settings" die beeld én geluid tegelijk
sturen: Polygon/LOD, Vertex Jitter, Affine Warp, Fog/Draw Distance, Interlace/FPS, Memory.
Standaard strak PS2; omlaag gedraaid zakt alles naar PS1. System Link: één globale
"drop naar PS1" over alle instanties. Daaronder: CRT Trombone (manipuleerbare 3D-tv/console,
ook als effect), Break Pet (deterministisch, sluit nooit functies af), gedeelde Memory Card.
Details: `docs/research/03-innovation-landscape.md`.

## Stand van zaken

| Onderdeel | Status | Waar |
|---|---|---|
| Onderzoek (UI-tekst, geluid, innovatie, techniek) | klaar | `docs/research/01`–`04` |
| Beeldonderzoek (48 beelden bekeken, 24 gekozen) | klaar | `docs/research/05`, `06`, `docs/design/references/` |
| UI-richtlijnen "System Browser" | vastgelegd, **wacht op akkoord gebruiker** | `docs/design/GUIDELINES.md`, `docs/design/moodboard.html` |
| Skelet + CI | klaar, CI groen op Linux én Windows | zie hieronder |
| Disc 1 DSP | alleen testsynth | `plugins/disc1` |
| Disc 1 UI | nog niets; placeholder-editor, in dev-builds schuifjes per parameter | `libs/lp_core/source/DevParamEditor.cpp` |
| Getest in FL Studio 20.7 | **geslaagd** (22 nov, gebruiker), VST3: laadt als instrument, noten klinken, glide werkt (ook met langere glide-tijd), venster scherp op 125% DPI, cutoff en glide komen terug na opslaan + FL herstarten (lokale dev-build). CLAP niet testbaar (zie Techniek) | — |
| Lokaal bouwen | opgezet op de pc van de gebruiker (22 nov) | zie "Lokaal bouwen op Windows" |

Let op: `docs/research/01-ui-aesthetic.md` en `docs/vision/fase1-synthese.html` zijn
op tekst gebaseerd en voor de UI **verouderd**. `GUIDELINES.md` gaat voor.

## Art direction: System Browser (kort)

Elke plugin is een ruimte in het systeemmenu van een verzonnen console uit ~2001, geen
apparaat met behuizing.
- **Browser-ruimte** (spelen): warmgrijze radiale gradiënt, objecten zweven zonder panelen.
- **Systeem-ruimte** (instellingen, Render Engine): violette wolken, glazen prisma's.
- **Memory card** (presets): 3D-save-iconen die langzaam draaien.
- Stappen = zwevende genummerde kubussen met kleurverloop (PS2 audio-cd-scherm).
- Hoofdknoppen = ring van 12 glazen prisma's die zich vullen (PS2-klok).
- Selectie = witte lichtpoel onder het object; nooit omlijningen.
- Tekst groot, sentence case, afgerond sans; waarden in een cyaan-wit VFD-strook.
- Geen chroom, geen geborsteld metaal, geen donkere navy/neon-paarse basis (daar zitten
  de concurrenten GuyEngine V2, Y2K Club, chipsynth).
- Disc 1 kleurverloop: `#3f4eaf` → `#4d8a9f` → `#38c176` → `#68f877`.
Moodboard online: https://claude.ai/artifact/FVmLbZqHbTq3nEriabxqxm

## Techniek

- JUCE 9.0.6 + clap-juce-extensions (main-commit 3837f4a) + Catch2 3.9.1, alle drie op
  commit gecontroleerd in `cmake/Dependencies.cmake`.
- Alle namen en ids staan alleen in `cmake/Names.cmake`. Bestandsnaam `LP Disc 1 dev`
  (JUCE breekt op haakjes); de host toont "LP Disc 1 (dev)". De codes/ids moeten vóór de
  eerste publieke build vastliggen.
- `libs/lp_core`: gedeelde code. `plugins/disc1`: polyBLEP-saw → TPT-SVF lowpass →
  amp-env, last-note priority, interne legato glide (FL geeft slide-noten niet door aan
  plugins), 6 parameters, state save/restore.
- Geverifieerd in de cloud (Linux): 15 Catch2-tests groen; pluginval 1.0.4 strictness 10
  geslaagd; clap-validator 33/0/1 (waarschuwing: JUCE kan state-laden niet laten falen).
- CI: `.github/workflows/build.yml`. Run 45041401596 op commit 498a358: Linux én Windows
  (MSVC, VST3 + CLAP) groen; artifact `lp-windows-x64-498a358c`.
- `scripts/get-latest.ps1`: haalt de nieuwste geslaagde Windows-build op (via `gh`) en
  installeert hem. Werkt (22 nov gedraaid). Op `main` was toen nog geen CI-run, dus
  `-Branch claude/skeleton-ci` was nodig.
- **De gebruiker heeft alleen FL Studio 20.7.1 en kan niet upgraden.** Die versie laadt
  geen CLAP. Gevolg: VST3 is het formaat dat de gebruiker hoort en test; CLAP blijft
  meegebouwd en wordt in CI met clap-validator gecontroleerd. **Ontwerpregel: geen functie
  mag alleen via CLAP werken** (bv. per-noot-modulatie). Vóór een publieke release één keer
  laten testen in een nieuwere FL.
- `LP_DEV_EDITOR` (CMake-optie, standaard AAN): plugins tonen een kaal venster met één
  schuifje per parameter in plaats van de placeholder, om in FL te kunnen testen. Geen
  ontwerp. **Zet UIT vóór elke publieke build**, en verwijder zodra het echte paneel er is.

### Lokaal bouwen op Windows

Op de pc van de gebruiker staat Visual Studio 2022 Community met de werklast
"Desktop development with C++" (MSVC 14.44, Windows SDK 10.0.26100, CMake 3.31).
CMake staat niet in PATH; het script zoekt de CMake van Visual Studio zelf.

**Eén commando: bouwen, testen, installeren** (FL Studio dicht):

```powershell
powershell -ExecutionPolicy Bypass -File scripts\build-local.ps1
```

Build-map `%LOCALAPPDATA%\lpb`, afhankelijkheden `%LOCALAPPDATA%\lpdeps`. **Niet in de
repo bouwen**: MSBuild faalt op paden boven 260 tekens (gebeurd op 22 nov met de repo in
een diepe map). Eerste keer ± 5–10 min (JUCE ophalen), daarna alleen wat veranderd is.
`-NoInstall` bouwt en test zonder te installeren. Uitvoer:
`%LOCALAPPDATA%\lpb\plugins\disc1\lp_disc1_artefacts\Release\{VST3,CLAP,Standalone}`.

### Installeren voor FL Studio

Sluit FL Studio (het houdt geladen plugins vast). Dan, met beheerdersrechten-prompt:

- lokale build (zonder opnieuw te bouwen): `powershell -ExecutionPolicy Bypass -File scripts\install-local.ps1`
- nieuwste CI-build: `powershell -ExecutionPolicy Bypass -File scripts\get-latest.ps1`

Beide schrijven naar `C:\Program Files\Common Files\VST3` en `\CLAP`, dus de ene vervangt
de andere (zelfde plugin-ids, geen dubbelen in FL). Nieuwe plugin: in FL
*Options → Manage plugins → Find more plugins*. Een bestaande update laadt FL bij het
heropenen van het project.

## Volgende stappen

1. ~~FL-test van de testsynth~~ **klaar** (22 nov): alles geslaagd, zie tabel.
2. **Akkoord op de art direction** vragen (moodboard). Nog niet expliciet gegeven; de
   gebruiker geeft zijn oordeel als eerstvolgende stap.
3. **Eerste echte render van het disc 1-paneel** in de Browser-ruimte: kubus-sequencer,
   prisma-ring-knoppen, VFD-strook, Vib-Ribbon-lijn als scope. Eerst als beeld (Blender of
   een realtime render) ter beoordeling, pas daarna in JUCE.
4. Daarna DSP van disc 1: Reese, hoover, 303-acid met accent-opbouw, SH-101-arp en
   sequencer met slide/accent/per-stap-parameters (zie `docs/research/02-sound-palette.md`).

## Nog te verifiëren

- PS1 SPU-reverb: formule, presets, licentie van PsxReverb. Clean-room bouwen, geen
  GPL-emulatorcode kopiëren.
- Windows code signing: Azure Artifact Signing is alleen voor individuen in VS/Canada.
- FL-eigenaardigheden: multi-out vraagt "Auto map outputs"; "Make bridged" breekt
  links tussen instanties; DPI-schaling boven 125% en met twee schermen met verschillende
  schaal nog niet gezien.

## Geschiedenis

Gestart op 22 november 2026 in een cloudsessie (Linux-container) die per ongeluk aan de
G02-repo hing. Daar zijn het onderzoek, de beeldresearch, het skelet en de CI gedaan.
Een eerste visie-pagina leek "te AI": die was op tekst gebaseerd, zonder dat iemand één
beeld had gezien. Het beeldonderzoek corrigeerde veel (zie de tabel onderaan
`GUIDELINES.md`). Les: bij esthetiek altijd echte beelden bekijken, en de gebruiker vragen
wat hij in zijn hoofd heeft.
