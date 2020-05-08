#pragma once
#include "Mundo.h"

class CoordinadorPang
{
private:
	Mundo mundo;
	enum Estado{INICIO,JUEGO};
	Estado estado;
public:
	CoordinadorPang();
	~CoordinadorPang();

	void teclaEspecial(unsigned char key);
	void tecla(unsigned char key);
	void mueve();
	void dibuja();

};