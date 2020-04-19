
#include "Pared.h"


Pared::Pared()
{
	limite1.SetCoordenadas(0, 0);
	limite2.SetCoordenadas(0, 0);
	rojo = 0;
	verde = 0;
	azul = 0;
}
Pared::~Pared()
{

}

void Pared::SetAtributos(float _xlim1, float _ylim1, float _xlim2, float _ylim2)
{
	limite1.SetCoordenadas(_xlim1, _ylim1);
	limite2.SetCoordenadas(_xlim2, _ylim2);
}

void Pared::SetColor(unsigned char _rojo, unsigned char _verde, unsigned char _azul)
{
	rojo = _rojo;
	verde = _verde;
	azul = _azul;
}
/*
float Pared::GetXLim1()
{
	return limite1.GetX();
}
float Pared::GetYLim1()
{
	return limite1.GetY();
}

float Pared::GetXLim2()
{
	return limite2.GetX();
}
float Pared::GetYLim2()
{
	return limite2.GetY();
}*/

Vector2D Pared::GetLimite1() {
	return limite1;
}

Vector2D Pared::GetLimite2() {
	return limite2;
}

unsigned char Pared::GetRojo()
{
	return rojo;
}
unsigned char Pared::GetVerde()
{
	return verde;
}
unsigned char Pared::GetAzul()
{
	return azul;
}


/// EN EL PLANO CONSIDERO LOS ATRIBUTOS X E Y DE VECTOR2D COMO EL PLANO DEL SUELO Y DEL TECHO

void Pared::Dibuja()
{

	glDisable(GL_LIGHTING);
	glColor3ub(rojo, verde, azul);
	glBegin(GL_POLYGON);
	glVertex3d(limite1.GetX(), limite1.GetY(), 10);
	glVertex3d(limite2.GetX(), limite2.GetY(), 10);
	glVertex3d(limite2.GetX(), limite2.GetY(), -10);
	glVertex3d(limite1.GetX(), limite1.GetY(), -10);
	glEnd();
	glEnable(GL_LIGHTING);

}


/*
float Pared::distancia(Vector2D punto, Vector2D* direccion)
{
	Vector2D u = (punto - limite1);
	Vector2D v = (limite2 - limite1).Unitario();
	float longitud = (limite2 - limite1).modulo();
	Vector2D dir;
	float valor = u*v;
	float distancia = 0;

	if (valor < 0)
		dir = u;
	else if (valor > longitud)
		dir = (punto - limite2);
	else
		dir = u - v * valor;
	distancia = dir.modulo();
	if (direccion != 0)
		*direccion = dir.Unitario();
	return distancia;

}*/


float Pared::distancia(Vector2D punto, Vector2D* direccion) {
	Vector2D u = (punto - limite1);
	Vector2D v = (limite2 - limite1).Unitario();
	float longitud = (limite1 - limite2).modulo();
	Vector2D dir;
	float valor = u * v;
	float distancia = 0;

	if (valor < 0)
		dir = u;
	else if (valor > longitud)
		dir = (punto - limite2);
	else
		dir = u - v * valor;
	distancia = dir.modulo();
	if (direccion != 0)
		*direccion = dir.Unitario();
	return distancia;

}