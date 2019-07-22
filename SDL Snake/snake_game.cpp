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
void input(Snake& snake, int& xSpeed, int& ySpeed);


int main(int argc, char* argv[]) {
	srand (time(NULL));

	

	sf::Screen screen;
	Snake snake;

	screen.init();

	// Random Fruit location
	int fruitX = (rand() % 68 + 6) * 10;
	int fruitY = (rand() % 68 + 6) * 10;
	drawFruit(screen, fruitX, fruitY);

	int testX = 400;
	int testY = 400;
	int testXSpeed = 0;
	int testYSpeed = 0;

	double startTime = SDL_GetTicks();

	while (true) {
		double currentTime = SDL_GetTicks() - startTime;
		input(snake, testXSpeed, testYSpeed);
		if (currentTime >= 500) { // Game updates once per half-second
			screen.drawBoard();
			
		
			snake.updatePosition(snake.getDir());


			if (snake.getX() == fruitX && snake.getY() == fruitY) { // If snake lands on fruit, new fruit location
				fruitX = (rand() % 68 + 6) * 10;
				fruitY = (rand() % 68 + 6) * 10;
				drawFruit(screen, fruitX, fruitY);
			}

			for (int row = -4; row <= 4; row++) { // Drawns 9x9 snake head
				for (int col = -4; col <= 4; col++) {
					screen.setPixel(snake.getX() + col, snake.getY() + row, 0x00, 0xff, 0x00);
				}
			}
			cout << "Current Snake Position: (" << snake.getX() << ", " << snake.getY() << ")." << endl;

			screen.setPixel(testX, testY, 0x00, 0xff, 0x00);


			screen.update();
					   			 		  			
			startTime = SDL_GetTicks();
		}	

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

void input(Snake& snake, int& xSpeed, int& ySpeed) {
	SDL_Event move_event;
	while (SDL_PollEvent(&move_event)) {
		if (move_event.type == SDL_KEYDOWN) {
			switch (move_event.key.keysym.sym)
			{
			case SDLK_w:
				ySpeed = -1;
				snake.updateDirection(1);
				break;
			case SDLK_s:
				ySpeed = 1;
				snake.updateDirection(3);
				break;
			case SDLK_a:
				xSpeed = -1;
				snake.updateDirection(4);
				break;
			case SDLK_d:
				xSpeed = 1;
				snake.updateDirection(2);
				break;
			}
		}
	}
}