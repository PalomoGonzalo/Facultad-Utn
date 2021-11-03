/*
 * informes.h
 *
 *  Created on: 2 nov. 2021
 *      Author: mati_
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include "salon.h"
#include "arcade.h"
#include "funciones.h"
#include "juegos.h"

int salon_baja(Salon *lista[],int len,Arcade *lista_arcade[],int len_arcade);
int salon_bajaMenu(Salon *lista[],int len,int indice,Arcade *lista_arcade[],int len_arcade);
int salonQueTieneArcade(Salon* lista_salon[], int len_salon, Arcade *lista_arcade[],int len_arcade,int indiceId);
int verCantidadDeSalonHay(Arcade *lista_arcade[],int len_arcade, Salon* lista_salon[],int len_salon);
void iniciarCantidadDeJuegoEnCero(Salon *lista_salon[],int len_salon);
void informe_arcadeMasDeCuatro(Salon *lista [],int len_salon,Arcade* lista_arcade[],int len_arcade);
void informe_arcadeDosJugadores(Arcade* lista[],int len_arcade,Salon* lista_salon[],int len_salon);
int informe_salonPorId(Salon* lista_salon[],int len_salon,Arcade* lista_arcade[], int len_arcade);

#endif /* INFORMES_H_ */
