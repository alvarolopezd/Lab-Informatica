#include "Interaccion.h"
#include <cmath>


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
		e.GetPos()= e.GetPos() - dir * dif;
		return true;
	}
	return false;
}

/*bool Interaccion::rebote(Esfera& e, Caja c)
{
	Vector2D dir;
	float dif = p.distancia(e.GetPos(), &dir) - e.GetRadius();
	if (dif <= 0.0f)
	{
		Vector2D v_inicial = e.GetVel();
		e.GetVel() = v_inicial - dir * 2.0 * (v_inicial * dir);
		e.GetPos() = e.GetPos() - dir * dif;
		return true;
	}
	return false;

}*/


bool Interaccion::rebote(Esfera& esfera1, Esfera& esfera2)
{
	//Vector que une los centros
	Vector2D dif = esfera2.GetPos() - esfera1.GetPos();
	float d = dif.modulo();
	float dentro = d - (esfera1.GetRadius() + esfera2.GetRadius());

	if (dentro < 0.0f)//si hay colision
	{
		//El modulo y argumento de la velocidad de la pelota1
		float v1 = esfera1.GetVel().modulo();
		float ang1 = esfera1.GetVel().argumento();

		//El modulo y argumento de la velocidad de la pelota2
		float v2 = esfera2.GetVel().modulo();
		float ang2 = esfera2.GetVel().argumento();

		//el argumento del vector que une los centros
		float angd = dif.argumento();

		//Separamos las esferas, lo que se han incrustado
		//la mitad cada una
		Vector2D desp;
		desp.SetCoordenadas(dentro / 2 * cos(angd), dentro / 2 * sin(angd));
		esfera1.posicion = esfera1.posicion + desp;
		esfera2.posicion = esfera2.posicion - desp;

		angd = angd - 3.14159f / 2;//la normal al choque

		//El angulo de las velocidades en el sistema relativo antes del choque
		float th1 = ang1 - angd;
		float th2 = ang2 - angd;

		//Las componentes de las velocidades en el sistema relativo ANTES del choque
		float u1x = v1 * cos(th1);
		float u1y = v1 * sin(th1);
		float u2x = v2 * cos(th2);
		float u2y = v2 * sin(th2);

		//Las componentes de las velocidades en el sistema relativo DESPUES del choque
		//la componente en X del sistema relativo no cambia
		float v1x = u1x;
		float v2x = u2x;

		//en el eje Y, rebote elastico
		float m1 = esfera1.GetRadius();
		float m2 = esfera2.GetRadius();
		float py = m1 * u1y + m2 * u2y;//Cantidad de movimiento inicial ejey
		float ey = m1 * u1y * u1y + m2 * u2y * u2y;//Energia cinetica inicial ejey

		//los coeficientes y discriminante de la ecuacion cuadrada
		float a = m2 * m2 + m1 * m2;
		float b = -2 * py * m2;
		float c = py * py - m1 * ey;
		float disc = b * b - 4 * a * c;
		if (disc < 0)disc = 0;

		//las nuevas velocidades segun el eje Y relativo
		float v2y = (-b + sqrt(disc)) / (2 * a);
		float v1y = (py - m2 * v2y) / m1;

		//Modulo y argumento de las velocidades en coordenadas absolutas
		float modv1, modv2, fi1, fi2;
		modv1 = sqrt(v1x * v1x + v1y * v1y);
		modv2 = sqrt(v2x * v2x + v2y * v2y);
		fi1 = angd + atan2(v1y, v1x);
		fi2 = angd + atan2(v2y, v2x);

		//Velocidades en absolutas despues del choque en componentes
		esfera1.SetVel(modv1 * cos(fi1), modv1 * sin(fi1));
		esfera2.SetVel(modv2 * cos(fi2), modv2 * sin(fi2));
		
		//esfera1.velocidad.GetX() = modv1 * cos(fi1);
		//esfera1.velocidad.GetY() = modv1 * sin(fi1);
		//esfera2.velocidad.GetX() = modv2 * cos(fi2);
		//esfera2.velocidad.GetY() = modv2 * sin(fi2);
	}
	return false;
}
