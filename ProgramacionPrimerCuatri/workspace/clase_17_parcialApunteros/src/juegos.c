/*
 * juegos.c
 *
 *  Created on: 1 nov. 2021
 *      Author: mati_
 */
#include "juegos.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Listajuegos* juegos_new(void)
{
	Listajuegos* pJuegos = malloc(sizeof(Listajuegos));
	return pJuegos;
}

int juegos_init(Listajuegos* lista[],int len)
{

	int retorno =-1;
	if(lista != NULL)
	{
		for(int i=0;i<len;i++)
		{
			lista[i]=NULL;
			retorno=1;
		}
	}
	return retorno;
}

int juegos_estaEnArcade(Listajuegos* list[],int len, char juego[])
{
	int retorno=0;
	int i;
	if(list!=NULL)
	{
		for (i=0;i<len;i++)
		{
			if(list[i]!=NULL)
			{
				if(strnicmp(list[i]->nombreJuego,juego,32)==0)
				{
					retorno=1;
					break;
				}
			}
		}
	}
	return retorno;
}
