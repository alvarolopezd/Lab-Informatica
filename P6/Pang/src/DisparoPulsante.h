#pragma once

#include "Disparo.h"

class DisparoPulsante :public Disparo
{
private:
	float radio_max;
	float radio_min;
	float pulso;
	friend class Interaccion;
public:
	DisparoPulsante();
	virtual ~DisparoPulsante();
	void Mueve(float t);
	void Dibuja();
	void SetPos(float _x, float _y);
	void SetVel(float _x, float _y);
};
