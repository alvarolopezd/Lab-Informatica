#pragma once

class toroide
{
private:
	float radioInt = 2;
	float radioExt = 4;
	float sides = 50;
	float rings = 100;
public:
	void mueve()
	{
		radioExt += 0.1;
		if (radioExt > 6)
			radioExt = 4;
	}

	void Drawtoroide()
	{
		glTranslatef(7, -3, 0);
		glColor3ub(0, 0, 255);
		glutWireTorus(radioInt, radioExt, sides, rings);
	}
};
toroide t;
