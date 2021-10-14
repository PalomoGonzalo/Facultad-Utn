/*
 ============================================================================
 Name        : esqueletoPrimerParcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "esqueleto.h"
#include "funciones.h"
#define ESQUELETO_LEN 100
int main(void) {
	setbuf(stdout, NULL);
	char seguir= 's';
	//Display displaysList[DISPLEYS_LEN];
	//disp_initList(displaysList,DISPLEYS_LEN);
	//char test[20];
	Esqueleto listaEsqueleto[ESQUELETO_LEN];
	esqueleto_inicializarArray(listaEsqueleto,ESQUELETO_LEN);
	esqueleto_altaHardcodeada(listaEsqueleto, "matias", "siempre viva", 99, OCUPADO, ESQUELETO_LEN, 0);
	esqueleto_altaHardcodeada(listaEsqueleto, "feder", "asd ds", 99, OCUPADO, ESQUELETO_LEN, 1);
	esqueleto_mostrarStructura(listaEsqueleto, ESQUELETO_LEN);
	int opcion;

	do{
		utn_getInt(&opcion, " 1-Dar de Alta\n 2-Modificar\n 3-Dar de baja\n 4-Salir\n", "error ingrese numeros validos", 1, 4, 4);
		switch(opcion)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			seguir='n';
			break;
		}
	}while(seguir=='s');
	return EXIT_SUCCESS;
}
