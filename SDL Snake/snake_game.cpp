#include <iostream>
#include <SDL.h>
#include "Screen.h"
#include "Snake.h"
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
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

	int testX = 400;
	int testY = 400;

	while (true) {
		screen.drawBoard();		
		input(snake);
		snake.updatePosition(snake.getDir());
		

		if (snake.getX() == fruitX && snake.getY() == fruitY) { // If snake lands on fruit, new fruit location
			fruitX = rand() % 693 + 56;
			fruitY = rand() % 693 + 56;
			drawFruit(screen, fruitX, fruitY);
		}

		for (int row = -4; row <= 4; row++) { // Drawns 9x9 snake head
			for (int col = -4; col <= 4; col++) {
				screen.setPixel(snake.getX() + col, snake.getY() + row, 0x00, 0xff, 0x00);
			}
		}

		//screen.setPixel(snake.getX(), snake.getY(), 0x00, 0xff, 0x00);


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
	SDL_Event move_event;
	while (SDL_PollEvent(&move_event)) {
		if (move_event.type == SDL_KEYDOWN) {
			switch (move_event.key.keysym.sym)
			{
			case SDLK_w:
				snake.updateDirection(1);
				break;
			case SDLK_s:
				snake.updateDirection(3);
				break;
			case SDLK_a:
				snake.updateDirection(4);
				break;
			case SDLK_d:
				snake.updateDirection(2);
				break;
			}
		}
	}
}