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
		gravedad.x=0.0f;
		gravedad.y=-0.981f;
		gravedad.z=0.0f;
		fuerza.x=1.0f;
		fuerza.y=10.0f;
		fuerza.z=0.0f;
	}
void Movimiento::move()
	{
		cout<<pos.x<<pos.y<<pos.z<<"\n";
		m=glm::mat4(1.0f);
		m=glm::translate(m,pos);
		m=glm::rotate(m,glm::radians(angulo),glm::vec3(0.0f,0.0f,1.0f));
	}
/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<MOVIMIENTOS JUGADOR<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
void Movimiento::saltar()
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
void Movimiento::adelante()
	{
		if (pos.x<=0.7 )
			{pos.x+=0.02f;}
	}
void Movimiento::atras()
	{
		if ( pos.x>=-0.7 )
			{pos.x-=0.02f;}
	}
void Movimiento::cabecear_atras()
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
void Movimiento::cabecear_adelante()
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
void Movimiento::retroceder_colision()
	{
		if ( pos.x<=0.7 and pos.x>=-0.7 )
		{
			pos.x-=0.12f;
		}		 	
 	} 	
void Movimiento::avanzar_colision()
	{
		if ( pos.x>=-0.7 and pos.x<=0.7 )
		{
			pos.x+=0.12f;
		}
	}		
/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<MOVIMIENTOS PELOTA<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
/*LIMITES DEL BALON*/
void Movimiento::choque()
	{
		if (choque_pelota){
		cout<<"\n<<<<<<<<<<<<<<<<<<<<choque<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
			if (pos.x<=-0.85f )
			{
				velocidad.x=-(0.8*velocidad.x);
				pos.x=-0.85f+0.05f;
				choque_pelota=0;
				cout<<"\n<<<<<<<<<<<<<<<<<<<choque_en_x_izquierda<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
			}else if ( pos.x>=0.85f){
				velocidad.x=-(0.8*velocidad.x);
				pos.x=0.85f-0.05f;
				choque_pelota=0;
				cout<<"\n<<<<<<<<<<<<<<<<<<<<choque_en_x_derecha<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
			}else if(pos.y<=0.0f ){		
				velocidad.y=-(0.8*velocidad.y);
				pos.y=0.0+0.06f;
				choque_pelota=0;
			}else if(pos.y>=1.00f){
				velocidad.y=-(0.8*velocidad.y);
				pos.y=1.00-0.05f;
				choque_pelota=0;
			}else if(obj_choque_der_up){
				//cout<<"\n<<<<<<<<<<<<<<<<<<<<derecha<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
				pos.x+=0.05f;
				pos.y+=0.005f;
				choque_pelota=0;
				obj_choque_der_up=0;
			}else if(obj_choque_izq_up ){
				//cout<<"\n<<<<<<<<<<<<<<<<<<<<izquierda<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
				pos.x-=0.05f;
				pos.y+=0.005f;
				choque_pelota=0;
				obj_choque_izq_up=0;
			}else if(obj_choque_der_down){
				pos.x+=0.05f;
				pos.y-=0.001f;
				choque_pelota=0;
				obj_choque_der_down=0;
			}else if(obj_choque_izq_down){
				pos.x-=0.05f;
				pos.y-=0.001f;
				choque_pelota=0;
				obj_choque_izq_down=0;
			}else if(parante_derecho){
				velocidad.x=-(0.8*velocidad.x);
				velocidad.y=-(0.8*velocidad.y);
				pos.y-=0.05f;
				pos.x-=0.05f;
				choque_pelota=0;
				parante_derecho=0;
			}else if(parante_izquierdo){
				velocidad.x=-(0.8*velocidad.x);
				velocidad.y=-(0.8*velocidad.y);
				pos.y-=0.05f;
				pos.x+=0.05f;
				choque_pelota=0;
				parante_izquierdo=0;		
			}else{
			cout<<"\n<<<<<<<<<<<<<<<<<<<<nada<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
			}
		}
	}
	
/*-------------------------MOVIMIENTOS DEL BALON-------------------------------------------*/
		
void Movimiento::parabola_derecha(float &dt)
	{
		if (disparo_parabola_derecha and obj_choque_der)
		{	
			    fuerza.x=100.0f;
				fuerza.y=100.0f;
				fuerza.z=0.0f;
				velocidad.x=0.0f;
				velocidad.y=0.0f;
				velocidad.z=0.0f;
				disparo_parabola_derecha=0;
		
		}else{
			disparo_parabola_derecha=0;
			obj_choque_der=0;
		}
	}
			
void Movimiento::parabola_izquierda(float &dt)
	{
		if (disparo_parabola_izquierda and obj_choque_izq)
			{
				fuerza.x=-100.0f;
				fuerza.y=100.0f;
				fuerza.z=0.0f;
				velocidad.x=0.0f;
				velocidad.y=0.0f;
				velocidad.z=0.0f;
				disparo_parabola_izquierda=0;
			
			}else{
				disparo_parabola_izquierda=0;
				obj_choque_izq=0;
			}
 	}
					
void Movimiento::move_balon(float &dt)
	{
		if(!golpe){
			velocidad=velocidad+fuerza*dt+gravedad*dt;
			pos=pos+velocidad*dt*disminucion;
			cout<<"VELOCIDAD::"<<velocidad.x<<"<<<<<<<<<<<<<<<<<<"<<velocidad.y<<"\n";
			fuerza.x=0.0f;
			fuerza.y=0.0f;	
			fuerza.z=0.0f;	
		}else{
			fuerza.y=0.0;
		}	
	}
/*REINICION DESPUES DEL GOL*/	
//sobreescribir la funcion
void Movimiento::anotacion()
	{
		if (gol)
		{
			
			velocidad.x=0.0f;
			velocidad.y=0.0f;
			velocidad.z=0.0f;
			fuerza.x=40.0f;
			fuerza.y=100.0f;
			fuerza.z=0.0f;
			pos.x=0.0f;
			pos.y=0.0f;
			pos.z=0.0f;
			gol=0;
		}else{
			gol=0;
		}	
	}
		
