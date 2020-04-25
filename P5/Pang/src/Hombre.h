#pragma once
#include "Vector2D.h"
#include "glut.h"

class Hombre
{
private:
	Vector2D posicion, velocidad, aceleracion;
	float size;
	unsigned char rojo, verde, azul;
	friend class Interaccion;
public:
	Hombre();
	virtual ~Hombre();
	void SetAtributos(float _xpos, float _ypos, float _xvel, float _yvel, float _acel, float _yacel, float _size);
	void SetVel(float _xvel, float _yvel);
	void SetColor(unsigned char _rojo, unsigned char _verde, unsigned char _azul);
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
	unsigned char GetRojo();
	unsigned char GetVerde();
	unsigned char GetAzul();
	void Dibuja();
	void Mueve(float t);
};


