#ifndef MOVIMIENTO_PELOTA_H
#define MOVIMIENTO_PELOTA_H
#include "movimiento.h"

using namespace std;

class Movimiento_pelota :public Movimiento
{
  public:
  	/*DECLARACION DE VARIABLES BALON*/
  	glm::vec3 gravedad; 
	glm::vec3 velocidad;
	glm::vec3 fuerza;
	
	/*VARIABLES DE PELOTA*/
	int disparo_parabola_derecha=0;
	int disparo_parabola_izquierda=0;
	int obj_choque_der=0;
	int obj_choque_izq=0;
	int obj_choque_der_up=0;
	int obj_choque_izq_up=0;
	int obj_choque_der_down=0;
	int obj_choque_izq_down=0;
	float disminucion=0.4f;
	int parante_derecho=0;
	int parante_izquierdo=0;
	int golpe=0;
	int choque_pelota=0;
	/*CONSTRUCOTR DE MI Movimiento */	
	Movimiento_pelota();
	/*FUNCIONES DE BALON*/
	void move();
	void move_balon(float &delta);
	void choque();
	void parabola_izquierda(float &delta);
	void parabola_derecha(float &delta);
	/*FUNCION SOBREESCRITA*/
	void anotacion();
};

#endif

