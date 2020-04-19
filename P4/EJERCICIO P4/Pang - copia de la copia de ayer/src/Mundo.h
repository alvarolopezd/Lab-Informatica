#pragma once
#include "Esfera.h"
#include "Caja.h"
#include "Hombre.h"
#include "Disparo.h"
#include "Bonus.h"
#include "Interaccion.h"

class Mundo
{
private:
	float x_ojo;
	float y_ojo;
	float z_ojo;
	Esfera esfera;
	Caja caja;
	Pared plataforma;
	Hombre hombre;
	Disparo disparo;
	Bonus bonus;
	friend class Interaccion;
public:
	void Inicializa();
	void Dibuja();
	void RotarOjo();
	void Mueve(int value);
	void Tecla(unsigned char key);
};