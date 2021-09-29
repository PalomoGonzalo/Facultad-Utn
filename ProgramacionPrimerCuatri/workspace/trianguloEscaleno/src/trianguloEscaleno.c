/*
 ============================================================================
 Name        : trianguloEscaleno.c
 Author      : asd
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "triangulo.h"

int main(void) {

	setbuf(stdout, NULL);
	Etriangulo triangulo;
	float area;
	float perimetro;

	trianguloCarga(&triangulo);
	trianguloMostrarPorReferencia(&triangulo);
	trianguloMostrarPorValor(triangulo);

	perimetro=trianguloPerimetro(&triangulo);
	area=trianguloArea(&triangulo);

	printf("\narea %f perimetro %f\n",area,perimetro);




	return EXIT_SUCCESS;
}
