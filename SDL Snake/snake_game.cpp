#include <iostream>
#include <SDL.h>
#include "Screen.h"
#include "Snake.h"
using namespace std;


int main(int argc, char* argv[]) {
	sf::Screen screen;
	Snake snake;

	screen.init();

	while (true) {
		screen.drawBoard();

		for (int row = -4; row <= 4; row++) {
			for (int col = -4; col <= 4; col++) {
				screen.setPixel(snake.getX() + col, snake.getY() + row, 0x00, 0xff, 0x00);
			}
		}
		
		screen.update();




		if (screen.processEvents() == false) {
			break;
		}
	}

	screen.close();
	return 0;
}