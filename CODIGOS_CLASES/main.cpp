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

#include "controler.h"
int main ()
{
	Controler controler;
	while(!glfwWindowShouldClose(controler.view->ventana) and (controler.tiempo<=60.0f))
		{controler.jugando();}					
	controler.fin();
	return 0;
}
