#pragma once
#include "Vector2D.h"

class ObjetoMovil
{
protected:
	Vector2D posicion, velocidad, aceleracion;
	Vector2D ruido;
public:
	virtual void Mueve(float t);
};
