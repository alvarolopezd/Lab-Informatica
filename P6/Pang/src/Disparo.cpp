#include "Disparo.h"
#include "glut.h"

Disparo::Disparo()
{
	posicion.SetCoordenadas(0, 0);
	velocidad.SetCoordenadas(0, 0);
	aceleracion.SetCoordenadas(0, 0);
	origen.SetCoordenadas(0, 0);
	radius = 0;
	slices = 0;
	stacks = 0;
	rojo = 0;
	verde = 0;
	azul = 0;
	origen.SetCoordenadas(0.0f, 0.0f);

}


Disparo::Disparo(float _xpos, float _ypos, float _xvel, float _yvel, float _xacel, float _yacel, float _radius)
{
	posicion.SetCoordenadas(_xpos, _ypos);
	origen.SetCoordenadas(_xpos, 0);
	velocidad.SetCoordenadas(_xvel, _yvel);
	aceleracion.SetCoordenadas(_xacel, _yacel);
	radius = _radius;
	slices = stacks = 50;
	rojo =verde=azul= 255;

}
Disparo::~Disparo()
{

}


void Disparo::SetAtributos(float _xpos, float _ypos, float _xvel, float _yvel, float _xacel, float _yacel, float _radius, float _slices, float _stacks)
{
	posicion.SetCoordenadas(_xpos, _ypos);
	velocidad.SetCoordenadas(_xvel, _yvel);
	aceleracion.SetCoordenadas(_xacel, _yacel);
	origen.SetCoordenadas(_xpos, _ypos);
	radius = _radius;
	slices = _slices;
	stacks = _stacks;
}

void Disparo::SetColor(unsigned char _rojo, unsigned char _verde, unsigned char _azul)
{
	rojo = _rojo;
	verde = _verde;
	azul = _azul;
}

void Disparo::SetPos(float _x, float _y)
{
	posicion.SetCoordenadas(_x, _y);
}
void Disparo::SetOrigen(float _x, float _y)
{
	origen.SetCoordenadas(_x, _y);

}
void Disparo::SetPos(Vector2D p)
{
	posicion = p;
}

void Disparo::SetVel(float _x, float _y)
{
	velocidad.SetCoordenadas(_x, _y);
}
void Disparo::SetVel(Vector2D p)
{
	velocidad = p;
}

void Disparo::SetAcel(float _x, float _y)
{
	aceleracion.SetCoordenadas(_x, _y);
}
void Disparo::SetAcel(Vector2D p)
{
	aceleracion = p;
}



float Disparo::GetXPos()
{
	return posicion.GetX();
}
float Disparo::GetYPos()
{
	return posicion.GetY();
}
Vector2D Disparo::GetPos()
{
	return posicion;
}

float Disparo::GetXPosOrigen()
{
	return origen.GetX();
}
float Disparo::GetYPosOrigen()
{
	return origen.GetY();
}
Vector2D Disparo::GetPosOrigen()
{
	return origen;
}

float Disparo::GetXVel()
{
	return velocidad.GetX();
}
float Disparo::GetYVel()
{
	return velocidad.GetY();
}
Vector2D Disparo::GetVel()
{
	return velocidad;
}

float Disparo::GetXAcel()
{
	return aceleracion.GetX();
}
float Disparo::GetYAcel()
{
	return aceleracion.GetY();
}



float Disparo::GetRadius()
{
	return radius;
}
float Disparo::GetSlices()
{
	return slices;
}
float Disparo::GetStacks()
{
	return stacks;
}

unsigned char Disparo::GetRojo()
{
	return rojo;
}
unsigned char Disparo::GetVerde()
{
	return verde;
}
unsigned char Disparo::GetAzul()
{
	return azul;
}

////////
/*
void Disparo::Dibuja()
{
	glColor3f(GetRojo(), GetVerde(), GetAzul());
	glPushMatrix();
	glTranslatef(posicion.GetX(), posicion.GetY(), 0);
	glutSolidSphere(GetRadius(), GetSlices(), GetStacks());
	glTranslatef(-posicion.GetX(), -posicion.GetY(), 0);
	glDisable(GL_LIGHTING);
	glBegin(GL_LINES);
	glVertex3d(0, 0, 0);
	glVertex3d(posicion.GetX(), posicion.GetY(), 0);
	glEnd();
	glEnable(GL_LIGHTING);
	glPopMatrix();

}*/


void Disparo::Dibuja()
{
	//origen.SetCoordenadas(posicion.GetX(), posicion.GetY());
	glColor3f(GetRojo(), GetVerde(), GetAzul());
	glPushMatrix();
	glTranslatef(posicion.GetX(), posicion.GetY(), 0);
	glutSolidSphere(radius, 50, 50);
	glPopMatrix();
	glBegin(GL_LINES);
	glVertex3f(origen.GetX(), origen.GetY(), 0.0f);
	glVertex3f(posicion.GetX(), posicion.GetY(), 0.0f);
	glEnd();
}



void Disparo::Mueve(float t)
{
	float xpos, ypos, xvel, yvel, xacel, yacel;
	xpos = posicion.GetX();
	ypos = posicion.GetY();
	xvel = velocidad.GetX();
	yvel = velocidad.GetY();
	xacel = aceleracion.GetX();
	yacel = aceleracion.GetY();

	xpos = xpos + xvel * t + 0.5f * xacel * t * t;
	ypos = ypos + yvel * t + 0.5f * yacel * t * t;
	xvel = xvel + xacel * t;
	yvel = yvel + yacel * t;

	posicion.SetCoordenadas(xpos, ypos);
	velocidad.SetCoordenadas(xvel, yvel);
	aceleracion.SetCoordenadas(xacel, yacel);

}


////////////
/*void Disparo::Mueve(int value)
{
	int i;
	for (i = 0; i <= posicion.GetY(); i++)
	{
		posicion.SetCoordenadas(posicion.GetX(), posicion.GetY()+0.02);
		if (i == 100)
			break;
	}

}*/