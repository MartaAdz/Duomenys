# Duomenys

# Vertinimas

## Pastabos

- Truksta cmake failo (ATSIRADO)
- Atsitiktiniu skaiciu generavimas nelabai atsitiktinis, bet cia panasu, kad g++ kliurka. 


## Pagyrimai

- Visa kita

## Naudojimosi instrukcija

Pasileidziame programa. Iskart paklausiama ar nuskaitysime is failo, ar ivedinesime ranka. 

### Nuskaitymas is failo

1. Reikia sugeneruoti faila. Programa paklausia, kiek studentu noresime generuoti.
2. Pasirenkame konteinerio tipa, kuriame bus saugomi studentai (deque, list ar vector). Programa sugeneruoja studentus i pasirinkta konteineri ir issaugo faile "kursiokai.txt".
3. Pasirenkame skirstymo strategija. 
4. Programa informuoja, kad faile "kursas.dat" issaugoti pazangus studentai. T.y. tokie studentai, kuriu galutinis balas (naudojant vidurki) yra daugiau nei 5.
5. Programa paraso, kiek laiko uztruko programos vykdymas: 
- studentu konteinerio sukurimas, nuskaitymas is failo, 
- isrikiavimas pagal pavardes,
- suskirstymas i dvi grupes
- pazangiu studentu irasymas i faila

### Ivedimas ranka

1. Ivedame studento varda ir pavarde (tarp ju paspaudziame tarpa arba enter)
2. Pasirenkame ar pazymius generuos programa, ar ivedinesime ranka
- generuojant random, naudojamas random generatorius. Sugeneruojamas pasirinktas kiekis namu darbu ivertinimu ir egzamino pazymys. Jie isvedami i ekrana.
- ranka vedama iki tol, kol ivedamas -1. Ivedus netinkama simboli, ismetamas klaidos pranesimas. Paprasoma ivesti egzamino pazymi.
3. Pasirenkame ar skaiciuojant galutini bala naudosime mediana ar vidurki.
4. Pasirenkame ar tesime duomenu irasyma.



## Darbo eiga

### Pradine uzduotis

Parašykite programa, kuri nuskaito šiuos studentu duomenis:
-varda ir pavarde
-n atliktu namu darbu rezultatus, o taip pat galutinio egzamino rezultata.

Tuomet iš šiu duomenu, suskaiciuoja galutini bala :
 `galutinis = 0.4 * vidurkis + 0.6 * egzaminas` 

### Versija v0.1

#### Reikalavimai

1. Pagal užduoties reikalavimus realizuokite programa ir atspausdinkite ekrane aktualia informacija:
- studento varda ir pavarde,
- namu darbu ir egzamino rezultatus
- galutini bala dvieju skaiciu po kablelio tikslumu

2. Papildykite programa, kad vietoj vidurkio butu galima naudoti mediana.

3. Papildykite programa taip, kad ji veiktu ir tokiu atveju, kai namu darbu skaicius (n) yra nezinomas is anksto, 
t.y. tik ivedimo metu vartotojas nusprendzia kuomet jis jau ivede visu namu darbu rezultatus. Sia uzduoti (papildyma) realizuoti reiktu dviem budais:
- naudojant C masyvus.
- naudojant vector ar kito tipo konteineri.

4. Papildykite programa taip, kad butu galimybe, jog mokinio gautieji balai uz namu darbus bei egzamina butu generuojami atsitiktinai.

#### Realizacija

1. Naudota *<iostream>* biblioteka duomenu isvedimui ir ivedimui. Nenaudojama `namespace std` biblioteka, o parenkami tik reikalingi jos nariai `std::cout` `std::cin` `std::vector` `std::endl ` ir kt.
2. Naudojama `std::fixed<<setprecision(2)`
3. Naudojamas random skaiciu generatorius `std::random_device` 

### Versija v0.2

#### Reikalavimai

1. Duomenis ne tik ivesti, bet ir nuskaityti is failu.

2. Nuskaiciuoti duomenis is failo. Reikalavimai output’ui: studentai turi buto surusiuoti pagal vardus (ar pavardes) ir stulpeliai butu graziai "islygiuoti".

#### Realizacija

1. Naudota *<fstream>* biblioteka. 
2. Naudojama `std::left<<setw(20)`

### Versija v0.3

#### Reikalavimai

1. Kur tikslinga, programoje naudokite (jeigu dar nenaudojote) struct'uras

