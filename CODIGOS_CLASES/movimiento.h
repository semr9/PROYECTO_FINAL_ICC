#ifndef MOVIMIENTO_H
#define MOVIMIENTO_H

using namespace std;

class Movimiento
{
  public:
  	/*DECLARACION DE VARIABLES GENERALES*/
  	glm::mat4 m;
	glm::vec3 pos;
	/*DECLARACION DE VARIABLES BALON*/
  	glm::vec3 gravedad; 
	glm::vec3 velocidad;
	glm::vec3 fuerza;
	/*VARIABLES DE JUGADOR*/	
	float angulo=0.0f;
	int salto=0;
	int cabeza_atras=0;
	int cabeza_adelante=0;
	float angulo_atras=-8.0f;
	float angulo_adelante=8.0f;
	int patear=0;
	int empujar_atras=0;
	int empujar_adelante=0;
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
	int gol=0;
	/*CONSTRUCOTR DE MI Movimiento */	
	Movimiento();
	/*FUNCIONES DE LA CLASE*/
	void move();
	/*FUNCIONES DE JUGADOR*/
	void adelante();
	void atras	();
	void saltar();
	void retroceder_colision();
	void avanzar_colision();
	void cabecear_atras();
	void cabecear_adelante();
	/*FUNCIONES DE BALON*/
	void move_balon(float &delta);
	void choque();
	void parabola_izquierda(float &delta);
	void parabola_derecha(float &delta);
	/*FUNCIONES GENERALES*/
	void anotacion();	
};

#endif

