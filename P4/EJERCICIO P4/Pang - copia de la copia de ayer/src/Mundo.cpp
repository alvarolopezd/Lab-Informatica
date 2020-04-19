#include "Mundo.h"
#include "glut.h"
#include <math.h>


void Mundo::Inicializa()
{
	x_ojo = 0;
	y_ojo = 11;
	z_ojo = 22;

	esfera.SetAtributos(0, 5, 0, 0, 0, 0, 1, 50, 50);
	esfera.SetColor(255, 0, 0);
	
	caja.Inicializa();
	plataforma.SetAtributos(-3.0f, -3.0f, 3.0f, -3.0f, 3.0f, 3.0f, -3.0f, 3.0f, 7, 7);
	plataforma.SetColor(255, 255, 255);
	
	hombre.SetAtributos(0, 0, 0, 0, 0, 0, 2);
	hombre.SetColor(0, 0, 255);

	disparo.SetAtributos(-2.0f, 0, 0, 0, 0, 0,0.1, 50, 50);
	disparo.SetColor(25, 0, 255);

	bonus.SetAtributos(3, 1, 0, 0, 0, 0, 2);


}

void Mundo::Dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			0.0, 5, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    


	esfera.Dibuja();
	
	caja.Dibuja();
	plataforma.Dibuja();
	
	hombre.Dibuja();

	disparo.Dibuja();

	bonus.Dibuja();
}


void Mundo::RotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}


void Mundo::Tecla(unsigned char key)
{
	hombre.Mueve(key);
	esfera.Mueve(key);
	Interaccion::rebote(hombre, caja);
	//Interaccion::rebote(esfera, caja);


}


void Mundo::Mueve(int value)
{
	
	disparo.Mueve(value);
}



