#include "grafica.h"
#include "movimiento.h"		
#ifndef ARCO_H
#define ARCO_H

using namespace std;

class Arco
{
  public:
  	Graficar  *arco_g;
  	Shader *shader_arco;
  	Movimiento *arco_m;
  	/*CONSTRUCOTR DE MI arco */	
	Arco(); 
	/*FUNCIONES DE LA CLASE*/
	void Cargar_grafica(const char* a, const char* b, const char* c,float (&v)[20], unsigned int (&i)[6],int flag);	
	void Cargar_colision();
	void Cargar_movimiento();
	void dibujar_arco();
	void limpiar_arco();	
	/*DESCONSTRUCOTR DE MI arco */	
	~Arco();
};

#endif		
