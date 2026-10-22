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

## Versija 0.3

Šioje versijoje atliktas `std::vector` ir `std::list` konteinerių našumo palyginimas.

### Pagrindiniai pakeitimai

1. Pridėta galimybė programos pradžioje pasirinkti konteinerį:
   - `1` – `std::vector<studentas>`.
   - `2` – `std::list<studentas>`.
2. Abu konteineriai naudojami studentų duomenims nuskaityti, skirstyti, rūšiuoti ir rezultatams įrašyti.
3. `std::vector` studentai į grupes perkeliami naudojant `std::move()`.
4. `std::list` studentai į grupes perkeliami naudojant `splice()`.
5. `std::vector` rūšiuojamas naudojant `std::sort()`, o `std::list` – `list.sort()`.
6. Rankiniu būdu įvedant studentų duomenis, išvedamas studento objekto atminties adresas.
7. Atliktas abiejų konteinerių našumo tyrimas su penkiais skirtingo dydžio duomenų failais.

### Testavimo kompiuteris

| Komponentas | Specifikacija |
|---|---|
| Procesorius | Snapdragon X 12-core X1E80100 |
| Procesoriaus dažnis | 3,40 GHz |
| Procesoriaus branduoliai | 12 |
| Operatyvioji atmintis | 16 GB LPDDR5 |
| RAM greitis | 8448 MT/s |
| Diskas | NVMe SSD |
| Operacinė sistema | Windows |

### Našumo tyrimo metodika

Buvo lyginami `std::vector<studentas>` ir `std::list<studentas>` konteineriai.

Naudoti penki duomenų failų dydžiai: 1 000, 10 000, 100 000, 1 000 000 ir 10 000 000 studentų.

Kiekvienas failas buvo apdorotas po tris kartus su kiekvienu konteineriu, naudojant tuos pačius pradinius duomenis.

Visuose `v0.3` bandymuose studentai rūšiuoti pagal pavardę.

Atskirai matuotos keturios operacijos:
- Duomenų nuskaitymas iš failo.
- Studentų skirstymas į vargšiukus ir kietiakus.
- Abiejų grupių rūšiavimas.
- Rezultatų įrašymas į failus.

Lentelėse pateikiami trijų bandymų aritmetiniai vidurkiai sekundėmis. Bendra trukmė apskaičiuota sudėjus keturių matuotų operacijų laikus. Vartotojo pasirinkimų įvedimo laikas neįtrauktas.

### v0.3 našumo tyrimo rezultatai

Toliau pateikiami trijų bandymų aritmetiniai vidurkiai sekundėmis. Abiem konteineriams naudoti tie patys pradiniai failai, o studentai rūšiuoti pagal pavardę.

#### `std::vector` rezultatai

| Studentų kiekis | Nuskaitymas (s) | Skirstymas (s) | Rūšiavimas (s) | Įrašymas (s) | Iš viso (s) |
|---|---:|---:|---:|---:|---:|
| 1 000 | 0.013502 | 0.001334 | 0.002523 | 0.007550 | 0.024909 |
| 10 000 | 0.032267 | 0.004813 | 0.028066 | 0.024028 | 0.089174 |
| 100 000 | 0.241075 | 0.049694 | 0.319308 | 0.162798 | 0.772875 |
| 1 000 000 | 2.224707 | 0.408699 | 3.233653 | 1.658493 | 7.525552 |
| 10 000 000 | 23.797733 | 3.921900 | 33.888500 | 16.361067 | 77.969200 |

#### `std::list` rezultatai

| Studentų kiekis | Nuskaitymas (s) | Skirstymas (s) | Rūšiavimas (s) | Įrašymas (s) | Iš viso (s) |
|---|---:|---:|---:|---:|---:|
| 1 000 | 0.004267 | 0.000402 | 0.000618 | 0.016526 | 0.021813 |
| 10 000 | 0.032968 | 0.001950 | 0.007142 | 0.057715 | 0.099775 |
| 100 000 | 0.246004 | 0.017517 | 0.063136 | 0.395943 | 0.722600 |
| 1 000 000 | 2.227920 | 0.157941 | 0.633990 | 3.734443 | 6.754294 |
| 10 000 000 | 22.328300 | 1.543723 | 7.656810 | 37.861533 | 69.390366 |

#### Bendros trukmės palyginimas

| Studentų kiekis | `std::vector` (s) | `std::list` (s) | Greitesnis konteineris |
|---|---:|---:|---|
| 1 000 | 0.024909 | 0.021813 | `list` |
| 10 000 | 0.089174 | 0.099775 | `vector` |
| 100 000 | 0.772875 | 0.722600 | `list` |
| 1 000 000 | 7.525552 | 6.754294 | `list` |
| 10 000 000 | 77.969200 | 69.390366 | `list` |

### v0.3 tyrimo išvados

1. Didėjant studentų skaičiui, abiejų konteinerių apdorojimo trukmė ilgėjo.
2. `std::list` skirstymo operacija visuose atliktuose bandymuose buvo greitesnė. Tam įtakos turi naudojama `splice()` funkcija, leidžianti perkelti sąrašo elementus nekopijuojant studentų objektų.
3. `std::list` rūšiavimas pagal pavardę visuose atliktuose bandymuose buvo greitesnis nei `std::vector` rūšiavimas.
4. `std::vector` visuose bandymuose greičiau įrašė suskirstytus studentus į tekstinius failus.
5. Apdorojant 10 000 000 studentų, vidutinė bendra `vector` trukmė buvo apie 77,97 s, o `list` – apie 69,39 s.
6. Tyrimas parodė, kad konteinerio našumas priklauso nuo atliekamos operacijos. Vienas konteineris nebūtinai yra greičiausias visais atvejais.
7. Mažų failų rezultatai gali labiau svyruoti dėl sistemos apkrovos, disko talpyklos ir kitų aplinkybių.
