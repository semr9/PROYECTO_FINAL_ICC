#include "grafica.h"
#ifndef ESTADIO_H
#define ESTADIO_H

using namespace std;

class Estadio
{
  public:
  	Graficar  *estadio_g;
  	Shader *shader_estadio;
  	/*CONSTRUCOTR DE MI estadio */	
	Estadio(); 
	/*FUNCIONES DE LA CLASE*/
	void Cargar_grafica(const char* a, const char* b, const char* c,float (&v)[20], unsigned int (&i)[6],int flag);	
	void dibujar_estadio();
	void limpiar_estadio();	
	/*DESCONSTRUCOTR DE MI estadio */	
	~Estadio();
};

#endif	
