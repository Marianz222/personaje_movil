#include "Ladrillo.h"

using namespace std;

Ladrillo::Ladrillo() {

	//Se hacen las transformaciones necesarias el sprite y la textura
    ladrillo_textura.loadFromFile("assets/images/ladrillo.png");
	ladrillo_sprite.setTexture(ladrillo_textura);
	ladrillo_sprite.setScale(1.75f, 1.75f);

	//Se añade al valor un número aleatorio entre 1 y 500
	valor = 1 + rand() % (1 - 500);

	//Se hacen las transformaciones al texto, incluyendo fuente, tamaño, color, etc.
	fuente.loadFromFile("assets/fonts/arial.ttf");
	texto_flotante.setFont(fuente);
	texto_flotante.setString(to_string(valor));
	texto_flotante.setCharacterSize(24);
	texto_flotante.setStyle(Text::Bold);
	texto_flotante.setFillColor(Color::White);

}

void Ladrillo::establecerPosicion(Vector2f ubicacion) {

	ladrillo_sprite.setPosition(ubicacion);
	texto_flotante.setPosition(ladrillo_sprite.getPosition().x + 20, ladrillo_sprite.getPosition().y - 32);

}

int Ladrillo::devolverValor() {

	return valor;

}

Sprite Ladrillo::retornarSprite() {

	return ladrillo_sprite;

}

Text Ladrillo::retornarTexto() {

	return texto_flotante;

}