/*
 * esqueleto.c
 *
 *  Created on: 13 oct. 2021
 *      Author: mati_
 */



// 0 lcd 1 led
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "esqueleto.h"
#include "funciones.h"

//MENU
/*

	setbuf(stdout, NULL);
	char seguir= 's';
	//Display displaysList[DISPLEYS_LEN];
	//disp_initList(displaysList,DISPLEYS_LEN);
	//char test[20];
	int opcion;

	do{
		utn_getInt(&opcion, " 1-Dar de Alta\n 2-Modificar\n 3-Dar de baja\n 4-Salir\n", "error ingrese numeros validos", 1, 4, 4);
		switch(opcion)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			seguir='n';
			break;
		}
	}while(seguir=='s');
 *
 *
 */
int esqueleto_inicializarArray( Esqueleto lista[],int len)
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
int dameUnIdNuevo(void)
{
	static int contador=0;
	contador++;
	return contador;

}
int esqueleto_buscarLugarLibre(Esqueleto listado[],int len)
{

	int i;
	int indice=-1;
	if(len > 0 && listado != NULL)
	{
		for(i=0; i<len; i++)
		{
			if(listado[i].flagEmpty==VACIO)
			{
				indice=i;
				break;
			}
		}
	}
	return indice;
}
void esqueleto_mostrarStructura(Esqueleto mostrar [],int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        if(mostrar[i].flagEmpty==OCUPADO)
        {
            printf("Id:%d NOMBRE: %s PRECIO: %f DIRECCION: %s \n",mostrar[i].id,mostrar[i].name,mostrar[i].price,mostrar[i].addres);

        }
    }

}
int esqueleto_buscarId(Esqueleto listado[],int len, int id)
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


