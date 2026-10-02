#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <vector>
#include "studentas.h"

double Vidurkis (const std :: vector<int>& namudarbai);
double Mediana (std :: vector<int> namudarbai);
int generuotipazymi();
bool rikiavimas_pagal_pavarde(const studentas& pirmas, const studentas& antras);

#endif
