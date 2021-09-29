/*
 * Cliente.h
 *
 *  Created on: 28 sept. 2021
 *      Author: mati_
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
typedef struct {
	char nombre[20];
	char direccion[20];
	int telefono;
	char usuario [20];
	char email[20];
	int catCliente;
	char feNacimiento[20];

}Cliente;
int alta (Cliente clienteUno);


#endif /* CLIENTE_H_ */
