/*
 * salon.h
 *
 *  Created on: 28 oct. 2021
 *      Author: mati_
 */

#ifndef SALON_H_
#define SALON_H_
typedef struct {

	int tipo;// 1 LOCAL 2 SHOPPING
	int id;
	char nombre[63];
	char direccion[128];
	int cantidadDeJuegos;
}Salon;
Salon* salon_new(void);
int salon_inicializarPuntero (Salon* lista[], int listLen);
int salon_dameIdNuevo(void);
int salon_buscarLugarLibre(Salon *lista[],int len,int *indiceRetorno);
char salon_reemplazarTipo(int tipo,char *retorno,int len);
void salon_mostrarStructura(Salon* lista [],int len);
void salon_mostrarUno(Salon* lista[],int i);
int salon_alta( Salon* lista[],int len);
int salon_buscarId(Salon* listado[],int len, int id,int* indice);
int salon_altaHardcodeada(Salon* lista[],char* nombre,char * direccion,int tipo,int len,int indice);

#endif /* SALON_H_ */
