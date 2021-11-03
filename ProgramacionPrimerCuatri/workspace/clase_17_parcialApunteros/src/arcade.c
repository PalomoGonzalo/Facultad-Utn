/*
 * arcade.c
 *
 *  Created on: 28 oct. 2021
 *      Author: mati_
 */

#include "arcade.h"
#include <stdio.h>
#include <stdlib.h>
#include "salon.h"
#include <string.h>
#include "juegos.h"
#include "funciones.h"
Arcade* arcade_new(void)
{
	Arcade* pDisplay = malloc(sizeof(Arcade));
	return pDisplay;
}
int arcade_inicializarPuntero (Arcade* lista[], int listLen)
{
	int index;
	int status = -1;
	if (lista != NULL && listLen > 0)
	{
		status = 1;
		for (index = 0; index < listLen; index++)
		{
			lista[index] = NULL;
		}
	}
	return status;
}

int arcade_dameIdNuevo(void)
{
	static int contador=0;
	contador++;
	return contador;

}
int arcade_buscarLugarLibre(Arcade* lista[],int len,int* indiceRetorno)
{

	int i;
	int retorno=-1;
	if(lista!=NULL)
	{
		for(i=0; i<len; i++)
		{
			if(lista[i]==NULL)
			{
				*indiceRetorno=i;
				retorno=0;
				break;
			}
		}
	}

	return retorno;
}
char arcade_reemplazarTipo(int tipo,char *retorno,int len)
{
	char aux[20];

	switch(tipo)
	{
	case 1:
		strncpy(aux,"ESTEREO",sizeof(aux));
		break;
	case 2:
		strncpy(aux,"MONO",sizeof(aux));
		break;

	}
	strncpy(retorno,aux,len);
	return *retorno;

}
void arcade_mostrarStructura(Arcade* lista [],int len)
{

	int i;
	char auxTipo[38];
	if(len > 0 && lista != NULL){
	    printf("\n\nid:\tnacionalidad:\tipo de sonido:\tcant jugad:\tfichas maximas:\t id salon:\tnombre del juego:");
	    for(i=0; i<len; i++)
	    {
	        if(lista[i]!=NULL)
	        {
	        	arcade_reemplazarTipo(lista[i]->tipoDeSonido, auxTipo, sizeof(auxTipo));
	        	printf("\n%d\t%10s\t%10s\t%10d\t%10d\t%10d\t%10s\t",lista[i]->id,lista[i]->nacionalidad,auxTipo,lista[i]->cantidadDeJugadores,lista[i]->capacidadMaxFicha,lista[i]->idSalon,lista[i]->nombreJuego);

	        }
	    }
	}
}
void arcade_mostrarUno(Arcade* lista[],int i)
{
	char auxTipo[20];

	if(lista!=NULL){
		arcade_reemplazarTipo(lista[i]->tipoDeSonido, auxTipo, sizeof(auxTipo));
		printf("\n\nid:\tnacionalidad:\tipo de sonido:\tcant jugad:\tfichas maximas:\t id salon:\tnombre del juego:");
		printf("\n%d\t%10s\t%10s\t%10d\t%10d\t%10d\t%10s\t",lista[i]->id,lista[i]->nacionalidad,auxTipo,lista[i]->cantidadDeJugadores,lista[i]->capacidadMaxFicha,lista[i]->idSalon,lista[i]->nombreJuego);

	}
}
int arcade_buscarId(Arcade* lista[],int len, int id,int* indice)
{
    int retorno = -1;
    int i;
    if(len > 0 && lista != NULL)
    {
        retorno = -1;
        for(i=0; i<len; i++)
        {
            if(lista[i]!=NULL&&lista[i]->id==id)
            {
                retorno = 0;
                *indice=i;
                break;
            }
        }
    }
    return retorno;
}


