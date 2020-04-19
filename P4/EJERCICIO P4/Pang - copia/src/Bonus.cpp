#include "Bonus.h"
#include <cstdlib>

#include "glut.h"


Bonus::Bonus()
{
	posicion.SetCoordenadas(0, 0);
	velocidad.SetCoordenadas(0, 0);
	aceleracion.SetCoordenadas(0, 0);
	size = 0;
}
Bonus::~Bonus()
{

}

void Bonus::SetAtributos(float _xpos, float _ypos, float _xvel, float _yvel, float _xacel, float _yacel, float _size)
{
	posicion.SetCoordenadas(_xpos, _ypos);
	velocidad.SetCoordenadas(_xvel, _yvel);
	aceleracion.SetCoordenadas(_xacel, _yacel);
	size = _size;

}


float Bonus::GetXPos()
{
	return posicion.GetX();
}
float Bonus::GetYPos()
{
	return posicion.GetY();
}
Vector2D Bonus::GetPos()
{
	Vector2D res;
	res.SetCoordenadas(GetXPos(), GetYPos());
	return res;
}

float Bonus::GetXVel()
{
	return velocidad.GetX();
}
float Bonus::GetYVel()
{
	return velocidad.GetY();
}
Vector2D Bonus::GetVel()
{
	Vector2D res;
	res.SetCoordenadas(GetXVel(), GetYVel());
	return res;
}

float Bonus::GetXAcel()
{
	return aceleracion.GetX();
}
float Bonus::GetYAcel()
{
	return aceleracion.GetY();
}
Vector2D Bonus::GetAcel()
{
	Vector2D res;
	res.SetCoordenadas(GetXAcel(), GetYAcel());
	return res;
}



float Bonus::GetSize()
{
	return size;
}


void Bonus::Dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.GetX(), posicion.GetY(), 0);
	glRotatef(30, 1, 1, 1);
	glColor3f(rand() / (float)RAND_MAX, rand() / (float)RAND_MAX,
		rand() / (float)RAND_MAX);
	glutSolidCube(GetSize());
	glPopMatrix();
}

void Bonus::Mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
}