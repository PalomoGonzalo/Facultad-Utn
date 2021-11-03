/*
 * informes.c
 *
 *  Created on: 2 nov. 2021
 *      Author: mati_
 */
#include "informes.h"
#include <stdio.h>
#include <stdlib.h>

int salon_baja(Salon *lista[],int len,Arcade *lista_arcade[],int len_arcade)
{
	int auxId;
	int retorno=0;
	salon_mostrarStructura(lista, len);
	int indice;
	utn_getInt(&auxId, "\ningrese el id que quiere de dar de baja \n", "error ingrese un numero valido\n", 0, len, 4);

	if (len!=0&&lista!=NULL&&lista_arcade!=NULL)
	{

		auxId=salon_buscarId(lista, len, auxId,&indice);
			if(auxId!=-1)
			{

			salon_bajaMenu(lista, len, indice,lista_arcade,len_arcade);
			retorno=1;

			}
			else
			{
				printf("no existe el id\n");
			}

		}
	return retorno;
	}


int salon_bajaMenu(Salon *lista[],int len,int indice,Arcade *lista_arcade[],int len_arcade)
{
	int auxBaja;
	int retorno;

	if (len!=0&&lista!=NULL)
	{
		printf("este es el salon que quiere dar de baja:\n");
		verCantidadDeSalonHay(lista_arcade, len_arcade, lista, len);
		salon_mostrarUno(lista, indice);
		utn_getInt(&auxBaja, "Aprete 1 para dar de baja 2 para cancelar", "error ingrese un numero valido", 1, 2, 3);

		if (auxBaja==1)
		{
			printf("se dio de baja\n");
			salonQueTieneArcade(lista, len, lista_arcade, len_arcade, indice);
			free(lista[indice]);
			lista[indice]=NULL;

			retorno=1;
		 }
		 else
		 {
			 printf("no se dio de baja\n");
			 retorno=0;
		 }

	}
	return retorno;
}
int salonQueTieneArcade(Salon* lista_salon[], int len_salon, Arcade *lista_arcade[],int len_arcade,int indiceId)
{
	int retorno=-1;
	if(lista_salon != NULL && len_salon > 0 && lista_arcade != NULL && len_arcade > 0 )
	{

		for(int i=0;i<len_arcade;i++)
		{
			if(lista_arcade[i]!=NULL)
			{

				if(lista_arcade[i]->idSalon==lista_salon[indiceId]->id)
				{
					free(lista_arcade[i]);
					lista_arcade[i]=NULL;
					retorno=0;
				}
			}
		}
	}

	return retorno;
}

int verCantidadDeSalonHay(Arcade *lista_arcade[],int len_arcade, Salon* lista_salon[],int len_salon)
{
	int retorno=-1;
	if(lista_arcade!=NULL&&lista_salon!=NULL)
	{
		iniciarCantidadDeJuegoEnCero(lista_salon, len_salon);
		for (int i=0;i<len_arcade;i++)
			{
				for (int j=0;j<len_salon;j++)
				{
					if(lista_arcade[i]!=NULL&&lista_salon[j]!=NULL)
					{
						if(lista_arcade[i]->idSalon==lista_salon[j]->id)
						{
							lista_salon[j]->cantidadDeJuegos++;
							retorno=0;
						}
					}
				}
			}
	}
	return retorno;
}
void iniciarCantidadDeJuegoEnCero(Salon *lista_salon[],int len_salon)
{
	if(lista_salon!=NULL)
	{
		for(int i=0;i<len_salon;i++)
		{
			if(lista_salon[i]!=NULL)
				lista_salon[i]->cantidadDeJuegos=0;
		}
	}
}

void informe_arcadeMasDeCuatro(Salon *lista [],int len_salon,Arcade* lista_arcade[],int len_arcade)
{
    int i;
    char auxTipo[38];
    printf("\nid:\t     nombre:\t   direccion:\t  tipo:\t     cantidad de juego:\t");
    verCantidadDeSalonHay(lista_arcade, len_arcade, lista, len_salon);
    if(lista!=NULL&&lista_arcade!=NULL)
    {
		for(i=0; i<len_salon; i++)
		{
			if(lista[i]!=NULL)
			{
				if(lista[i]->cantidadDeJuegos>4)
				{
					salon_reemplazarTipo(lista[i]->tipo, auxTipo, sizeof(auxTipo));
					printf("\n%2d\t%10s\t%10s\t%10s\t%2d\t",lista[i]->id,lista[i]->nombre,lista[i]->direccion,auxTipo,lista[i]->cantidadDeJuegos);
				}


			}
		}
    }

}

void informe_arcadeDosJugadores(Arcade* lista[],int len_arcade,Salon* lista_salon[],int len_salon)
{
		int i;
	    int indice;

	    printf("\n\nid:\tCtd Jugadores :\t nombre del juego:\tnombre del salon:");
	    if(lista!=NULL&&lista_salon!=NULL)
	    {
			for(i=0; i<len_arcade; i++)
			{

				if(lista[i]!=NULL)
				{
					salon_buscarId(lista_salon, len_salon, lista[i]->idSalon,&indice);
					if(lista[i]->cantidadDeJugadores>2)
					{

						printf("\n%d\t%10d\t%10s\t%15s\t",lista[i]->id,lista[i]->cantidadDeJugadores,lista[i]->nombreJuego,lista_salon[indice]->nombre);
					}
				}
			}
	    }
}

int informe_salonPorId(Salon* lista_salon[],int len_salon,Arcade* lista_arcade[], int len_arcade)
{
	int retorno=-1;
	int idAux;
	int opcion;
	int indice;
	utn_getInt(&idAux, "\ningrese el id a buscar\n", "error ingrese un numero valido\n", 1, len_salon, 5);
	opcion=salon_buscarId(lista_salon, len_salon, idAux, &indice);
	verCantidadDeSalonHay(lista_arcade, len_arcade, lista_salon, len_salon);
	if(opcion==0)
	{
		salon_mostrarUno(lista_salon, indice);
		retorno=0;
	}
	else
		printf("no existe el id ingresado\n");

	return retorno;

}






