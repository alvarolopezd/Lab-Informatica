#include "Mundo.h"
#include "Interaccion.h"
#include "EsferaPulsante.h"

#include <math.h>

#include "glut.h"

Mundo::~Mundo()
{
	esferas.destruirContenido();
}



void Mundo::Inicializa()
{
	impacto = false;
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 20;

	//esfera.SetAtributos(2, 8, -5, 15, 0, -9.81, 1, 50, 50);
	//esfera.SetColor(255, 0, 0);

	//esfera2.SetAtributos(-2, 10, 5, 15, 0, -9.81, 1.5, 50, 50);
	//esfera2.SetColor(255, 255, 0);
	
	caja.Inicializa();

		
	hombre.SetAtributos(0, 0, 0, 0, 0, 0, 2);
	hombre.SetColor(0, 0, 255);

	esferas.destruirContenido();
	disparos.DestruirContenido();

	//disparo.SetAtributos(0, 0, 0, 0, 0, 9.81,0.1, 50, 50);
	//disparo.SetColor(255, 255, 0);

	bonus.SetAtributos(3, 1, 0, 0, 0, 0, 0.5);

	
	for (int i = 0; i < 3; i++)
	{
		// Se inicilizan las esferas de forma dinamica con el operador new
		Esfera* aux = new Esfera(0.75+i*0.25, i+2, i+2, i, i);

		esferas.agregar(aux);
	}

	///EsferaPulsante* e = new EsferaPulsante;
	

}

void Mundo::Dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			0.0, 7.5, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    


	//esfera.Dibuja();
	//esfera2.Dibuja();
	
	caja.Dibuja();

	
	hombre.Dibuja();

	//disparo.Dibuja();

	bonus.Dibuja();

	esferas.Dibuja();

	disparos.Dibuja();

	disparoPulsante.Dibuja();

	esferaPulsante.Dibuja();

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
	//objectoMovil.Mueve(0.025f);
	//disparo.Mueve(0.025f);	
	//esfera.Mueve(0.025f);
	//esfera2.Mueve(0.025f);
	bonus.Mueve(0.025f);
	hombre.Mueve(0.025f);
	esferas.Mueve(0.025f);
	disparos.Mueve(0.025f);
	disparoPulsante.Mueve(0.025f);

	Interaccion::rebote(hombre, caja);
	
	Interaccion::rebote(esfera, caja);

	//Interaccion::rebote(esfera2, caja);

	//Interaccion::rebote(esfera, esfera2);

	esferas.Rebote(caja);
	esferas.Rebote();

	disparos.Rebote(caja);

	Esfera* aux = esferas.colision(hombre);
	if (aux != 0)
	{
		//esferas.Eliminar(aux);
		impacto = true;
	}
	
	/*Esfera* auxd = esferas.colision(disparoPulsante);
	if (auxd != 0)
	{
		esferas.Eliminar(auxd);
	}*/

	Interaccion::rebote(disparoPulsante, caja);
	//Interaccion::rebote(disparo, caja);

	
	esferaPulsante.Mueve(0.025f);
	Interaccion::rebote(esferaPulsante, caja);
	for (int i = 0; i<esferas.GetNumero(); i++)
	{
		esferas.Rebote(esferaPulsante);
	}


	for (int i = 0; i < esferas.GetNumero(); i++)
	{
		for (int j = 0; j < disparos.GetNumero(); j++)
		{
			if (Interaccion::colision(*disparos[j], *esferas[i]))
			{
				Esfera* e = esferas[i]->dividir();
				if (e == 0)
					esferas.Eliminar(esferas[i]);
				else
					esferas.agregar(e);

				disparos.Eliminar(disparos[j]);

				//ETSIDI::play("sonidos/impacto.wav");
				//break;
			}
		}
	}

}

void Mundo::TeclaEspecial(unsigned char key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		hombre.SetVel(-5.0f, 0.0f);
		break;
	case GLUT_KEY_RIGHT:
		hombre.SetVel(5.0f, 0.0f);
		break;
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
		Disparo* aux = new Disparo(hombre.GetXPos()+0.5, hombre.GetYPos()+0.5);
		aux->SetOrigen(hombre.GetXPos()+0.5, 0);
		disparos.agregar(aux);

	}
}

int Mundo::GetNumEsferas()
{
	return esferas.GetNumero();
}
bool Mundo::GetImpacto()
{	
	if (impacto == true)
		return true;
	else
		return false;
}

/*
bool Mundo::CargarNivel()
{
	nivel++;
	hombre.SetPos(0, 0);
	esferas.destruirContenido();
	disparos.DestruirContenido();

	if (nivel == 1)
	{
		plataforma.setPos(-5.0f, 9.0f, 5.0f, 9.0f);
		Esfera* e1 = new Esfera(1.5f, 2, 4, 5, 15);
		e1->SetColor(0, 0, 255);
		esferas.agregar(e1); //esfera
	}
	if (nivel == 2)
	{
		plataforma.setPos(-3.0f, 6.0f, 3.0f, 6.0f);
		plataforma.setColor(255, 0, 0);
		EsferaPulsante* e3 = new EsferaPulsante;
		e3->SetPos(0, 12);
		e3->SetVel(5, 3);
		esferas.agregar(e3);
	}
	if (nivel == 3)
	{
		plataforma.setPos(-10.0f, 12.0f, 4.0f, 10.0f);
		plataforma.setColor(255, 0, 255);
		for (int i = 0; i < 6; i++)
		{
			Esfera* aux = new Esfera(1.5, -5 + i, 13, i, 5);
			aux->SetColor(i * 40, 0, 255 - i * 40);
			esferas.agregar(aux);
		}
	}
	if (nivel <= 3)
		return true;

	if (nivel > 3)
		return false;


}*/








