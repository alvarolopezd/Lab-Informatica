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

void Pared::SetAtributos(float _xlim1, float _ylim1, float _xlim2, float _ylim2, float _alturamin, float _alturamax)
{
	limite1.SetCoordenadas(_xlim1, _ylim1);
	limite2.SetCoordenadas(_xlim2, _ylim2);
	alturamin = _alturamin;
	alturamax = _alturamax;

}

void Pared::SetColor(unsigned char _rojo, unsigned char _verde, unsigned char _azul)
{
	rojo = _rojo;
	verde = _verde;
	azul = _azul;
}

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
}


float Pared::GetAlturaMin()
{
	return alturamin;
}
float Pared::GetAlturaMax()
{
	return alturamax;
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

void Pared::DibujaS()
{

	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(GetRojo(), GetVerde(), GetAzul());
	glVertex3f(limite1.GetX(), GetAlturaMin(), limite1.GetY());
	glVertex3f(limite2.GetX(), GetAlturaMin(), limite1.GetY());
	//glColor3ub(255, 255, 0);
	glVertex3f(limite2.GetX(), GetAlturaMax(), limite2.GetY());
	glVertex3f(limite1.GetX(), GetAlturaMax(), limite2.GetY());
	glEnd();
	glEnable(GL_LIGHTING);

}

void Pared::DibujaL()
{

	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(GetRojo(), GetVerde(), GetAzul());
	glVertex3f(limite1.GetX(), GetAlturaMin(), limite1.GetY());
	glVertex3f(limite2.GetX(), GetAlturaMin(), limite2.GetY());
	//glColor3ub(255, 255, 0);
	glVertex3f(limite2.GetX(), GetAlturaMax(), limite2.GetY());
	glVertex3f(limite1.GetX(), GetAlturaMax(), limite1.GetY());
	glEnd();
	glEnable(GL_LIGHTING);

}



float Pared::distancia(Vector2D punto, Vector2D* direccion)
{
	Vector2D u = (punto - limite1);
	Vector2D v = (limite2 - limite1).Unitario();
	float longitud = (limite2 - limite1).modulo();
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