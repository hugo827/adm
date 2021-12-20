#include "Header.h"


int nombreAleatoire(int m, int a, int c, int xn) {
	int temp = (((a * xn) + c) % m);
	//printf("XN -> %d\n", temp);
	return temp;
}