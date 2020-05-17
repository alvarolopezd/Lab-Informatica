
#include "ETSIDI.h"
#include "CoordinadorPang.h"

#include <stdlib.h>
#include <stdio.h> 

#include "glut.h"


CoordinadorPang::CoordinadorPang()
{
	estado = INICIO;
	//mundo.Inicializa();
}
CoordinadorPang::~CoordinadorPang()
{

}

void CoordinadorPang::teclaEspecial(unsigned char key)
{
	//mundo.TeclaEspecial(key)
}
void CoordinadorPang::Tecla(unsigned char key)
{
	// INICIO A JUEGO 
	if (estado == INICIO)
	{
		if (key == 'e' || key=='E')
		{
			mundo.Inicializa();
			estado = JUEGO;
		}
		if(key=='s') 
			exit(0);
	}
	//JUEGO 
	else if (estado == JUEGO)
		mundo.Tecla(key);
	// GAMEOVER A INICIO
	else if (estado == GAMEOVER)
	{
		if (key == 'c' || key=='C')
			estado = INICIO;
	}
	// FIN A INICIO
	else if (estado == FIN)
	{
		if (key == 'c' || key == 'C')
			estado = INICIO;
	}
	// JUEGO A PAUSA
	else if (estado == JUEGO)
	{
		if (key == 'p' || key == 'P')
			estado = PAUSA;
	}
	// PAUSA A JUEGO 
	else if (estado == PAUSA)
	{
		if (key == 'c' || key == 'C')
			estado = JUEGO;
	}
}
void CoordinadorPang::Mueve()
{
	// JUEGO
	if (estado == JUEGO)
	{
		mundo.Mueve();
		if (mundo.GetNumEsferas() == 0)
		{
			if(!mundo.CargarNivel())
				estado = FIN;
		}
		if (mundo.GetImpacto())
		{
			estado = GAMEOVER;
		}
	}
		
}
void CoordinadorPang::Dibuja()
{
	// INICIO
	if (estado == INICIO)
	{
		gluLookAt(0, 7.5, 20,  // posicion del ojo
			0.0, 7.5, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)  

		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Pang 1.1", -5, 8);
		
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -5, 7);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -5, 6);
		//ETSIDI::printxy("PULSE LA TECLA -A- PARA SALIR", -5, 6);
		ETSIDI::printxy("Alvaro Lopez", 2, 1);
	}
	
	// JUEGO 
	else if (estado == JUEGO)
		mundo.Dibuja();
	
	// GAMEOVER
	else if (estado == GAMEOVER)
	{
		mundo.Dibuja();
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("GAMEOVER: Has perdido", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 5);
	}
	
	// FIN 
	else if (estado == FIN)
	{
		mundo.Dibuja();
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("ENHORABUENA, ¡Has triunfado!", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 9);
	}
	
	// PAUSA 
	else if (estado == PAUSA)
	{
		mundo.Dibuja();
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("PAUSA", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 9);
		
	}
}

