#pragma once
//#include "Vector2D.h"
#include "ObjetoMovil.h"

class Disparo:public ObjetoMovil
{
protected:
	//Vector2D posicion, velocidad, aceleracion, origen;
	Vector2D origen;
	unsigned char rojo, verde, azul;
	float radius, slices, stacks;
	friend class Hombre;
public:
	Disparo();
	Disparo(float _xpos, float _ypos, float _xvel = 0.0f, float _yvel = 0.0f, float _xacel=0.0f, float _yacel=9.81, float _radius=0.1f);
	virtual ~Disparo();
	void SetAtributos(float _xpos, float _ypos, float _xvel, float _yvel, float _acel, float _yacel, float _radius, float _slices, float _stacks);
	void SetColor(unsigned char _rojo, unsigned char _verde, unsigned char _azul);
	void SetPos(float _x, float _y);
	void SetOrigen(float _x, float _y);
	void SetVel(float _x, float _y);
	void SetAcel(float _x, float _y);
	void SetVel(Vector2D p);
	void SetPos(Vector2D p);
	void SetAcel(Vector2D p);
	float GetXPos();
	float GetYPos();
	Vector2D GetPos();
	float GetXPosOrigen();
	float GetYPosOrigen();
	Vector2D GetPosOrigen();
	float GetXVel();
	float GetYVel();
	Vector2D GetVel();
	float GetXAcel();
	float GetYAcel();
	float GetRadius();
	float GetSlices();
	float GetStacks();
	unsigned char GetRojo();
	unsigned char GetVerde();
	unsigned char GetAzul();
	void Dibuja();
	void Mueve(float t);
};
