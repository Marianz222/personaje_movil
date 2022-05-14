#include "Gestor.h"
#include "Personaje.h"
#include "Ladrillo.h"
#include "Reloj.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>


using namespace std;
using namespace sf;

//Constructor

Gestor::Gestor() {

	fondo_cargado = false;

	alturaSuelo = 427;
	gravedad = 3.5;

}

//Método de control principal

void Gestor::iniciar() {

	//Se genera la ventana principal
	RenderWindow * ventana_principal = new RenderWindow(VideoMode(800, 600), "Personaje Móvil");
	cout << "[INFO]: Ventana principal creada" << endl;

	//Se fijan los FPS a 60
	ventana_principal->setFramerateLimit(60);
	cout << "[INFO]: Framerate fijado" << endl;

	//Se crea el personaje a utilizar para la simulación
	Personaje *personaje_principal = new Personaje;
	cout << "[INFO]: Personaje creado" << endl;

	//Se crea el arreglo de ladrillos
	Ladrillo ladrillos[5];
	cout << "[INFO]: Ladrillos creados" << endl;

	//Se asigna una posición fija en la ventana para cada uno de los ladrillos dentro del arreglo
	float coordenadaX = 200.0;

	for (int i = 0; i < 5; i++) {

		ladrillos[i].establecerPosicion({ (float)coordenadaX, (float)200 });

		coordenadaX += 75.0;

	}

	//Se crea el temporizador para controlar el minijuego
	Reloj * reloj_principal = new Reloj;
	cout << "[INFO]: Temporizador generado" << endl;

	reloj_principal->posicionar({ (float)750, (float)20 });
	cout << "[INFO]: El reloj se ha reposicionado a la esquina" << endl;

	while (ventana_principal->isOpen()) {

		//Linea que limpia el framebuffer para el siguiente frame de dibujado
		ventana_principal->clear();

		//Carga el fondo de la escena para ser dibujado
		cargarFondo();

		//Bucle para notificar por consola cuando se carga el fondo, usa la variable para solo enviar 1 mensaje. De lo contrario
		//la consola se inunda de mensajes constantes.
		if (!fondo_cargado) {

			cout << "[INFO]: Fondo cargado" << endl;
			fondo_cargado = true;

		}

		controlarEventos(ventana_principal, personaje_principal);

		//Llama al método de caída para el personaje
		aplicarGravedad(personaje_principal);

		colisionSuelo(personaje_principal);

		//Lineas para dibujar y mostrar la pantalla
		ventana_principal->draw(fondo_sprite);
		ventana_principal->draw(personaje_principal->retornarSprite());

		for (int i = 0; i < 5; i++) {

			ventana_principal->draw(ladrillos[i].retornarSprite());
			ventana_principal->draw(ladrillos[i].retornarTexto());

		}

		ventana_principal->draw(reloj_principal->retornarTexto());

		ventana_principal->display();

	}

}

//Métodos de carga de assets

void Gestor::cargarFondo() {

	fondo_textura.loadFromFile("assets/images/fondo.jpg");
	fondo_sprite.setTexture(fondo_textura);

}

//Método de gestión de eventos

void Gestor::controlarEventos(RenderWindow * ventana_principal, Personaje * personaje_principal) {

	Event evento;

	float velocidadMovimiento = 4.5;

	while (ventana_principal->pollEvent(evento)) {

		switch (evento.type) {

		case Event::Closed: //Disparado al cerrar la ventana

			//Se cierra la ventana
			ventana_principal->close();
			cout << "[INFO]: Ventana principal cerrada" << endl;

			break;

		case Event::KeyPressed: //Disparado al presionar una tecla

			switch (evento.key.code) {

			case Keyboard::D: //Evento para la tecla "D"

				//Mueve al personaje, con dirección DERECHA ya que el bool es true

				if (!colisionParedDerecha(personaje_principal)) {

					moverPersonaje(true, personaje_principal, velocidadMovimiento);

				}
				else {

					cout << "[ERROR]: Movimiento cancelado: Colision detectada (Derecha)" << endl;

				}

				break;

			case Keyboard::A: //Evento para la tecla "A"

				//Mueve al personaje, con dirección IZQUIERDA ya que el bool es false

				if (!colisionParedIzquierda(personaje_principal)) {

					moverPersonaje(false, personaje_principal, velocidadMovimiento);

				}
				else {

					cout << "[ERROR]: Movimiento cancelado: Colision detectada (Izquierda)" << endl;

				}

				break;

			case Keyboard::Space: //Evento para la tecla "Espacio"

				//Hace saltar al personaje, moviendolo en el eje Y
				
				ejecutarSalto(personaje_principal, gravedad);

				break;

			case Keyboard::H: //Evento para la tecla "H"

				//Coloca al personaje en su posición inicial
				personaje_principal->reposicionar({(float) 350, (float) 430 });
				cout << "[INFO]: Personaje reposicionado [350, 430]" << endl;

				break;

			}

		default:

			break;

		}

	}

}

//Métodos de control de movimiento

void Gestor::moverPersonaje(bool direccion, Personaje* personaje_principal, float velocidad) {

	if (direccion) {

		personaje_principal->movimientoDerecha(velocidad);

	}
	else {

		personaje_principal->movimientoIzquierda(velocidad);

	}

}

//Métodos de Salto

void Gestor::ejecutarSalto(Personaje* personaje_principal, float gravedad) {

	if (personaje_principal->puedeSaltar()) {

		personaje_principal->saltar();

		cout << "[INFO]: Salto ejecutado" << endl;

	}

}

void Gestor::aplicarGravedad(Personaje * personaje_principal) {

	if ((personaje_principal->retornarPosicion().y < alturaSuelo)) {

		personaje_principal->caer(gravedad);

	}

}

//Métodos de Colision

bool Gestor::colisionParedIzquierda(Personaje * personaje_principal) {

	if (((personaje_principal->retornarPosicion().x) <= -2)) {

		return true;

	}

	return false;

}

bool Gestor::colisionParedDerecha(Personaje* personaje_principal) {

	if (((personaje_principal->retornarPosicion().x) >= 706)) {

		return true;

	}

	return false;

}

bool Gestor::colisionSuelo(Personaje* personaje_principal) {

	if ((personaje_principal->retornarPosicion().y) == alturaSuelo) {

		personaje_principal->permitirSalto(true);

		return true;

	}

	return false;

}
