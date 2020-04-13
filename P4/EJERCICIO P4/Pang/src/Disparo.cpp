#include "Disparo.h"
#include "glut.h"

Disparo::Disparo()
{
	posicion.SetCoordenadas(0, 0);
	velocidad.SetCoordenadas(0, 0);
	aceleracion.SetCoordenadas(0, 0);
	radius = 0;
	rojo = 0;
	verde = 0;
	azul = 0;

}
Disparo::~Disparo()
{

}


void Disparo::SetAtributos(float _xpos, float _ypos, float _xvel, float _yvel, float _xacel, float _yacel, float _radius, float _slices, float _stacks)
{
	posicion.SetCoordenadas(_xpos, _ypos);
	velocidad.SetCoordenadas(_xvel, _yvel);
	aceleracion.SetCoordenadas(_xacel, _yacel);
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



float Disparo::GetXPos()
{
	return posicion.GetX();
}
float Disparo::GetYPos()
{
	return posicion.GetY();
}
float Disparo::GetXVel()
{
	return velocidad.GetX();
}
float Disparo::GetYVel()
{
	return velocidad.GetY();
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

void Disparo::Dibuja()
{
	glColor3f(GetRojo(), GetVerde(), GetAzul());
	glPushMatrix();
	glTranslatef(posicion.GetX(), posicion.GetY(), 0);
	glutSolidSphere(GetRadius(), GetSlices(), GetStacks());
	glTranslatef(-posicion.GetX(), -posicion.GetY(), 0);
	glDisable(GL_LIGHTING);
	glBegin(GL_LINES);
	glVertex3d(-2, 0, 0);
	glVertex3d(posicion.GetX(), posicion.GetY(), 0);
	glEnd();
	glEnable(GL_LIGHTING);
	glPopMatrix();

}

void Disparo::Mueve(int value)
{
	int i;
	for(i=0;i<=posicion.GetY();i++)
		posicion.SetCoordenadas(posicion.GetX(), posicion.GetY()+0.25);

}