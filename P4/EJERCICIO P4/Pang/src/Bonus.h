#pragma once
#include "Vector2D.h"

class Bonus
{
private:
	Vector2D posicion, velocidad, aceleracion;
	float size;
public:
	Bonus();
	virtual ~Bonus();
	void SetAtributos(float _xpos, float _ypos, float _xvel, float _yvel, float _acel, float _yacel, float _size);
	float GetXPos();
	float GetYPos();
	Vector2D GetPos();
	float GetXVel();
	float GetYVel();
	Vector2D GetVel();
	float GetXAcel();
	float GetYAcel();
	Vector2D GetAcel();
	float GetSize();
	void Dibuja();
	void Mueve(float t);
};
