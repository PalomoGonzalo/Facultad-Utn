/*
 ============================================================================
 Name        : clase3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int sumarEnteros(int numUno, int nomDos);
void imprimirResultado(float num);
float dividirEnteros(int numUno, int numDos);
int factorial(int a);
int main(void) {
	int numUno;
	int numDos;
	float resultado;
	float impuestos;
	float promedio;
	float impuestosResultados;


	printf("ingrese el valor de la primera compra: \n");
	scanf("%d",&numUno);
	printf("ingrese el valor de la segunda compra: \n");
	scanf("%d",&numDos);

	resultado= dividirEnteros(numUno, numDos);

	promedio= (float)resultado /2;

	imprimirResultado(resultado);

	factorial(numUno);


	/*printf("este es el resultado del promedio %f",promedio);

	printf("ingrese los impuestos pagados");
	scanf("%f",&impuestos);

	impuestosResultados= impuestos+resultado;
*/


	return EXIT_SUCCESS;
}

int sumarEnteros(int numUno, int numDos)
{
	int resultado;
	resultado=numUno +numDos;
	return resultado;

}

int restarEnteros(int numUno, int numDos)
{
	int resultado;
	resultado=numUno-numDos;
	return resultado;

}
float dividirEnteros(int numUno, int numDos)
{
	float resultado;
	while(numDos==0)
	{
		printf("no se puede dividir por cero, reingrese numero");
		scanf("%d",&numDos);

	}
	resultado=(float)numUno/numDos;

	return resultado;

}
int multiplicarEnteros(int numUno, int nomDos)
{
	int resultado;
	resultado=numUno*nomDos;
	return resultado;

}



void imprimirResultado(float num)
{
	printf("El resultado es %f",num);


}
int factorial(int a)
{
    int factor=a;
    int factorial=1;
    while(a<0)
    {
    printf("no se puede sacar factor numero negativo, reingrese el numero\n");
    scanf("%d",&a);
    }



    for(int i=1; i<=a; i++)
        {
            factorial *= i;
        }
         printf("\nEl factorial de %d es: %d \n",a,factorial);

}




