#pragma once
#include "Vector2D.h"
#include "glut.h"

class Hombre
{
private:
	Vector2D posicion, velocidad, aceleracion;
	float size;
	unsigned char rojo, verde, azul;
public:
	Hombre();
	virtual ~Hombre();
	void SetAtributos(float _xpos, float _ypos, float _xvel, float _yvel, float _acel, float _yacel, float _size);
	void SetColor(unsigned char _rojo, unsigned char _verde, unsigned char _azul);
	float GetXPos();
	float GetYPos();
	float GetXVel();
	float GetYVel();
	float GetXAcel();
	float GetYAcel();
	float GetSize();
	unsigned char GetRojo();
	unsigned char GetVerde();
	unsigned char GetAzul();
	void Dibuja();
	void Mueve(unsigned char key);
};


