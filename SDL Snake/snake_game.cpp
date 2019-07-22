#include <iostream>
#include <SDL.h>
#include "Screen.h"
#include "Snake.h"
#include <time.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;

void drawFruit(sf::Screen& screen, int randX, int randY);
void input(Snake& snake);


int main(int argc, char* argv[]) {
	srand (time(NULL));

	

	sf::Screen screen;
	Snake snake;

	screen.init();

	// Random Fruit location
	int fruitX = rand() % 693 + 56;
	int fruitY = rand() % 693 + 56;
	drawFruit(screen, fruitX, fruitY);


	while (true) {
		screen.drawBoard();				

		if (snake.getX() == fruitX && snake.getY() == fruitY) { // If snake lands on fruit, new fruit location
			fruitX = rand() % 693 + 56;
			fruitY = rand() % 693 + 56;
			drawFruit(screen, fruitX, fruitY);
		}

		//for (int row = -4; row <= 4; row++) { // Drawns 9x9 snake head
		//	for (int col = -4; col <= 4; col++) {
		//		screen.setPixel(snake.getX() + col, snake.getY() + row, 0x00, 0xff, 0x00);
		//	}
		//}

		screen.setPixel(snake.getX(), snake.getY(), 0x00, 0xff, 0x00);

		char key = ' ';
		if (_kbhit()) {
			key = _getch();
			screen.setPixel(500, 500, 0x00, 0xff, 0x00);
		}
		snake.updatePosition(key);

		screen.update();




		if (screen.processEvents() == false) {
			break;
		}
	}

	screen.close();
	return 0;
}

void drawFruit(sf::Screen &screen, int randX, int randY) {
	for (int row = -4; row <= 4; row++) {	// Draw fruit at random loc	
		for (int col = -4; col <= 4; col++) {
			screen.setPixel(randX + col, randY + row, 0xFF, 0x00, 0x00);
		}
	}
}

void input(Snake& snake) {
	
}