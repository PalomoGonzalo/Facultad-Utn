/*
 ============================================================================
 Name        : clase_11_pantalla_testParcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "pantalla.h"
#include "funciones.h"
#define DISPLEYS_LEN 100

int main(void) {
	setbuf(stdout, NULL);
	char seguir= 's';
	Display displaysList[DISPLEYS_LEN];
	disp_initList(displaysList,DISPLEYS_LEN);
	//char test[20];
	int opcion;

	do{
		utn_getInt(&opcion, " 1-Dar de Alta\n 2-Modificar\n 3-Dar de baja\n 4-Salir\n", "error ingrese numeros validos", 1, 4, 4);
		switch(opcion)
		{
		case 1:
			disp_loadDisplay(displaysList, DISPLEYS_LEN);
			mostrarStruct(displaysList,DISPLEYS_LEN);
			break;
		case 2:
			disp_modifica(displaysList, DISPLEYS_LEN);
			mostrarStruct(displaysList,DISPLEYS_LEN);
			break;
		case 3:
			disp_Baja(displaysList, DISPLEYS_LEN);
			mostrarStruct(displaysList,DISPLEYS_LEN);
			break;
		case 4:
			seguir='n';
			break;
		}
	}while(seguir=='s');
/*


	mostrarStruct(displaysList,DISPLEYS_LEN);

	mostrarStruct(displaysList,DISPLEYS_LEN);


	*/

//	getString("asdasdasd", test);
	//getString("asdasdsadsadasd", test);



	return EXIT_SUCCESS;
}
