/*INICIALIZAMOS TODAS LAS CARPETAS Y LIBRERIAS QUE VAMOS A NECESITAR */
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <learnopengl/shader_s.h>

#include <iostream>
#include "jugador.h"
#include "grafica.h"
#include "movimiento_jugador.h"
#include "control.h"
	
Jugador::Jugador()
	{
		cout<<"INICIO JUGADOR\n";
		Cargar_movimiento();
		Cargar_control();
	}    
void Jugador::Cargar_grafica(const char* a, const char* b, const char* c,float (&v)[20], unsigned int (&i)[6],int flag)
	{	
		/*PREPARACION DE NUESTRO OBJETO GRAFICA DE PLAYER*/
		player_g=new Graficar(a, b,c,v,i);
		shader_jugador=new Shader(player_g->vertexPath, player_g->fragmentPath);	    
		player_g->llenado_vertices();
		player_g->creacion_textura(flag);
		shader_jugador->use(); 
		shader_jugador->setInt("texture1", 0);
	}		
void Jugador::Cargar_movimiento()
	{
		/*PREPARACION DE NUESTRO  OBJERTO MOVIMEINTO PARA PLAYER1*/
		player_m=new Movimiento_jugador;
	}
void Jugador::Cargar_colision()
	{
		/*PREPARACION LA COLISION*/
	}
void Jugador::Cargar_control()
	{
		player_c=new Control();
	}				
		
void Jugador::dibujar_jugador()
	{
		/*DIBUJAMOS JUGADOR1*/
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, player_g->texture1);
        shader_jugador->use();
		shader_jugador->setMat4("model", player_m->m);
		//shader_jugador->setMat4("rotacion", player_m->r);
		player_g->dibujar();
	}	
	
void Jugador::limpiar_jugador()
	{	
		player_g->limpiar();
	}
		
Jugador::~Jugador()
	{
		delete player_g;
		delete player_m;
		delete shader_jugador;
	}
