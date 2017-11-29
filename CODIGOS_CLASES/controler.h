
#include "jugador.h"
#include "arco.h"
#include "estadio.h"
#include "pelota.h"

#include "model.h"
#include "view.h"

#ifndef CONTROLER_H
#define CONTROLER_H

using namespace std;
class Controler
{
  public:
  	/*OBJETOS D¿QUE SE MUESTRAN*/
  	Jugador *jugador1;
	Jugador *jugador2;
	Pelota  *pelota;
	Estadio *campo;
	Arco 	*arco1;
	Arco 	*arco2; 	    
	/*OBJETOS ABSTRACTOS QUE MANEJAN EL FLUIDO DEL JUEGO*/
	View *view;
	Model *model;
	float tiempo;
	/*CONSTRUCOTR DE MI MODEL */	
	Controler();
	/*FUNCIONES DE LA CLASE*/
	void cargar_view();
	void cargar_model();
	void jugando();
	void fin();
	void salir_pantalla(GLFWwindow *ventana);
	void loop_controler(Jugador *a,Jugador *b,Pelota *c,GLFWwindow *ventana);
	
		
	/*DESCONSTRUCTOR DE MI MODEL */	
	~Controler();

};

#endif

