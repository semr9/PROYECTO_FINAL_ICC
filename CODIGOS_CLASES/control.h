
#include "movimiento_jugador.h"
#include "movimiento_pelota.h"
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
	void teclas(Movimiento_jugador *objeto,Movimiento_pelota *objeto_b,GLFWwindow *ventana,int salto,int adelante,int atras,int cabecear_atras,int cabecear_adelante);
	void cambio(int &cambio);
	void colision_cabeza_balon(Movimiento_jugador *objeto_a,Movimiento_pelota *objeto_pelota);
	void colision_costados_balon(Movimiento_pelota *objeto_pelota);
	float  punto_circulo(float x,float h,float y,float k);
	void colision_cuerpo(Movimiento_jugador *objeto_a,Movimiento_jugador *objeto_b);
	void colision_arcos(Movimiento_pelota *objeto_pelota,Movimiento_jugador *objeto_jugador1,Movimiento_jugador *objeto_jugador2);
};
	
#endif

