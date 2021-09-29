/*
 * triangulo.h
 *
 *  Created on: 28 sept. 2021
 *      Author: mati_
 */

#ifndef TRIANGULO_H_
#define TRIANGULO_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct {

	float ladoUno;
	float ladoDos;
	float ladoTres;

}Etriangulo;

int getFloat(char *mensaje,float* resultado);
int myGets(char pResultado[], int len);
int esNumericoFlotante(char str[]);
void trianguloMostrarPorValor(Etriangulo triangulo);
void trianguloMostrarPorReferencia(Etriangulo *triangulo);
int trianguloCarga(Etriangulo *triangulo);
float trianguloArea(Etriangulo *triangulo);
float trianguloPerimetro(Etriangulo *triangulo);
#endif /* TRIANGULO_H_ */
