/*
 * contrataciones.h
 *
 *  Created on: 12 oct. 2021
 *      Author: mati_
 */

#ifndef CONTRATACIONES_H_
#define CONTRATACIONES_H_
#include "funciones.h"
typedef struct {

	int cuilCliente;// 0 lcd 1 plasma
	int cantidadDeDias;
	int id;
	char nameVideo[128];
	int idCliente;
	int flagEmpty;
}Contrataciones;

int contra_initList( Contrataciones list[],int len);
int contra_loadDisplay( Contrataciones list[],int len);
int contra_buscarLibre(Contrataciones list[],int len);
int dameUnIdNuevoContra(void);
void mostrarStructContra(Contrataciones mostrar [],int len);
int buscarIdStructContra(Contrataciones listado[],int len, int id);
int contra_menuModificar(Contrataciones list[],int len,int indice);
int contra_modifica(Contrataciones list[],int len);
void mostrarUnoContra(Contrataciones list[],int indice);
int contra_bajaMenu(Contrataciones list[],int len,int indice);
int contra_Baja(Contrataciones list[],int len);
//int deseaContinuar(void);


#endif /* CONTRATACIONES_H_ */
