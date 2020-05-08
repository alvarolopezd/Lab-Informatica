#pragma once
#include "Vector2D.h"
#include "glut.h"

class Esfera
{
protected:
	Vector2D posicion, velocidad, aceleracion;
	float radius, slices, stacks;
	unsigned char rojo, verde, azul;
	friend class Interaccion;
public:
	Esfera();
	Esfera(float _radius, float _xpos=0.0f, float _ypos=0.0f, float _xvel=0.0f, float _yvel=0.0f);
	virtual ~Esfera();
	void SetAtributos(float _xpos, float _ypos, float _xvel, float _yvel, float _acel, float _yacel, float _radius, float _slices, float _stacks);
	void SetColor(unsigned char _rojo, unsigned char _verde, unsigned char _azul);
	void SetPos(float _xpos, float _ypos);
	void SetVel(float _xvel, float _yvel);
	void SetAcel(float _xacel, float _yacel);
	void SetRadius(float _radius);
	void SetVel(Vector2D v);
	void SetPos(Vector2D p);
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


