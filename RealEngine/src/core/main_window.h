#pragma once

#include <SDL3/SDL.h>
#include <GL/glew.h>
#include <glm.hpp>

#include "event_handler/mouse_movement.h"

namespace Core {

	class Window {
	public:
		static Window* Instance();
		static Window* GetDisc();
		static void Delete();

		Window();
		~Window();

		SDL_Window* GetWinDisc() { return window; }
		glm::ivec2	GetWinSize();

		void SwapWinBuf();

		void UpdateEventListener();
		void EventHandler(bool& status);

	private:
		SDL_Window*		window	= nullptr;
		SDL_GLContext	context;
		SDL_Event		event;
		const SDL_DisplayMode* display_mode;

		MouseMovement*	mouse_listener	= nullptr;
	};
}