#include "main_window.h"

namespace Core {

	namespace {
		Window* discription_window = nullptr;

		GLint width;
		GLint height;
	}

	glm::ivec2 Window::GetWinSize() { return { width, height }; }

	Window* Window::GetDisc() { return discription_window; }

	// Creating a window descriptor
	//------------------------------
	Window* Window::Instance() {
		discription_window = new Window();
		return discription_window;
	}

	// Removing the window descriptor
	//------------------------------
	void Window::Delete() {
		if (discription_window)
			delete discription_window;
	}

	// Defualt Constructor
	//------------------------------
	Window::Window() : event{} {

		// Instanse SDL
		//------------------------------
		SDL_Init(SDL_INIT_VIDEO);

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
		SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

		// Instanse description monitor
		//------------------------------
		display_mode = SDL_GetCurrentDisplayMode(1);

		// Instanse monitor size
		//------------------------------

		width = display_mode->w;
		height = display_mode->h;

		//width = 800;
		//height = 600;

		// Create window
		///------------------------------
		window = SDL_CreateWindow("RealEngine", width, height, SDL_WINDOW_OPENGL);

		context = SDL_GL_CreateContext(window);

		// Instanse GLEW
		//------------------------------
		glewExperimental = GL_TRUE;
		if (glewInit() != GLEW_OK)
			return;
	}

	// Destuctor
	//------------------------------
	Window::~Window() {
		SDL_GL_DestroyContext(context);
		SDL_Quit();
	}

	// Updating the window buffer
	//------------------------------
	void Window::SwapWinBuf() {
		SDL_GL_SwapWindow(window);
	}

	// Getting initialized event listeners
	//------------------------------
	void Window::UpdateEventListener() {
		mouse_listener = MouseMovement::GetDisc();
	}

	// Event handler
	//------------------------------
	void Window::EventHandler(bool& status) {
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_EVENT_QUIT)
				status = false;

			if (event.type == SDL_EVENT_MOUSE_MOTION) {
				mouse_listener->UpdatePosition();
			}

		}
	}
}