/*INICIALIZAMOS TODAS LAS CARPETAS Y LIBRERIAS QUE VAMOS A NECESITAR */
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <learnopengl/shader_s.h>

#include <iostream>
#include "movimiento.h"
#include<cmath>
using namespace std;

Movimiento::Movimiento()
	{
		cout<<"INICIO MOVIMIENTO";	
		
	}
void Movimiento::move()
	{
		cout<<pos.x<<pos.y<<pos.z<<"\n";
		m=glm::mat4(1.0f);
		m=glm::translate(m,pos);
		m=glm::rotate(m,glm::radians(angulo),glm::vec3(0.0f,0.0f,1.0f));
	}

/*REINICION DESPUES DEL GOL*/	
//sobreescribir la funcion
void Movimiento::anotacion()
	{
		if (gol)
		{
			
			pos.x=0.0f;
			pos.y=0.0f;
			pos.z=0.0f;
			gol=0;
		}else{
			gol=0;
		}	
	}
		
