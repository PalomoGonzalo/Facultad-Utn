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
void getInt (char mensaje[],int* numeros);
void imprimirFloatArray(float array[],int len);
void inicializadorArrayFloat( float array[],int len,int valorInicial);

void agregarTemeperaturas(float array[]);


#endif /* FUNCIONES_H_ */
