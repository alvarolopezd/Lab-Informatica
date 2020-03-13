#include "octaedro.h"
#include "glut.h"

void octaedro::SetPos(float _posX, float _posY, float _posZ)
{
	posX = _posX;
	posY = _posY;
	posZ = _posZ;
}

void octaedro::arriba()
{
	posY += 0.5;
}

void octaedro::abajo()
{
	posY -= 0.5;
}

void octaedro::derecha()
{
	posX += 0.5;
}

void octaedro::izquierda()
{
	posX -= 0.5;
}

void octaedro::Drawoctaedro()
{
	glColor3ub(255, 255, 0);  // AMARILLO
	glTranslatef(posX, posY, posZ);    // POSICION
	glutSolidOctahedron();
}