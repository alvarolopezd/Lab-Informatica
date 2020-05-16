#include "ListaDisparos.h"
#include "Interaccion.h"

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

void ListaDisparos::Rebote(Caja caja)
{
	for (int i = 0; i < numero; i++)
	{
		Interaccion::rebote(*(lista[i]), caja);

	}
}

int ListaDisparos::GetNumero()
{
	return numero;
}

void ListaDisparos::Eliminar(Disparo* d)
{
	for (int i = 0; i < numero; i++)
	{
		if (lista[i] == d)
			Eliminar(i);
		return;
	}

}
void ListaDisparos::Eliminar(int index)
{
	if ((index < 0) || (index >= numero))
	{
		return;
	}
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
	{
		lista[i] = lista[i + 1];
	}

}
void ListaDisparos::DestruirContenido()
{
	for (int i = 0; i < numero; i++)
	{
		delete lista[i];
	}
	numero = 0;

}


Disparo* ListaDisparos::operator [](int i)
{
	if (i >= numero)
		i = numero - 1;
	if (i < 0)
		i = 0;

	return lista[i];
}