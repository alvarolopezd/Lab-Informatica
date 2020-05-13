#pragma once
#include "Esfera.h"
#include "Caja.h"
#include "Hombre.h"
#include "Disparo.h"
#include "DisparoPulsante.h"
#include "Bonus.h"
#include "Interaccion.h"
#include "ListaEsferas.h"
#include "ListaDisparos.h"
#include "EsferaPulsante.h"
#include "ObjetoMovil.h"

class Mundo
{
private:
	float x_ojo;
	float y_ojo;
	float z_ojo;
	bool impacto=false;
	Esfera esfera, esfera2;
	ListaEsferas esferas;
	EsferaPulsante esferaPulsante;
	ListaDisparos disparos;
	Caja caja;
	Hombre hombre;
	Disparo disparo;
	DisparoPulsante disparoPulsante;
	Bonus bonus;	
	ObjetoMovil objectoMovil;
public:		
	virtual ~Mundo();
	void Inicializa();
	void Dibuja();
	void RotarOjo();
	void Mueve();
	void Tecla(unsigned char key);
	int GetNumEsferas();
	bool GetImpacto();

};