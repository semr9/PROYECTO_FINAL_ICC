#ifndef GRAFICA_H
#define GRAFICA_H

using namespace std;

class Graficar
{
  public:
  	/*VERTICES DE MI FIGURA*/
	unsigned int VBO, VAO, EBO;
	//float vertices[20];
	float (&vertices)[20];
	//unsigned int indices[6];
	unsigned int (&indices)[6];
	/*SHADERS*/
	const char* vertexPath; 
	const char* fragmentPath;
	/*TEXTURA DE LA IMAGEN*/
	unsigned int texture1;
	const char* imagen;
	int width  ,height, nrChannels;
	unsigned char *data;
	
	/*CONSTRUCOTR DE MI JUGADOR */	
	Graficar(const char* vertexPath, const char* fragmentPath,const char* imagen,float (&v)[20], unsigned int (&i)[6]);
	/*FUNCIONES DE LA CLASE*/
	//Void vincular_shader();
	void llenado_vertices();
	void dibujar();
	void creacion_textura(int flag);
  	void limpiar();
};
#endif
