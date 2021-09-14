/*
 ============================================================================
 Name        : clase6_tarea.c
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
	int numeros[5];
	setbuf(stdout, NULL);
	for(int i=0;i<5;i++)
	{
		getInt("ingrese numeros", &numeros[i]);
	}
	imprimirIntArray(numeros, 5);
	viltrarParArray(numeros,5);
	imprimirIntArray(numeros, 5);
	return EXIT_SUCCESS;
}
