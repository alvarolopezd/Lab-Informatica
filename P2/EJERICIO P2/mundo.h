#pragma once
#include "esfera.h"
#include "toroide.h"
#include "octaedro.h"

class Mundo
{
private:
	float x, y, z;

	Esfera e;
	Toroide t;
	Octaedro o;
public:
	void InicioMundo(float _x, float _y, float _z);
	void PintarMundo();
	void AccionesMundo(unsigned char _key);
	void MuevePorTiempo();
	void LookAt();
};

