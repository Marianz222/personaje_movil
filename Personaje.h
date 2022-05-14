#pragma once

#include "SFML/Graphics.hpp"

using namespace sf;

class Personaje {

private:

	//Atributos gráficos
	Sprite personaje_sprite;
	Texture personaje_textura;

	//Atributos extra
	Vector2f velocidad;
	bool saltoPermitido;

public:

	//Constructor de la clase
	Personaje();

	//Método que devuelve el sprite que contiene el personaje
	Sprite retornarSprite();

	//Método que devuelve la posición del personaje
	Vector2f retornarPosicion();

	//Métodos de movimiento horizontal. Vinculados a las teclas "A" y "D"
	void movimientoDerecha(float velocidad);
	void movimientoIzquierda(float velocidad);

	//Método que permite mover al jugador a una posición pasada por parámetro
	void reposicionar(Vector2f posicion);

	//Métodos de movimiento vertical. Vinculados a la tecla "Espacio". Aplica caída al personaje y detecta cuando está o no en el aire para evitar
	//El siguiente salto o permitirlo dependiendo de ese estado. El método de salto recibe la "distancia" o fuerza del salto
	void caer(float gravedad);
	bool puedeSaltar();
	void saltar();

};


