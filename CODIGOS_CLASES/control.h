
#include "movimiento.h"

#ifndef CONTROL_H
#define CONTROL_H

using namespace std;

class Control
{
  public:
  	 const float limite=0.000000001f;
  	/*DECLARACION DE VARIABLES*/
  	/*CONSTRUCOTR DE MI Movimiento */	
	Control();
	/*FUNCIONES DE LA CLASE*/
	void teclas(Movimiento *objeto,Movimiento *objeto_b,GLFWwindow *ventana,int salto,int adelante,int atras,int cabecear_atras,int cabecear_adelante);
	void cambio(int &cambio);
	void colision_cabeza_balon(Movimiento *objeto_a,Movimiento *objeto_pelota);
	void colision_costados_balon(Movimiento *objeto_pelota);
	float  punto_circulo(float x,float h,float y,float k);
	void colision_cuerpo(Movimiento *objeto_a,Movimiento *objeto_b);
	void colision_arcos(Movimiento *objeto_pelota,Movimiento *objeto_jugador1,Movimiento *objeto_jugador2);
};
	
#endif

