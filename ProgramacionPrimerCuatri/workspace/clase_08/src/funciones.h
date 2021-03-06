/*
 * funciones.h
 *
 *  Created on: 9 sep. 2021
 *      Author: palom
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef FUNCIONES_H_
#define FUNCIONES_H_
int myGets(char* cadena, int longitud);
int getInt(int* pResultado, char bufferString[]);
int getFloat(float* numeros,char* mensaje);
int max(int num1, int num2);
void imprimirFloatArray(float array[],int len);
int inicializadorArrayFloat( float array[],int len,int valorInicial);
int inicializadorArrayInt( float array[],int len,int valorInicial);
void imprimirIntArray(int arrayImprimir[],int len);
int filtrarParArray(int arrayPar [],int len);
int pedirFloatInt(int arrayFloat[],int len);
int pedirFloatArray(float arrayFloat[],int len);
int pedirMensajeParaOrdenerArrays();
int ordenarArrayIntSegunCriterio(int arrayParaOrdenar[], int len);
int esNumerica(char str[]);


#endif /* FUNCIONES_H_ */
