#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Personaje.h"

using namespace sf;

class Gestor {

private:

	//Atributos de Sprite y Textura para el fondo de la escena
	Texture fondo_textura;
	Sprite fondo_sprite;

	//Variable extra para controlar la salida en consola al cargar el fondo
	bool fondo_cargado;

	int alturaSuelo;
	float gravedad;

public:

	Gestor();

	//Método encargado de cargar la imagen de fondo (sprite y textura)
	void cargarFondo();

	//Método que inicia todo el bucle, se llama desde "main"
	void iniciar();

	//Método encargado de recibir y procesar todos los eventos. Esto lo hace en torno al personaje y a la ventana
	void controlarEventos(RenderWindow * ventana_principal, Personaje * personaje_principal);

	//Método que se encarga de mover un personaje pasado por parámetro, siendo su dirección también pasada por parámetro
	// si direccion es TRUE, el personaje se moverá a la Derecha, sino lo hará hacia la Izquierda
	void moverPersonaje(bool direccion, Personaje * personaje_principal, float velocidad);

	//Método que se encarga de mover el personaje en el eje Y, haciendolo saltar. Solo recibe un pasaje del objeto personaje
	void ejecutarSalto(Personaje * personaje_principal, float gravedad);
	void aplicarGravedad(Personaje * personaje_principal);

	//Métodos encargados de detectar colisiones con los bordes de la ventana
	bool colisionParedIzquierda(Personaje* personaje_principal);
	bool colisionParedDerecha(Personaje* personaje_principal);
	bool colisionSuelo(Personaje* personaje_principal);

};

