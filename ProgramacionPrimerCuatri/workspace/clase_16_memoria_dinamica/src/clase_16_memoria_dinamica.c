/*
 ============================================================================
 Name        : clase_16_memoria_dinamica.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "pantalla.h"


int main(void) {
	setbuf(stdout, NULL);



	Display* arrayDisplays[1100];
	disp_initList(arrayDisplays);
	int opcion;
	switch(opcion)
	{
	case 1:
		//agregar nuevo display (alta de display)
		// creo el display (llamo al new)
		// llamo a loadDisplay para que el usario cargue los dataos
		// lo agrega a la lista



		break;


	}







	/*float* pDireccion= (float*)malloc(sizeof(float));

	printf("me dio la direccion: %d \n",pDireccion);
	*pDireccion=3.14;
	printf("me dio la direccion: %f \n",*pDireccion);
	printf("me dio la direccion: %d \n",*pDireccion);
*/

	/*float* pDireccion= (float*)malloc(sizeof(float)*10);
	*(pDireccion+3)=3.14;
	printf("me dio la direccion: %f \n",*(pDireccion+3));
	*/
/*	int variableLocal;
	int * pVariableDinamica=malloc(sizeof(int));

	printf("direccion de var global: %p \n",&variableGlobal);
	printf("direccion de var local: %p \n",&variableLocal);
	printf("direccion de var dinamica: %p \n",pVariableDinamica);
	printf("direccion de var funcion: %p \n",funcionSarasa);

	int* pNuevoEspacio=realloc(pVariableDinamica,sizeof(int)*5);
	if(pNuevoEspacio!=NULL)
	{
		pVariableDinamica=pNuevoEspacio;
	}

	free(pVariableDinamica);
	// NO USAR MAS EL PUNTERO DESPUES DE HABER HECHO EL FREE


*/
	return EXIT_SUCCESS;
}
