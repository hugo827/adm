#include "Header.h"

double loiPoisson(double param, int k) {
	int factorial=1;
	if(k!=0) {
		for (int i = 1; i <= k; i++) {
			factorial *= i;
		}
			
		return (exp(-param) * (pow(param, k))) / factorial;
	}
	else {
		return (exp(-param));
	}
	
} 
