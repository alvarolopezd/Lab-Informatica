#include "glut.h"
#include "esfera.h"
#include "toroide.h"
#include "octaedro.h"
#include "mundo.h"
#include <math.h>

void Mundo::InicioMundo(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
	o.SetPos(0, 0, 0);
	e.SetRadio(2);
	e.SetPos(-7, 3, 0);
	e.SetColor(255, 255, 255);
}
void Mundo::PintarMundo()
{
	// ESFERAS
	e.Drawesfera();

	// TOROIDE
	t.Drawtoroide();

	// OCTAEDRO
	o.Drawoctaedro();

}
void Mundo::AccionesMundo(unsigned char _key)
{
	// MOVIMIENTO CUBO
	if (_key == 'w')		o.arriba();
	if (_key == 's')		o.abajo();
	if (_key == 'd')		o.derecha();
	if (_key == 'a')		o.izquierda();

	// COLORES ESFERA
	if (_key == '1') 	e.SetColor(255, 0, 0); // Rojo	
	if (_key == '2') 	e.SetColor(0, 255, 0); // Verde
	if (_key == '3') 	e.SetColor(0, 0, 255); // Azul

	// TAMAÑO ESFERA
	if (_key == '+')		e.aumenta();
	if (_key == '-')		e.disminuye();

	// MOVIMIENTO MUNDO
	if (_key == '4')		x -= 2;
	if (_key == '6')		x += 2;
	if (_key == '7')		z -= 2;
	if (_key == '9')		z += 2;
}


void Mundo::LookAt()
{
	gluLookAt(x, y, z,  // posicion del ojo
		0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 
}

void Mundo::MuevePorTiempo()
{
	t.mueve();
}