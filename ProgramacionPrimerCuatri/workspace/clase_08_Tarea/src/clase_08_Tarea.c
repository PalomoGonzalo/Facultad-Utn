/*
 ============================================================================
 Name        : clase_08_Tarea.c
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
	setbuf(stdout, NULL);
	int aux;
	getInt("ingrese edad",&aux);

	printf("\nLa edad es %d",aux);



	/*int edad;

		if(utn_getNumero(&edad, "\nEdad? ","\nError", 0,200,2) == 0)
		{
			printf("\nLa edad es %d",edad);
		}*/
	return EXIT_SUCCESS;
}
