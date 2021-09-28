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
	float numeros;
	char text[50];
	getFloat("ingrese solo numeros\n", &numeros);
	//pedirMensaje(text, sizeof(text), "ingrese algo");
	printf("%f",numeros);
	//getEmail("ingrese email", text);
	//puts(text);


	return EXIT_SUCCESS;
}
