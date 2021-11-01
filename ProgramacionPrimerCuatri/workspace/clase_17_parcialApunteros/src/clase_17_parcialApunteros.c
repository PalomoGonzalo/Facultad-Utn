/*
 ============================================================================
 Name        : clase_17_parcialApunteros.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "arcade.h"
#include "salon.h"
#include "juegos.h"
#define LEN_SALON 100
#define LEN_ARCADE 1000
int main(void) {

	setbuf(stdout, NULL);
	Salon* lista_salon[100];
	salon_inicializarPuntero(lista_salon, 100);
	Arcade* lista_arcade[1000];
	arcade_inicializarPuntero(lista_arcade, 1000);

	Listajuegos* lista_juegos[LEN_SALON];



	salon_altaHardcodeada(lista_salon, "matias", "av la plata", 1, LEN_SALON, 0);
	salon_altaHardcodeada(lista_salon, "gonzalo", "av belgrano", 2, LEN_SALON, 1);
	salon_altaHardcodeada(lista_salon, "lucas", "mexico", 2, LEN_SALON, 2);
	salon_altaHardcodeada(lista_salon, "lia", "salta", 1, LEN_SALON, 3);
	salon_altaHardcodeada(lista_salon, "mia", "rosario", 2, LEN_SALON, 4);
	salon_altaHardcodeada(lista_salon, "kira", "venezuela", 1, LEN_SALON, 5);

	arcade_altaHardcodeada(lista_arcade, "DOTA", "argent", 1, 3, 2, 3, LEN_ARCADE, 0);
	arcade_altaHardcodeada(lista_arcade, "APEX", "brasil", 2, 7, 4, 1, LEN_ARCADE, 1);
	arcade_altaHardcodeada(lista_arcade, "HADES", "chile", 1, 2, 5, 1, LEN_ARCADE, 2);
	arcade_altaHardcodeada(lista_arcade, "CSGO", "españa", 1, 12, 5, 2, LEN_ARCADE, 3);
	arcade_altaHardcodeada(lista_arcade, "DOOM", "grecia", 1, 12, 5, 2, LEN_ARCADE, 4);
	arcade_altaHardcodeada(lista_arcade, "DOTA", "argent", 1, 5, 2, 2, LEN_ARCADE, 5);
	arcade_altaHardcodeada(lista_arcade, "CSGO", "españa", 1, 12, 5, 2, LEN_ARCADE, 6);
	arcade_altaHardcodeada(lista_arcade, "LOL",  "españa", 1, 10, 5, 7, LEN_ARCADE, 7);



	//salon_alta(lista_salon, 100);
	//printf("TEST");
	//arcade_alta(lista_arcade, 100, lista_salon, LEN_ARCADE);

	salon_mostrarStructura(lista_salon, LEN_SALON);
	arcade_mostrarStructura(lista_arcade, 100);
	generListaJuegos(lista_juegos, LEN_SALON, lista_arcade, LEN_ARCADE);
	juegos_mostrarStructura(lista_juegos, LEN_SALON);







	return EXIT_SUCCESS;
}
