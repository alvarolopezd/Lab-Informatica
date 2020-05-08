#include "ListaDisparos.h"

ListaDisparos::ListaDisparos()
{
	numero = 0;
	for (int i = 0; i < MAX_DISPAROS; i++)
	{
		lista[i] = 0;
	}
}

ListaDisparos::~ListaDisparos()
{

}

bool ListaDisparos::agregar(Disparo *d)
{
	if (numero < MAX_DISPAROS)
	{
		lista[numero] = d;
		numero++;
		return true;
	}
	return false;
}

void ListaDisparos::Dibuja()
{
	for (int i = 0; i < numero; i++)
	{
		lista[i]->Dibuja();
	}
}

void ListaDisparos::Mueve(float t)
{
	for (int i = 0; i < numero; i++)
	{
		lista[i]->Mueve(t);
	}
}