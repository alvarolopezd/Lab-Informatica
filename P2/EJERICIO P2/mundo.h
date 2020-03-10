#pragma once

class mundo
{
private:
	float x = 0, y = 10, z = 30;
public:
	void aumentaX()
	{
		x += 2;
	}
	void disminuyeX()
	{
		x -= 2;
	}
	void aumentaZ()
	{
		z += 2;
	}
	void disminuyeZ()
	{
		z -= 2;
	}
	void LookAt()
	{
		gluLookAt(x, y, z,  // posicion del ojo
			0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 
	}
};
mundo camara;
