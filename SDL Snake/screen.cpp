#include <iostream>
#include "Screen.h"
#include "Snake.h"

namespace sf {

	Screen::Screen() : m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer1(NULL) {

	}
	bool Screen::init() {
		// Set const screen dimensions
		const int SCREEN_WIDTH = 1280;
		const int SCREEN_HEIGHT = 800;

		// Check if SDL initialized properly. SDL_Init will return < 0 if it failed.
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
			return false;
		}
		// Sets a pointer to window, and creates a window (Title, window xpos, window ypos, screen width, screen height, window param(see ref))
		m_window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		// Checks to make sure window loaded properly, returns error if not
		if (m_window == NULL) {
			SDL_Quit();
			return false;
		}

		// Creates a 2D rendering context for window
		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
		// Creates texture for rendering context
		m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

		// Checks to see if renderer and texture loads, exits with error if not.
		if (m_renderer == NULL) {
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}
		if (m_texture == NULL) {
			SDL_DestroyRenderer(m_renderer);
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}

		m_buffer1 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT]; // Allocate memory for all pixels in program

		memset(m_buffer1, 50, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32)); // Sets all pixel memory to dark grey once update is called


		return true;
	}

	bool Screen::processEvents() {
		SDL_Event event; // Event listener

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				return false;
			}
		}


		return true;
	}
	void Screen::close() {
		// Destroys window when program is ending, and exits program
		delete[] m_buffer1;
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyTexture(m_texture);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
	}

	void Screen::update() {
		// Update screen information
		SDL_UpdateTexture(m_texture, NULL, m_buffer1, SCREEN_WIDTH * sizeof(Uint32));
		SDL_RenderClear(m_renderer);
		SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
		SDL_RenderPresent(m_renderer);
	}

	void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {

		if (x < 0 || x >= sf::Screen::SCREEN_WIDTH || y < 0 || y >= sf::Screen::SCREEN_HEIGHT) {
			return;
		}

		Uint32 color = 0;

		color += red;
		color <<= 8;
		color += green;
		color <<= 8;
		color += blue;
		color <<= 8;
		color += 0xFF;

		m_buffer1[(y * SCREEN_WIDTH) + x] = color;
	}

	void Screen::drawBoard() {
		
		for (int y = 0; y < SCREEN_HEIGHT; y++) {
			for (int x = 0; x < SCREEN_WIDTH; x++) {
				if (x >= 50 && x <= 751 && y >= 50 && y <= 751) {
					if ((x >= 50 && x <= 51) || (y >= 50 && y <= 51) || (x >= 750 && x <= 751) || (y >= 750 && y <= 751)) {
						setPixel(x, y, 0xFF, 0xFF, 0xFF);					}
				}
				
			}
		}
	}
}