int arcade_alta(Arcade* lista_arcade[],int len,Salon* lista_salon[],int lenSalon)
{
	int retorno=0;
	int indice;
	int existeLugarLibre;
	int idSalon;
	int indiceSalon;

	int retornoOpcion;
	Arcade* auxArcade;

	if (len!=0&&lista_arcade!=NULL&&lista_salon!=NULL)
	{


		existeLugarLibre=arcade_buscarLugarLibre(lista_arcade, len,&indice);
		if(existeLugarLibre==0)
		{
			printf("\nasdasd \n");
			auxArcade=arcade_new();
			if(auxArcade!=NULL)
			{
				salon_mostrarStructura(lista_salon, lenSalon);
				utn_getInt(&idSalon, "\ningrese el id del salon\n", "error reingrese \n", 0, len, 10);
				retornoOpcion=salon_buscarId(lista_salon, lenSalon, idSalon,&indiceSalon);
				if(retornoOpcion==0)
				{
					auxArcade->idSalon=idSalon;
					getString("ingrese la nacionalidad \n",auxArcade->nacionalidad);
					utn_getInt(&auxArcade->tipoDeSonido, "ingrese el tipo de sonido\n1-ESTEREO\n2-MONO", "error reingrese numeros validos\n", 1, 2, 10);
					utn_getInt(&auxArcade->cantidadDeJugadores, "ingrese la cantidad de jugadores", "error reingrese\n", 1, 78, 10);
					utn_getInt(&auxArcade->capacidadMaxFicha, "ingrese la capacidad maxima de ficha", "error reingrese\n", 1, 78, 10);
					getString("ingrese el nombre del juego \n",auxArcade->nombreJuego);
					auxArcade->id=arcade_dameIdNuevo();
					printf("se cargo correctamente la publicacion: \n");
					lista_arcade[indice]=auxArcade;
					arcade_mostrarUno(lista_arcade, indice);
					//lista[indiceCliente].contadorPublicacion=lista[indiceCliente].contadorPublicacion+1;

				}
				else
					printf("el id no existe \n");
			}
		}
	}


	return retorno;
}



int arcade_altaHardcodeada(Arcade *lista[],char* nombreJuego,char * nacionalidad,int tipoSonido,int fichas,int idSalon,int cantJugadores,int len,int indice)
{
	int respuesta=-1;
	Arcade* aux;
	if(len > 0 && lista != NULL)
	{
		aux=arcade_new();
		if(aux!=NULL)
		{
			strncpy(aux->nombreJuego,nombreJuego,sizeof(aux->nombreJuego));
			strncpy(aux->nacionalidad,nacionalidad,sizeof(aux->nacionalidad));
			aux->id=arcade_dameIdNuevo();
			aux->idSalon=idSalon;
			aux->tipoDeSonido=tipoSonido;
			aux->capacidadMaxFicha=fichas;
			aux->cantidadDeJugadores=cantJugadores;
			respuesta= 0;
		}
		lista[indice]=aux;

	}

	return respuesta;

}

int arcade_modificar(Arcade *lista_arcade[],int len, Listajuegos* lista_juegos[], int len_juegos)
{
	int idAux;
	int retorno=0;
	int indice;
	int retornoId;
//	int auxContinuar=1;

	arcade_mostrarStructura(lista_arcade, len);
	utn_getInt(&idAux, "\ningrese el id a modidficar \n", "eror ingrese un numero\n", 1, len, 5);
	retornoId=arcade_buscarId(lista_arcade, len, idAux,&indice);
	if (len!=0&&lista_arcade!=NULL)
	{
			if(retornoId!=-1)
			{
				arcade_menuModificar(lista_arcade, len, indice, lista_juegos, len_juegos);
				retorno=1;
			//	indice=-1;
			}
			else
			{
				printf("no se encontro el id\n");
			}
	}
	return retorno;
}

