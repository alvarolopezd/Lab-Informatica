#pragma once

#include "Esfera.h"

class EsferaPulsante :public Esfera
{
private:
	float radio_max;
	float radio_min;
	float pulso;
public:
	EsferaPulsante();
	virtual ~EsferaPulsante();
	void mueve(float t);

};