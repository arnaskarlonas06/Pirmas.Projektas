#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <random>

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


int main(){
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
  
  
  return 0;
}
