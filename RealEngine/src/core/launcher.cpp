
#include "launcher.h"

#include <SDL3/SDL_opengl.h>


namespace Core {

	// Defualt Constructor
	//------------------------------
	Launcher::Launcher() {

		// Instanse SDL
		//------------------------------
		SDL_Init(SDL_INIT_VIDEO);

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

		// Instanse description monitor
		//------------------------------
		display_mode = SDL_GetCurrentDisplayMode(1);

		// Instanse monitor size
		//------------------------------
		
		width	= display_mode->w;
		height	= display_mode->h;

		// Create window
		///------------------------------
		window = SDL_CreateWindow("RealEngine", width, height, SDL_WINDOW_OPENGL);

		if (!window)
			return ;

		context = SDL_GL_CreateContext(window);

		// Instanse GLEW
		//------------------------------
		glewExperimental = GL_TRUE;
		if (glewInit() != GLEW_OK)
			return;

		// Instanse other class
		//------------------------------
		output_frame = new RenderingFrame({width, height});
	}

	// Destuctor
	//------------------------------
	Launcher::~Launcher() {
		SDL_GL_DestroyContext(context);
		SDL_Quit();
		
		if (output_frame)
			delete output_frame;
	}

	// Main executable func
	//------------------------------
	int Launcher::exec() {



		// Main cycle
		//------------------------------
		SDL_Event windowEvent;
		while (true) {
			glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			if (SDL_PollEvent(&windowEvent))
			{
				if (windowEvent.type == SDL_EVENT_QUIT) break;

			}

			output_frame->Draw();

			SDL_GL_SwapWindow(window);
		}

		return 0;
	}
}