int generListaJuegos(Listajuegos *lista_juegos[],int len_juegos,Arcade* lista_arcade[],int len_arcade)
{
	int retorno=-1;
	int i;
	int indiceListaJuegos=0;
	Listajuegos* aux_juegos;
	juegos_init(lista_juegos, len_juegos);
	if(lista_juegos!=NULL&&lista_arcade!=NULL)
	{

		for(i=0;i<len_arcade;i++)
		{
			aux_juegos=juegos_new();
			if(aux_juegos!=NULL)
			{
				if(lista_arcade[i]!=NULL)
				{
					if(juegos_estaEnArcade(lista_juegos, len_juegos, lista_arcade[i]->nombreJuego)==0)
					{

						strncpy(aux_juegos->nombreJuego,lista_arcade[i]->nombreJuego,32);
						lista_juegos[indiceListaJuegos]=aux_juegos;
						indiceListaJuegos++;
						retorno=0;
					}


				}
			}
		}

	}

	return retorno;
}
void juegos_mostrarStructura(Listajuegos* lista [],int len)
{
	int i;
	if(lista!=NULL)
	{
	    printf("\nJUEGOS CARGADOS \n");
	    for(i=0; i<len; i++)
	    {
	        if(lista[i]!=NULL)
	        {

	        	printf("%s\n",lista[i]->nombreJuego);


	        }
	    }
	}
}

int arcade_menuModificar(Arcade *lista[],int len,int indice,Listajuegos* lista_juegos[],int len_juegos)
{
	int retorno=-1;
	int opcion;
	char auxNombre[32];
	int  cantidadJugAux;
	if(lista!=NULL&&lista_juegos!=NULL)
	{
		utn_getInt(&opcion, " Que desea modificar? \n 1-CANTIDAD DE JUGADORES\n 2-NOMBRE DEL JUEGO\n", "error ingrese un numero valid\n", 1, 2, 5);
		switch(opcion)
		{
		case 1:
			utn_getInt(&cantidadJugAux, "\ningrese nueva cantidad de jugadores \n", "error ingrese numero validos\n", 1, 9999, 3);
			lista[indice]->cantidadDeJugadores=cantidadJugAux;
			printf("\n se cambio correctamente \n");

			break;
		case 2:
			juegos_mostrarStructura(lista_juegos, len_juegos);
			getString("\ningrese el nombre que aparece en la lista \n", auxNombre);
			if(juegos_estaEnArcade(lista_juegos, len_juegos,auxNombre)==1)
				{
					strncpy(lista[indice]->nombreJuego,auxNombre,sizeof(lista[indice]->nombreJuego));
					printf ("se cambio correctamente\n");
				}
			else
			{
				printf("\n no existe ese nombre de juego \n");
			}
			break;
		default:
			printf("no es un numero valido \n");
			break;
		}
	}
return retorno;
}

int arcade_Baja(Arcade* list[],int len)
{
	int auxId;
	int retorno=0;
	arcade_mostrarStructura(list, len);
	int indice;
	int auxEncontro;
	utn_getInt(&auxId, "\ningrese el id que quiere de dar de baja \n", "error ingrese un numero valido", 1, len, 4);

	if (len!=0&&list!=NULL)
	{

		auxEncontro=arcade_buscarId(list, len, auxId, &indice);
			if(auxEncontro!=-1)
			{

			arcade_bajaMenu(list, len, indice);
			retorno=1;

			}
			else
			{
				printf("no existe el id\n");
			}

		}
	return retorno;
	}


int arcade_bajaMenu(Arcade* list[],int len,int indice)
{
	int auxBaja;
	int retorno;

	if (len!=0&&list!=NULL)
	{
		arcade_mostrarUno(list, indice);
		utn_getInt(&auxBaja, "Aprete 1 para dar de baja 2 para cancelar", "error ingrese un numero valido", 1, 2, 3);

		if (auxBaja==1)
		{
			printf("se dio de baja\n");
			free(list[indice]);
			list[indice]=NULL;
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




