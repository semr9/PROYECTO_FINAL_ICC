/*INICIALIZAMOS TODAS LAS CARPETAS Y LIBRERIAS QUE VAMOS A NECESITAR */
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <learnopengl/shader_s.h>

#include <iostream>
#include "movimiento_jugador.h"
#include<cmath>
using namespace std;

Movimiento_jugador::Movimiento_jugador()
	{
		cout<<"INICIO Movimiento JUGADOR";	
	}
/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Movimiento JUGADOR<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
void Movimiento_jugador::move()
	{
		cout<<pos.x<<pos.y<<pos.z<<"\n";
		m=glm::mat4(1.0f);
		m=glm::translate(m,pos);
		m=glm::rotate(m,glm::radians(angulo),glm::vec3(0.0f,0.0f,1.0f));
	}
void Movimiento_jugador::saltar()
	{
		if (salto==1)
		{
			salto=1;
			pos.y+=0.01;
			if(pos.y>=0.5f)
				salto=-1;
		}else if(salto==-1){
			pos.y-=0.01;
			if(pos.y<=0.0f)
				salto=0;
		}
	}
void Movimiento_jugador::adelante()
	{
		if (pos.x<=0.7 )
			{pos.x+=0.02f;}
	}
void Movimiento_jugador::atras()
	{
		if ( pos.x>=-0.7 )
			{pos.x-=0.02f;}
	}
void Movimiento_jugador::cabecear_atras()
	{
		if (cabeza_atras)
		{
			cout<<"CABEZA_ATRAZ<<<<<<<<<<<<";
			angulo_atras=angulo_atras+0.175f;
			angulo=angulo_atras;
			if(angulo_atras>=0.0f)
			{
				angulo_atras=-10.0f;
				cabeza_atras=0;
			}
		}		
	}
void Movimiento_jugador::cabecear_adelante()
	{
		
		 if(cabeza_adelante){
		 	cout<<"CABEZA_ADELANTE<<<<<<<<<";
			angulo_adelante=angulo_adelante-0.175f;
			angulo=angulo_adelante;
			if(angulo_adelante<=0.0f)
			{
				angulo_adelante=10.0f;
				cabeza_adelante=0;
			}
		}		
	}	
	
//PARTE DE COLISIONES DE JUGADOR	
void Movimiento_jugador::retroceder_colision()
	{
		if ( pos.x<=0.7 and pos.x>=-0.7 )
		{
			pos.x-=0.12f;
		}		 	
 	} 	
void Movimiento_jugador::avanzar_colision()
	{
		if ( pos.x>=-0.7 and pos.x<=0.7 )
		{
			pos.x+=0.12f;
		}
	}		

/*REINICION DESPUES DEL GOL*/	
//sobreescribir la funcion
void Movimiento_jugador::anotacion()
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
		
