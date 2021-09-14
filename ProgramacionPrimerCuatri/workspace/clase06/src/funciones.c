/*
 * funciones.c
 *
 *  Created on: 9 sep. 2021
 *      Author: palom
 */
#include "funciones.h"
char getChar (char mensaje[], char auxiliarChar[])
{

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%s", &auxiliarChar);
    return auxiliarChar;
}
void getInt (char mensaje[],int* numeros)
{
	int flag=1;
	printf(mensaje);
	fflush(stdin);
	scanf("%d",numeros);
}
void getFloat(float* numeros,char* mensaje)
{
	int flag=1;
	printf(mensaje);
	fflush(stdin);
	scanf("%f",numeros);
}

void inicializadorArrayFloat( float array[],int len,int valorInicial)
{
	for(int i=0;i<len;i++)
		{
			array[i]=valorInicial;

		}
}
void imprimirFloatArray(float array[],int len)
{
	for(int i=0;i<len;i++)
	{
		printf("indice %d, valor %f\n",i+1,array[i]);
	}

}
void agregarTemeperaturas(float array[])
{
	int indice;
	float temperatura;
	printf("ingrese numero de dia 1 a 31");
	scanf("%d",&indice);
	printf("ingrese la temperatura");
	scanf("%f",&temperatura);
	array[indice-1]=temperatura;

}
