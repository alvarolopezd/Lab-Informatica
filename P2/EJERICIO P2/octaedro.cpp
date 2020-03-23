#include "octaedro.h"
#include "glut.h"

void Octaedro::SetPos(float _posX, float _posY, float _posZ)
{
	posX = _posX;
	posY = _posY;
	posZ = _posZ;
}

void Octaedro::arriba()
{
	posY += 0.5;
}

void Octaedro::abajo()
{
	posY -= 0.5;
}

void Octaedro::derecha()
{
	posX += 0.5;
}

void Octaedro::izquierda()
{
	posX -= 0.5;
}

void Octaedro::Drawoctaedro()
{
	glColor3ub(255, 255, 0);  // AMARILLO
	glTranslatef(posX, posY, posZ);    // POSICION
	glutSolidOctahedron();
}