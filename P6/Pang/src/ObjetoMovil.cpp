#include "ObjetoMovil.h"
#include <stdlib.h>


void ObjetoMovil::Mueve(float t)
{
	//float ruido (0.1f * (0.5f - rand() / (float (RAND_MAX))));
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t); //Isertar ruido en (0.5f * t * t+ruido);
	velocidad = velocidad + aceleracion * (t); //Insertar rudio en * (t+ruido);
}