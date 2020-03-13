#include "glut.h"

class mundo
{
private:
	float x = 0, y = 10, z = 30;
public:
	void aumentaX();
	void disminuyeX();
	void aumentaZ();
	void disminuyeZ();
	void LookAt();
};

