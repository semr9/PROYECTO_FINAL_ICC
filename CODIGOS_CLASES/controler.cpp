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
		
	}		
void Controler::salir_pantalla(GLFWwindow *ventana)
	{
    	/*ESCAPE PARA PODER SALIR DEL   JUEGO*/
    	if (glfwGetKey(ventana, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    	    glfwSetWindowShouldClose(ventana, true);    
	}	
void Controler::loop_controler(Jugador *a,Jugador *b,Pelota *c,GLFWwindow *ventana)
	{	
	 	a->player_c->teclas(a->player_m,c->pelota_m,ventana,GLFW_KEY_K,GLFW_KEY_L,GLFW_KEY_J,GLFW_KEY_H,GLFW_KEY_U);
		b->player_c->teclas(b->player_m,c->pelota_m,ventana,GLFW_KEY_S,GLFW_KEY_D,GLFW_KEY_A,GLFW_KEY_E,GLFW_KEY_F)
	}
Controler::~Controler()
	{
		cout<<"TERMINO CONTROLER\n";
	}
