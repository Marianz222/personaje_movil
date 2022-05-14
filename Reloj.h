#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Reloj {

private:

	int valor;

	Font fuente;
	Text texto;

public:

	Reloj();

	Text retornarTexto();

	void posicionar(Vector2f ubicacion);

};

