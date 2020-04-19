#include "Vector2D.h"
#include <math.h>

Vector2D::Vector2D()
{
	x = 0;
	y = 0;
}

void Vector2D::SetCoordenadas(float _x, float _y)
{
	x = _x;
	y = _y;
}

float Vector2D::GetX()
{
	return x;
}

float Vector2D::GetY()
{
	return y;
}

float Vector2D::modulo()
{
	return (float)sqrt((GetX() * GetX()) + (GetY() * GetY()));
}

float Vector2D::argumento()
{
	return (float)atan2(GetY(), GetX());
}

Vector2D Vector2D::Unitario()
{
	Vector2D res;
	float mod = modulo();
	if (mod < 0.00001)
	{
		res.SetCoordenadas(GetX() / mod, GetY() / mod);
	}
	return res;
}

Vector2D Vector2D::operator - (Vector2D &v)
{
	Vector2D res;
	res.SetCoordenadas(GetX() - v.GetX(), GetY() - v.GetY());
	return res;
}

Vector2D Vector2D::operator + (Vector2D &v)
{
	Vector2D res;
	res.SetCoordenadas(GetX() + v.GetX(), GetY() + v.GetY());
	return res;
}

float Vector2D::operator * (Vector2D& v)
{
	float res;
	res = (GetX() * v.GetX()) + (GetY() * v.GetY());
	return res;
}
Vector2D Vector2D::operator * (float n)
{
	Vector2D res;
	res.SetCoordenadas(GetX() * n, GetY() * n);
}
