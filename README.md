# Lowpoly System (werktitel)

Een familie VST3/CLAP-instrumenten voor FL Studio met een Y2K / PS2-tijdperk UI
(3D-knoppen, console-menu's, memory-card presets) en een wavy jungle /
breakbeat / drum & bass sound.

*Lower the graphics. Raise the vibe.*

## Status

**Fase 1 (onderzoek) is afgerond. Fase 0 (skelet + CI) staat op branch
`claude/skeleton-ci`:** CMake + JUCE 9 + CLAP, een eerste instrument-shell
(`lp_disc1`, nog zonder echte UI) en tests. Namen zijn codenamen ("LP", "LP Disc 1 (dev)").
Zie `HANDOFF.md` voor de actuele stand en de open beslissingen.

## Inhoud

| Pad | Wat |
|---|---|
| `HANDOFF.md` | Actuele stand, beslissingen, volgende stappen. Begin hier. |
| `CLAUDE.md` | Werkregels voor AI-agents in deze repo |
| `docs/vision/fase1-synthese.html` | Synthese van fase 1 (ook als pagina: https://claude.ai/artifact/NDx661jybpyVaKktLxdtmw) |
| `docs/research/01-ui-aesthetic.md` | UI-esthetiek: referenties, beeldtaal, drie art directions |
| `docs/research/02-sound-palette.md` | Geluid: genre, breaks, sounds per instrument, signature-effecten |
| `docs/research/03-innovation-landscape.md` | Innovatie en markt: concurrentie, ideeën, kerninnovatie |
| `docs/research/04-tech-stack.md` | Techniek: FL Studio, JUCE, 3D-UI, CI, fasering |
| `cmake/Names.cmake` | **Enige plek** voor familie-, merk- en pluginnamen en ids |
| `cmake/Dependencies.cmake` | Vastgepinde versies: JUCE, clap-juce-extensions, Catch2 |
| `libs/lp_core/` | Gedeelde code: DSP-bouwstenen (zonder JUCE), parameterhelpers, versie/build-hash, placeholder-editor |
| `plugins/disc1/` | Eerste instrument-shell: mono saw → lowpass → amp-env, last-note priority, legato glide |
| `tests/` | Catch2-tests (offline render, blokgroottes, state, NaN, allocaties) |
| `.github/workflows/build.yml` | CI: Linux (build, tests, pluginval, clap-validator) en Windows x64 (MSVC, VST3 + CLAP) |
| `scripts/get-latest.ps1` | Nieuwste Windows-build downloaden en installeren |

## De familie

| Disc | Instrument | Accent | Status |
|---|---|---|---|
| 1 | Mono arp synth | acid groen | gepland (voorstel: eerst) |
| 2 | Drum computer | geel / amber | gepland (vlaggenschip) |
| 3 | Poly synth | kobalt | gepland |
| 4 | Sampler | oranje | later |

## Bouwen

Vereist: CMake ≥ 3.28, een C++20-compiler (MSVC 2022+, GCC 13+ of Clang 16+), Git.
Afhankelijkheden worden bij de eerste configure opgehaald en op exacte commits
gecontroleerd (`cmake/Dependencies.cmake`).

**Windows (x64, primair doel)**

```powershell
cmake -S . -B build -A x64
cmake --build build --config Release --parallel
ctest --test-dir build -C Release --output-on-failure
```

**Linux (agents, tests)**

```bash
sudo apt-get install -y ninja-build libasound2-dev libfreetype-dev libfontconfig1-dev \
  libx11-dev libxcomposite-dev libxcursor-dev libxext-dev libxinerama-dev \
  libxrandr-dev libxrender-dev libxi-dev xvfb
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel
ctest --test-dir build --output-on-failure
```

Uitvoer staat in `build/plugins/<plugin>/<target>_artefacts/Release/{VST3,CLAP,Standalone}`.
De bestandsnaam is de productnaam zonder haakjes (`LP Disc 1 dev.vst3`); de naam in
de host blijft `LP Disc 1 (dev)`. Opties: `-DLP_BUILD_TESTS=OFF`,
`-DLP_COPY_PLUGIN_AFTER_BUILD=ON`, `-DLP_DEPS_DIR=.cache/deps` (downloads bewaren
buiten de build-map).

**Hernoemen:** pas alleen `cmake/Names.cmake` aan. Weergavenamen mogen vrij
veranderen; de codes/ids (manufacturer code, plugin code, CLAP-id) moeten vóór de
eerste publieke build vastliggen, anders vindt FL Studio de plugin in oude projecten
niet meer terug.

## Nieuwste build installeren (Windows)

Elke push bouwt via GitHub Actions een artifact `lp-windows-x64-<korte sha>`
(VST3 + CLAP + `BUILD_INFO.txt`). Installeren:

1. Eenmalig: installeer de GitHub CLI (`winget install GitHub.cli`) en log in met `gh auth login`.
2. Sluit FL Studio (het houdt geladen plugins vast).
3. Vanuit de repo-map:

   ```powershell
   powershell -ExecutionPolicy Bypass -File scripts\get-latest.ps1
   # andere branch:
   powershell -ExecutionPolicy Bypass -File scripts\get-latest.ps1 -Branch claude/skeleton-ci
   ```

Het script zoekt de laatste geslaagde run, downloadt het artifact, kopieert `*.vst3`
naar `C:\Program Files\Common Files\VST3` en `*.clap` naar
`C:\Program Files\Common Files\CLAP` (vraagt dan om beheerdersrechten) en toont de
commit. Daarna in FL Studio: *Options → Manage plugins → Find more plugins*.

## Licenties

JUCE is dubbel gelicentieerd: AGPLv3 of een commerciële JUCE-licentie. Zolang de code
privé en onuitgebracht is volstaat AGPLv3; voor een closed-source release is minimaal
de (gratis) Starter-licentie nodig. Zie `docs/research/04-tech-stack.md` en JUCE's
`LICENSE.md`. clap-juce-extensions is MIT, Catch2 is BSL-1.0.
