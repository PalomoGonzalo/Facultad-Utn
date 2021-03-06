/*
 * funciones.h
 *
 *  Created on: 9 sep. 2021
 *      Author: palom
 */
#include <stdio.h>
#include <stdlib.h>
#ifndef FUNCIONES_H_
#define FUNCIONES_H_
char getChar (char mensaje[], char auxiliarChar[]);
int getInt (char mensaje[],int* numeros);
int getFloat(float* numeros,char* mensaje);
void imprimirFloatArray(float array[],int len);
int inicializadorArrayFloat( float array[],int len,int valorInicial);
int inicializadorArrayInt( float array[],int len,int valorInicial);
void imprimirIntArray(int arrayImprimir[],int len);
int filtrarParArray(int arrayPar [],int len);
int pedirFloatInt(float arrayFloat[],int len);
int pedirFloatArray(float arrayFloat[],int len);


#endif /* FUNCIONES_H_ */
