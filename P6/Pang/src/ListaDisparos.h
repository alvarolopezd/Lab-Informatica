#pragma once

#define MAX_DISPAROS 10
#include "Disparo.h"
#include "Caja.h"

class ListaDisparos
{
private:
	Disparo* lista[MAX_DISPAROS];
	int numero;
	friend class Interaccion;
public:
	ListaDisparos();
	virtual ~ListaDisparos();

	bool agregar(Disparo* d);

	void Dibuja();
	void Mueve(float t);
	void Rebote(Caja caja);
	void Rebote(Pared p);
	int GetNumero();

	void Eliminar(Disparo* d);
	void Eliminar(int index);
	void DestruirContenido();

	Disparo* operator[](int index);

};