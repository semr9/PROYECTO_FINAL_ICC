/*INICIALIZAMOS TODAS LAS CARPETAS Y LIBRERIAS QUE VAMOS A NECESITAR */
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <learnopengl/shader_s.h>

#include <iostream>
#include "view.h"
View::View()
	{
		cout<<"CREACION VIEW\n";
		InicializacionPantalla();		
	}	
void View::framebuffer_size_callback(GLFWwindow* ventana, int width, int height)
	{
    	glViewport(0, 0, width, height);
	}
    
void View::InicializacionPantalla()
	{    
		/*PROCESOS PARA PODER INICIALIZAR NUESTRA PROYECCION*/	
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		ventana = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Head soccer", NULL, NULL);
		
		if (ventana == NULL)
		{
		    std::cout << "Fallo para crear  GLFW window" << std::endl;
		    glfwTerminate();
		}
		glfwMakeContextCurrent(ventana);
		//glfwGetFramebufferSize(ventana, &width, &height);
		//glfwSetFramebufferSizeCallback(ventana,framebuffer_size_callback);
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
		    std::cout << "Fallo para inicializar  GLAD" << std::endl;
		glEnable(GL_DEPTH_TEST);
		}
		std::cout << "paso11" << std::endl;
	}
	
void View::Cargando_objetos(Estadio *campo,Jugador *jugador1,Jugador *jugador2,Pelota *pelota,Arco *arco1,Arco *arco2)
	{	
	 	/*PREPARACION DE NUESTRO OBJETO PANTALLA*/
		
		campo->Cargar_grafica("/home/sebastian/Documents/LIBRIRY_GLFW/pruebas/PROYECT_1/JUEGO_CABEZONES/EjemploOpenGLCmake/src/SHADERS/shader_pantalla.vs", "/home/sebastian/Documents/LIBRIRY_GLFW/pruebas/PROYECT_1/JUEGO_CABEZONES/EjemploOpenGLCmake/src/SHADERS/shader_pantalla.fs","/home/sebastian/Documents/LIBRIRY_GLFW/pruebas/PROYECT_1/JUEGO_CABEZONES/EjemploOpenGLCmake/src/IMAGENES/bernabeu.jpg",vertices2,indices1,GL_RGB);
		
	 	/*PREPARACION DE NUESTRO PRIMER OBJERTO, LLAMADO PLAYER2*/
		jugador1->Cargar_grafica("/home/sebastian/Documents/LIBRIRY_GLFW/pruebas/PROYECT_1/JUEGO_CABEZONES/EjemploOpenGLCmake/src/SHADERS/shader_jugador.vs", "/home/sebastian/Documents/LIBRIRY_GLFW/pruebas/PROYECT_1/JUEGO_CABEZONES/EjemploOpenGLCmake/src/SHADERS/shader_jugador.fs","/home/sebastian/Documents/LIBRIRY_GLFW/pruebas/PROYECT_1/JUEGO_CABEZONES/EjemploOpenGLCmake/src/IMAGENES/messi.png",vertices1,indices1,GL_RGBA);
		
		/*PREPARACION DE NUESTRO PRIMER OBJERTO, LLAMADO PLAYER1*/
		jugador2->Cargar_grafica("/home/sebastian/Documents/LIBRIRY_GLFW/pruebas/PROYECT_1/JUEGO_CABEZONES/EjemploOpenGLCmake/src/SHADERS/shader_jugador.vs", "/home/sebastian/Documents/LIBRIRY_GLFW/pruebas/PROYECT_1/JUEGO_CABEZONES/EjemploOpenGLCmake/src/SHADERS/shader_jugador.fs","/home/sebastian/Documents/LIBRIRY_GLFW/pruebas/PROYECT_1/JUEGO_CABEZONES/EjemploOpenGLCmake/src/IMAGENES/maradona.png",vertices1,indices1,GL_RGBA);
		
		/*PREPARACION DE NUESTRO OBJETO PELOTA*/
		pelota->Cargar_grafica("/home/sebastian/Documents/LIBRIRY_GLFW/pruebas/PROYECT_1/JUEGO_CABEZONES/EjemploOpenGLCmake/src/SHADERS/shader_pelota.vs", "/home/sebastian/Documents/LIBRIRY_GLFW/pruebas/PROYECT_1/JUEGO_CABEZONES/EjemploOpenGLCmake/src/SHADERS/shader_pelota.fs","/home/sebastian/Documents/LIBRIRY_GLFW/pruebas/PROYECT_1/JUEGO_CABEZONES/EjemploOpenGLCmake/src/IMAGENES/pelota.png",vertices3,indices1,GL_RGBA);
		
		/*PREPARACION DE NUESTRO OBJETO ARCO1*/
		arco1->Cargar_grafica("/home/sebastian/Documents/LIBRIRY_GLFW/pruebas/PROYECT_1/JUEGO_CABEZONES/EjemploOpenGLCmake/src/SHADERS/shader_pantalla.vs", "/home/sebastian/Documents/LIBRIRY_GLFW/pruebas/PROYECT_1/JUEGO_CABEZONES/EjemploOpenGLCmake/src/SHADERS/shader_pantalla.fs","/home/sebastian/Documents/LIBRIRY_GLFW/pruebas/PROYECT_1/JUEGO_CABEZONES/EjemploOpenGLCmake/src/IMAGENES/arco2.png",vertices4,indices1,GL_RGBA);
		/*PREPARACION DE NUESTRO OBJETO ARCO2*/
		arco2->Cargar_grafica("/home/sebastian/Documents/LIBRIRY_GLFW/pruebas/PROYECT_1/JUEGO_CABEZONES/EjemploOpenGLCmake/src/SHADERS/shader_pantalla.vs", "/home/sebastian/Documents/LIBRIRY_GLFW/pruebas/PROYECT_1/JUEGO_CABEZONES/EjemploOpenGLCmake/src/SHADERS/shader_pantalla.fs","/home/sebastian/Documents/LIBRIRY_GLFW/pruebas/PROYECT_1/JUEGO_CABEZONES/EjemploOpenGLCmake/src/IMAGENES/arco2.png",vertices5,indices1,GL_RGBA);
	}
void View::loop_graficar(Estadio *campo,Jugador *jugador1,Jugador *jugador2,Pelota *pelota,Arco *arco1,Arco *arco2)
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
		/*DIBUJAMOS EL CAMPO EN QUE SE JUGARA*/
        campo->dibujar_estadio();
		/*DIBUJAMOS A ARCO1*/
        arco1->dibujar_arco();
        /*DIBUJAMOS A ARCO2*/
        arco2->dibujar_arco();
        /*DIBUJAMOS JUGADOR2*/
     	jugador1->dibujar_jugador();
		/*DIBUJAMOS JUGADOR1*/
       	jugador2->dibujar_jugador();
        /*DIBUJAMOS A PELOTA*/
		pelota->dibujar_pelota();
		
		glfwSwapBuffers(ventana);
        glfwPollEvents();		
	}	
	
void View::limpiar(Estadio *campo,Jugador *jugador1,Jugador *jugador2,Pelota *pelota,Arco *arco1,Arco *arco2)
	{	
		jugador1->limpiar_jugador();
		jugador2->limpiar_jugador();
		pelota->limpiar_pelota();
		campo->limpiar_estadio();
		arco1->limpiar_arco();
		arco2->limpiar_arco();
		glfwTerminate(); 
	}	
View:: ~View()
	{
		cout<<"TERMINO VIEW\n";
	}	
