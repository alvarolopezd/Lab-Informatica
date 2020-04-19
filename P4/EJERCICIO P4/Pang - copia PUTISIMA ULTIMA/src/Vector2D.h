#pragma once

class Vector2D
{
private:
	float x;
	float y;
public:
	Vector2D();
	void SetCoordenadas(float _x, float _y);
	float GetX();
	float GetY();

	float modulo();
	float argumento();
	Vector2D Unitario();
	Vector2D operator - (Vector2D &v);
	Vector2D operator + (Vector2D &v);
	float operator * (Vector2D& v);
	Vector2D operator * (float n);
;
};


