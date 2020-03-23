#include "esfera.h"
#include "glut.h"

void Esfera::SetColor(int _colorX, int _colorY, int _colorZ)
{
	colorX = _colorX;
	colorY = _colorY;
	colorZ = _colorZ;
}

void Esfera::SetRadio(float _radius)
{
	radius = _radius;
}

void Esfera::SetPos(float _posX, float _posY, float _posZ)
{
	posX = _posX;
	posY = _posY;
	posZ = _posZ;
}

void Esfera::aumenta()
{
	radius += 0.25;
}

void Esfera::disminuye()
{
	radius -= 0.25;
}

void Esfera::Drawesfera()
{
	glColor3ub(colorX, colorY, colorZ);

	glTranslatef(posX, posY, posZ);
	glutWireSphere(radius, slices, stacks);
}