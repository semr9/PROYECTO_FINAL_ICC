/*INICIALIZAMOS TODAS LAS CARPETAS Y LIBRERIAS QUE VAMOS A NECESITAR */
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <learnopengl/shader_s.h>

#include <iostream>
#include "control.h"
#include "movimiento_jugador.h"
#include "movimiento_pelota.h"
using namespace std;

Control::Control()
	{
		cout<<"CREO CONTROL\n";	
	}

void Control::teclas(Movimiento_jugador *objeto,Movimiento_pelota *objeto_b,GLFWwindow *ventana,int salto,int adelante,int atras,int cabecear_atras,int cabecear_adelante )
	{
	/*SALTO */
		if (glfwGetKey(ventana, salto) == GLFW_PRESS)
		    {
				if (!objeto->salto){
					cambio(objeto->salto);
				}
		   }
	/*MOVIMIENTO */    
		if (glfwGetKey(ventana, atras) == GLFW_PRESS)
		    {objeto->atras();}
		    
		if (glfwGetKey(ventana, adelante) == GLFW_PRESS)
		    {objeto->adelante();}
	/*CABECEAR ATRAS*/	
		if (glfwGetKey(ventana,cabecear_atras) == GLFW_PRESS)
		    {
		    	if (!objeto->cabeza_atras){
					cambio(objeto->cabeza_atras);
				}
				if (!objeto_b->disparo_parabola_izquierda){
						cambio(objeto_b->disparo_parabola_izquierda);
					}	
			}
	/*CABECEAR ADELANTE*/		
		if (glfwGetKey(ventana,cabecear_adelante) == GLFW_PRESS)
				{
					if (!objeto->cabeza_adelante){
						cambio(objeto->cabeza_adelante);
					}
					if (!objeto_b->disparo_parabola_derecha){
						cambio(objeto_b->disparo_parabola_derecha);
					}
				}
	}
void Control::colision_cuerpo(Movimiento_jugador *objeto_a,Movimiento_jugador *objeto_b)
	{
 		cout<<"recta_costado_derecha::"<<objeto_a->pos.x+0.3f<<"\n";
		cout<<"recta_costado_izquierda::"<<objeto_a->pos.x-0.3f<<"\n";
		cout<<"recta_arriba::"<<objeto_a->pos.y+0.3f<<"\n";
		cout<<"recta_abajo::"<<objeto_a->pos.y-0.3f<<"\n";
		cout<<"punto del otro::>>>>>>x::"<<objeto_b->pos.x<<">>>>y::"<<objeto_b->pos.y<<"\n";
 		
 		if ((objeto_a->pos.x+0.3f>=objeto_b->pos.x) and (objeto_a->pos.x-0.3f<=objeto_b->pos.x) and (objeto_a->pos.y+0.3f>=objeto_b->pos.y) and (objeto_a->pos.y-0.3f<=objeto_b->pos.y))
 		{
 			cout<<"ENTRO<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
 			if(objeto_a->pos.x>objeto_b->pos.x)
 			{
 				objeto_a->avanzar_colision();
 				objeto_b->retroceder_colision();
 				
 			}else{
 				
 				objeto_b->avanzar_colision();
 				objeto_a->retroceder_colision();
 			}
 		
 	}
 }	
void Control::colision_cabeza_balon(Movimiento_jugador *objeto_a,Movimiento_pelota *objeto_pelota)
	{	
 		float punto=punto_circulo( objeto_pelota->pos.x, objeto_a->pos.x, objeto_pelota->pos.y, objeto_a->pos.y+0.15);
 		cout<<"PUNTO:::"<<punto<<"\n";
 		cout<<"RADIO:::"<<((0.1f)*(0.1f))<<"\n";
 		cout<<"LIMITE:::"<<limite<<"\n";
 		cout<<"CALCULO:::"<<(punto-((0.1f)*(0.1f)))<<"\n";
		if (punto -((0.20f)*(0.20f))<=-limite)
		{
			cout<<"entro:::"<<punto<<"\n";		
			if (objeto_a->pos.x<=objeto_pelota->pos.x and objeto_a->pos.y<=objeto_pelota->pos.y){
			
			cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ENTRO_COLISION_BALON_1<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
			
			objeto_pelota->choque_pelota=1;			
			objeto_pelota->obj_choque_der_up=1;
			objeto_pelota->obj_choque_der=1;
			objeto_pelota->velocidad.x=-(1.00158*objeto_pelota->velocidad.x);
			objeto_pelota->velocidad.y=-(1.001*objeto_pelota->velocidad.y);
			
			}else if(objeto_a->pos.x>=objeto_pelota->pos.x and objeto_a->pos.y<=objeto_pelota->pos.y){
			
			cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ENTRO_COLISION_BALON_2<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
			
			objeto_pelota->choque_pelota=1;			
			objeto_pelota->obj_choque_izq_up=1;
			objeto_pelota->obj_choque_izq=1;
			objeto_pelota->velocidad.x=-(1.00162f*objeto_pelota->velocidad.x);//+objeto_pelota->velocidad.x;
			objeto_pelota->velocidad.y=-(1.001*objeto_pelota->velocidad.y);//+objeto_pelota->velocidad.y;
				
			}else if(objeto_a->pos.x<=objeto_pelota->pos.x and objeto_a->pos.y>=objeto_pelota->pos.y){
			
			cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ENTRO_COLISION_BALON_3<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
			
			objeto_pelota->choque_pelota=1;			
			objeto_pelota->obj_choque_der_down=1;
			objeto_pelota->obj_choque_der=1;
			objeto_pelota->velocidad.x=-(1.00162*objeto_pelota->velocidad.x);//+objeto_pelota->velocidad.y;
			objeto_pelota->velocidad.y=-(0.95f*objeto_pelota->velocidad.y);//+objeto_pelota->velocidad.y;
			
			}else if(objeto_a->pos.x>=objeto_pelota->pos.x and objeto_a->pos.y>=objeto_pelota->pos.y){
			
			cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ENTRO_COLISION_BALON_4<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
			
			objeto_pelota->choque_pelota=1;			
			objeto_pelota->obj_choque_izq_down=1;
			objeto_pelota->obj_choque_izq=1;
			objeto_pelota->velocidad.x=-(1.00158*objeto_pelota->velocidad.x);//+objeto_pelota->velocidad.y;
			objeto_pelota->velocidad.y=-(0.95*objeto_pelota->velocidad.y);//+objeto_pelota->velocidad.y;
			
			}else{
			
			objeto_pelota->choque_pelota=1;			
			objeto_pelota->disparo_parabola_derecha=0;
			objeto_pelota->disparo_parabola_izquierda=0;			
			}
		}else{
			objeto_pelota->disparo_parabola_derecha=0;	
			objeto_pelota->disparo_parabola_izquierda=0;
		}
	}
