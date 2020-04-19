#include "Vector2D.h"
#include <math.h>

Vector2D::Vector2D()
{
	x =0;
	y = 0;
}

Vector2D::Vector2D(float _x, float _y)
{
	x = _x;
	y = _y;

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
	return (float)sqrt((x * x) + (y * y));
}

float Vector2D::argumento()
{
	return (float)atan2(y, x);
}

Vector2D Vector2D::Unitario()
{
	Vector2D res(x,y);
	float mod = modulo();
	if (mod > 0.00001)
	{
		res.SetCoordenadas(res.GetX() / mod, res.GetY() / mod);
	}
	return res;
}

Vector2D Vector2D::operator - (Vector2D &v)
{
	Vector2D res;
	res.SetCoordenadas(x - v.GetX(), y - v.GetY());
	return res;
}

Vector2D Vector2D::operator + (Vector2D &v)
{
	Vector2D res;
	res.SetCoordenadas(x + v.GetX(), y + v.GetY());
	return res;
}

float Vector2D::operator * (Vector2D& v)
{
	float res;
	res = (x * v.GetX()) + (y * v.GetY());
	return res;
}

Vector2D Vector2D::operator * (float n)
{
	Vector2D res;
	res.SetCoordenadas(x * n, y* n);
	return res;
}
