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
	if (h.GetXPos() < xmin)
		h.SetAtributos(xmin, h.GetYPos(), h.GetXVel(), h.GetYVel(), h.GetXAcel(), h.GetYAcel(), h.GetSize());

}

bool Interaccion::rebote(Esfera& e, Pared p)
{
	Vector2D dir;
	float dif = p.distancia(e.GetPos(), &dir) - e.GetRadius();
	if (dif <= 0.0f)
	{
		Vector2D v_inicial = e.GetVel();
		e.GetVel() = v_inicial - dir * 2.0 * (v_inicial * dir);
		e.GetPos = e.GetPos() - dir * dif;
		return true;
	}
	return false;
}

