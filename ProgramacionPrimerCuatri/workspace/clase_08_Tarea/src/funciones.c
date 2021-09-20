/*
 * funciones.c
 *
 *  Created on: 9 sep. 2021
 *      Author: palom
 *      setbuf(stdout, NULL);
 */
#include "funciones.h"
int myGets(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4000];

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}

int getFloat(float* numeros,char* mensaje)
{
	int flag=1;
	printf(mensaje);
	fflush(stdin);
	scanf("%f",numeros);
	return flag;
}

int inicializadorArrayFloat( float array[],int len,int valorInicial)
{
	int retorno=-1;
	for(int i=0;i<len;i++)
		{
			array[i]=valorInicial;
			retorno=0;
		}
	return retorno;
}
int inicializadorArrayInt( float array[],int len,int valorInicial)
{
	int retorno=-1;
	for(int i=0;i<len;i++)
		{
			array[i]=valorInicial;
			retorno=0;
		}
	return retorno;
}
void imprimirFloatArray(float array[],int len)
{
	for(int i=0;i<len;i++)
	{
		printf("indice %d, valor %f\n",i+1,array[i]);
	}

}
int pedirFloatArray(float arrayFloat[],int len)
{
	int retorno =-1;
	for(int i=0;i<len;i++)
	{
		printf("ingrese los numeros para meter en el array");
		fflush(stdin);
		scanf("%f",&arrayFloat[i]);
		retorno=0;
	}
	return retorno;
}
int pedirIntArray(int arrayFloat[],int len)
{
	int retorno =-1;
	for(int i=0;i<len;i++)
	{
		printf("ingrese los numeros para meter en el array");
		fflush(stdin);
		scanf("%d",&arrayFloat[i]);
		retorno=0;
	}
	return retorno;
}
void imprimirIntArray(int arrayImprimir[],int len)
{
	if(arrayImprimir!=NULL&&len>=0)
	{
		for(int i=0;i<len;i++)
		{
			printf("indice %d, valor %d\n\n",i,arrayImprimir[i]);
		}

	}
}
int filtrarParArray(int arrayPar [],int len)
{
	int retorno=-1;
	if(arrayPar!=NULL&&len>=0)
	{
		for(int i=0;i<len;i++)
		{
			if(arrayPar[i]% 2== 0 )
			//	if(array[i]% 2 != 0 )impar
			{
				arrayPar[i]=0;
				retorno =0;
			}
		}
	}
	imprimirIntArray(arrayPar, len);
	return retorno;
}
int ordenarArrayIntSegunCriterio(int arrayParaOrdenar[], int len) {
	int aux;
	int contador = 0;
	int criterioParaOrdenar;
	int flagSwap;

	criterioParaOrdenar = pedirMensajeParaOrdenerArrays();

	do
	{
		flagSwap = 0;
		if (criterioParaOrdenar == 1)
		{
			for (int i = 0; i < len - 1; i++)
			{
				if (arrayParaOrdenar[i] < arrayParaOrdenar[i + 1])
				{

					flagSwap = 1;
					aux = arrayParaOrdenar[i];
					arrayParaOrdenar[i] = arrayParaOrdenar[i + 1];
					arrayParaOrdenar[i + 1] = aux;
				}

			}
		}
		else
		{
			for (int i = 0; i < len - 1; i++)
						{
							if (arrayParaOrdenar[i] > arrayParaOrdenar[i + 1])
							{
								flagSwap = 1;
								aux = arrayParaOrdenar[i];
								arrayParaOrdenar[i] = arrayParaOrdenar[i + 1];
								arrayParaOrdenar[i + 1] = aux;
							}

						}



		}
		contador++;

	} while (flagSwap == 1);
	imprimirIntArray(arrayParaOrdenar, len);
	return contador;

}
int pedirMensajeParaOrdenerArrays()
{
	int retorno;
	int opcion;
	do{
	printf("Aprete 1 si quiere ordenar de mayor a menor\n");
	printf("Aprete 2 si quiere ordenar de menor a mayor \n");
	fflush(stdin);
	scanf("%d",&opcion);
	switch(opcion)
	{
	case 1:
		retorno=1;
		break;
	case 2:
		retorno=2;
		break;
	default:
		printf("error datos incorrectos reingrese \n");

	}
	}while(opcion!=1&&opcion!=2);
	return retorno;
}

int max(int num1, int num2)
{
   int result;
   if (num1 > num2)
      {
	   result = num1;
      }
   else
      result = num2;
   return result;
}


/*int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	do
	{
		printf("%s",mensaje);
		if(	getInt(&bufferInt,mensaje) == 0 &&
			bufferInt >= minimo &&
			bufferInt <= maximo)
		{
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		printf("%s",mensajeError);
		reintentos--;
	}while(reintentos>=0);

	return retorno;
}*/
int esNumerico(char str[])
{
	int retorno=1;
	 int i=0;
	 if (str[i] == '-')
	 	{
	 		i = 1;
	 	}
	   while(str[i] != '\0')
	   {
	       if(str[i] < '0' || str[i] > '9')
	           return 0;
	       i++;
	   }
	 retorno=1;
	   return retorno;

}
int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}
char pedirMensaje (char mensaje[], char auxiliarChar[])
{
    printf("%s",mensaje);
    gets(auxiliarChar);
    fflush(stdin);
    return *auxiliarChar;
}

int getInt(char *cadena,int* aux)
 {
	int retorno=-1;
	int auxRetorno;
	char auxiliarChar[500];
	pedirMensaje(cadena, auxiliarChar);
	auxRetorno=esNumerico(auxiliarChar);
	while (!auxRetorno)
	{
		pedirMensaje("error reingrese solo numeros", auxiliarChar);
		auxRetorno=esNumerico(auxiliarChar);
	}
	retorno=1;
	 *aux= atoi(auxiliarChar);
	return retorno;
}
