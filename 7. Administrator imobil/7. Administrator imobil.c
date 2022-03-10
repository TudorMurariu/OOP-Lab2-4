#include <stdio.h>
#include "cheltuieli.h"
#include "UI.h"
#include "Lista.h"
#include "Service.h"
#include "Repo.h"
#include "Validators.h"

void tests();

int main()
{
    // definim lista 
    Lista lista_cheltuieli;
    lista_cheltuieli.len = 0;

    // pornim aplicatia din UI
    tests();
    start_console(&lista_cheltuieli);
    return 0;
}

/*
    7. Administrator imobil
    Creati o aplicatie care petmite gestiunea de cheltuieli lunare pentru 
    apartamentele dintr-un bloc.
    Fiecare cheltuiala are: numarul apartamentului, suma, tipul 
    (apa, canal, incalzire, gaz).

    Aplicatia permite:
    a) Adaugarea de cheltuieli pentru un apartament
    b) Modificarea unei cheltuieli existente (tipul, suma)
    c) Stergere cheltuiala
    d) Vizualizare lista de cheltuieli filtrat dupa o proprietate 
    (suma, tipul,apartament)
    e) Vizualizare lista de cheltuieli ordonat dupa suma sau tip 
    (crescator/descrescator)
*/

void tests()
{
    /// <summary>
    /// Aceasta functie apeleaza toate functiile de teste din program
    /// </summary>
     
    test_isType();
    test_Adauga();
    test_Modifica();
    test_Sterge();
    test_not_negative();
}