#include "Interaccion.h"

Interaccion::Interaccion()
{

}

Interaccion:: ~Interaccion()
{


}


void Interaccion::rebote(Hombre& h, Caja c)
{
	float xmax = c.XMaxSuelo();
	float xmin = c.XMinSuelo();
	if (h.GetXPos() > xmax)
		h.SetAtributos(xmax, h.GetYPos(), h.GetXVel(), h.GetYVel(), h.GetXAcel(), h.GetYAcel(), h.GetSize());
	if(h.GetXPos()<xmin)
		h.SetAtributos(xmin, h.GetYPos(), h.GetXVel(), h.GetYVel(), h.GetXAcel(), h.GetYAcel(), h.GetSize());

}
