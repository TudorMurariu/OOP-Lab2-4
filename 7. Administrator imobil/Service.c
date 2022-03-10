#include "Service.h"

int ValidareTip(char tip[21])
{
	return isType(tip);
}	

int ValidareSuma(int suma)
{
	return not_negative(suma);
}

int ValidareID(int id,Lista l)
{
	if (!not_negative(id))
		return 0;

	for (int i = 0; i < l.len; i++)
		if (id == l.array[i].id)
			return 0;
	return 1;
}


void Adauga_predefinite(Lista* l)
{
	/// Adaugam in lista cheltuieli predefinite
	cheltuiala c1;
	c1.id = 5341;
	c1.suma = 377;
	strcpy_s(c1.tip, 20, "apa");
	cheltuiala c2;
	c2.id = 43521;
	c2.suma = 8;
	strcpy_s(c2.tip, 20, "canal");
	cheltuiala c3;
	c3.id = 37;
	c3.suma = 989;
	strcpy_s(c3.tip, 20, "apa");
	cheltuiala c4;
	c4.id = 99905;
	c4.suma = 12345;
	strcpy_s(c4.tip, 20, "apa");
	cheltuiala c5;
	c5.id = 101777;
	c5.suma = 8;
	strcpy_s(c5.tip, 20, "gaz");

	Adauga(c1, l);
	Adauga(c2, l);
	Adauga(c3, l);
	Adauga(c4, l);
	Adauga(c5, l);
}

void test_ValidareID()
{
	int id = 335;
	Lista l1;
	l1.len = 0;
	cheltuiala c1;
	c1.id = 123;
	c1.suma = 77;
	strcpy_s(c1.tip,20, "apa");
	cheltuiala c2;
	c2.id = 778;
	c2.suma = 77;
	strcpy_s(c2.tip,20, "canal");
	cheltuiala c3;
	c3.id = 335;
	c3.suma = 77;
	strcpy_s(c3.tip,20, "apa");

	Adauga(c1, &l1);
	Adauga(c2, &l1);
	assert(ValidareID(id,l1) == 1);
	Adauga(c3, &l1);
	assert(ValidareID(id, l1) == 0);
}