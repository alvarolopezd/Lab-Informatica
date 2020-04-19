#include "Caja.h"




void Caja::Inicializa()
{
	suelo.SetAtributos(-5.0f, -5.0f, 5.0f, 5.0f, 0, 0);
	suelo.SetColor(0, 225, 0);
	techo.SetAtributos(-5.0f, -5.0f, 5.0f, 5.0f, 10, 10);
	techo.SetColor(0, 225, 0);
	pared_izq.SetAtributos(-5.0f, -5.0f, -5.0f, 5.0f, 0, 10);
	pared_izq.SetColor(0, 225, 0);
	pared_dcha.SetAtributos(5.0f, -5.0f, 5.0f, 5.0f, 0, 10);
	pared_dcha.SetColor(0, 225, 0);
}


void Caja::Dibuja()
{
	suelo.DibujaS();
	techo.DibujaS();
	pared_dcha.DibujaL();
	pared_izq.DibujaL();
}

float Caja::XMaxSuelo()
{
	float XMax = suelo.GetXLim2();
	return XMax;
}
float Caja::XMinSuelo()
{
	float XMin = suelo.GetXLim1();
	return XMin;
}