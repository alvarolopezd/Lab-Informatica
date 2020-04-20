#pragma once
#include "Vector2D.h"

class Disparo
{
private:
	Vector2D posicion, velocidad, aceleracion;
	unsigned char rojo, verde, azul;
	float radius, slices, stacks;
public:
	Disparo();
	virtual ~Disparo();
	void SetAtributos(float _xpos, float _ypos, float _xvel, float _yvel, float _acel, float _yacel, float _radius, float _slices, float _stacks);
	void SetColor(unsigned char _rojo, unsigned char _verde, unsigned char _azul);
	float GetXPos();
	float GetYPos();
	float GetXVel();
	float GetYVel();
	float GetXAcel();
	float GetYAcel();
	float GetRadius();
	float GetSlices();
	float GetStacks();
	unsigned char GetRojo();
	unsigned char GetVerde();
	unsigned char GetAzul();
	void Dibuja();
	void Mueve(int t);
};