2. Funkcijas, naujus duomenu tipus (struct’uras) perkelkite i antrastinius (angl. header (*.h)) failus.

3. Kur tikslinga, panaudokite išimciu valdyma (angl. Exception Handling)

#### Realizacija

1. Sukurta studento struktura `studentas.h`
2. Funkcijos ir headeriai medianai ir vidurkiui skaiciuoti `mediana.h` `mediana.cpp` bei `vidurkis.h` `vidurkis.cpp`
3. Exception handling'as failui, kuriame saugomas studentu sarasas
```c++
std::ifstream duomenys("kursiokai.txt");

        try{
            if(duomenys.fail())
            {
                throw std::exception();
            }
        }
        catch (std::exception &e1)
        {   e1.what();
            cout<<"Tokio failo nera. Baigiu programa.";
            exit(1);
        }
```

### Versija v0.4

#### Reikalavimai

1. Sugeneruokite penkis atsitiktinius studentu failus, sudarytus is: 100, 1000, 10000, 100000 irasu. Vardus ir Pavardes generuoti "šabloninius" (Vardas1 Pavarde1, Vardas2 Pavarde2 ir t.t.)
2. Surusiuokite (padalinkite) studentus i dvi kategorijas:
- Studentai, kurie surinko < 5 uz namu darbu uzduotis
- Studentai, kurie surinko >= 5 uz namu darbu uzduotis ir buvo prileisti prie egzamino.
3. Ismatuokite visos programos (t.y. failu sukurima irgi reikia matuoti) veikimo laika testuojant su siais keturiais skirtingo dydzio duomenu failais.

#### Realizacija

*Studentu failu generavimo laikai*


| Elementu skaicius  |      Laikas, s      |  
|----------|:-------------|
| 10 | 0.00401 |
| 100 | 0.01 |
| 1000 | 0.15 | 
| 10000 | 7.31 | 

### Versija v0.5

#### Reikalavimai

1. Ismatuokite programos veikimo sparta (be failu generavimo) priklausomai nuo naudojamo vieno iš triju konteineriu:
- vector
- list
- deque

#### Realizacija

*Studentu failu generavimo laikai*


| Elementu skaicius  |   vector  |  list  | deque |
|---|---|---|---|
| 100 | 0.004045 | 0.00406 | 0.005014 |
| 1000 | 0.037601 | 0.035558 |0.044143 |
| 10000 | 0.377501 | 0.316956 | 0.383523 |
| 100000 | 4.13496 | 2.96753 | 4.32415 |


### Versija v1.0

#### Reikalavimai

1. Visiems trims konteineriu tipams (vector, list ir deque) ismatuokite programos veikimo sparta priklausomai nuo studentu dalijimo i dvi kategorijas strategijos:

- Bendro studentai konteinerio skaidymas (rušiavimas) panaudojant du naujus konteinerius: "vargšiuku" ir "kietiaku". Tokiu budu tas pats studentas yra dvejuose konteineriuose: studentai ir (vargšiukai arba kietiakai). 
- Bendro studentu konteinerio skaidymas (rušiavimas) panaudojant tik viena nauja konteineri: "vargšiukai". Tokiu budu, jei studentas yra vargšiukas, ji turime ikelti i "vargšiuku" konteineri ir ištrinti ir bendro studentai konteinerio. Tokiu budu, studentai konteineryje liks vien tik kietiakai.


#### Realizacija

1. Sukurtos atskiros funkcijos su elementu trynimu is konteineriu.

2. Naudoti algoritmai deque tipo konteineriui.

*Studentu failu generavimo laikai*

|Strategija| Elementu skaicius  |   vector  |  list  | deque |
|---|---|---|---|---|
|Perkeliant| 100 | 0.003004 | 0.003796 |  0.00278 |
|Trinant|  | 0.003007 | 0.002917 | 0.003746 |
|Perkeliant| 1000 |  0.027095 | 0.035558 | 0.028975 |
|Trinant|  |  0.079606 | 0.021253 | 0.028752 |
|Perkeliant| 10000 |  0.372993 | 0.234045 |  0.369981 |
|Trinant| | 15.4193 |  0.226891 | 0.409104 |
|Perkeliant| 100000 | 3.71094 | 2.4352 | 4.00827 |
|Trinant| | way too long | 1.88293 | 4.2199 |





















