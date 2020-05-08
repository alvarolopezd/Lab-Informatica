#include "EsferaPulsante.h"

EsferaPulsante::EsferaPulsante()
{
	SetAcel(0.0f, 5.0f);
	radio_max = 2.0f;
	radio_min = 0.5f;
	pulso = 0.5f;
}
EsferaPulsante::~EsferaPulsante()
{


}
void EsferaPulsante::mueve(float t)
{
	Esfera::Mueve(t);

	if (radius > radio_max)
		pulso = -pulso;
	if (radius < radio_min)
		pulso = -pulso;

	radius += pulso * t;
	
	SetColor(radius * 255, 255 - radius * 100, 100 + radius * 50);
}
