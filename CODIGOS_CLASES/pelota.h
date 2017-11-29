#include "grafica.h"
#include "movimiento.h"
#include "control.h"
#ifndef PELOTA_H
#define PELOTA_H

using namespace std;

class Pelota
{
  public:
  	Movimiento_pelota  *pelota_m;
  	Graficar  	*pelota_g;
  	Control     *pelota_c;
  	Shader      *shader_pelota;
	/*CONSTRUCOTR DE MI pelota */	
	Pelota(); 
	/*FUNCIONES DE LA CLASE*/
	void Cargar_grafica(const char* a, const char* b, const char* c,float (&v)[20], unsigned int (&i)[6],int flag);	
	void Cargar_movimiento();
	void Cargar_colision();
	void Cargar_control();
	void dibujar_pelota();
	void limpiar_pelota();	
	/*DESCONSTRUCOTR DE MI pelota */	
	~Pelota();
};

#endif	
