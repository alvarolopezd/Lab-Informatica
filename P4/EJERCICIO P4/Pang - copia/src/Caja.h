#pragma once
#include "Pared.h"

class Caja
{
private:
	Pared suelo, techo, pared_izq, pared_dcha;
	friend class Interaccion;
public:
	void Inicializa();
	void Dibuja();
	float XMaxSuelo();
	float XMinSuelo();
};