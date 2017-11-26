#include"jugador.h"
#include"pelota.h"
#ifndef CONTROLER_H
#define CONTROLER_H

using namespace std;

class Controler
{
  public:
	/*CONSTRUCOTR DE MI MODEL */	
	Controler();
	/*FUNCIONES DE LA CLASE*/
	void salir_pantalla(GLFWwindow *ventana);
	void loop_controler(Jugador *a,Jugador *b,Pelota *c,GLFWwindow *ventana);
	~Controler();

};

#endif

