#include "Mundo.h"
//#include "Interaccion.h"
#include <math.h>
#include "glut.h"



void Mundo::Inicializa()
{
	x_ojo = 0;
	y_ojo = 11;
	z_ojo = 22;

	esfera.SetAtributos(2, 4, 5, 15, 0, 0, 1, 50, 50);
	esfera.SetColor(255, 0, 0);

	esfera2.SetAtributos(-2, 4, -5, 15, 0, 0, 1.5, 50, 50);
	esfera2.SetColor(255, 255, 0);

	caja.Inicializa();
	plataforma.SetAtributos(-3.0f, -3.0f, 3.0f, 3.0f, 7, 7);
	plataforma.SetColor(255, 255, 255);

	hombre.SetAtributos(0, 0, 0, 0, 0, 0, 2);
	hombre.SetColor(0, 0, 255);

	disparo.SetAtributos(-2.0f, 0, 0, 0, 0, 0, 0.1, 50, 50);
	disparo.SetColor(25, 0, 255);

	bonus.SetAtributos(3, 1, 0, 0, 0, 0, 2);


}

void Mundo::Dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		0.0, 5, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    


	esfera.Dibuja();
	esfera2.Dibuja();

	caja.Dibuja();
	plataforma.DibujaS();

	hombre.Dibuja();

	disparo.Dibuja();

	bonus.Dibuja();
}


void Mundo::RotarOjo()
{
	float dist = sqrtf(x_ojo * x_ojo + z_ojo * z_ojo);
	float ang = atan2(z_ojo, x_ojo);
	ang += 0.05f;
	x_ojo = dist * cos(ang);
	z_ojo = dist * sin(ang);
}

void Mundo::Mueve()
{

	disparo.Mueve(0.025f);
	esfera.Mueve(0.025f);
	esfera2.Mueve(0.025f);
	bonus.Mueve(0.025f);

	//Interaccion::rebote(hombre, caja);

	//Interaccion::rebote(esfera, plataforma);
	//Interaccion::rebote(esfera, caja);

	//Interaccion::rebote(esfera2, plataforma);
	//Interaccion::rebote(esfera2, caja);

	//Interaccion::rebote(esfera, esfera2);

}

void Mundo::Tecla(unsigned char key)
{
	hombre.Mueve(key, 0.025f);

}
