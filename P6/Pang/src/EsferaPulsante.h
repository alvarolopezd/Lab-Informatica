#pragma once

#include "Esfera.h"

class EsferaPulsante :public Esfera
{
private:
	float radio_max;
	float radio_min;
	float pulso;
	friend class Interaccion;
public:
	EsferaPulsante();
	virtual ~EsferaPulsante();
	void Mueve(float t);

};