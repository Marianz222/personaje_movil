#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Ladrillo {

private:

	//Atributos gr�ficos
	Texture ladrillo_textura;
	Sprite ladrillo_sprite;

	//Atributos de texto
	Font fuente;
	Text texto_flotante;

	//Atributo de valor
	int valor;

public:

	//Constructor de la clase
	Ladrillo();

	//M�todo que coloca al ladrillo en la coordenada pasada por par�metro
	void establecerPosicion(Vector2f ubicacion);

	//M�todo que retorna el valor que contiene el ladrillo
	int devolverValor();

	//M�todo que devuelve el sprite que contiene el ladrillo
	Sprite retornarSprite();

	Text retornarTexto();

};