int esqueleto_alta( Esqueleto displaysList[],int len)
{
	int retorno=0;
	int indice;
	if (len!=0&&displaysList!=NULL)
	{
		indice=esqueleto_buscarLugarLibre(displaysList, len);
		if(indice>=0)
		{
			utn_getInt(&displaysList[indice].type, "ingrese 0 para lcd \ningrese 1 para led\n ", "error reingrese 0 para lcd \ningrese 1 para led\n ", 0, 1, 100);
			utn_getFloat(&displaysList[indice].price, "ingrese el precio", "error reingrese ", 1, 555555, 10);
			getString("ingrese el nombre",displaysList[indice].name );
			getString("ingrese la direccion",displaysList[indice].addres);
			displaysList[indice].id=dameUnIdNuevo();
			retorno =1;
			displaysList[indice].flagEmpty=0;
		}
	}


	return retorno;
}
void esqueleto_mostrarUno(Esqueleto displaysList[],int indice)
{
	printf("Id:%d NOMBRE: %s PRECIO: %f DIRECCION: %s \n",displaysList[indice].id,displaysList[indice].name,displaysList[indice].price,displaysList[indice].addres);
}
int esqueleto_modificar(Esqueleto displaysList[],int len)
{
	int idAux;
	int retorno=0;
	int indice;
//	int auxContinuar=1;

	esqueleto_mostrarStructura(displaysList, len);
	utn_getInt(&idAux, "ingrese el id a modificar \n", "error ingrese un numero\n", 1, len, 5);
	indice=esqueleto_buscarId(displaysList, len, idAux);
	if (len!=0&&displaysList!=NULL)
	{
			if(indice!=-1)
			{
				esqueleto_menuModificar(displaysList, len, indice);
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
int esqueleto_menuModificar(Esqueleto displaysList[],int len,int indice)
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
		strncpy(displaysList[indice].name,auxNombre,sizeof(displaysList->name));
		break;
	case 2:
		utn_getFloat(&precioAux, "ingrese nuevo precio", "error ingrese numero validos", 1, 9999, 3);
		displaysList[indice].price=precioAux;
		break;
	case 3:
		getString("ingrese la nueva direccion", auxDireccion);
		strncpy(displaysList[indice].addres,auxDireccion,sizeof(displaysList->addres));
		break;
	default:
		printf("no es un numero valido \n");
		break;
	}


return retorno;
}

int esqueleto_baja(Esqueleto displaysList[],int len)
{
	int auxId;
	int retorno=0;
	esqueleto_mostrarStructura(displaysList, len);
	int indice;
	utn_getInt(&auxId, "ingrese el ide que quiere de dar de baja \n", "error ingrese un numero valido", 1, len, 4);

	if (len!=0&&displaysList!=NULL)
	{

			indice=esqueleto_buscarId(displaysList, len, auxId);
			if(indice!=-1)
			{

			esqueleto_bajaMenu(displaysList, len, indice);
			retorno=1;

			}
			else
			{
				printf("no existe el id\n");
			}

		}
	return retorno;
	}


int esqueleto_bajaMenu(Esqueleto displaysList[],int len,int indice)
{
	int auxBaja;
	int retorno;

	if (len!=0&&displaysList!=NULL)
	{
		esqueleto_mostrarUno(displaysList, indice);
		utn_getInt(&auxBaja, "Aprete 1 para dar de baja 2 para cancelar", "error ingrese un numero valido", 1, 2, 3);

		if (auxBaja==1)
		{
			printf("se dio de baja\n");
			displaysList[indice].flagEmpty=2;
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
void transefrirDatos(Esqueleto listado  [],Esqueleto auxiliarListado  [],int len)
{
    int i;

    for(i=0;i<len;i++)
    {
       // if(listado[i].isEmpty==OCUPADO)
        {
          /*  listado[i].isEmpty=auxiliarListado[i].isEmpty;
            listado[i].id=auxiliarListado[i].id;
            listado[i].salary=auxiliarListado[i].salary;
            listado[i].sector=auxiliarListado[i].sector;
            strcpy(listado[i].name,auxiliarListado[i].name);
            strcpy(listado[i].lastName,auxiliarListado[i].lastName);*/
        }
    }
}
char esqueleto_reemplazarTipo(int tipo,char *retorno,int len)
{
	char aux[20];

	switch(tipo)
	{
	case 1:
		strncpy(aux,"administracion",sizeof(aux));
		break;
	case 2:
		strncpy(aux,"programacion",sizeof(aux));
		break;

	}
	strncpy(retorno,aux,len);
	return *retorno;

}
int esqueleto_ordenarArraySegunCriterio(Esqueleto lista [], int len, int orden)
{
	Esqueleto Aux;

	int contador = 0;
	char auxTipo[15];
	char auxTipoDos[15];
	switch (orden)
	{
	case 1:

		for (int i = 0; i < len - 1; i++)
		{
			if (lista[i].flagEmpty == OCUPADO)
			{
				if (stricmp(lista[i].name, lista[i + 1].name) > 0)// descendente
				{
					Aux = lista[i];
					lista[i] = lista[i + 1];
					lista[i + 1] = Aux;
					esqueleto_reemplazarTipo(lista[i].id, auxTipo, len);
					esqueleto_reemplazarTipo(lista[i + 1].id, auxTipoDos, len);
					if (stricmp(auxTipo, auxTipoDos) == 0)
					{
						Aux = lista[i];
						lista[i] = lista[i + 1];
						lista[i + 1] = Aux;
					}
				}
			}
		}
		break;

	case 2:

		for (int i = 0; i < len - 1; i++)// ascendente
		{
			if (lista[i].flagEmpty == OCUPADO)
			{
				if (stricmp(lista[i].name, lista[i + 1].name) < 0)
				{

					Aux = lista[i];
					lista[i] = lista[i + 1];
					lista[i + 1] = Aux;
					esqueleto_reemplazarTipo(lista[i].id, auxTipo, len);
					esqueleto_reemplazarTipo(lista[i + 1].id, auxTipoDos, len);
					if (stricmp(auxTipo, auxTipoDos) == 0)
					{
						Aux = lista[i];
						lista[i] = lista[i + 1];
						lista[i + 1] = Aux;
					}
				}
			}
		}
		break;
	}


	//falta imprimir array aca
	return contador;

}

/*
 *
 *
 * int type;// 0 lcd 1 plasma
	float price;
	int id;
	char name[128];
	char addres[128];
	int flagEmpty;
 */
int esqueleto_altaHardcodeada(Esqueleto lista[],char* nombre,char * direccion,float precio,int flagEmpty,int len,int indice)
{
	int respuesta=-1;
	if(len > 0 && lista != NULL)
	{

		strncpy(lista[indice].name,nombre,sizeof(lista->name));
		strncpy(lista[indice].addres,direccion,sizeof(lista->addres));
		lista[indice].id=dameUnIdNuevo();
		lista[indice].price=precio;
		lista[indice].flagEmpty=flagEmpty;
		respuesta= 0;

	}

	return respuesta;

}









