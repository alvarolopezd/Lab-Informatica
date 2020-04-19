#pragma once


#include "Hombre.h"
#include "Caja.h"


class Interaccion
{
private:
public:
	Interaccion();
	virtual ~Interaccion();
	static void rebote(Hombre& h, Caja c);

};


