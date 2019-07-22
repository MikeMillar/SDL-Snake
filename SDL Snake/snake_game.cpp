#include <iostream>
#include <SDL.h>
#include "Screen.h"
using namespace std;


int main(int argc, char* argv[]) {
	sf::Screen screen;

	screen.init();

	while (true) {
		screen.drawBoard();
		screen.update();




		if (screen.processEvents() == false) {
			break;
		}
	}

	screen.close();
	return 0;
}