#pragma once

class Esfera
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
	void SetColor(int _colorX, int _colorY, int _colorZ);
	void SetRadio(float _radius);
	void SetPos(float _posX, float _posY, float _posZ);
	void aumenta();
	void disminuye();
	void Drawesfera();
};

