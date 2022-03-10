#pragma once
#include "Validators.h"
#include "Lista.h"
#include "cheltuieli.h"
#include "Repo.h"
#include <string.h>
#include <assert.h>

int ValidareTip(char tip[21]);
int ValidareSuma(int suma);
int ValidareID(int id, Lista l);
void Adauga_predefinite(Lista* l);
void test_ValidareID();