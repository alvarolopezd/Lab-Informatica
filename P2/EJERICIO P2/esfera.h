#include "glut.h"

class esfera
{
private:
	float radius;
	float slices=10;
	float stacks=10;
	float posX;
	float posY;
	float posZ;
	int colorX;
	int colorY;
	int colorZ;
public:
	void SetColor(int _colorX, int _colorY, int _colorZ)
	{
		colorX = _colorX;
		colorY = _colorY;
		colorZ = _colorZ;
	}
	void SetRadio(float _radius)
	{
		radius = _radius;
	}
	void SetPos(float _posX, float _posY, float _posZ)
	{
		posX = _posX;
		posY = _posY;
		posZ = _posZ;
	}
	void aumenta()
	{
		radius += 0.25;
	}
	void disminuye()
	{
		radius -= 0.25;
	}

	void Drawesfera()
	{
		glColor3ub(colorX, colorY, colorZ);

		glTranslatef(posX, posY, posZ);
		glutWireSphere(radius, slices, stacks);
	}

};
esfera e;
