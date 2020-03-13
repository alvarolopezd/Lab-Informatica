#include "mundo.h"
#include "glut.h"

void mundo::aumentaX()
{
	x += 2;
}

void mundo::disminuyeX()
{
	x -= 2;
}

void mundo::aumentaZ()
{
	z += 2;
}

void mundo::disminuyeZ()
{
	z -= 2;
}

void mundo::LookAt()
{
	gluLookAt(x, y, z,  // posicion del ojo
		0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 
}