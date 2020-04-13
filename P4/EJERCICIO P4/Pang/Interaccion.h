#pragma once

#include "Hombre.h"
#include "Caja.h"
#include "Esfera.h"
#include "Pared.h"


class Interaccion
{
private:
public:
	Interaccion();
	virtual ~Interaccion();
	static void rebote(Hombre& h, Caja c);
	static bool rebote(Esfera& e, Pared p);
};


