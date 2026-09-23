#include <iostream>
#include <string>
#include <vector>

struct studentas {
std :: string vardas;
std :: string pavarde;
std :: vector<int> namudarbai;
int egzaminas;
};

int main(){
  studentas S;

  std :: cout << "Iveskite studento varda: ";
  std :: cin >> S.vardas;

  std :: cout << "Iveskite studento pavarde: ";
  std :: cin >> S.pavarde;

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
  return 0;
}
