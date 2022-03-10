#include "UI.h"
#include <stdio.h>
#include <string.h>
#include "cheltuieli.h"
#include "Repo.h"
#include "Validators.h"

void Afisare(Lista lista_cheltuieli)
{
	printf("Numarul de elemente este : %d\n", lista_cheltuieli.len);
	for (int i = 0; i < lista_cheltuieli.len; i++)
		printf("%d %d %s\n", lista_cheltuieli.array[i].id, lista_cheltuieli.array[i].suma, lista_cheltuieli.array[i].tip);
}

cheltuiala Citire_UI()
{
	/*
	* Citim de la tastatura o cheltuiala si o returnam
	*/
	int id;
	printf("Id-ul : ");
	scanf_s("%d", &id);
	int suma;
	printf("suma : ");
	scanf_s("%d", &suma);
	printf("tipul : ");
	char type[21];
	type[20] = '\0';
	scanf_s("%s",type,20);

	cheltuiala c;
	c.id = -1;
	c.suma = -1;
	strcpy_s(c.tip, 20, type);
	if (!isType(type))
		return c;

	c.id = id;
	c.suma = suma;
	strcpy_s(c.tip,20,type);
	return c;
}

void start_console(Lista* lista_cheltuieli)
{
	printf("Scrieti 6 pentru a vedea toate comenzile.\n");
	while (1)
	{
		int command;
		printf("Scrieti o comanda :\n");
		scanf_s("%d", &command);

		cheltuiala c;
		int id;
		int x;

		switch (command)
		{
		// Exit
		case 0:
			return;
			break;
		// Adaugare 
		case 1:
			c = Citire_UI();
			if (c.id == -1)
				printf("Tipul introdus este incorect!\n");
			else 
				Adauga(c,lista_cheltuieli);
			break;

		// Modificare
		case 2:
			c = Citire_UI();
			Modifica(c,lista_cheltuieli);
			break;

		// Stergere
		case 3:

			// citim un id
			printf("Id-ul : ");
			scanf_s("%d", &id);
			// stergem cheltuiala
			Sterge(id, lista_cheltuieli);
			break;

		// Filtrare
		case 4:
			printf("Dupa ce vreti sa filtrati lista?\n");
			printf("1 - dupa id\n");
			printf("2 - dupa suma\n");
			printf("3 - dupa tip\n");

			scanf_s("%d", &x);
			if (x == 1)
			{
				int id_x;
				scanf_s("%d", &id_x);
				Lista new_L = Filtrare1(id_x,lista_cheltuieli);
				Afisare(new_L);
			}
			else if (x == 2)
			{
				int suma_x;
				scanf_s("%d", &suma_x);
				Lista new_L = Filtrare2(suma_x, lista_cheltuieli);
				Afisare(new_L);
			}
			else if (x == 3)
			{
				char type_x[21];
				type_x[20] = '\0';
				scanf_s("%s", type_x, 20);
				Lista new_L = Filtrare3(type_x, lista_cheltuieli);
				Afisare(new_L);
			}
			else
				printf("Aceasta nu este o optiune.");

			break;
			
		// Sortare
		case 5:
			printf("Dupa ce vreti sa sortati lista?\n");
			printf("1 - dupa suma\n");
			printf("2 - dupa tip\n");

			int mod;
			scanf_s("%d", &x);
			Lista new_L;
			if (x == 1)
			{
				printf("1 - Crescator\n2 - Derscrescator\n");
				scanf_s("%d", &mod);

				if (mod == 2)
					mod = 0;
	
				Afisare(Sortare1(*lista_cheltuieli,mod));
			}
			else if (x == 2)
			{
				printf("1 - Crescator\n2 - Derscrescator\n");
				scanf_s("%d", &mod);

				if (mod == 2)
					mod = 0;
				
				Afisare(Sortare2(*lista_cheltuieli, mod));
			}
			else
				printf("Aceasta nu este o optiune.");

			break;
		case 6:
			printf("0 pentru a inchide programul\n");
			printf("1 pentru a adauga o cheltuiala in lista\n");
			printf("2 pentru a modifica o cheltuiala existenta\n");
			printf("3 pentru a sterge o cheltuiala existenta\n");
			printf("4 Vizualizare lista de cheltuieli filtrat dupa o proprietate (suma, tipul, id)\n");
			printf("5 Vizualizare lista de cheltuieli ordonat dupa suma sau tip (crescator/descrescator)\n");
			printf("6 pentru a vedea toate comenzile\n");
			printf("7 pentru a vedea toate cheltuielile\n");
			break;
		case 7:
			Afisare(*lista_cheltuieli);
			break;
		default:
			break;
		}
	}
}