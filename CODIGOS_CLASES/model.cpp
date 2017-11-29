/*INICIALIZAMOS TODAS LAS CARPETAS Y LIBRERIAS QUE VAMOS A NECESITAR */
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <learnopengl/shader_s.h>

#include <iostream>
#include "model.h"
#include "jugador.h"
#include "arco.h"
#include "pelota.h"

#include "model.h"
#include "view.h"

Model::Model()
	{
		cout<<"CREO MODEL";
	}	
void Model::Cargando_movimiento(Jugador *a,Jugador *b,Pelota *c,Arco *e,Arco *f)
	{	
	 	a->Cargar_movimiento();
		b->Cargar_movimiento();
		c->Cargar_movimiento();
		e->Cargar_movimiento();
		f->Cargar_movimiento();
	}
void Model::loop_model(Jugador *a,Jugador *b,Pelota *c)
	{
		tiempo_frame = glfwGetTime();
		tiempo_delta = tiempo_frame- ultimo_frame;
		
		a->player_m->anotacion();
		b->player_m->anotacion();
		c->pelota_m->anotacion();
		
		a->player_m->cabecear_atras();
		a->player_m->cabecear_adelante();
		b->player_m->cabecear_adelante();
		b->player_m->cabecear_atras();
		
		a->player_m->move();
		b->player_m->move();
		c->pelota_m->move();
		
		a->player_m->saltar();
		b->player_m->saltar();
		
		c->pelota_m->parabola_derecha(tiempo_delta);
		c->pelota_m->parabola_izquierda(tiempo_delta);
		c->pelota_m->move_balon(tiempo_delta);
		
		c->pelota_c->colision_costados_balon(c->pelota_m);
		
		b->player_c->colision_cuerpo(b->player_m,a->player_m);
		a->player_c->colision_cabeza_balon(a->player_m,c->pelota_m);
		b->player_c->colision_cabeza_balon(b->player_m,c->pelota_m);
		c->pelota_m->choque();
		c->pelota_c->colision_arcos(c->pelota_m,a->player_m,b->player_m);
    	
    	ultimo_frame = tiempo_frame;
	}
Model::~Model()
	{
		cout<<"TERMINO MODEL\n";
	}