void Control::colision_costados_balon(Movimiento_pelota *objeto_pelota)
	{	 		
		if(objeto_pelota->pos.x>=0.90 or objeto_pelota->pos.x<=-0.90)
		{
			objeto_pelota->choque_pelota=1;
			cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<CHOCO PELOTA COASTADOS<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
		}
		
		if(objeto_pelota->pos.y>=1.00 or objeto_pelota->pos.y<=0.0)
		{
			objeto_pelota->choque_pelota=1;
			cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<CHOCO PELOTA COSTADOS DERECHO<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
		}
		if(objeto_pelota->pos.y>=0.3 and objeto_pelota->pos.x<=-0.83 )
		{
			objeto_pelota->choque_pelota=1;
			objeto_pelota->parante_izquierdo=1;
			cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ENTRO PARANTE IZQUIERDO<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
		}
		if(objeto_pelota->pos.y>=0.3 and objeto_pelota->pos.x>=0.83 )
		{
			cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ENTRO PARANTE DERECHO<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
			objeto_pelota->choque_pelota=1;
			objeto_pelota->parante_derecho=1;
		}
	}
void Control::colision_arcos(Movimiento_pelota *objeto_pelota,Movimiento_jugador *objeto_jugador1,Movimiento_jugador *objeto_jugador2)
	{	 		
		if(objeto_pelota->pos.x<=0.85f+0.15f and objeto_pelota->pos.x>=0.85f-0.15f and objeto_pelota->pos.y>=-0.28f-0.6f and objeto_pelota->pos.y<=-0.28f+0.9f)
		{
			cout<<"<<<<<<<<<<<<<<<<<<<estoy_en_el_arco<<<<<<<<<<<<<<<<<\n";
			cout<<"<<<<<<<<<<<<<<<<<<<<<<GOL!!!!<<<<<<<<<<<<<<<<<\n";
			objeto_pelota->velocidad.x=0.0f;
			objeto_pelota->velocidad.y-=0.005f;
			objeto_pelota->pos.x+=0.00025;
			objeto_pelota->gol=1;
			objeto_jugador1->marcador++;
			objeto_jugador1->gol=1;
			objeto_jugador2->gol=1;
		}
		
		if(objeto_pelota->pos.x<=-0.85f+0.15f and objeto_pelota->pos.x>=-0.85f-0.15f and objeto_pelota->pos.y>=-0.28f-0.6f and objeto_pelota->pos.y<=-0.28f+0.9f)
		{
			cout<<"<<<<<<<<<<<<<<<<<<<estoy_en_el_arco<<<<<<<<<<<<<<<<<\n";
			cout<<"<<<<<<<<<<<<<<<<<<<<<<GOL!!!!<<<<<<<<<<<<<<<<<\n";
			objeto_pelota->velocidad.x=0.0f;
			objeto_pelota->velocidad.y-=0.005f;
			objeto_pelota->pos.x-=0.00025;
			objeto_pelota->gol=1;
			objeto_jugador2->marcador++;
			objeto_jugador1->gol=1;
			objeto_jugador2->gol=1;
		}
	}	
	
float Control::punto_circulo(float x,float h,float y,float k)
	{
		return ((x-h)*(x-h)+(y-k)*(y-k));
    }	
void Control::cambio(int &cambio)	
	{
	cambio=1;
	}	
	
