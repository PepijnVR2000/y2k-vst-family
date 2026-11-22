# UI-richtlijnen: System Browser

Versie 1, 22 november 2026. Gebaseerd op 48 bekeken beelden (`docs/research/05-…` en `06-…`),
gecureerd tot 24 in `docs/design/references/` en `docs/design/moodboard.html`.
**Vervangt** de visuele woordenschat, paletten en de drie richtingen in
`docs/research/01-ui-aesthetic.md` en in `docs/vision/fase1-synthese.html`. Die waren
op tekst gebaseerd en bleken op veel punten fout (zie "Correcties" onderaan).

Kleurwaarden met "gemeten" komen uit de pixels van de referenties.

## 1. Concept

Elke plugin is een **ruimte in het systeemmenu van een verzonnen console uit ~2001**.
Niet een apparaat met een behuizing (GameVerb bezet dat terrein met een controllervormige
body), maar de software van de console zelf. Objecten zweven in een lichte ruimte, wat je
kiest krijgt licht, tekst is groot en vriendelijk.

## 2. Drie ruimtes per plugin

| Ruimte | Functie | Basis | Ref |
|---|---|---|---|
| **Browser** | Spelen: stappen, hoofdknoppen, scope | Radiale gradiënt warmgrijs: midden `#8f9590` → `#5e625a` → rand `#272922` (gemeten) | 01, 02 |
| **Systeem** | Instellingen, Render Engine-graphics | Violette wolken: `#312456` / `#241b46` → diep `#090517` (gemeten), zachte wolkenruis | 03, 04 |
| **Memory card** | Presets | Browser-grijs, 3D-save-iconen die langzaam draaien | 01, 07 |

- Wisselen tussen ruimtes is een camerabeweging door de ruimte (diepte), geen tabblad-flits.
  450–650 ms, ease-in-out.
- **Geen panelen, kaders of kaarten** in de Browser-ruimte. Groepen ontstaan door afstand
  en uitlijning. Enige uitzondering: de VFD-strook.

## 3. Kiezen en status

- Geselecteerd/actief object: **witte lichtpoel eronder** (bloom, wit 60–80%), en het object
  komt iets omhoog en wordt ~6% groter (GameCube memory card). 150–250 ms.
- Nooit omlijningen, highlight-balken of focusrechthoeken rond objecten (toetsenbordfocus
  gebruikt dezelfde lichtpoel).
- Actieve tekstregel: groter en cyaan `#72c7d7`.
- Afspeelpositie in de sequencer: de kubus gloeit van binnenuit wit.
- Uit/inactief: object dimt naar ~55% en verliest zijn lichtpoel. Geen wireframes.

## 4. Tekst

- Afgerond sans, medium gewicht, **gewone hoofdletters (sentence case)**, normale spatiëring.
  Werkkeuze: M PLUS Rounded 1c (OFL). Een eigen letter kan later.
- **Groot**: 3–5% van de vensterhoogte; bij 600 px hoog: titels 26–30 px, labels 18–20 px,
  kleinste tekst 14 px.
- Drie kleuren: gebroken wit `#eef0ea` (standaard), geelgroen `#e4f17c` (titels, context),
  cyaan `#72c7d7` (actief). Zachte schaduw 1–2 px, zwart 50%.
- Geen caps-microlabels, geen techno-letter in de hoofd-UI (dat was Xbox/WipEout, niet PS2).
- Nooit bloom, dither, scanlines of andere effecten over tekst.

## 5. Bediening

| Element | Vorm | Ref |
|---|---|---|
| **Stap** | Zwevende kubus met nummer, rijen van 8, kleurverloop per disc over het patroon | 02 |
| **Hoofdknop** | **Prisma-ring**: 12 glazen prisma's in een cirkel; de waarde vult/verlicht de prisma's als een meter; bij aanraken staat de waarde groot in het midden | 03 |
| **Kleine knop** | Matte cilinder, 1 px bevel, licht linksboven, één indicatorstreep | 16 |
| **Toggle** | Doorschijnende toets die van binnen gloeit als hij aan staat | 16, 18 |
| **Speelse actie** | Glanzende snoepbal, hooguit 1–2 per plugin (randomize, Break Pet) | 20 |
| **Pagina's binnen een ruimte** | Vlakken van één draaiend glazen object | 06 |

- Parameters volgen de muis 1:1, zonder vertraging. Alleen decoratie animeert.

## 6. Materiaal en licht

