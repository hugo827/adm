#include "Header.h"


int nombreAleatoire(unsigned long int m, unsigned long int a, unsigned long int c, unsigned long int xn) {

	unsigned long int multiple = a * xn;
	unsigned long int addition = multiple + c;
	unsigned long int modulo = addition % m;

	unsigned long int temp = modulo;
	//printf("XN -> %d\n", temp);
	return temp;
}