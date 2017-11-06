/*INICIALIZAMOS TODAS LAS CARPETAS Y LIBRERIAS QUE VAMOS A NECESITAR */
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <learnopengl/shader_s.h>

#include <iostream>
#include "juga.h"
using namespace std;

Jugador::Jugador(const char* a, const char* b, const char* c,float (&v)[20], unsigned int (&i)[6])//, const char* geometryPath = nullptr)
			:Cargar(a,b,c,v,i){}
void Jugador::dibujar()
{
	if (salto==1)
    {
    	pos.y+=0.01;
    	if(pos.y>=0.5f)
    		salto=-1;
    }else if(salto==-1){
    	pos.y-=0.01;
    	if(pos.y<=0.0f)
    		salto=0;
    }
	m=glm::mat4(1.0f); 
	m=glm::translate(m,pos);
	
	m=glm::rotate(m,0.0f,glm::vec3(0.0f,0.0f,1.0f));
			
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glDisable(GL_BLEND);

}

 
