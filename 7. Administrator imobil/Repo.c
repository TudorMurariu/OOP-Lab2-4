#include "Repo.h"
#include <string.h>
#include <assert.h>

void Adauga(cheltuiala c,Lista* l)
{
	/// <summary>
	/// Functia adauga un element la finalul listei
	/// </summary>
	/// <param name="c"></param>
	/// <param name="l"></param>
	l->array[l->len].id = c.id;
	l->array[l->len].suma = c.suma;
	strcpy_s(l->array[l->len].tip,20,c.tip);
	l->len++;
}

void Modifica(cheltuiala c, Lista* l)
{
	/// <summary>
	/// Functia modifica un element din lista daca acesta exista
	/// </summary>
	/// <param name="c"></param>
	/// <param name="l"></param>
	for (int i = 0; i < l->len; i++)
	{
		if (l->array[i].id == c.id)
		{
			l->array[i].suma = c.suma;
			strcpy_s(l->array[i].tip, 20, c.tip);
		}
	}
}

void Sterge(int id, Lista* l)
{
	/// <summary>
	/// Functia sterge un element din lista daca acesta exista
	/// </summary>
	/// <param name="id"></param>
	/// <param name="l"></param>
	int ok = 0;
	for (int i = 0; i < l->len; i++)
	{
		if (l->array[i].id == id)
			ok = 1;

		if (ok && i < l->len-1)
		{
			l->array[i].id = l->array[i+1].id;
			l->array[i].suma = l->array[i+1].suma;
			strcpy_s(l->array[i].tip, 20, l->array[i+1].tip);
		}
	}

	if(ok)
		l->len--;
}

Lista Filtrare1(int id,Lista* l)
{
	/// <summary>
	/// Filtram lista data dupa un id dat
	/// returnneaza o lista in care toate elementele au acelasi id cu id ul dat.
	/// </summary>
	Lista new_L;
	new_L.len = 0;

	for (int i = 0; i < l->len; i++)
	{
		if (l->array[i].id == id)
			Adauga(l->array[i], &new_L);
	}

	return new_L;
}

Lista Filtrare2(int suma, Lista* l)
{
	/// <summary>
	/// Filtram dupa suma
	/// </summary>
	/// <param name="suma"></param>
	/// <param name="l"></param>
	/// <returns>o lista raspuns in care toate elementele au suma egala cu suma data</returns>
	Lista new_L;
	new_L.len = 0;

	for (int i = 0; i < l->len; i++)
	{
		if (l->array[i].suma == suma)
			Adauga(l->array[i], &new_L);
	}

	return new_L;
}

Lista Filtrare3(char tip[21], Lista* l)
{
	/// <summary>
	/// Filtram dupa tip
	/// </summary>
	/// <param name="tip"></param>
	/// <param name="l"></param>
	/// <returns>o lista raspuns in care toate elementele au tipul dat</returns>
	Lista new_L;
	new_L.len = 0;

	for (int i = 0; i < l->len; i++)
	{
		if (strcmp(l->array[i].tip, tip) == 0)
			Adauga(l->array[i], &new_L);
	}

	return new_L;
}

int cmp1(cheltuiala c1, cheltuiala c2 ,int mod)
{
	if(mod) 
		return c1.suma > c2.suma;
	return c1.suma < c2.suma;
}

Lista Sortare1(Lista l,int mod)
{
	/// <summary>
	/// Sortam lista data dupa suma in modul dat
	/// mod = 1 => Crescator
	/// mod = 0 => Descrescator
	/// </summary>
	/// <param name="l"></param>
	/// <param name="mod"></param>
	/// <returns> Lista sortata </returns>
	int ok = 1;
	while (ok)
	{
		ok = 0;
		for(int i=0;i<l.len-1;i++)
			if (cmp1(l.array[i],l.array[i + 1], mod))
			{
				cheltuiala aux = l.array[i];
				l.array[i] = l.array[i + 1];
				l.array[i + 1] = aux;
				ok = 1;
			}
	}
	return l;
}

int cmp2(cheltuiala c1, cheltuiala c2, int mod)
{
	if (mod)
		return strcmp(c1.tip,c2.tip) > 0;
	return strcmp(c1.tip, c2.tip) < 0;
}

Lista Sortare2(Lista l, int mod)
{
	/// <summary>
	/// Sortam lista data dupa tip in mod-ul dat
	/// mod == 1 => Crescator
	/// mod == 0 => Descrescator
	/// </summary>
	/// <param name="l"></param>
	/// <param name="mod"></param>
	/// <returns> Lista sortata </returns>
	int ok = 1;
	while (ok)
	{
		ok = 0;
		for (int i = 0; i < l.len - 1; i++)
			if (cmp2(l.array[i], l.array[i + 1], mod))
			{
				cheltuiala aux = l.array[i];
				l.array[i] = l.array[i + 1];
				l.array[i + 1] = aux;
				ok = 1;
			}
	}
	return l;
}


/// Teste

void test_Adauga()
{
	Lista l1;
	l1.len = 0;
	cheltuiala c1;
	c1.id = 1321;
	c1.suma = 15;
	strcpy_s(c1.tip,20,"apa");

	Adauga(c1, &l1);
	assert(l1.len == 1);
	assert(l1.array[0].id == 1321);
	assert(l1.array[0].suma == 15);
	assert(strcmp(l1.array[0].tip,"apa") == 0);
}

void test_Modifica()
{
	Lista l1;
	l1.len = 0;
	cheltuiala c1;
	c1.id = 1321;
	c1.suma = 15;
	strcpy_s(c1.tip,20, "apa");
	Adauga(c1, &l1);

	c1.id = 1321;
	c1.suma = 722;
	strcpy_s(c1.tip,20, "canal");
	Modifica(c1, &l1);

	assert(l1.len == 1);
	assert(l1.array[0].id == 1321);
	assert(l1.array[0].suma == 722);
	assert(strcmp(l1.array[0].tip, "canal") == 0);
}

void test_Sterge()
{
	Lista l1;
	l1.len = 0;
	cheltuiala c1;
	c1.id = 1321;
	c1.suma = 15;
	strcpy_s(c1.tip,20, "apa");
	Adauga(c1, &l1);
	Sterge(1321, &l1);

	assert(l1.len == 0);
}
