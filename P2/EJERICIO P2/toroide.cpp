#include "toroide.h"
#include "glut.h"

void toroide::mueve()
{
	radioExt += 0.1;
	if (radioExt > 6)
		radioExt = 4;
}

void toroide::Drawtoroide()
{
	glTranslatef(7, -3, 0);
	glColor3ub(0, 0, 255);
	glutWireTorus(radioInt, radioExt, sides, rings);
}