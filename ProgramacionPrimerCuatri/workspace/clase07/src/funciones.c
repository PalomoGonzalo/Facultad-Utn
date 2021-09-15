/*
 * funciones.c
 *
 *  Created on: 9 sep. 2021
 *      Author: palom
 *      setbuf(stdout, NULL);
 */
#include "funciones.h"
char getChar (char mensaje[], char auxiliarChar[])
{

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%s", &auxiliarChar);
    return auxiliarChar;
}
int getInt (char mensaje[],int* numeros)
{
	int flag=1;
	printf(mensaje);
	fflush(stdin);
	scanf("%d",numeros);
	return flag;
}
int getFloat(float* numeros,char* mensaje)
{
	int flag=1;
	printf(mensaje);
	fflush(stdin);
	scanf("%f",numeros);
	return flag;
}

int inicializadorArrayFloat( float array[],int len,int valorInicial)
{
	int retorno=-1;
	for(int i=0;i<len;i++)
		{
			array[i]=valorInicial;
			retorno=0;
		}
	return retorno;
}
int inicializadorArrayInt( float array[],int len,int valorInicial)
{
	int retorno=-1;
	for(int i=0;i<len;i++)
		{
			array[i]=valorInicial;
			retorno=0;
		}
	return retorno;
}
void imprimirFloatArray(float array[],int len)
{
	for(int i=0;i<len;i++)
	{
		printf("indice %d, valor %f\n",i+1,array[i]);
	}

}
int pedirFloatArray(float arrayFloat[],int len)
{
	int retorno =-1;
	for(int i=0;i<len;i++)
	{
		printf("ingrese los numeros para meter en el array");
		fflush(stdin);
		scanf("%f"&arrayFloat[i]);
		retorno=0;
	}
	return retorno;
}
int pedirIntArray(float arrayFloat[],int len)
{
	int retorno =-1;
	for(int i=0;i<len;i++)
	{
		printf("ingrese los numeros para meter en el array");
		fflush(stdin);
		scanf("%d"&arrayFloat[i]);
		retorno=0;
	}
	return retorno;
}
void imprimirIntArray(int arrayImprimir[],int len)
{
	if(arrayImprimir!=NULL&&len>=0)
	{
		for(int i=0;i<len;i++)
		{
			printf("indice %d, valor %d\n\n",i,arrayImprimir[i]);
		}

	}
}
int filtrarParArray(int arrayPar [],int len)
{
	int retorno=-1;
	if(arrayPar!=NULL&&len>=0)
	{
		for(int i=0;i<len;i++)
		{
			if(arrayPar[i]% 2== 0 )
			//	if(array[i]% 2 != 0 )impar
			{
				arrayPar[i]=0;
				retorno =0;
			}
		}
	}
	imprimirIntArray(arrayPar, len);
	return retorno;
}
