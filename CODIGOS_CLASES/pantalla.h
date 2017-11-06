#ifndef PANTALLA_H
#define PANTALLA_H
#include "cargar.h"

using namespace std;

class Pantalla:public Cargar
{
  public: 
	/*CONSTRUCOTR DE MI PANTALLA */	
	Pantalla(const char* vertexPath, const char* fragmentPath,const char* imagen,float (&v)[20], unsigned int (&i)[6]);
	/*FUNCIONES DE LA CLASE*/
	void dibujar();
};

#endif
