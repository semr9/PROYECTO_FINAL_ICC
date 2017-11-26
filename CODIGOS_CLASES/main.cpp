/*INICIALIZAMOS TODAS LAS CARPETAS Y LIBRERIAS QUE VAMOS A NECESITAR */
#define STB_IMAGE_IMPLEMENTATION
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <learnopengl/shader_s.h>

#include <iostream>
#include "jugador.h"
#include "arco.h"
#include "estadio.h"
#include "pelota.h"

#include "grafica.h"
#include "movimiento.h"
#include "control.h"

#include "model.h"
#include "view.h"
#include "controler.h"
Jugador *jugador1;
Jugador *jugador2;
Pelota  *pelota;
Estadio *campo;
Arco 	*arco1;
Arco 	*arco2; 	    
int main ()
{
	jugador1=new Jugador;
	jugador2=new Jugador;
	pelota=new Pelota;
	campo=new Estadio;
	arco1=new Arco;
	arco2=new Arco;
	View view;
	view.Cargando_objetos(campo,jugador1,jugador2,pelota,arco1,arco2);
	Model model;
	Controler controler;
	float tiempo;
	while(!glfwWindowShouldClose(view.ventana) and (tiempo<=60.0f))
	{
		tiempo = glfwGetTime();
		view.loop_graficar(campo,jugador1,jugador2,pelota,arco1,arco2);
		model.loop_model(jugador1,jugador2,pelota);
  		controler.loop_controler(jugador1,jugador2,pelota,view.ventana);
  		controler.salir_pantalla(view.ventana);
	}
		
		
		view.limpiar(campo,jugador1,jugador2,pelota,arco1,arco2);
	return 0;
}

