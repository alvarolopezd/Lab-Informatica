
#include "Caja.h"


void Caja::Inicializa()
{
	/*suelo.SetAtributos(-5.0f, -5.0f, 5.0f, 5.0f, 0, 0);
	
	techo.SetAtributos(-5.0f, -5.0f, 5.0f, 5.0f, 10, 10);

	pared_izq.SetAtributos(-5.0f, -5.0f, -5.0f, 5.0f, 0, 10);
	
	pared_dcha.SetAtributos(5.0f, -5.0f, 5.0f, 5.0f, 0, 10);
	pared_dcha.SetColor(0, 225, 0);*/
	
	pared_izq.SetColor(0, 225, 0);
	pared_izq.SetAtributos(-10, 0, -10, 15);
	pared_dcha.SetColor(0, 225, 0); 
	pared_dcha.SetAtributos(10, 0, 10, 15);
	techo.SetColor(0, 225, 250);
	techo.SetAtributos(10, 15, -10, 15);
	suelo.SetColor(0, 225, 250);
	suelo.SetAtributos(-10, 0, 10, 0);

}


void Caja::Dibuja()
{
	suelo.Dibuja();
	techo.Dibuja();
	pared_dcha.Dibuja();
	pared_izq.Dibuja();
}



Pared Caja::GetSuelo() {
	return suelo;
}

Pared Caja::GetParedIzq() {
	return pared_izq;
}

Pared Caja::GetParedDer() {
	return pared_dcha;
}

Pared Caja::GetTecho() {
	return techo;
}

/*Pared Caja::GetPlataforma()
{
	return plataforma;
}*/

