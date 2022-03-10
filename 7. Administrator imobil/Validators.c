#include "Validators.h"
#include <string.h>
#include <assert.h>

int isType(char tip[21])
{
	/// tipul (apa, canal, incalzire, gaz)

	return strcmp(tip, "apa") == 0 || strcmp(tip, "canal") == 0 
		|| strcmp(tip, "incalzire") == 0 || strcmp(tip, "gaz") == 0;
}

int not_negative(int x)
{
	// tests is the number x is positive
	return x >= 0;
}

void test_isType()
{
	assert(isType("apa") == 1); 
	assert(isType("canal") == 1);
	assert(isType("gaz") == 1);
	assert(isType("canal") == 1);
	assert(isType("dwaefsedfsgrdthf") == 0); 
	assert(isType("CaNaL") == 0);
	assert(isType("apppa") == 0);
	assert(isType("a") == 0);
}

void test_not_negative()
{
	assert(not_negative(13) == 1);
	assert(not_negative(0) == 1);
	assert(not_negative(-32) == 0);
	assert(not_negative(-1) == 0);
}