- Materialen: **glas** (prisma's, geselecteerde iconen in ijsblauw), **mat korrelig blok**
  (grote vormen, boot), **doorschijnend verlicht plastic** (toetsen, kubussen).
- **Geen chroom, geen geborsteld metaal, geen gekleurd randlicht.**
- Eén licht, linksboven. Bevels 1 px. Hooguit 2 highlightlagen per object.
- Diepte komt van een zachte schaduw onder zwevende objecten en bloom op het actieve object.

## 7. Waarden en displays

- Alle precieze waarden staan in een **VFD-strook**: glyphs `#f2fdfb` met lichte gloed op
  `#1a2c3a`, uitgeschakelde segmenten zichtbaar in `#2e445b` (SU700, ref 17).
- Tempo en tijd: amber dot-matrix `#cbab36` op zwart raster (GameCube-klok, ref 08).
- De VFD is het enige rechthoekige "paneel" in de Browser-ruimte.

## 8. Identiteit per disc

Zelfde basis voor de hele familie, één kleurverloop per disc (Electribe-principe, ref 15).
Het verloop kleurt de stap-kubussen; het merkteken is een stapel kleurstrepen (Wip3out, ref 11).

| Disc | Verloop | Bron |
|---|---|---|
| 1 · mono arp | `#3f4eaf` → `#4d8a9f` → `#38c176` → `#68f877` | PS2 audio-cd-kubussen (gemeten) |
| 2 · drums | `#7a4c10` → `#cbab36` → `#f2a70d` → `#fef579` | GameCube-amber, Wip3out-selectie, Electribe-geel |
| 3 · poly | `#241b46` → `#5865ac` → `#72c7d7` → `#7cbbf3` | PS2-klokprisma's (gemeten) |
| 4 · sampler | `#6a6048` → `#ece3c3` → `#48b3a8` → `#81a7c8` | MPC2000XL, Dreamcast-lucht |

## 9. Render Engine

- De zes graphics settings staan in de **Systeem-ruimte**, als in een echt console-menu.
- Standaard: strak PS2 (bilineair, Gouraud, zachte bloom).
- Omlaag gedraaid zakt het beeld naar PS1 (ref 21): vertex-jitter, affine textures, dither,
  lage resolutie, rafelige regenbooglabels. Het geluid zakt mee.

## 10. Beweging en prestaties

- Save-iconen en prisma's draaien langzaam (één omwenteling per 8–14 s), synchroon met het
  host-tempo als de transport loopt.
- Boot ≤ 1,2 s, alleen de eerste keer per sessie.
- Idle ≤ 30 fps; animatie stopt als het venster verborgen is; nooit alloceren in paint.
- UI-geluiden standaard uit.

## 11. Niet doen

- Donkere navy/paarse basis met neon en platte boogknoppen: daar zitten GuyEngine V2,
  Y2K Club, chipsynth al (refs 22, 24).
- Een apparaat- of controllerbehuizing (GameVerb, ref 23).
- Chroom, geborsteld aluminium, lens flares, vlinders, tribal, bubbelletters.
- Sony/Xbox/Nintendo-merken, △○×□, nep-Japans, Designers Republic-clichés.
- Het Xbox-groen en de Xbox-orb (te herkenbaar), behalve het polygoonweb als patroon.

## Correcties ten opzichte van het tekstonderzoek

| Tekstonderzoek zei | Gezien |
|---|---|
| PS2-menu's: donkere navy void | Violette wolken of lichtgrijs |
| Boot-torens: doorzichtig kristal | Matte, korrelige grijs-lila blokken |
| Selectie: schaalveer en glans-sweep | Lichtpoel eronder, of groter + andere kleur |
| Labels in caps, +6–10% spatiëring, 9–11 px | Sentence case, normale spatiëring, 3–5% schermhoogte |
| Chroom en geborsteld aluminium | Niet gezien |
| MPC-scherm grijsgroen; sampler-displays amber | MPC teal; SU700 cyaan-wit VFD |
| Gekleurd randlicht per plugin | Bestond niet; 1 px bevels, licht linksboven |
| "PS2 cobalt #2E5BFF" | Nergens; echte kleuren zijn violet, teal, cyaan, geelgroen |
| Xbox-hexagonen | Onregelmatig polygoonweb |
| Niemand doet een console-look | GameVerb doet een console-apparaat; het OS is nog vrij |

Afbeeldingen in `references/` zijn screenshots en productfoto's van derden, alleen voor
intern ontwerpwerk. Niet meeleveren of publiceren.
