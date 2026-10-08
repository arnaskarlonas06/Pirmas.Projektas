# Pirmas.Projektas

Apie programa:
Tai C++ programa, skirta studentų duomenims apdoroti ir jų galutiniams pažymiams apskaičiuoti.
Galutinis pažymys apskaičiuojamas pagal formulę: Galutinis = 0,4 * namų darbų vidurkis + 0,6 * egzamino pažymys.
Programa taip pat gali apskaičiuoti galutinį pažymį naudojant namų darbų medianą.

Programa leidžia:
- Įvesti studentų duomenis rankiniu būdu.
- Atsitiktinai generuoti studentų pažymius.
- Nuskaityti studentų duomenis iš tekstinio failo.
- Generuoti tekstinius failus su pasirinktu studentų kiekiu.
- Suskirstyti studentus į dvi grupes pagal galutinį pažymį.
- Rikiuoti studentus pagal vardą, pavardę arba galutinį pažymį.
- Išsaugoti suskirstytus studentus atskiruose tekstiniuose failuose.
- Išmatuoti pagrindinių duomenų apdorojimo operacijų trukmę.

Versija 0.2
Šioje versijoje pridėta:

1. Studentų failų generavimas su 1 000, 10 000, 100 000, 1 000 000 ir 10 000 000 įrašų.
2. Studentų skirstymas į dvi grupes:
   - Vargsiukai – galutinis pažymys mažesnis nei 5,0.
   - kietiakiai – galutinis pažymys ne mažesnis nei 5,0.
3. Abiejų grupių išsaugojimas failuose `vargsiukai.txt` ir `kietiakiai.txt`.
4. Rikiavimas pagal vartotojo pasirinktą kriterijų.
5. Failo nuskaitymo, studentų skirstymo, rūšiavimo ir rezultatų įrašymo laiko matavimas.
6. Programos kodo suskirstymas į antraštinius (`.h`) ir realizacijos (`.cpp`) failus.
7. Studentų perkėlimas į grupes naudojant `std::move()`.

Programos paaleidimas:
Programai reikalingas C++ kompiliatorius, pavyzdžiui, `g++`.
Kompiliavimas:

g++ -std=c++11 pagrindinis.cpp funkcijos.cpp -o programa

Paleidimas:
./programa

Paleidus programą, galima pasirinkti vieną iš trijų veiksmų:

- `1` – įvesti studentų duomenis.
- `2` – nuskaityti studentus iš failo.
- `3` – sugeneruoti studentų failą.

Pasirinkus failo nuskaitymą, programa paprašo įvesti failo pavadinimą ir pasirinkti rūšiavimo būdą:

- `1` – pagal vardą.
- `2` – pagal pavardę.
- `3` – pagal galutinį pažymį.

Našumo tyrimas:

Buvo naudojami penki skirtingo dydžio studentų duomenų failai. Kiekvienas failas buvo apdorotas 3 kartus, pasirinkus rūšiavimą pagal galutinį pažymį.

Atskirai matuotas:

- Failo nuskaitymas.
- Studentų skirstymas į grupes.
- Studentų rūšiavimas.
- Rezultatų įrašymas į du failus.

Toliau pateikiami trijų bandymų laikų aritmetiniai vidurkiai sekundėmis.

| Studentų kiekis | Nuskaitymas (s) | Skirstymas (s) | Rūšiavimas (s) | Įrašymas (s) |
|---|---:|---:|---:|---:|
| 1 000 | 0,00897 | 0,00055 | 0,00334 | 0,06921 |
| 10 000 | 0,04304 | 0,00582 | 0,04162 | 0,02209 |
| 100 000 | 0,25539 | 0,04008 | 0,39605 | 0,17118 |
| 1 000 000 | 2,27400 | 0,44161 | 5,36025 | 1,80220 |
| 10 000 000 | 23,93310 | 4,07036 | 67,51763 | 17,40193 |

Tyrimo išvados:

Didėjant studentų kiekiui, ilgėja duomenų nuskaitymo, skirstymo, rūšiavimo ir įrašymo laikas.
Didžiausiems failams daugiausia laiko užtruko studentų rūšiavimas pagal galutinį pažymį.
Mažų failų matavimo rezultatai labiau svyravo, nes trumpoms operacijoms didesnę santykinę įtaką gali turėti operacinės sistemos ir disko apkrova.
Programa sėkmingai apdorojo visus penkis failų dydžius, įskaitant 10 000 000 studentų.

Pastabos:

Dideli sugeneruoti duomenų failai nėra būtini programos kodui saugoti GitHub saugykloje. Juos galima sugeneruoti naudojant trečiąjį programos meniu pasirinkimą.
Ateities versijose galima toliau optimizuoti programos atminties naudojimą ir duomenų apdorojimo spartą.
