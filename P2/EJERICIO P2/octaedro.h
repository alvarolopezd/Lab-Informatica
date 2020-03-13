#include "glut.h"

class octaedro
{
private:
	float posX;
	float posY;
	float posZ;
public:
	void SetPos(float _posX, float _posY, float _posZ);
	void arriba();
	void abajo();
	void derecha();
	void izquierda();
	void Drawoctaedro();
};

