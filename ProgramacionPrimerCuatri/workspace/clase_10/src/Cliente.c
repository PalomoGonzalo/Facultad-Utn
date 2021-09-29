/*
 * Cliente.c
 *
 *  Created on: 28 sept. 2021
 *      Author: mati_
 */
#include "Cliente.h"


int alta (Cliente clienteUno)
{
	int retorno=1;
	strncpy(clienteUno.nombre,"nombre",sizeof(clienteUno.nombre));

	return retorno;

}
