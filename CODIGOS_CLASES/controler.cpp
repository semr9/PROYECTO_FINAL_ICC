/*INICIALIZAMOS TODAS LAS CARPETAS Y LIBRERIAS QUE VAMOS A NECESITAR */
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <learnopengl/shader_s.h>


#include <iostream>

#include "controler.h"
Controler::Controler()
	{
		cout<<"INICIALIZO CONTROLER";
		jugador1=new Jugador;
		jugador2=new Jugador;
		pelota=new Pelota;
		campo=new Estadio;
		arco1=new Arco;
		arco2=new Arco;
		
		cargar_view();
		cargar_model();
	}		
void Controler::cargar_view()
	{
		view =new View ;
		view->Cargando_objetos(campo,jugador1,jugador2,pelota,arco1,arco2);
	
	}
void Controler::cargar_model()
	{
		model =new Model;
	}	
void Controler::jugando()
	{
		tiempo = glfwGetTime();
		view->loop_graficar(campo,jugador1,jugador2,pelota,arco1,arco2);
		model->loop_model(jugador1,jugador2,pelota);
  		loop_controler(jugador1,jugador2,pelota,view->ventana);
  		salir_pantalla(view->ventana);
	}	
void Controler::fin()
	{
		cout<<"MARCADOR::°°°°°°°"<<"LOCAL::"<<jugador1->player_m->marcador<<" - "<<jugador2->player_m->marcador<<"::VISITANTE°°°°°°°°°°\n";
		
		view->limpiar(campo,jugador1,jugador2,pelota,arco1,arco2);
	}	
void Controler::salir_pantalla(GLFWwindow *ventana)
	{
    	
    	if (glfwGetKey(ventana, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    	    glfwSetWindowShouldClose(ventana, true);    
	}	
void Controler::loop_controler(Jugador *a,Jugador *b,Pelota *c,GLFWwindow *ventana)
	{	
	 	a->player_c->teclas(a->player_m,c->pelota_m,ventana,GLFW_KEY_K,GLFW_KEY_L,GLFW_KEY_J,GLFW_KEY_H,GLFW_KEY_U);
		b->player_c->teclas(b->player_m,c->pelota_m,ventana,GLFW_KEY_S,GLFW_KEY_D,GLFW_KEY_A,GLFW_KEY_E,GLFW_KEY_F);
	}	
Controler::~Controler()
	{
		delete jugador1;
		delete  jugador2;
		delete  pelota;
		delete  campo;
		delete  arco1;
		delete  arco2;
		delete model ;
		delete view;
		cout<<"TERMINO CONTROLER\n";
	}	
