#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <vector>
#include "studentas.h"
#include <string>

double Vidurkis (const std :: vector<int>& namudarbai);
double Mediana (std :: vector<int> namudarbai);
int generuotipazymi();
bool rikiavimas_pagal_pavarde(const studentas& pirmas, const studentas& antras);
void generuoti_faila (const std :: string& failoPavadinimas, int studentuKiekis);

#endif
