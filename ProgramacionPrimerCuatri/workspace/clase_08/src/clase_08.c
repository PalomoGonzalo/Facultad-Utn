/*
 ============================================================================
 Name        : clase_08.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
int myStrLen(char cadena[]);

void myPuts(char cadena[]);

void myStrCpy(char cadenaUno[],char cadenaDos[]);

int main(void) {
	setbuf(stdout, NULL);
/*
	char cadenaDeCaracteres[100]="asddasd";
	int len= strlen(cadenaDeCaracteres); mide la cantidad de caracteres que tiene un string
	printf("%d",len);

	char cad1[20];
	char cad2[20]="ho54la";
	//strcpy(cad1,cad2);// copia del segundo argumento al primer argumento pero hay que estar atento al tamaño del array
	strncpy(cad1,cad2,sizeof(cad1)-1);//pasa como 3 argumento el tamaño donde se guarda el tamaño
	puts(cad1);
*/

	int len;
	char cadenaUno[30]="test";
	char cadenaDos[20]="reemplazado";
	len=myStrLen(cadenaUno);
	printf("%d\n",len);

	myPuts(cadenaUno);
	myStrCpy(cadenaUno, cadenaDos);
	puts(cadenaUno);


	return EXIT_SUCCESS;
}
int myStrLen(char cadena[])
{
	int retorno=0;
	int i=0;

	while(cadena[i]!='\0')
	{
		retorno++;
		i++;
	}
	return retorno;
}

	void myPuts(char cadena[])
{
	for(int i=0;i<myStrLen(cadena);i++)
	{
		printf("%c",cadena[i]);
	}
	printf("\n");

}

void myStrCpy(char cadenaUno[],char cadenaDos[])
{
	int lenCharUno=myStrLen(cadenaUno);
	int lenCharDos=myStrLen(cadenaDos);
	int len;
	len=max(lenCharUno, lenCharDos);

	for(int i=0;i<len;i++)
	{
		cadenaUno[i]=cadenaDos[i];

		if (cadenaUno[i] == '\0')
		{

			break;
		}

	}



}

