#include "estadio.h"
#include "jugador.h"
#include "pelota.h"
#include "arco.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#ifndef VIEW_H
#define VIEW_H

using namespace std;

const unsigned int SCR_WIDTH = 1200;
const unsigned int SCR_HEIGHT = 800;
const float AUM=0.38f;
const float ARC=0.1f;

class View
{
  public:
  	GLFWwindow *ventana;
	/*DATOS DEL TAMAÑO DE LA PANTALLA*/
	View();
	/*VERTICES DE NUESTRAS FIGURAS*/
	/*VERTICES DE LOS ARCOS*/
		/*ARCO UNO*/
	float vertices4[20] = {
        // positions           // texture coords
         -0.8f+ARC,  0.7f-AUM-ARC, 0.0f,      0.0f, 1.0f, // top right
         -0.8f+ARC, -0.4f-AUM-ARC, 0.0f,      0.0f, 0.0f, // bottom right
         -1.0f,     -0.4f-AUM-ARC, 0.0f,      1.0f, 0.0f, // bottom left
         -1.0f,      0.7f-AUM-ARC, 0.0f,      1.0f, 1.0f  };// top left 
    	/*ARCO DOS*/
    float vertices5[20] = {
        // positions           // texture coords
         1.0f,      0.7f-AUM-ARC, 0.0f,      1.0f, 1.0f, // top right
         1.0f,     -0.4f-AUM-ARC, 0.0f,      1.0f, 0.0f, // bottom right
         0.8f-ARC, -0.4f-AUM-ARC, 0.0f,      0.0f, 0.0f, // bottom left
         0.8f-ARC,  0.7f-AUM-ARC, 0.0f,      0.0f, 1.0f  };// top left 

	/*VERTICES DE LA PANTALLA*/
	float vertices2[20] = {
        // positions           // texture coords
         1.0f,  1.0f, 0.0f,      1.0f, 1.0f, // top right
         1.0f, -1.0f, 0.0f,      1.0f, 0.0f, // bottom right
         -1.0f, -1.0f, 0.0f,      0.0f, 0.0f, // bottom left
         -1.0f, 1.0f, 0.0f,      0.0f, 1.0f  };// top left 
    /*VERTICES DE LA PELOTA*/
	float vertices3[20] = {
        // posicion         // textura
          0.05f, -0.15f-AUM, 0.0f,      1.0f, 1.0f, // top right
          0.05f, -0.25f-AUM, 0.0f,      1.0f, 0.0f, // bottom right
         -0.05f, -0.25f-AUM, 0.0f,      0.0f, 0.0f, // bottom left
         -0.05f, -0.15f-AUM, 0.0f,      0.0f, 1.0f  };// top left 
	/*DATOS DEL JUGADOR UNO*/
	float vertices1_1[20] = {
        // positions           // texture coords
         -0.1f,  0.1f-AUM, 0.0f,      1.0f, 1.0f, // top right
         -0.1f, -0.3f-AUM, 0.0f,      1.0f, 0.0f, // bottom right
         -0.5f, -0.3f-AUM, 0.0f,      0.0f, 0.0f, // bottom left
         -0.5f, 0.1f-AUM, 0.0f,      0.0f, 1.0f  };// top left 
    float vertices1_2[20] = {
        // positions           // texture coords
         0.5f,  0.1f-AUM, 0.0f,      1.0f, 1.0f, // top right
         0.5f, -0.3f-AUM, 0.0f,      1.0f, 0.0f, // bottom right
         0.1f, -0.3f-AUM, 0.0f,      0.0f, 0.0f, // bottom left
         0.1f, 0.1f-AUM, 0.0f,      0.0f, 1.0f  };// top left
    float vertices1[20] = {
        // positions           // texture coords
         0.2f,  0.1f-AUM, 0.0f,      1.0f, 1.0f, // top right
         0.2f, -0.3f-AUM, 0.0f,      1.0f, 0.0f, // bottom right
        -0.2f, -0.3f-AUM, 0.0f,      0.0f, 0.0f, // bottom left
        -0.2f,  0.1f-AUM, 0.0f,      0.0f, 1.0f  };// top left      
              
	unsigned int indices1[6] = {  
        0, 1, 3, // first triangle
        1, 2, 3 }; // second triangle
    
    /*FUCNIONES PARA QUE EL USUARIO PUEDA VER*/
    void framebuffer_size_callback(GLFWwindow* window, int width, int height); 
    void InicializacionPantalla();
    void Cargando_objetos(Estadio *campo,Jugador *jugador1,Jugador *jugador2,Pelota *pelota,Arco *arco1,Arco *arco2);
    void loop_graficar(Estadio *campo,Jugador *jugador1,Jugador *jugador2,Pelota *pelota,Arco *arco1,Arco *arco2);
    void limpiar(Estadio *campo,Jugador *jugador1,Jugador *jugador2,Pelota *pelota,Arco *arco1,Arco *arco2);
    ~ View();
};    

#endif
