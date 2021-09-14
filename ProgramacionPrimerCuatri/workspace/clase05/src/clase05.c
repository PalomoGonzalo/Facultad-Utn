/*
 ============================================================================
 Name        : clase05.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define REINTENTOS 3

int pedirFloatAlUsuario(float* pNum,float min,float max,int reintentos,char* variableTexto,char* mensajeError);
int main(void) {

	/*float numUno;
	float numDos;

	if (pedirFloatAlUsuario(&numUno,0.0,1000.0,REINTENTOS,"ingrese la humedad","error reingrese")==0)
	{
		printf("ingresaste %f",numUno);
	}
	else
	{
		printf("ese numero nooo");
	}



*/

	return EXIT_SUCCESS;
}

int pedirFloatAlUsuario(float* pNum,float min,float max,int reintentos,char* variableTexto,char* mensajeError)
{
	int retorno=1;
	float aux;
	printf("%s",variableTexto);
	scanf("%f",&aux);


	for(int i=1;i<reintentos;i++)
	{
		if(aux>=min&&aux<=max)
		{
			retorno=0;
			*pNum=aux;
			break;
		}
		else
		{
			retorno=1;
			printf("%s",mensajeError);
			scanf("%f",&aux);

		}
	}

	return retorno;
}
