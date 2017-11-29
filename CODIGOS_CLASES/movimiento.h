#ifndef MOVIMIENTO_H
#define MOVIMIENTO_H

using namespace std;

class Movimiento
{
  public:
  	/*DECLARACION DE VARIABLES GENERALES*/
  	glm::mat4 m;
	glm::vec3 pos;
	int gol=0;
	float angulo=0.0f;
	/*CONSTRUCOTR DE MI Movimiento */	
	Movimiento();
	/*FUNCIONES DE LA CLASE*/
	virtual void move();
	virtual void anotacion();	
};

#endif

