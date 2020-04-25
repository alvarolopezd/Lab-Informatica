#pragma once

#define MAX_ESFERAS 100
#include "Esfera.h"
#include "Caja.h"
#include "Hombre.h"

class ListaEsferas
{
private:
	Esfera* lista[MAX_ESFERAS];
	int numero;
public:
	ListaEsferas();
	virtual ~ListaEsferas();
	
	//AGREGAR ESFERAS devuelve un valor booleano para saber si se agrego bien la esfera (por si supero el limite de las esferas)
	bool agregar(Esfera* e);
	
	//DIBUJA llama a todas las esferas del vector para dibujarlas
	void Dibuja();
	
	//MUEVE le paso el timepo con el que se mueven las esferas
	void Mueve(float t);

	//REBOTE
	void Rebote(Caja caja);

	//DESTRUCTOR
	void destruirContenido();

	//ELIMINAR ESFERA
	void Eliminar(int index); // Elimina la esfera de posicion index
	void Eliminar(Esfera* e);

	//COLISION CON LISTA DE ESFERAS
	Esfera* colision(Hombre h);
};
