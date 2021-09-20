/*
 * funciones.h
 *
 *  Created on: 9 sep. 2021
 *      Author: palom
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifndef FUNCIONES_H_
#define FUNCIONES_H_
int myGets(char* cadena, int longitud);
int getInt(char *cadena,int* aux);
int getFloat(float* numeros,char* mensaje);
char pedirMensaje (char mensaje[], char auxiliarChar[]);
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
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int esNumerico(char str[]);
int esSoloLetras(char str[]);


#endif /* FUNCIONES_H_ */
