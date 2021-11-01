/*
 * salon.c
 *
 *  Created on: 28 oct. 2021
 *      Author: mati_
 */
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "salon.h"
Salon* salon_new(void)
{
	Salon* pSalon = malloc(sizeof(Salon));
	pSalon->cantidadDeJuegos=0;
	return pSalon;
}
int salon_inicializarPuntero (Salon* lista[], int listLen)
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

int salon_dameIdNuevo(void)
{
	static int contador=0;
	contador++;
	return contador;

}

int salon_buscarLugarLibre(Salon *lista[],int len,int *indiceRetorno)
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
char salon_reemplazarTipo(int tipo,char *retorno,int len)
{
	char aux[20];

	switch(tipo)
	{
	case 1:
		strncpy(aux,"LOCAL",sizeof(aux));
		break;
	case 2:
		strncpy(aux,"SHOPPING",sizeof(aux));
		break;

	}
	strncpy(retorno,aux,len);
	return *retorno;

}

void salon_mostrarStructura(Salon* lista [],int len)
{
	int i;
	char auxTipo[38];

	if(lista!=NULL)
	{
		printf("\nid:\tnombre:\t  direccion:\t tipo:\t");
		for(i=0;i<len;i++)
		{
			if(lista[i]!=NULL)
			{
				salon_reemplazarTipo(lista[i]->tipo, auxTipo, sizeof(auxTipo));
				printf("\n%d\t%s\t%s    \t%s\t",lista[i]->id,lista[i]->nombre,lista[i]->direccion,auxTipo);
			}
		}
	}
}

void salon_mostrarUno(Salon* lista[],int i)
{
	char auxTipo[32];

	if(lista!=NULL)
	{
		salon_reemplazarTipo(lista[i]->tipo, auxTipo, sizeof(auxTipo));
		printf("\nid:%d nombre:%s direccion:%s tipo:%s cantidad de arcades que posee %d\n",lista[i]->id,lista[i]->nombre,lista[i]->direccion,auxTipo,lista[i]->cantidadDeJuegos);
	}
}

int salon_alta( Salon* lista[],int len)
{
	int retorno=0;
	int hayLugarLibre;
	int indice;
	Salon* aux;
	if (len!=0&&lista!=NULL)
	{
		hayLugarLibre=salon_buscarLugarLibre(lista, len,&indice);
		if(hayLugarLibre==0)
		{
			aux=salon_new();
			if(aux!=NULL)
			{
				getString("ingrese el nombre \n",aux->nombre );
				getString("ingrese la direccion\n",aux->direccion);
				utn_getInt(&aux->tipo, "ingrese tipo\n 1-LOCAl\n 2-SHOPPING\n","error ingrese 1 o 2\n", 1, 2, 100);
				aux->id=salon_dameIdNuevo();
				retorno=1;
				printf("se dio de alta el salon:");
				lista[indice]=aux;
				salon_mostrarUno(lista, indice);
			}
		}
	}
	return retorno;
}

int salon_buscarId(Salon* listado[],int len, int id,int* indice)
{
    int retorno = -1;
    int i;
    if(len > 0 && listado != NULL)
    {
        retorno = -1;
        for(i=0; i<len; i++)
        {
            if(listado[i] != NULL && listado[i]->id == id)
            {
                retorno = 0;
                *indice=i;
                break;
            }
        }
    }
    return retorno;
}


int salon_altaHardcodeada(Salon* lista[],char* nombre,char * direccion,int tipo,int len,int indice)
{
	int respuesta=-1;
	Salon* aux;
	if(len > 0 && lista != NULL)
	{
		aux=salon_new();
		if(aux!=NULL)
		{
			strncpy(aux->nombre,nombre,sizeof(aux->nombre));
			strncpy(aux->direccion,direccion,sizeof(aux->direccion));
			aux->id=salon_dameIdNuevo();
			aux->tipo=tipo;
		}
		lista[indice]=aux;
		respuesta= 0;
	}

	return respuesta;

}



