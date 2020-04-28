#include "Mundo.h"
#include "Interaccion.h"

#include <math.h>

#include "glut.h"

Mundo::~Mundo()
{
	esferas.destruirContenido();
}



void Mundo::Inicializa()
{
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 20;

	esfera.SetAtributos(2, 8, -5, 15, 0, -9.81, 1, 50, 50);
	esfera.SetColor(255, 0, 0);

	esfera2.SetAtributos(-2, 10, 5, 15, 0, -9.81, 1.5, 50, 50);
	esfera2.SetColor(255, 255, 0);
	
	caja.Inicializa();

		
	hombre.SetAtributos(0, 0, 0, 0, 0, 0, 2);
	hombre.SetColor(0, 0, 255);

	disparo.SetAtributos(0, 0, 0, 0, 0, 9.81,0.1, 50, 50);
	disparo.SetColor(255, 255, 0);

	bonus.SetAtributos(3, 1, 0, 0, 0, 0, 2);


	for (int i = 0; i < 6; i++)
	{
		// Se inicilizan las esferas de forma dinamica con el operador new
		Esfera* aux = new Esfera(0.75+i*0.25, i, 1+i, i, i);
				
		//aux->SetAtributos(i, i + 1, i, i, 0, -9.81, 0.75 + i * 0.25, 50, 50);
		
		////// No funciona porque me falta un SetStack y SetSlices /////
		/*aux->SetPos(i, 1 + i);
		aux->SetVel(i, i);
		aux->SetRadius(0.75+ i * 0.25);
		aux->SetAcel(0, -9.81);*/ 
		//aux->SetColor(255, 0, 255);
		esferas.agregar(aux);
	}



}

void Mundo::Dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			0.0, 7.5, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    


	esfera.Dibuja();
	esfera2.Dibuja();
	
	caja.Dibuja();

	
	hombre.Dibuja();

	disparo.Dibuja();

	bonus.Dibuja();

	esferas.Dibuja();

	disparos.Dibuja();

}


void Mundo::RotarOjo()
{
	float dist=sqrtf(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}

void Mundo::Mueve()
{
	
	disparo.Mueve(0.025f);	
	esfera.Mueve(0.025f);
	esfera2.Mueve(0.025f);
	bonus.Mueve(0.025f);
	hombre.Mueve(0.025f);
	esferas.Mueve(0.025f);
	disparos.Mueve(0.025f);

	Interaccion::rebote(hombre, caja);
	
	Interaccion::rebote(esfera, caja);

	Interaccion::rebote(esfera2, caja);

	Interaccion::rebote(esfera, esfera2);

	esferas.Rebote(caja);


	Esfera* aux = esferas.colision(hombre);
	if (aux != 0)
	{
		esferas.Eliminar(aux);
	}
	
}

void Mundo::Tecla(unsigned char key)
{
	if (key == 'd' || key== 'D')
	{
		hombre.SetVel(5.0f, 0.0f);
		
	}
	if (key == 'a' || key=='A')
	{
		hombre.SetVel(-5.0f, 0.0f);
	}
	if (key == ' ')
	{
		Disparo* aux = new Disparo(hombre.GetXPos(), hombre.GetYPos());
		disparos.agregar(aux);
	}
}







