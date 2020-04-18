#include "Esfera.h"

Esfera::Esfera()
{
	posicion.SetCoordenadas(0, 0);
	velocidad.SetCoordenadas(0, 0);
	aceleracion.SetCoordenadas(0, 0);
	radius = 0;
	slices = 0;
	stacks = 0;
	rojo = 0;
	verde = 0;
	azul = 0;

}
Esfera::~Esfera()
{

}


void Esfera::SetAtributos(float _xpos, float _ypos, float _xvel, float _yvel, float _xacel, float _yacel, float _radius, float _slices, float _stacks)
{	
	posicion.SetCoordenadas(_xpos, _ypos);
	velocidad.SetCoordenadas(_xvel, _yvel);
	aceleracion.SetCoordenadas(_xacel, _yacel);
	radius = _radius;
	slices = _slices;
	stacks = _stacks;
}

void Esfera::SetColor(unsigned char _rojo, unsigned char _verde, unsigned char _azul)
{
	rojo = _rojo;
	verde = _verde;
	azul = _azul;
}

void Esfera::SetVel(float _xvel, float _yvel)
{
	velocidad.SetCoordenadas(_xvel, _yvel);
}



float Esfera::GetXPos()
{
	return posicion.GetX();
}
float Esfera::GetYPos()
{
	return posicion.GetY();
}
Vector2D Esfera::GetPos()
{
	Vector2D res;
	res.SetCoordenadas(GetXPos(), GetYPos());
	return res;
}


float Esfera::GetXVel()
{
	return velocidad.GetX();
}
float Esfera::GetYVel()
{
	return velocidad.GetY();
}
Vector2D Esfera::GetVel()
{
	Vector2D res;
	res.SetCoordenadas(GetXVel(), GetYVel());
	return res;
}


float Esfera::GetXAcel()
{
	return aceleracion.GetX();
}
float Esfera::GetYAcel()
{
	return aceleracion.GetY();
}
Vector2D Esfera::GetAcel()
{
	Vector2D res;
	res.SetCoordenadas(GetXAcel(), GetYAcel());
	return res;
}



float Esfera::GetRadius()
{
	return radius;
}
float Esfera::GetSlices()
{
	return slices;
}
float Esfera::GetStacks()
{
	return stacks;
}
unsigned char Esfera::GetRojo()
{
	return rojo;
}
unsigned char Esfera::GetVerde()
{
	return verde;
}
unsigned char Esfera::GetAzul()
{
	return azul;
}

void Esfera::Dibuja()
{
	glColor3ub(rojo, verde, azul);
	glTranslatef(posicion.GetX(), posicion.GetY(), 0);
	glutSolidSphere(radius, slices, stacks);
	glTranslatef(-posicion.GetX(), -posicion.GetY(), 0);
}

void Esfera::Mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
}


/*if (key == '+')
		radius = radius + 0.1;
	if (key == '-')
		radius = radius - 0.1;*/