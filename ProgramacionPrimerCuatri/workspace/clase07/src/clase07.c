/*
 ============================================================================
 Name        : clase07.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define QY_COD_AREA 5
int main(void) {

	setbuf(stdout,NULL);
	int codigosArea[QY_COD_AREA]= {8,20,134,23,50};
	int aux;
	int flagSwap;
	int contador=0;
//	int limite=QY_COD_AREA;


	do
	{
		flagSwap=0;
		for(int i=0;i<QY_COD_AREA-1;i++)
		{
			if(codigosArea[i]<codigosArea[i+1])
			{

				flagSwap=1;
				aux=codigosArea[i];
				codigosArea[i]=codigosArea[i+1];
				codigosArea[i+1]=aux;
			}

		}

		contador++;

	}while(flagSwap==1);
	/*for(int i=0;i<QY_COD_AREA;i++)
	{
		for(int k=i+1;k<QY_COD_AREA;k++)
		if(codigosArea[i]>codigosArea[k])
		{
			auxOrdenamiento[i]=codigosArea[i];
			codigosArea[i]=codigosArea[k];
			codigosArea[k]=auxOrdenamiento[i];

		}
	}*/
	imprimirIntArray(codigosArea, QY_COD_AREA);
	printf("%d",contador);

	return EXIT_SUCCESS;

}




