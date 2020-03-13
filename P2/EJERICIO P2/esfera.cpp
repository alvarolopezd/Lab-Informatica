#include "esfera.h"
#include "glut.h"

void esfera::SetColor(int _colorX, int _colorY, int _colorZ)
{
	colorX = _colorX;
	colorY = _colorY;
	colorZ = _colorZ;
}

void esfera::SetRadio(float _radius)
{
	radius = _radius;
}

void esfera::SetPos(float _posX, float _posY, float _posZ)
{
	posX = _posX;
	posY = _posY;
	posZ = _posZ;
}

void esfera::aumenta()
{
	radius += 0.25;
}

void esfera::disminuye()
{
	radius -= 0.25;
}

void esfera::Drawesfera()
{
	glColor3ub(colorX, colorY, colorZ);

	glTranslatef(posX, posY, posZ);
	glutWireSphere(radius, slices, stacks);
}