#ifndef JUGADOR_H
#define JUGADOR_H
#include "cargar.h"

using namespace std;

class Jugador:public Cargar
{
  public:
  	glm::mat4 m;
	glm::vec3 pos;
	float salto=0;
	float rotacion; 
	/*CONSTRUCOTR DE MI JUGADOR */	
	Jugador(const char* vertexPath, const char* fragmentPath,const char* imagen,float (&v)[20], unsigned int (&i)[6]);
	/*FUNCIONES DE LA CLASE*/
	void dibujar();
};

#endif
