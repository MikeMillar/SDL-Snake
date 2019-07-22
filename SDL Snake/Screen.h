#ifndef SCREEN_H
#define SCREEN_H
#include <SDL.h>

namespace sf {

	class Screen {
	private:
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;
		SDL_Texture* m_texture;
		Uint32* m_buffer1;

	public:
		const static int SCREEN_WIDTH = 1280;
		const static int SCREEN_HEIGHT = 800;

	public:
		Screen();
		bool init();
		bool processEvents();
		void close();
		void update();
	};

}
#endif