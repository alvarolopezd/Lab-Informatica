#include "Hombre.h"

Hombre::Hombre()
{
	posicion.SetCoordenadas(0, 0);
	velocidad.SetCoordenadas(0, 0);
	aceleracion.SetCoordenadas(0, 0);
	size = 0;
	rojo = 0;
	verde = 0;
	azul = 0;

}
Hombre::~Hombre()
{

}


void Hombre::SetAtributos(float _xpos, float _ypos, float _xvel, float _yvel, float _xacel, float _yacel, float _size)
{
	posicion.SetCoordenadas(_xpos, _ypos);
	velocidad.SetCoordenadas(_xvel, _yvel);
	aceleracion.SetCoordenadas(_xacel, _yacel);
	size = _size;
}

void Hombre::SetColor(unsigned char _rojo, unsigned char _verde, unsigned char _azul)
{
	rojo = _rojo;
	verde = _verde;
	azul = _azul;
}



float Hombre::GetXPos()
{
	return posicion.GetX();
}
float Hombre::GetYPos()
{
	return posicion.GetY();
}
Vector2D Hombre::GetPos()
{
	Vector2D res;
	res.SetCoordenadas(GetXPos(), GetYPos());
	return res;
}

float Hombre::GetXVel()
{
	return velocidad.GetX();
}
float Hombre::GetYVel()
{
	return velocidad.GetY();
}
Vector2D Hombre::GetVel()
{
	Vector2D res;
	res.SetCoordenadas(GetXPos(), GetYPos());
	return res;
}

float Hombre::GetXAcel()
{
	return aceleracion.GetX();
}
float Hombre::GetYAcel()
{
	return aceleracion.GetY();
}
Vector2D Hombre::GetAcel()
{
	Vector2D res;
	res.SetCoordenadas(GetXPos(), GetYPos());
	return res;
}



float Hombre::GetSize()
{
	return size;
}


unsigned char Hombre::GetRojo()
{
	return rojo;
}
unsigned char Hombre::GetVerde()
{
	return verde;
}
unsigned char Hombre::GetAzul()
{
	return azul;
}

void Hombre::Dibuja()
{
	glColor3ub(rojo, verde, azul);
	glTranslatef(posicion.GetX(), posicion.GetY(), 0);
	glutSolidCube(size);
	glTranslatef(-posicion.GetX(), -posicion.GetY(), 0);
}

void Hombre::Mueve(unsigned char key, float t)
{
	if (key == 'd')
	{
		velocidad.SetCoordenadas(5.0f, 0.0f);
		posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
		
	}
	if (key == 'a')
	{
		velocidad.SetCoordenadas(-5.0f, 0.0f);
		posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	}
		


}


/*	if (key == 'd')
	{
		posicion.SetCoordenadas(posicion.GetX() + 0.25, posicion.GetY());
	}
	if (key == 'a')
	{
		posicion.SetCoordenadas(posicion.GetX() - 0.25, posicion.GetY());
	}*/