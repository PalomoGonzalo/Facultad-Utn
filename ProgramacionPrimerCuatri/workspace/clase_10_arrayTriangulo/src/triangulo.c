/*
 * triangulo.c
 *
 *  Created on: 28 sept. 2021
 *      Author: mati_
 */

#ifndef TRIANGULO_C_
#define TRIANGULO_C_
#include "triangulo.h"



int myGets(char pResultado[], int len)
{
    int retorno=-1;
    int indexFinal;
    fflush(stdin);
    if(fgets(pResultado,len,stdin)!=NULL)
    {
        indexFinal = strlen(pResultado)-1;
        if(pResultado[indexFinal] == '\n')
        {
            pResultado[indexFinal] = '\0';
        }
        retorno = 0;

    }
    return retorno;
}
int esNumericoFlotante(char str[])
{

	 int i=0;
	 int contadorDePuntos=0;
	 if (str[i] == '-')
	 	{
	 		i = 1;
	 	}
	   while(str[i] != '\0')
	   {
	       if((str[i] < '0' || str[i] > '9')&& str[i]!='.')
	           return 0;
	       if(str[i]=='.')
	    	   contadorDePuntos++;
	       i++;
	   }
	// if(contadorDePuntos==1)
		 return 1;

	   return 0;

}
int getFloat(char *mensaje,float* resultado)
 {
	int retorno=-1;
	char auxiliarChar[50];
	if(resultado !=NULL)
	{

	printf(mensaje);
	myGets(auxiliarChar,sizeof(auxiliarChar));
	while (!esNumericoFlotante(auxiliarChar))
	{

		printf("error reingrese ");
		myGets(auxiliarChar,sizeof(auxiliarChar));
	}
	}
	retorno=1;
	*resultado= atof(auxiliarChar);

	return retorno;
}

void trianguloMostrarPorValor(Etriangulo triangulo[])
{



}
void trianguloMostrarPorReferencia(Etriangulo *triangulo[])
{
	printf("%f\n",triangulo->ladoUno);
	printf("%f\n",triangulo->ladoDos);
	printf("%f\n",triangulo->ladoTres);



}
int trianguloCarga(Etriangulo *triangulo[])
{
	int retorno=0;
	float ladoUno=0;
	float ladoDos=0;
	float ladoTres=0;
	if(triangulo !=NULL)
	{
		getFloat("ingrese el primero lado\n", &ladoUno);
		getFloat("ingrese el segundo lado\n", &ladoDos);
		getFloat("ingrese el tercer lado\n", &ladoTres);

		if(ladoUno!=0&&ladoDos!=0&&ladoTres!=0)
		{
			triangulo->ladoUno=ladoUno;
			triangulo->ladoDos=ladoDos;
			triangulo->ladoTres=ladoTres;
			retorno=-1;
		}
	}
	return retorno;
}
float trianguloPerimetro(Etriangulo *triangulo[])
{
	float resultado;

	if(triangulo !=NULL)
	{
		resultado=triangulo->ladoUno+triangulo->ladoDos+triangulo->ladoTres;
	}
	return resultado;

}
float trianguloArea(Etriangulo *triangulo[])
{
	float resultado;
	if(triangulo !=NULL)
	{
		resultado=(triangulo->ladoTres*3)/2;
	}
	return resultado;


}
#endif /* TRIANGULO_C_ */
