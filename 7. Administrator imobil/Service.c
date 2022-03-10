#include "Service.h"
#include "Validators.h"
#include "Lista.h"

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