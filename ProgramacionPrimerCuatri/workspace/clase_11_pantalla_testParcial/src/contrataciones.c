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
		indice=contra_buscarLibre(list, len);
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

	mostrarStructContra(list, len);
	utn_getInt(&idAux, "ingrese el id a modificar \n", "error ingrese un numero\n", 1, len, 5);
	indice=buscarIdStructContra(list, len, idAux);
	if (len!=0&&list!=NULL)
	{
			if(indice!=-1)
			{
				contra_menuModificar(list, len, indice);
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
	mostrarStructContra(list, len);
	int indice;
	utn_getInt(&auxId, "ingrese el ide que quiere de dar de baja \n", "error ingrese un numero valido", 1, len, 4);

	if (len!=0&&list!=NULL)
	{

			indice=buscarIdStructContra(list, len, auxId);
			if(indice!=-1)
			{

			contra_bajaMenu(list, len, indice);
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
		mostrarUnoContra(list, indice);
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




typedef struct {

	char cuilCliente[32];// 0 lcd 1 plasma
	int flagEmpty;
}Cliente;

Cliente listaClientes[1000];

int cliente_init(Cliente lista[],int len)
{

	int retorno =-1;
	if(lista != NULL)
	{
		for(int i=0;i<len;i++)
		{
			lista[i].flagEmpty=VACIO;
			retorno=1;

		}
	}
	return retorno;
}

int cliente_estaCuitEnLista(Cliente list[],int len, char cuit[])
{
	int retorno=0;
	int i;
	for (i=0;i<len;i++)
	{
		if(list[i].flagEmpty==0)
		{
			if(strncmp(list[i].cuilCliente,cuit,32)==0)
			{

				retorno=1;
				break;
			}
		}
	}
	return retorno;
}

int generListaClientes(Cliente listaClientes[],int lenListaClientes,Contrataciones listaContrataciones,int lenListaContrat)
{
	int retorno=-1;
	int i;
	int indiceListaCliente=0;
	cliente_init(listaClientes, lenListaClientes);
	for(i=0;i<lenListaContrat;i++)
	{
		if(listaContrataciones[i].flagEmpty==0)
		{
			if(cliente_estaCuitEnLista(listaClientes, lenListaClientes, listaContrataciones[i].cuilCliente)==0)
			{
				strncmp(listaClientes[indiceListaCliente].cuilCliente,listaContrataciones[i].cuilCliente,32);
				listaContrataciones[indiceListaCliente].flagEmpty=0;
				indiceListaCliente++;
				retorno=0;

			}
		}
	}

	return retorno;


	return retorno;
}
void informe2_clienteConImporteMasAltoAFacturar(Contrataciones listaContrataciones[], lenListaContrat)
{

	Cliente listaClientes[1000];
	generListaClientes(listaClientes, 1000, listaContrataciones, lenListaContrat);
	int i;
	int iMax=0;
	float importeMax;
	if(listaClientes[i].flagEmpty==0)
	{
		importeMax=getImporteDeCliente(listaClientes[0].cuilCliente);

		for(i=1;i<1000;i++)
		{
			if(listaClientes[i].flagEmpty==0)
			{
				if(getImporteDeCliente(listaClientes[i].cuilCliente)>importeMax)
					{
						importeMax=getImporteDeCliente(listaClientes[i].cuilCliente);
					}
		}

			}
	}
}
float getImporteDeCliente(char cuit[],Contrataciones listaConta[],int lenContrata,int lenDisplay, Display listaDisplays[])
{
	int i;
	float acc=0;
	for(i=0;i<listaConta;i++)
	{
		if(listaConta[i].flagEmpty==0)
		{
			if(strncmp(cuit,listaConta[i].cuilCliente,32)==0)
			{
				float importe=listaConta[i].cantidadDeDias* getPrecioPorDiaDeDisplay(listaConta[i].idCliente,listaDisplays,lenDisplay);
				acc=acc+importe;
			}


		}


	}

}
float getPrecioPorDiaDeDisplay(int idDisp,Display listaDisplays[],int lenDisplay)
{
	int posicionEncontrada;
	posicionEncontrada=buscarIdStruct(listaDisplays, lenDisplay, idDisp);
	if(posicionEncontrada!=-1)
	{

		return listaDisplays[posicionEncontrada].price;

	}

	return 0;

}
