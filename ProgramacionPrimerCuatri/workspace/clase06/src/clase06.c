/*
 ============================================================================
 Name        : clase06.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TEMPERATURAS_LEN 31
//la direccion de memoria donde empieza el array (nombre solo del array )

int main(void) {
	setbuf(stdout, NULL);
	float temperaturaPorDia[TEMPERATURAS_LEN];
	//float auxTemperatura;
	char seguir= 's';
	int opcion=0;
	inicializadorArrayFloat(temperaturaPorDia, TEMPERATURAS_LEN, 0);
	while (seguir=='s')
	{
		printf("1- imprimir valores\n");
		printf("2- agregar temperaturas\n");
		printf("3- salir\n");
		scanf("%d",&opcion);
		switch(opcion)
		{
		case 1:
			imprimirFloatArray(temperaturaPorDia, TEMPERATURAS_LEN);
			break;
		case 2:
			agregarTemeperaturas(temperaturaPorDia);
			break;
		case 3:
			seguir='n';
			break;
		}
	}




	return EXIT_SUCCESS;
}




