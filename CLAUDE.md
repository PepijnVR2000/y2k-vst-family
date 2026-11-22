# Werkregels voor agents

Lees eerst `HANDOFF.md`. Die is de actuele waarheid; werk hem bij in dezelfde commit
als je werk wanneer de stand verandert.

## Rollen

- De orchestrator-sessie verdeelt werk over agents en heeft de **eindbeslissing over de UI**.
  Wijk niet af van de vastgelegde art direction zonder dat die eerst is aangepast.
- De gebruiker test in FL Studio op Windows; zijn oren en ogen zijn de eindtoets.
  Een groene testsuite bewijst niet dat iets goed klinkt of eruitziet.

## Harde UI-regels

- Volg `docs/design/GUIDELINES.md` (System Browser). Die gaat voor op `docs/research/01-ui-aesthetic.md`.
- Eén licht (linksboven) en één materiaalbibliotheek voor de hele familie. Geen chroom, geen geborsteld metaal.
- Nooit post-effecten (bloom, dither, scanlines, CRT) over tekst. Waarden scherp in de VFD-strook.
- Standaardlook is strak PS2; PS1-artefacten alleen via de Render Engine-settings.
- Warme accenten tegen "liminal horror"-drift.
- Verzin de console: geen Sony/Xbox/Nintendo-merken, geen △○×□-glyphs, geen nep-Japans
  of Designers Republic-clichés.
- UI-geluiden standaard uit (ze zouden in bounces belanden).
- Boot-animatie ≤ 1,2 s, alleen eerste keer per sessie. Animatie pauzeert als het venster
  verborgen is; idle ≤ 30 fps; nooit alloceren in paint.
- Parameterfeedback altijd direct (1:1), alleen decoratie animeert.

## Audio en content

- Nooit alloceren of locken op de audio-thread. Test met variabele blokgroottes (FL doet dat).
- Geen originele breaks, ROM-samples of game-assets meeleveren. Geen GPL-code kopiëren
  (Mednafen, DuckStation, PCSX2); emulatie clean-room vanuit openbare documentatie.

## Git

- Werk op een eigen branch per taak; `main` blijft schoon en bouwbaar.
- Commit geen build-output, binaries of secrets.
