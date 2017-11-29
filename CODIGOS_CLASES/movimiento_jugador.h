#ifndef MOVIMIENTO_JUGADOR_H
#define MOVIMIENTO_JUGADOR_H
#include "movimiento.h"

using namespace std;

class Movimiento_jugador:public Movimiento
{
  public:
  	/*DECLARACION DE VARIABLES GENERALES*/
  	glm::mat4 m;
	glm::vec3 pos;
	/*VARIABLES DE JUGADOR*/	
	int salto=0;
	int cabeza_atras=0;
	int cabeza_adelante=0;
	float angulo_atras=-8.0f;
	float angulo_adelante=8.0f;
	int patear=0;
	int empujar_atras=0;
	int empujar_adelante=0;
	int marcador=0;
	/*CONSTRUCOTR DE MI MOVIMIENTO_JUGADOR */	
	Movimiento_jugador();
	/*FUNCIONES DE JUGADOR*/
	void move();
	void adelante();
	void atras	();
	void saltar();
	void retroceder_colision();
	void avanzar_colision();
	void cabecear_atras();
	void cabecear_adelante();
	void anotacion();
};

#endif

