/*
 * arcade.h
 *
 *  Created on: 28 oct. 2021
 *      Author: mati_
 */

#ifndef ARCADE_H_
#define ARCADE_H_
#include "arcade.h"
#include <stdio.h>
#include <stdlib.h>
#include "salon.h"
#include <string.h>
#include "funciones.h"
#include "juegos.h"

typedef struct {

	int idSalon;
	int id;
	int tipoDeSonido;
	int capacidadMaxFicha;
	int cantidadDeJugadores;
	char nacionalidad[64];
	char nombreJuego[32];

}Arcade;

Arcade* arcade_new(void);
int arcade_dameIdNuevo(void);
int arcade_inicializarPuntero (Arcade* lista[], int listLen);
int arcade_buscarLugarLibre(Arcade* lista[],int len,int* indiceRetorno);
char arcade_reemplazarTipo(int tipo,char *retorno,int len);
void arcade_mostrarStructura(Arcade* lista [],int len);
void arcade_mostrarUno(Arcade* lista[],int i);
int arcade_buscarId(Arcade* lista[],int len, int id,int* indice);
int arcade_alta(Arcade* lista_arcade[],int len,Salon* lista_salon[],int lenSalon);
int arcade_altaHardcodeada(Arcade *lista[],char* nombreJuego,char * nacionalidad,int tipoSonido,int fichas,int idSalon,int cantJugadores,int len,int indice);
void juegos_mostrarStructura(Listajuegos* lista [],int len);
int generListaJuegos(Listajuegos *aux_juegos[],int len_juegos,Arcade* lista_arcade[],int len_arcade);
int arcade_modificar(Arcade *lista_arcade[],int len, Listajuegos* lista_juegos[], int len_juegos);
int arcade_menuModificar(Arcade *lista[],int len,int indice,Listajuegos* lista_juegos[],int len_juegos);
int arcade_Baja(Arcade* list[],int len);
int arcade_bajaMenu(Arcade* list[],int len,int indice);

#endif /* ARCADE_H_ */
