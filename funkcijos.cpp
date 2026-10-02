#include "funkcijos.h"
#include <algorithm>
#include <random>

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
