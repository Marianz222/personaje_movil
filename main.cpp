#include <iostream>
#include <SFML/Graphics.hpp>
#include "Gestor.h"
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace sf;

int main() {

	srand(time(0));

	Gestor gestor;

	cout << "[INFO]: Iniciando..." << endl;
	gestor.iniciar();

	return 0;

}
