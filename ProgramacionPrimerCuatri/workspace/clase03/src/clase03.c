#include <stdio.h>
#include <stdlib.h>
int sumarEnteros(int numUno, int nomDos);
void imprimirResultado(int num);
float dividirEnteros(int numUno, int numDos);
int factorial(int a);
int dividir (int numUno,int numDos,int* resultado);


int main(void) {
	int numUno;
	int numDos;
	int resultado;
	int resultadoDivison=dividir(numUno, numDos,&resultado);
	float impuestos;
	float promedio;
	float impuestosResultados;

	printf("ingrese el valor de la primera compra: \n");
	scanf("%d", &numUno);
	printf("ingrese el valor de la segunda compra: \n");
	scanf("%d", &numDos);
	resultadoDivison=dividir(numUno, numDos,&resultado);
	//resultado = dividirEnteros(numUno, numDos);

	promedio = (float) resultado / 2;

	if(resultadoDivison==1)
	{

		printf("no se puede divivir por cero");
	}
	else
	{
		imprimirResultado(resultado);
	}

	//imprimirResultado(resultado);

	factorial(numUno);



	/*printf("este es el resultado del promedio %f",promedio);
	 printf("ingrese los impuestos pagados");
	 scanf("%f",&impuestos);
	 impuestosResultados= impuestos+resultado;
	 */

	return EXIT_SUCCESS;
}

int sumarEnteros(int numUno, int numDos) {
	int resultado;
	resultado = numUno + numDos;
	return resultado;

}

int restarEnteros(int numUno, int numDos) {
	int resultado;
	resultado = numUno - numDos;
	return resultado;

}
float dividirEnteros(int numUno, int numDos) {
	float resultado;
	while (numDos == 0) {
		printf("no se puede dividir por cero, reingrese numero");
		scanf("%d", &numDos);

	}
	resultado = (float) numUno / numDos;

	return resultado;

}
int multiplicarEnteros(int numUno, int nomDos) {
	int resultado;
	resultado = numUno * nomDos;
	return resultado;

}

void imprimirResultado(int num) {
	printf("El resultado es %d", num);

}
int factorial(int a) {
	int factor = a;
	int factorial = 1;
	while (a < 0) {
		printf(
				"no se puede sacar factor numero negativo, reingrese el numero\n");
		scanf("%d", &a);
	}

	for (int i = 1; i <= a; i++) {
		factorial *= i;
	}
	printf("\nEl factorial de %d es: %d \n", a, factorial);

}

int dividir (int numUno,int numDos,int* resultado)
{
	int retorno;

	if(numDos!=0)
	{
		*resultado=numUno /numDos;

	}
	else
	{
		retorno=1;
	}
	return retorno;

}

void imprimirResultadoString(char mensaje[],int numero)
{
	printf("")

}
