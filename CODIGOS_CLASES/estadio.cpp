/*INICIALIZAMOS TODAS LAS CARPETAS Y LIBRERIAS QUE VAMOS A NECESITAR */
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <learnopengl/shader_s.h>

#include <iostream>
#include "estadio.h"
#include "grafica.h"
	
Estadio::Estadio()
	{
		cout<<"INICIO estadio\n";
	}
void Estadio::Cargar_grafica(const char* a, const char* b, const char* c,float (&v)[20], unsigned int (&i)[6],int flag)
	{	
		/*PREPARACION DE NUESTRO OBJETO GRAFICA DE estadio*/
		estadio_g=new Graficar(a, b,c,v,i);
		shader_estadio=new Shader(estadio_g->vertexPath, estadio_g->fragmentPath);	    
		estadio_g->llenado_vertices();
		estadio_g->creacion_textura(flag);
		shader_estadio->use(); 
		shader_estadio->setInt("texture1", 0);		
	}
void Estadio::dibujar_estadio()
	{
		/*DIBUJAMOS estadio1*/
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, estadio_g->texture1);
        shader_estadio->use();
		//shader_estadio->setMat4("model", estadio_m->m);
		estadio_g->dibujar();
	}	
void Estadio::limpiar_estadio()
	{	
		estadio_g->limpiar();
	}
		
Estadio::~Estadio()
	{
		delete estadio_g;
	}
