/*
 * contrataciones.c
 *
 *  Created on: 12 oct. 2021
 *      Author: mati_
 */
#include <stdio.h>
#include <stdlib.h>
#include "contrataciones.h"
int contra_initList( Contrataciones list[],int len)
{
	int retorno =-1;
	if(list != NULL)
	{
		for(int i=0;i<len;i++)
		{
			list[i].flagEmpty=VACIO;
			retorno=1;

		}
	}
	return retorno;

}
int dameUnIdNuevoContra(void)
{
	static int contador=0;
	contador++;
	return contador;

}
int contra_buscarLibre(Contrataciones list[],int len)
{

	int i;
	int indice=-1;
	for(i=0; i<len; i++)
	{
		if(list[i].flagEmpty==VACIO)
		{
			indice=i;
			break;
		}
	}
	return indice;
}
void mostrarStructContra(Contrataciones mostrar [],int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        if(mostrar[i].flagEmpty==OCUPADO)
        {
           // printf("Id:%d NOMBRE: %s PRECIO: %f DIRECCION: %s \n",mostrar[i].id,mostrar[i].name,mostrar[i].price,mostrar[i].addres);

        }
    }

}
int buscarIdStructContra(Contrataciones listado[],int len, int id)
{
    int retorno = -1;
    int i;
    if(len > 0 && listado != NULL)
    {
        retorno = -1;
        for(i=0; i<len; i++)
        {
            if(listado[i].flagEmpty == 0 && listado[i].id == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


int contra_loadDisplay( Contrataciones list[],int len)
{
	int retorno=0;
	int indice;
	if (len!=0&&list!=NULL)
	{
		indice=disp_buscarLibre(list, len);
		if(indice>=0)
		{
			/*utn_getInt(&list[indice].type, "ingrese 0 para lcd \ningrese 1 para led\n ", "error reingrese 0 para lcd \ningrese 1 para led\n ", 0, 1, 100);
			utn_getFloat(&list[indice].price, "ingrese el precio", "error reingrese ", 1, 555555, 10);
			getString("ingrese el nombre",list[indice].name );
			getString("ingrese la direccion",list[indice].addres);
			list[indice].id=dameUnIdNuevo();
			retorno =1;
			list[indice].flagEmpty=0;*/
		}
	}


	return retorno;
}
void mostrarUnoContra(Contrataciones list[],int indice)
{
	//printf("Id:%d NOMBRE: %s PRECIO: %f DIRECCION: %s \n",list[indice].id,displaysList[indice].name,list[indice].price,list[indice].addres);
}
int contra_modifica(Contrataciones list[],int len)
{
	int idAux;
	int retorno=0;
	int indice;
//	int auxContinuar=1;

	mostrarStruct(list, len);
	utn_getInt(&idAux, "ingrese el id a modificar \n", "error ingrese un numero\n", 1, len, 5);
	indice=buscarIdStruct(list, len, idAux);
	if (len!=0&&list!=NULL)
	{
			if(indice!=-1)
			{
				disp_menuModificar(list, len, indice);
				retorno=1;
				indice=-1;
			}
			else
			{
				printf("no se encontro el id\n");
			}
	}
	return retorno;
	}


/*int deseaContinuar(void)
{
	int continuar;
	int retorno;
	utn_getInt(&continuar,"desea seguir modificando \n 1-si 2-no\n","error reingrese",1,2,4);
		if(continuar==1)
		{
			retorno=1;
		}
		else
			retorno=-1;

}*/
int contra_menuModificar(Contrataciones list[],int len,int indice)
{
	int retorno=-1;
	int opcion;
	char auxNombre[20];
	char auxDireccion[20];
	float precioAux;
	//int continuar;

	utn_getInt(&opcion, " Que desea modificar? \n 1-NOMBRE\n 2-PRECIO\n 3-DIRECCION\n", "error ingrese un numero valid\n", 1, len, 5);

	switch(opcion)
	{
	case 1:
		getString("ingrese el nuevo nombre", auxNombre);
		strncpy(list[indice].nameVideo,auxNombre,sizeof(list->nameVideo));
		break;
	case 2:
		utn_getFloat(&precioAux, "ingrese nuevo precio", "error ingrese numero validos", 1, 9999, 3);
		//list[indice].price=precioAux;
		break;
	case 3:
		getString("ingrese la nueva direccion", auxDireccion);
	//	strncpy(list[indice].addres,auxDireccion,sizeof(list->addres));
		break;
	default:
		printf("no es un numero valido \n");
		break;
	}


return retorno;
}

int contra_Baja(Contrataciones list[],int len)
{
	int auxId;
	int retorno=0;
	mostrarStruct(list, len);
	int indice;
	utn_getInt(&auxId, "ingrese el ide que quiere de dar de baja \n", "error ingrese un numero valido", 1, len, 4);

	if (len!=0&&list!=NULL)
	{

			indice=buscarIdStruct(list, len, auxId);
			if(indice!=-1)
			{

			disp_bajaMenu(list, len, indice);
			retorno=1;

			}
			else
			{
				printf("no existe el id\n");
			}

		}
	return retorno;
	}


int contra_bajaMenu(Contrataciones list[],int len,int indice)
{
	int auxBaja;
	int retorno;

	if (len!=0&&list!=NULL)
	{
		mostrarUno(list, indice);
		utn_getInt(&auxBaja, "Aprete 1 para dar de baja 2 para cancelar", "error ingrese un numero valido", 1, 2, 3);

		if (auxBaja==1)
		{
			printf("se dio de baja\n");
			list[indice].flagEmpty=2;
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

