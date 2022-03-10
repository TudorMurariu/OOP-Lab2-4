#pragma once
#include "Lista.h"
#include <string.h>
#include <assert.h>

void Adauga(cheltuiala c, Lista* l);
void Modifica(cheltuiala c, Lista* l);
void Sterge(int id, Lista* l);

Lista Filtrare1(int id,Lista* l);
Lista Filtrare2(int suma, Lista* l);
Lista Filtrare3(char tip[21], Lista* l);

Lista Sortare1(Lista l, int mod);
Lista Sortare2(Lista l, int mod);
int cmp1(cheltuiala c1, cheltuiala c2, int mod);
int cmp2(cheltuiala c1, cheltuiala c2, int mod);

void test_cmp1();
void test_cmp2();
void test_Adauga();
void test_Modifica();
void test_Sterge();