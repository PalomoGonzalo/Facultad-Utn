/*
 * juegos.h
 *
 *  Created on: 1 nov. 2021
 *      Author: mati_
 */

#ifndef JUEGOS_H_
#define JUEGOS_H_
typedef struct {

		char nombreJuego[32];
	}Listajuegos;

	Listajuegos* juegos_new(void);
int juegos_estaEnArcade(Listajuegos* list[],int len, char juego[]);
int juegos_init(Listajuegos* lista[],int len);

#endif /* JUEGOS_H_ */
