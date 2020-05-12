/*
#include "CoordinadorPang.h"
#include "ETSIDI.h"
#include <stdlib.h>
#include <stdio.h> 

#include "glut.h"


CoordinadorPang::CoordinadorPang()
{
	estado = INICIO;
	mundo.Inicializa();
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
	if (estado == INICIO)
	{
		if (key == 'e')
		{
			mundo.Inicializa();
			estado = JUEGO;
		}
		
	}
	else if (estado == JUEGO)
		mundo.Tecla(key);

}
void CoordinadorPang::Mueve()
{
	if (estado == JUEGO)
		mundo.Mueve();
}
void CoordinadorPang::Dibuja()
{
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
		ETSIDI::printxy("Hernando & Rodriguez-Losada", 2, 1);
	}
	else if (estado == JUEGO)
		mundo.Dibuja();
}*/

