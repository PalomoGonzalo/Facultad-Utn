/*
 ============================================================================
 Name        : clase01.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);

	int numeroUno;
	int numeroDos;
	char letra = 's';
	int resultado;


	while(letra=='s')
	{

			printf("ingrese numero\n");
			scanf("%d",&numeroUno);
			printf("ingrese otro numero\n");
			scanf("%d",&numeroDos);
			resultado=numeroUno+numeroDos;

			printf("\n desea continuar s para si n para no\n");
			fflush(stdin);
			scanf("%c",&letra);

	}
	printf("La suma es %d \n",resultado);








	return EXIT_SUCCESS;
}
