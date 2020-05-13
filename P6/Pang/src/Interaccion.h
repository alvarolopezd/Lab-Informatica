#pragma once

#include "Hombre.h"
#include "Caja.h"
#include "Esfera.h"
#include "Pared.h"
#include "Disparo.h"
#include "DisparoPulsante.h"


class Interaccion
{
private:
public:
	Interaccion();
	virtual ~Interaccion();
	static void rebote(Hombre& h, Caja c);
	static bool rebote(Esfera& e, Pared p);
	static void rebote(Esfera& e, Caja c);
	static bool rebote(Esfera& esfera1, Esfera& esfera2);

	static bool rebote(Disparo& d, Pared p);
	static void rebote(Disparo& d, Caja c);
	static bool rebote(DisparoPulsante& d, Pared p);
	static void rebote(DisparoPulsante& d, Caja c);
	static bool colision(Disparo d, Esfera e);

	static bool colision(Esfera e, Hombre h);

};

