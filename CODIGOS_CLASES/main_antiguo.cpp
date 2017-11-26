/*INICIALIZAMOS TODAS LAS CARPETAS Y LIBRERIAS QUE VAMOS A NECESITAR */
#define STB_IMAGE_IMPLEMENTATION
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <learnopengl/shader_s.h>

#include <iostream>
#include "juga.h"
#include "pelota.h"
#include "pantalla.h"
#include "cargar.h"
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
/*DATOS DEL TAMAÑO DE LA PANTALLA*/
const unsigned int SCR_WIDTH = 1200;
const unsigned int SCR_HEIGHT = 800;
const float AUM=0.38f;
const float ARC=0.1f;
Jugador  *player1;
Jugador  *player2;
Pelota   *pelota;
Pantalla *campo;
Pantalla *arco1;
Pantalla *arco2;
int main()
{		
	/*VERTICES DE LOS ARCOS*/
		/*ARCO UNO*/
	float vertices4[] = {
        // positions           // texture coords
         -0.8f+ARC,  0.7f-AUM-ARC, 0.0f,      0.0f, 1.0f, // top right
         -0.8f+ARC, -0.4f-AUM-ARC, 0.0f,      0.0f, 0.0f, // bottom right
         -1.0f,     -0.4f-AUM-ARC, 0.0f,      1.0f, 0.0f, // bottom left
         -1.0f,      0.7f-AUM-ARC, 0.0f,      1.0f, 1.0f  // top left 
    };
    	/*ARCO DOS*/
    float vertices5[] = {
        // positions           // texture coords
         1.0f,      0.7f-AUM-ARC, 0.0f,      1.0f, 1.0f, // top right
         1.0f,     -0.4f-AUM-ARC, 0.0f,      1.0f, 0.0f, // bottom right
         0.8f-ARC, -0.4f-AUM-ARC, 0.0f,      0.0f, 0.0f, // bottom left
         0.8f-ARC,  0.7f-AUM-ARC, 0.0f,      0.0f, 1.0f  // top left 
    };
	/*VERTICES DE LA PANTALLA*/
	float vertices2[] = {
        // positions           // texture coords
         1.0f,  1.0f, 0.0f,      1.0f, 1.0f, // top right
         1.0f, -1.0f, 0.0f,      1.0f, 0.0f, // bottom right
         -1.0f, -1.0f, 0.0f,      0.0f, 0.0f, // bottom left
         -1.0f, 1.0f, 0.0f,      0.0f, 1.0f  // top left 
    };
    /*VERTICES DE LA PELOTA*/
	float vertices3[] = {
        // positions           // texture coords
          0.1f, -0.1f-AUM, 0.0f,      1.0f, 1.0f, // top right
          0.1f, -0.3f-AUM, 0.0f,      1.0f, 0.0f, // bottom right
         -0.1f, -0.3f-AUM, 0.0f,      0.0f, 0.0f, // bottom left
         -0.1f, -0.1f-AUM, 0.0f,      0.0f, 1.0f  // top left 
    };
	/*DATOS DEL JUGADOR UNO*/
	float vertices1[] = {
        // positions           // texture coords
          0.2f,  0.1f-AUM, 0.0f,      1.0f, 1.0f, // top right
          0.2f, -0.3f-AUM, 0.0f,      1.0f, 0.0f, // bottom right
         -0.2f, -0.3f-AUM, 0.0f,      0.0f, 0.0f, // bottom left
         -0.2f, 0.1f-AUM, 0.0f,      0.0f, 1.0f  // top left 
    };
	unsigned int indices1[] = {  
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };
    
	/*PROCESOS PARA PODER INICIALIZAR NUESTRA PROYECCION*/	
	glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    glEnable(GL_DEPTH_TEST);
    }
    
 	/*PREPARACION DE NUESTRO OBJETO PANTALLA*/
	campo=new Pantalla("/home/sebastian/Documents/LIBRIRY_GLFW/pruebas/PROYECT_1/JUEGO_CABEZONES/shader_pantalla.vs", "/home/sebastian/Documents/LIBRIRY_GLFW/pruebas/PROYECT_1/JUEGO_CABEZONES/shader_pantalla.fs","/home/sebastian/Documents/LIBRIRY_GLFW/pruebas/PROYECT_1/JUEGO_CABEZONES/bernabeu.jpg",vertices2,indices1);
	
	Shader shader4(campo->vertexPath, campo->fragmentPath);	    
    
    campo->llenado_vertices();
	campo->creacion_textura(GL_RGB);
	
	shader4.use();
	shader4.setInt("texture1", 0);
	
 	/*PREPARACION DE NUESTRO PRIMER OBJERTO, LLAMADO PLAYER2*/
	player2=new Jugador("/home/sebastian/Documents/LIBRIRY_GLFW/pruebas/PROYECT_1/JUEGO_CABEZONES/shader_jugador.vs", "/home/sebastian/Documents/LIBRIRY_GLFW/pruebas/PROYECT_1/JUEGO_CABEZONES/shader_jugador.fs","/home/sebastian/Documents/LIBRIRY_GLFW/pruebas/PROYECT_1/JUEGO_CABEZONES/messi.png",vertices1,indices1);
	
	Shader shader2(player2->vertexPath, player2->fragmentPath);	    
    
    player2->llenado_vertices();
	player2->creacion_textura(GL_RGBA);
	
	shader2.use();
	shader2.setInt("texture1", 0);
	
    /*PREPARACION DE NUESTRO PRIMER OBJERTO, LLAMADO PLAYER1*/
    player1=new Jugador("/home/sebastian/Documents/LIBRIRY_GLFW/pruebas/PROYECT_1/JUEGO_CABEZONES/shader_jugador.vs", "/home/sebastian/Documents/LIBRIRY_GLFW/pruebas/PROYECT_1/JUEGO_CABEZONES/shader_jugador.fs","/home/sebastian/Documents/LIBRIRY_GLFW/pruebas/PROYECT_1/JUEGO_CABEZONES/maradona.png",vertices1,indices1);

	
	Shader shader1(player1->vertexPath, player1->fragmentPath);	    
    
	player1->llenado_vertices();
	player1->creacion_textura(GL_RGBA);
	//
	
    shader1.use(); 
    shader1.setInt("texture1", 0);
    /*PREPARACION DE NUESTRO OBJETO PELOTA, LLAMADO PLAYER1*/
    pelota=new Pelota("/home/sebastian/Documents/LIBRIRY_GLFW/pruebas/PROYECT_1/JUEGO_CABEZONES/shader_pelota.vs", "/home/sebastian/Documents/LIBRIRY_GLFW/pruebas/PROYECT_1/JUEGO_CABEZONES/shader_pelota.fs","/home/sebastian/Documents/LIBRIRY_GLFW/pruebas/PROYECT_1/JUEGO_CABEZONES/pelota.png",vertices3,indices1);

	
	Shader shader3(pelota->vertexPath, pelota->fragmentPath);	    
    
	pelota->llenado_vertices();
	pelota->creacion_textura(GL_RGBA);
	//
	
    shader3.use(); 
    shader3.setInt("texture1", 0);
    /*PREPARACION DE NUESTRO OBJETO PELOTA, LLAMADO PLAYER1*/
    arco1=new Pantalla("/home/sebastian/Documents/LIBRIRY_GLFW/pruebas/PROYECT_1/JUEGO_CABEZONES/shader_pantalla.vs", "/home/sebastian/Documents/LIBRIRY_GLFW/pruebas/PROYECT_1/JUEGO_CABEZONES/shader_pantalla.fs","/home/sebastian/Documents/LIBRIRY_GLFW/pruebas/PROYECT_1/JUEGO_CABEZONES/arco2.png",vertices4,indices1);

	
	Shader shader5(arco1->vertexPath, arco1->fragmentPath);	    
    
	arco1->llenado_vertices();
	arco1->creacion_textura(GL_RGBA);
	
    shader5.use(); 
    shader5.setInt("texture1", 0);
    
    arco2=new Pantalla("/home/sebastian/Documents/LIBRIRY_GLFW/pruebas/PROYECT_1/JUEGO_CABEZONES/shader_pantalla.vs", "/home/sebastian/Documents/LIBRIRY_GLFW/pruebas/PROYECT_1/JUEGO_CABEZONES/shader_pantalla.fs","/home/sebastian/Documents/LIBRIRY_GLFW/pruebas/PROYECT_1/JUEGO_CABEZONES/arco2.png",vertices5,indices1);

	
	Shader shader6(arco2->vertexPath, arco2->fragmentPath);	    
    
	arco2->llenado_vertices();
	arco2->creacion_textura(GL_RGBA);
	
    shader6.use(); 
    shader6.setInt("texture1", 0);
    
    
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
		
		/*DIBUJAMOS EL CAMPO EN QUE SE JUGARA*/
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, campo->texture1);
        
        shader4.use();
		campo->dibujar();
		
		/*DIBUJAMOS A ARCO1*/
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, arco1->texture1);
        
		shader5.use();
		arco1->dibujar();
        
        /*DIBUJAMOS A ARCO2*/
        
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, arco2->texture1);
        
		shader6.use();
		arco2->dibujar();
		
		/*DIBUJAMOS JUGADOR2*/
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, player2->texture1);
        
        shader2.use();
        shader2.setMat4("model", player2->m);
		player2->dibujar();
		
		/*DIBUJAMOS JUGADOR1*/
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, player1->texture1);
        
		shader1.use();
		shader1.setMat4("model", player1->m);
		player1->dibujar();
		
        /*DIBUJAMOS A PELOTA*/
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, pelota->texture1);
        
		shader3.use();
		shader3.setMat4("model", pelota->m);
		pelota->dibujar();
		
		
		glfwSwapBuffers(window);
        glfwPollEvents();
    }
	player1->limpiar();
	player2->limpiar();
	pelota->limpiar();
	campo->limpiar();
	arco1->limpiar();
	arco2->limpiar();
	glfwTerminate(); 
		
	return 0;
}
void processInput(GLFWwindow *window)
{
    /*ESCAPE PARA PODER SALIR DEL   JUEGO*/
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    /*SALTO DE MI JUGADOR UNO*/
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        if (player1->salto==0){player1->salto=1;}
    /*SALTO DE MI JUGADOR DOS*/
    if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
        if (player1->salto==0){player2->salto=1;}    
    /*MOVIMIENTO DE MI JUGADOR1*/    
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        player1->pos.x-=0.02f;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        player1->pos.x+=0.02f;
    /*MOVIMIENTO DE MI JUGADOR2*/    
    if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
        player2->pos.x-=0.02f;
    if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)
        player2->pos.x+=0.02f;    
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    
    glViewport(0, 0, width, height);
}
