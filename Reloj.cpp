#include "Reloj.h"

using namespace std;

Reloj::Reloj() {

	valor = 0;

	fuente.loadFromFile("assets/fonts/strasua.ttf");
	texto.setFont(fuente);
	texto.setString(to_string(valor));
	texto.setCharacterSize(32);
	texto.setFillColor(Color::White);

}

Text Reloj::retornarTexto() {

	return texto;

}

void Reloj::posicionar(Vector2f ubicacion) {

	texto.setPosition(ubicacion);

}
