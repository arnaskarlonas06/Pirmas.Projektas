#include "funkcijos.h"
#include <algorithm>
#include <random>
#include <fstream>
#include <chrono>
#include <iostream>

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
double GalutinisVidurkis(const studentas& S){
  double vidurkis = Vidurkis(S.namudarbai);
  return 0.4 * vidurkis + 0.6 * S.egzaminas;
}
void padalinti_studentus(const std::vector<studentas>& studentai, std::vector<studentas>& vargsiukai, std::vector<studentas>& kietiakiai){
  for (int i=0; i<studentai.size(); i++){
    if(GalutinisVidurkis(studentai[i])<5.0){
      vargsiukai.push_back(studentai[i]);
    }
    else {
      kietiakiai.push_back(studentai[i]);
    }
  }
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
void generuoti_faila(const std :: string& failoPavadinimas, int studentuKiekis){
  auto pradzia = std :: chrono :: high_resolution_clock :: now();
  
  std :: ofstream failas(failoPavadinimas);

  failas << "Pavarde Vardas ND1 ND2 ND3 ND4 ND5 Egzaminas\n";

  for (int i=1; i <= studentuKiekis; i++){
    failas << "Pavarde" << i << " " << "Vardas" << i << " ";
    for (int j=0; j<5; j++){
      failas << generuotipazymi() << " ";
    }
    failas << generuotipazymi() << "\n";
  }
  failas.close();

  auto pabaiga = std :: chrono :: high_resolution_clock :: now();
  std :: chrono :: duration<double> laikas = pabaiga - pradzia;
  std :: cout << "Failo " << failoPavadinimas << " generavimas uztruko " << laikas.count() << " s." << std :: endl;
}
