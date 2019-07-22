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
void update(Snake& snake, sf::Screen& screen, int& fruitX, int& fruitY, bool& gOver);


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
	bool gameOver = false;
	while (true) {
		double currentTime = SDL_GetTicks() - startTime;
		input(snake, testXSpeed, testYSpeed);
		if (currentTime >= 500) { // Game updates once per half-second
			screen.drawBoard();

			update(snake, screen, fruitX, fruitY, gameOver);
			
			//screen.setPixel(testX, testY, 0x00, 0xff, 0x00);


			screen.update();

			if (gameOver) {
				break;
			}
					   			 		  			
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
				if (snake.getDir() != 3) {
					ySpeed = -1;
					snake.updateDirection(1);
				}				
				break;
			case SDLK_s:
				if (snake.getDir() != 1) {
					ySpeed = 1;
					snake.updateDirection(3);
				}				
				break;
			case SDLK_a:
				if (snake.getDir() != 2) {
					xSpeed = -1;
					snake.updateDirection(4);
				}				
				break;
			case SDLK_d:
				if (snake.getDir() != 4) {
					xSpeed = 1;
					snake.updateDirection(2);
				}				
				break;
			}
		}
	}
}

void update(Snake& snake, sf::Screen& screen, int& fruitX, int& fruitY, bool& gOver) {
	int currentX = snake.getX();
	int currentY = snake.getY();
	for (int row = -4; row <= 4; row++) { // Clears old snake head pos
		for (int col = -4; col <= 4; col++) {
			screen.setPixel(currentX + col, currentY + row, 0x32, 0x32, 0x32);
		}
	}
	snake.updatePosition(snake.getDir());
	if (snake.getX() < 60 || snake.getX() > 740 || snake.getY() < 60 || snake.getY() > 740) {
		gOver = true;
	}


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
}