#pragma once

#include <GL\glew.h>
#include <SDL3/SDL.h>

#include "rendering_frame.h"

namespace Core {

	namespace {
		GLuint width;
		GLuint height;
	}

	class Launcher {
	public:
		Launcher();

		~Launcher();

		int exec();

	private:
		SDL_Window*		window			= nullptr;
		SDL_GLContext	context;
		const SDL_DisplayMode* display_mode;

		RenderingFrame* output_frame	= nullptr;
	};
}