/*
 ============================================================================
 Name        : clase_09.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int utn_getText(char pResultado[], int len, char* mensaje, char* mensajeError, int reintentos);
static int myGets(char pResultado[], int len);
static int esNumerica(char str[]);
int utn_getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

int main(void) {
	char cadena[8];
	setbuf(stdout, NULL);

	int numero;
	//utn_getInt(&numero,"ingrese numero", "error");
	printf("%d",numero);



	return EXIT_SUCCESS;
}

static int myGets(char pResultado[], int len)
{
    int retorno=-1;
    int indexFinal;
    fflush(stdin);
    //gets(pResultado); // NOOOOOOO
    //if(scanf("%s", pResultado)==1) // NOOOOOOO
    if(fgets(pResultado,len,stdin)!=NULL)
    {
        // borro el \n del final
        indexFinal = strlen(pResultado)-1;
        if(pResultado[indexFinal] == '\n')
        {
            pResultado[indexFinal] = '\0';
        }
        retorno = 0;

    }
    return retorno;
}
int utn_getText(char pResultado[], int len, char* mensaje, char* mensajeError, int reintentos)
{
    int retorno = -1;
    int i;
    for(i=0; i<=reintentos; i++)
    {
        if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
        {
            printf("%s", mensaje);
            fflush(stdin);
            //gets(pResultado); // NOOOOOOO
            //if(scanf("%s", pResultado)==1) // NOOOOOOO
            if(fgets(pResultado,len,stdin)!=NULL)
            {
                retorno = 0;
                break;
            }
            else
                printf("%s", mensajeError);
        }
    }
    return retorno;
}
static int esNumerica(char str[])
{
	int retorno=-1;
	 int i=0;
	 if (str[i] == '-')
	 	{
	 		i = 1;
	 	}
	   while(str[i] != '\0')
	   {
	       if(str[i] < '0' || str[i] > '9')
	           retorno= -1;
	       i++;
	   }
	 retorno=0;
	   return retorno;

}
int utn_getFloat(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){
    int retorno = -1;
    int bufferInt;
    int i;
    char bufferCadenaAux[16];
    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        for(i=0; i<=reintentos; i++)
        {
            printf("%s", mensaje);
            fflush(stdin);
            //if(scanf("%d", &bufferInt)==1)
            if(myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
            {
                // el usuario ingreso algo
                // lo valido, para ver si los simbolos ingresados son numericos
                if(esNumerica(bufferCadenaAux)==0)
                {
                    // si son numericos, convierto la cadena a INT
                    bufferInt = atoi(bufferCadenaAux);
                    if(bufferInt >= minimo && bufferInt <= maximo){
                        *pResultado = bufferInt;
                        retorno = 0;
                        break;
                    }else{
                        printf("%s", mensajeError);
                    }
                }
                else {
                    printf("%s", mensajeError);
                }
            }
            else {
                printf("%s", mensajeError);
            }
        }
    }
    return retorno;
}
