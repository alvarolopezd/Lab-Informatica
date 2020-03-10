#pragma once

class octaedro
{
private:
	float posX;
	float posY;
	float posZ;
public:
	void SetPos(float _posX, float _posY, float _posZ)
	{
		posX = _posX;
		posY = _posY;
		posZ = _posZ;
	}
	void arriba()
	{
		posY += 0.5;
	}
	void abajo()
	{
		posY -= 0.5;
	}
	void derecha()
	{
		posX += 0.5;
	}
	void izquierda()
	{
		posX -= 0.5;
	}
	void Drawoctaedro()
	{
		glColor3ub(255, 255, 0);  // AMARILLO
		glTranslatef(posX, posY, posZ);    // POSICION
		glutSolidOctahedron();
	}
};
octaedro o;
