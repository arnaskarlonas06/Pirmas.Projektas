#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <vector>
#include "studentas.h"
#include <string>

double Vidurkis (const std :: vector<int>& namudarbai);
double GalutinisVidurkis(const studentas& S);
void padalinti_studentus (const std :: vector<studentas>& studentai, std :: vector<studentas>& vargsiukai, std :: vector<studentas>& kietiakiai);
double Mediana (std :: vector<int> namudarbai);
int generuotipazymi();
bool rikiavimas_pagal_pavarde(const studentas& pirmas, const studentas& antras);
void generuoti_faila (const std :: string& failoPavadinimas, int studentuKiekis);
void irasyti_studentus_i_faila(const std :: string& failoPavadinimas, const std :: vector<studentas>& studentai);

#endif
