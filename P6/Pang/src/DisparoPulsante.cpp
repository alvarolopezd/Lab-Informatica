#include "DisparoPulsante.h"
#include "glut.h"

DisparoPulsante::DisparoPulsante()
{
	posicion.SetCoordenadas(-5, 0);
	velocidad.SetCoordenadas(0, 0.05);
	aceleracion.SetCoordenadas(0, 9.81);
	radius = 0.2;
	slices = stacks = 50;
	rojo = verde = azul = 20;
	radio_max = 0.3f;
	radio_min = 0.2f;
	pulso = 0.5f;
}

/*DisparoPulsante::DisparoPulsante(float _xpos, float _ypos, float _xvel, float _yvel, float _xacel, float _yacel, float _radius)
{
	posicion.SetCoordenadas(_xpos, _ypos);
	velocidad.SetCoordenadas(_xvel, _yvel);
	aceleracion.SetCoordenadas(_xacel, _yacel);
	radius = _radius;
	slices = stacks = 50;
	rojo = verde = azul = 255;
	radio_max = 1.0f;
	radio_min = 0.2f;
	pulso =0.5f;
}*/
DisparoPulsante:: ~DisparoPulsante()
{

}
void DisparoPulsante::Mueve(float t)
{
	Disparo::Mueve(t);

	if (radius > radio_max)
		pulso = -pulso;
	if (radius < radio_min)
		pulso = -pulso;

	radius += pulso * t;

	SetColor(radius * 255, 255 - radius * 100, 100 + radius * 50);
}

void DisparoPulsante::Dibuja()
{
		//origen.SetCoordenadas(posicion.GetX(), posicion.GetY());
		glColor3f(GetRojo(), GetVerde(), GetAzul());
		glPushMatrix();
		glTranslatef(posicion.GetX(), posicion.GetY(), 0);
		glutSolidSphere(radius, 50, 50);
		glPopMatrix();
		glBegin(GL_LINES);
		/////////// CAMBIAR ESOS 0.0F Y 0.0F A COORDENDADAS DEL PERSONAJE //////////////////
		glVertex3f(posicion.GetX()-0.1, 0.0f, 0.0f);
		glVertex3f(posicion.GetX()-0.1, posicion.GetY(), 0.0f);
		glVertex3f(posicion.GetX()+0.1, 0.0f, 0.0f);
		glVertex3f(posicion.GetX()+0.1, posicion.GetY(), 0.0f);
		glEnd();
}

void DisparoPulsante::SetPos(float _x, float _y)
{
	posicion.SetCoordenadas(_x, _y);
}
void DisparoPulsante::SetVel(float _x, float _y)
{
	posicion.SetCoordenadas(_x, _y);
}