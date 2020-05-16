#include "ListaEsferas.h"
#include "Interaccion.h"

ListaEsferas::ListaEsferas()
{
	//Inicilizar el numero de esferas iniciales a 0
	numero = 0;
	//Poner a NULL todos lo selementos de la lista 
	for (int i = 0; i < MAX_ESFERAS; i++)
	{
		lista[i] = 0;
	}
}

ListaEsferas::~ListaEsferas()
{

}

bool ListaEsferas::agregar(Esfera* e)
{
	// Añadir que si la esfera ya está creatda haga un return false
	if (numero < MAX_ESFERAS)
	{
		lista[numero] = e;
		numero++; // Aumentar el numero para ir recorriendo la lista e ir agregando esferas sobre la lista
		return true;
	}
	else
		return false;
}

void ListaEsferas::Dibuja()
{
	for (int i = 0; i < numero; i++)
	{ //lista[i] es una direccion de memoria y para acceder dentro necesito ->
		lista[i]->Dibuja(); // Dibujar una a una las esferas para llamar al metood Dibuja dentro de Esferas
	}
}

void ListaEsferas::Mueve(float t)
{
	for (int i = 0; i < numero; i++)
	{
		lista[i]->Mueve(t);
	}

}

void ListaEsferas::Rebote(Caja caja)
{
	for (int i = 0; i < numero; i++)
	{
		Interaccion::rebote(*(lista[i]), caja);
	}
}

void ListaEsferas::Rebote()
{
	for (int i = 0; i < numero; i++)
	{
		for (int j = 1; j < numero; j++)
		{
			Interaccion::rebote(*lista[i], *lista[j]);
		}
	}
}

void ListaEsferas::Rebote(Esfera esfera)
{
	for (int i = 0; i < numero; i++)
	{
		Interaccion::rebote(esfera, *lista[i]);
	}
}

bool ListaEsferas::Rebote(Disparo disparo, int i)
{
	if (Interaccion::colision(disparo, *lista[i]))
		return true;
	else return false;
}


void ListaEsferas::destruirContenido()
{
	for (int i = 0; i < numero; i++)
	{
		delete lista[i];
	}
	numero = 0;
}

void ListaEsferas::Eliminar(int index)
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

void ListaEsferas::Eliminar(Esfera *e)
{
	for (int i = 0; i < numero; i++)
	{
		if (lista[i] == e)
			Eliminar(i);
		return;
	}
}

Esfera* ListaEsferas::colision(Hombre h)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::colision(*(lista[i]), h))
		{
			return lista[i];
		}
		return 0;
	}
}

Esfera* ListaEsferas::colision(Disparo d)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::colision(d,*(lista[i])))
		{
			return lista[i];
		}
		return 0;
	}
}


Esfera* ListaEsferas::operator [](int i)
{
	if (i >= numero)
		i = numero - 1;
	if (i < 0)
		i = 0;

	return lista[i];
}


