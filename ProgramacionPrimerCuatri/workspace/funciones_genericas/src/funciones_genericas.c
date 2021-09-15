/*
 ============================================================================
 Name        : funciones_genericas.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
int main(void) {
	setbuf(stdout,NULL);
	int numeros[5]={22,33,1,2,6};

	ordenarArrayIntSegunCriterio(numeros, 5);
	return EXIT_SUCCESS;
}
