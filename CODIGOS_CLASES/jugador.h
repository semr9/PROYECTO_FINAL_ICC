#include "grafica.h"
#include "movimiento.h"
#include "control.h"
//#include <learnopengl/shader_s.h>

#ifndef JUGADOR_H
#define JUGADOR_H

using namespace std;

class Jugador
{
  public:
  	Movimiento_jugador  *player_m;
  	Graficar  	*player_g;
  	Control     *player_c;
  	Shader		*shader_jugador;	 
	/*CONSTRUCOTR DE MI JUGADOR */	
	Jugador(); 
	/*FUNCIONES DE LA CLASE*/
	void Cargar_grafica(const char* a, const char* b, const char* c,float (&v)[20], unsigned int (&i)[6],int flag);	
	void Cargar_movimiento();
	void Cargar_colision();
	void Cargar_control();
	void dibujar_jugador();
	void limpiar_jugador();	
	/*DESCONSTRUCOTR DE MI JUGADOR */	
	~Jugador();
};

#endif	
