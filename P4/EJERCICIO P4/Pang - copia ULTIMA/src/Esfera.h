#pragma once
#include "Vector2D.h"
#include "glut.h"

class Esfera
{
private:
	Vector2D posicion, velocidad, aceleracion;
	float radius, slices, stacks;
	unsigned char rojo, verde, azul;
	friend class Interaccion;
public:
	Esfera();
	virtual ~Esfera();
	void SetAtributos(float _xpos, float _ypos, float _xvel, float _yvel, float _acel, float _yacel, float _radius, float _slices, float _stacks);
	void SetColor(unsigned char _rojo, unsigned char _verde, unsigned char _azul);
	void SetVel(float _xvel, float _yvel);
	float GetXPos();
	float GetYPos();
	Vector2D GetPos();
	float GetXVel();
	float GetYVel();
	Vector2D GetVel();
	float GetXAcel();
	float GetYAcel();
	Vector2D GetAcel();
	float GetRadius();
	float GetSlices();
	float GetStacks();
	unsigned char GetRojo();
	unsigned char GetVerde();
	unsigned char GetAzul();
	void Dibuja();
	void Mueve(float t);
};


