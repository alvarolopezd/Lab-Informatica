#include "Coordinadorpang.h"

CoordinadorPang::CoordinadorPang()
{
	estado = INICIO;

}
CoordinadorPang::~CoordinadorPang()
{

}

void CoordinadorPang::teclaEspecial(unsigned char key)
{

}
void CoordinadorPang::tecla(unsigned char key)
{
	mundo.Tecla(key);
}
void CoordinadorPang::mueve()
{
	mundo.Mueve();
}
void CoordinadorPang::dibuja()
{
	mundo.Dibuja();
}

