/*INICIALIZAMOS TODAS LAS CARPETAS Y LIBRERIAS QUE VAMOS A NECESITAR */
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <learnopengl/shader_s.h>

#include <iostream>
#include "pelota.h"
#include "grafica.h"
#include "movimiento_pelota.h"
#include "control.h"
	
Pelota::Pelota()
{
	cout<<"INICIO Pelota\n";
	Cargar_control();
	Cargar_movimiento();
}
    
void Pelota::Cargar_grafica(const char* a, const char* b, const char* c,float (&v)[20], unsigned int (&i)[6],int flag)
	{	
		/*PREPARACION DE NUESTRO OBJETO GRAFICA DE pelota*/
		pelota_g=new Graficar(a, b,c,v,i);
		shader_pelota=new Shader(pelota_g->vertexPath, pelota_g->fragmentPath);	    
		pelota_g->llenado_vertices();
		pelota_g->creacion_textura(flag);
		shader_pelota->use(); 
		shader_pelota->setInt("texture1", 0);
	}	
void Pelota::Cargar_movimiento()
	{
		/*PREPARACION DE NUESTRO  OBJERTO MOVIMEINTO PARA pelota1*/
		pelota_m=new Movimiento_pelota;
	}
void Pelota::Cargar_colision()
	{
		/*PREPARACION LA COLISION*/
	}
void Pelota::Cargar_control()
	{
		pelota_c=new Control();
	}				
		
void Pelota::dibujar_pelota()
	{
		/*DIBUJAMOS Pelota1*/
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, pelota_g->texture1);
        shader_pelota->use();
		shader_pelota->setMat4("model", pelota_m->m);
		pelota_g->dibujar();
	}	
	
void Pelota::limpiar_pelota()
	{	
		pelota_g->limpiar();
	}
		
Pelota::~Pelota()
	{
		delete pelota_g;
		delete pelota_m;
	}
