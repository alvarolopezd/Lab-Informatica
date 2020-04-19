#include "Pared.h"


Pared::Pared()
{
	p1.SetCoordenadas(0, 0);
	p2.SetCoordenadas(0, 0);
	p3.SetCoordenadas(0, 0);
	p4.SetCoordenadas(0, 0);
	rojo = 0;
	verde = 0;
	azul = 0;
}
Pared::~Pared()
{

}

void Pared::SetAtributos(float _xp1, float _yp1, float _xp2, float _yp2, float _xp3, float _yp3, float _xp4, float _yp4, float _alturamin, float _alturamax)
{
	p1.SetCoordenadas(_xp1, _yp1);
	p2.SetCoordenadas(_xp2, _yp2);
	p3.SetCoordenadas(_xp3, _yp3);
	p4.SetCoordenadas(_xp4, _yp4);
	alturamin = _alturamin;
	alturamax = _alturamax;

}

void Pared::SetColor(unsigned char _rojo, unsigned char _verde, unsigned char _azul)
{
	rojo = _rojo;
	verde = _verde;
	azul = _azul;
}

float Pared::GetXP1()
{
	return p1.GetX();
}
float Pared::GetYP1()
{
	return p1.GetY();
}

float Pared::GetXP2()
{
	return p2.GetX();
}
float Pared::GetYP2()
{
	return p2.GetY();
}

float Pared::GetXP3()
{
	return p3.GetX();
}
float Pared::GetYP3()
{
	return p3.GetY();
}

float Pared::GetXP4()
{
	return p4.GetX();
}
float Pared::GetYP4()
{
	return p4.GetY();

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
void Pared::Dibuja()
{

	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(GetRojo(), GetVerde(), GetAzul());
	glVertex3f(p1.GetX(), GetAlturaMin(), p1.GetY());
	glVertex3f(p2.GetX(), GetAlturaMin(), p2.GetY());
	//glColor3ub(255, 255, 0);
	glVertex3f(p3.GetX(), GetAlturaMax(), p3.GetY());
	glVertex3f(p4.GetX(), GetAlturaMax(), p4.GetY());
	glEnd();
	glEnable(GL_LIGHTING);
	   	
}


float Pared::distancia(Vector2D punto, Vector2D* direccion)
{
	Vector2D u = (punto - p1);
	Vector2D v = (p3 - p1).Unitario();
	float longitud = (p3 - p1).modulo();
	Vector2D dir;
	float valor = u*v;
	float distancia = 0;

	if (valor < 0)
		dir = u;
	else if (valor > longitud)
		dir = (punto - p3);
	else
		dir = u - v * valor;
	distancia = dir.modulo();
	if (direccion != 0)
		*direccion = dir.Unitario();
	return distancia;

}
