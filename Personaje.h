#pragma once

#include "SFML/Graphics.hpp"

using namespace sf;

class Personaje {

private:

	//Atributos gr�ficos
	Sprite personaje_sprite;
	Texture personaje_textura;

	//Atributos extra
	Vector2f velocidad;
	bool saltoPermitido;

public:

	//Constructor de la clase
	Personaje();

	//M�todo que devuelve el sprite que contiene el personaje
	Sprite retornarSprite();

	//M�todo que devuelve la posici�n del personaje
	Vector2f retornarPosicion();

	//M�todos de movimiento horizontal. Vinculados a las teclas "A" y "D"
	void movimientoDerecha(float velocidad);
	void movimientoIzquierda(float velocidad);

	//M�todo que permite mover al jugador a una posici�n pasada por par�metro
	void reposicionar(Vector2f posicion);

	//M�todos de movimiento vertical. Vinculados a la tecla "Espacio". Aplica ca�da al personaje y detecta cuando est� o no en el aire para evitar
	//El siguiente salto o permitirlo dependiendo de ese estado. El m�todo de salto recibe la "distancia" o fuerza del salto
	void caer(float gravedad);
	bool puedeSaltar();
	void saltar();

};


