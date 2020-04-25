#pragma once

#include "Vector2D.h"
#include "glut.h"

class Pared
{
private:
	Vector2D limite1, limite2;
	unsigned char rojo, verde, azul;

	friend class Interaccion;
public:
	Pared();
	virtual ~Pared();
	void SetAtributos(float _xlim1, float _ylim1, float _xlim2, float _ylim2);
	void SetColor(unsigned char _rojo, unsigned char _verde, unsigned char _azul);
	//float GetXLim1();
	//float GetYLim1();
	//float GetXLim2();
	//float GetYLim2();
	Vector2D GetLimite1();
	Vector2D GetLimite2();
	
	unsigned char GetRojo();
	unsigned char GetVerde();
	unsigned char GetAzul();
	void Dibuja();


	float distancia(Vector2D punto, Vector2D* direccion = 0);
};




