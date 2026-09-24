#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <random>
#include <fstream>
#include <sstream>

struct studentas {
std :: string vardas;
std :: string pavarde;
std :: vector<int> namudarbai;
int egzaminas;
};

double Vidurkis (const std:: vector <int>& namudarbai){
  if (namudarbai.empty()) {
    return 0.0;
  }

  double suma = 0.0;

  for (int i=0; i < namudarbai.size(); i++){
    suma = suma + namudarbai[i];
  }

  return suma / namudarbai.size();
  
}

double Mediana(std :: vector<int> namudarbai){
  if (namudarbai.empty()){
    return 0.0;
  }
  std :: sort(namudarbai.begin(), namudarbai.end());
  
  int dydis = namudarbai.size();

  if (dydis % 2 == 0){
    return (namudarbai[dydis / 2 - 1] + namudarbai[dydis / 2]) / 2.0;
  }
  else {
    return namudarbai[dydis / 2];
  }
}

int generuotipazymi(){
  static std :: random_device atsitiktine_prad_reiksme;
  static std :: mt19937 generatorius(atsitiktine_prad_reiksme());
  std :: uniform_int_distribution<int> intervalas(1,10);

  return intervalas(generatorius);
  
}
bool rikiavimas_pagal_pavarde(const studentas& pirmas, const studentas& antras){
  return pirmas.pavarde < antras.pavarde;
}


int main(){

  std :: vector <studentas> studentai;

  int veiksmas;
  std::cout << "Pasirinkite programos veiksma:" << std::endl;
  std::cout << "1 - Ivesti studentu duomenis" << std::endl;
  std::cout << "2 - Nuskaityti studentus is failo" << std::endl;
  std::cout << "Pasirinkimas: ";
  std::cin >> veiksmas;

while (veiksmas != 1 && veiksmas != 2) {
    std::cout << "Klaida. Pasirinkite 1 arba 2: ";
    std::cin >> veiksmas;
}

  if (veiksmas == 1){

  while (true){
  studentas S;

  std :: cout << "Iveskite studento varda: ";
  std :: cin >> S.vardas;

  std :: cout << "Iveskite studento pavarde: ";
  std :: cin >> S.pavarde;

  int budas;
    
  std::cout << "\nPasirinkite pazymiu ivedimo buda:" << std::endl;
  std::cout << "1 - Ivesti pazymius ranka" << std::endl;
  std::cout << "2 - Generuoti pazymius atsitiktinai" << std::endl;
  std::cout << "Pasirinkimas: ";
  std::cin >> budas;
    
  while (budas !=1 && budas !=2){
    std :: cout << "Klaida, galima pasirinkti tik 1 arba 2 buda: ";
    std :: cin >> budas;
  }

  if (budas == 1){
  std :: cout << "Iveskite namu darbu pazymius (desimt baleje sistemoje)." << std :: endl;
  std :: cout << "Baige ivesti, iveskite 0." << std :: endl;

  int pazymys;

  while (true){
    std :: cout << "pazymys: ";
    std :: cin >> pazymys;
    if (pazymys == 0){
      break;
    }

    if (pazymys >= 1 && pazymys <= 10) {
      S.namudarbai.push_back(pazymys);
    }
    else {
      std :: cout << "Klaida. Pazymys turi buti desimt baleje sistemoje." << std :: endl;
    }
  }

  std :: cout << "Iveskite egzamino rezultata: ";
  std :: cin >> S.egzaminas;

  while (S.egzaminas < 1 || S.egzaminas > 10) {
    std::cout << "Klaida. Egzamino rezultatas turi buti nuo 1 iki 10." << std::endl;
    std::cout << "Iveskite egzamino rezultata dar karta: ";
    std::cin >> S.egzaminas;
}
  }
  else if (budas == 2){
    int kiek;

    std :: cout << "Kiek namu darbu pazymiu sugeneruoti? ";
    std :: cin >> kiek;

    for (int i=0; i < kiek; i++) {
      S.namudarbai.push_back(generuotipazymi());
    }

    S.egzaminas = generuotipazymi();

    std :: cout << "Sugeneruoti namu darbu pazymiai: ";

    for (int i = 0; i < S.namudarbai.size(); i++){
      std :: cout << S.namudarbai[i] << " ";
    }
    std :: cout << std :: endl;
    std :: cout << "Sugeneruotas egzamino rezultatas: " << S.egzaminas << std :: endl;
  }
  double vidurkis = Vidurkis(S.namudarbai);
  double mediana = Mediana(S.namudarbai);

  double galutinisVid = 0.4 * vidurkis + 0.6 * S.egzaminas;
  double galutinisMed = 0.4 * mediana + 0.6 * S.egzaminas;

  std :: cout << "Galutinis balas (Vid.): " << std :: fixed << std :: setprecision(2) << galutinisVid << std :: endl;
  std :: cout << "Galutinis balas (Med.): " << std :: fixed << std :: setprecision(2) << galutinisMed << std :: endl;

    studentai.push_back(S);

    char testi;

    std :: cout << "Ar norite ivesti dar viena studenta? (t/n): ";
    std :: cin >> testi;

    if (testi == 'n' || testi == 'N'){
      break;
    }
  }
  }
  else if (veiksmas == 2){
    std :: string failoPav;
    std :: cout << "Iveskite failo pavadinima: ";
    std :: cin >> failoPav;
    std :: ifstream failas(failoPav);

    if(!failas.is_open()){
    std :: cout << "Nepavyko atidaryti failo." << std :: endl;
  }
    else {
    std :: cout << "Failas atidarytas." << std :: endl;
    std :: string antraste;
    std :: getline(failas, antraste);

    std :: string eil;

      while (std :: getline(failas, eil)){
        studentas S;

        std :: istringstream eilutesSrautas(eil);

        eilutesSrautas >> S.pavarde >> S.vardas;

        int pazymys;
        std :: vector<int> pazymiai;
        while (eilutesSrautas >> pazymys){
          pazymiai.push_back(pazymys);
        }
        if (!pazymiai.empty()){
          S.egzaminas = pazymiai.back();
          pazymiai.pop_back();

          S.namudarbai = pazymiai;
          studentai.push_back(S);
        }
      }

      
    // std::cout << "Nuskaityta studentu: " << studentai.size() << std::endl;

    //std :: cout << "Failo antraste: " << antraste << std :: endl;
      std :: cout << "Duomenys sekmingai nuskaityti is failo." << std :: endl;
  }
  }

  std :: sort(studentai.begin(), studentai.end(), rikiavimas_pagal_pavarde);
  std::cout << std::endl;

std::cout << std::left << std::setw(20) << "Pavarde" << std::setw(20) << "Vardas" << std::setw(20) << "Galutinis (Vid.)" << std::setw(20) << "Galutinis (Med.)" << std::endl;

std::cout << "--------------------------------------------------------------------------" << std::endl;


  for (int i=0; i < studentai.size(); i++){
    double vidurkis = Vidurkis(studentai[i].namudarbai);
    double mediana = Mediana(studentai[i].namudarbai);

    double galutinisVid = 0.4 * vidurkis + 0.6 * studentai[i].egzaminas;
    double galutinisMed = 0.4 * mediana + 0.6 * studentai[i].egzaminas;

    std::cout << std::left << std::setw(20) << studentai[i].pavarde << std::setw(20) << studentai[i].vardas << std::setw(20) << std::fixed << std::setprecision(2) << galutinisVid << std::setw(20) << galutinisMed << std::endl;

    
  }
  
  return 0;
}
