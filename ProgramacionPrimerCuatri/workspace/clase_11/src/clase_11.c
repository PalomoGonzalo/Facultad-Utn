/*
 ============================================================================
 Name        : clase_11.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "triangulo.h"
#define TRIANGULOS_LEN 3
int main(void) {

	setbuf(stdout, NULL);
    Etriangulo triangulos[TRIANGULOS_LEN];
    int perimetros[TRIANGULOS_LEN];
    int perimetroMayor;
    int i;
    int indexDeTrianguloMayor;
    for(i=0; i<TRIANGULOS_LEN ; i++)
    {
    	trianguloCarga( & triangulos[i] );
        perimetros[i] = trianguloPerimetro(&triangulos[i]);
    }
    // busco mayor en un array de ints
    perimetroMayor = perimetros[0]; // tomo la primera como mayor
    indexDeTrianguloMayor = 0;
    for(i=1; i<TRIANGULOS_LEN ; i++)
    {
        if(perimetros[i] > perimetroMayor)
        {
            // encontre un nuevo mayor! jajajaj
            perimetroMayor = perimetros[i];
            indexDeTrianguloMayor = i;
        }
    }
    // en perimetroMayor me quedo el mayor (no me sirve pa nada)
    // en indexDeTrianguloMayor me quedo la posicion donde esta el mayor
    trianguloMostrarPorReferencia(&triangulos[indexDeTrianguloMayor]);





	return EXIT_SUCCESS;
}
