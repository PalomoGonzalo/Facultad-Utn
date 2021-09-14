/*


* Ejercicio 2:

 a) Realizar un programa que le pida 5 numeros int al usuario y los almacene en un array.

 Luego ejecutar la funcion borrarImpares() pasandole el array y que deberá reemplazar

 los numeros que son impares por un cero.

 b) Luego imprimir el array para chequear el funcionamiento.

 c) Ordenar el array y volver a imprimirlo ordenado.


 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
int main(void) {
	int numeros[5];
	setbuf(stdout, NULL);
	for(int i=0;i<5;i++)
	{
		getInt("ingrese numeros", &numeros[i]);
	}
	imprimirIntArray(numeros, 5);
	viltrarParArray(numeros,5);
	imprimirIntArray(numeros, 5);
	return EXIT_SUCCESS;
}
