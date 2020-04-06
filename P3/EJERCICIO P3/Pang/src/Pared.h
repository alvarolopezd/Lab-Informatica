#pragma once

#include "Vector2D.h"
#include "glut.h"

class Pared
{
private:
	Vector2D p1, p2, p3, p4;
	unsigned char rojo, verde, azul;
	float alturamin,alturamax;
public:
	Pared();
	virtual ~Pared();
	void SetAtributos(float _xp1, float _yp1, float _xp2, float _yp2, float _xp3, float _yp3, float _xp4, float _yp4, float _alturamin, float _alturamax);
	void SetColor(unsigned char _rojo, unsigned char _verde, unsigned char _azul);
	float GetXP1();
	float GetYP1();
	float GetXP2();
	float GetYP2();
	float GetXP3();
	float GetYP3();
	float GetXP4();
	float GetYP4();
	float GetAlturaMin();
	float GetAlturaMax();
	unsigned char GetRojo();
	unsigned char GetVerde();
	unsigned char GetAzul();
	void Dibuja();
};




