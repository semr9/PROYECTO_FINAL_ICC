/*INICIALIZAMOS TODAS LAS CARPETAS Y LIBRERIAS QUE VAMOS A NECESITAR */
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <learnopengl/shader_s.h>

#include <iostream>
#include "arco.h"
#include "grafica.h"
#include "movimiento.h"	
Arco::Arco()
	{
		cout<<"INICIO ARCO\n";
		Cargar_movimiento();
	}
    
void Arco::Cargar_grafica(const char* a, const char* b, const char* c,float (&v)[20], unsigned int (&i)[6],int flag)
	{	
		/*PREPARACION DE NUESTRO OBJETO GRAFICA DE arco*/
		arco_g=new Graficar(a, b,c,v,i);
		shader_arco=new Shader(arco_g->vertexPath, arco_g->fragmentPath);	    
		arco_g->llenado_vertices();
		arco_g->creacion_textura(flag);
		shader_arco->use(); 
		shader_arco->setInt("texture1", 0);
	}	
void Arco::Cargar_colision()
	{
		/*PREPARACION LA COLISION*/
	}
void Arco::Cargar_movimiento()
	{
		/*PREPARACION DE NUESTRO  OBJETO MOVIENTO , YA QUE REQUIERE COLISIONES*/
		arco_m=new Movimiento;
	}
				
		
void Arco::dibujar_arco()
	{
		/*DIBUJAMOS ARCO1*/
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, arco_g->texture1);
        shader_arco->use();
		shader_arco->setMat4("model", arco_m->m);
		arco_g->dibujar();
	}	
	
void Arco::limpiar_arco()
	{	
		arco_g->limpiar();
	}
		
Arco::~Arco()
	{
		delete arco_g;
	}
