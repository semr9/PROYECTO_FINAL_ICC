#include "jugador.h"
#include "arco.h"
#include "pelota.h"
#ifndef MODEL_H
#define MODEL_H

using namespace std;

class Model
{
  public:
  	int cont=0;
  	float tiempo_frame=0.0f;
	float tiempo_delta=0.0f;
	float ultimo_frame=0.0f;
	/*CONSTRUCOTR DE MI MODEL */	
	Model();
	/*FUNCIONES DE LA CLASE*/
	void Cargando_movimiento(Jugador *a,Jugador *b,Pelota *c,Arco *e,Arco *f);
	void loop_model(Jugador *a,Jugador *b,Pelota *c);

	~Model();

};
#endif

