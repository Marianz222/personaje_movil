#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Ladrillo {

private:

	//Atributos gráficos
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

	//Método que coloca al ladrillo en la coordenada pasada por parámetro
	void establecerPosicion(Vector2f ubicacion);

	//Método que retorna el valor que contiene el ladrillo
	int devolverValor();

	//Método que devuelve el sprite que contiene el ladrillo
	Sprite retornarSprite();

	Text retornarTexto();

};

