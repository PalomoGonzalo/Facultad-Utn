/*
 * pantalla.h
 *
 *  Created on: 30 sept. 2021
 *      Author: mati_
 */

#ifndef PANTALLA_H_
#define PANTALLA_H_
#define OCUPADO 0
#define VACIO 1
typedef struct {

	int type;// 0 lcd 1 plasma
	float price;
	int id;
	char name[128];
	char addres[128];
	int flagEmpty;
}Display;

int disp_initList( Display displaysList[],int len);
int disp_loadDisplay( Display displaysList[],int len);
int disp_buscarLibre(Display displaysList[],int len);
int dameUnIdNuevo(void);
void mostrarStruct(Display mostrar [],int len);
int buscarIdStruct(Display listado[],int len, int id);
int disp_menuModificar(Display displaysList[],int len,int indice);
int disp_modifica(Display displaysList[],int len);
void mostrarUno(Display displaysList[],int indice);
int disp_bajaMenu(Display displaysList[],int len,int indice);
int disp_Baja(Display displaysList[],int len);
//int deseaContinuar(void);


#endif /* PANTALLA_H_ */
