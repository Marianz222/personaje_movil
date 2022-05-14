#include "Personaje.h"
#include <iostream>
#include <ctime>

using namespace std;

Personaje::Personaje() {

	//Se carga la textura y se transforma el sprite
	personaje_sprite.setScale(0.75f, 0.75f);
	personaje_sprite.setPosition(350, 430);
	personaje_textura.loadFromFile("assets/images/personaje.png");
	personaje_sprite.setTexture(personaje_textura);

	//Se establece el bool de salto
	saltoPermitido = true;

}

Sprite Personaje::retornarSprite() {

	return personaje_sprite;

}

void Personaje::movimientoDerecha(float velocidad) {

	personaje_sprite.move(velocidad, 0);

}

void Personaje::movimientoIzquierda(float velocidad) {

	personaje_sprite.move(-velocidad, 0);

}

Vector2f Personaje::retornarPosicion() {

	return personaje_sprite.getPosition();

}

void Personaje::caer(float gravedad) {

	personaje_sprite.move({0, gravedad});

}

void Personaje::saltar() {

	if (puedeSaltar()) {

		Clock reloj;
		Time tiempo_transcurrido = reloj.getElapsedTime();

		personaje_sprite.move(0, -35);

		if (tiempo_transcurrido.asSeconds() > 3) {

			personaje_sprite.move(0, -100);

		}

		//Total: 200

	}
	
}

bool Personaje::puedeSaltar() {

	return saltoPermitido;

}

void Personaje::reposicionar(Vector2f posicion) {

	personaje_sprite.setPosition(posicion);

}