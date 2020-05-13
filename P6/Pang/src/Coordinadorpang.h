#pragma once
#include "Mundo.h"

class CoordinadorPang
{
protected:
	Mundo mundo;
	enum Estado { INICIO, JUEGO, GAMEOVER, FIN, PAUSA };
	Estado estado;
public:
	CoordinadorPang();
	~CoordinadorPang();

	void teclaEspecial(unsigned char key);
	void Tecla(unsigned char key);
	void Mueve();
	void Dibuja();

};
