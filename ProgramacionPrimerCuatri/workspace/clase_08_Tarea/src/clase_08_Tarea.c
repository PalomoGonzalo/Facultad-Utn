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
	char *auxChar[500];
	getInt("ingrese edad",&aux);

	printf("\nstring es %d\n",aux);
	getString("\ningrise un string",auxChar);
	puts(*auxChar);


	for(int i=0;i<strlen(*auxChar);i++)
	{
		printf("%c\n",*auxChar[i]);
	}



	/*int edad;

		if(utn_getNumero(&edad, "\nEdad? ","\nError", 0,200,2) == 0)
		{
			printf("\nLa edad es %d",edad);
		}*/
	return EXIT_SUCCESS;
}
