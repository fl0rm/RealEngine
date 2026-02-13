#include "mouse_movement.h"

#include <SDL3/SDL.h>
#include <GL/glew.h>

namespace Core {

	namespace {
		MouseMovement* discription_mouse = nullptr;

		SigMove EventMove;
	}// namespace


	MouseMovement* MouseMovement::GetDisc() { return discription_mouse; }

	SigMove& MouseMovement::GetSlot() { return EventMove; }

	MouseMovement* MouseMovement::Instance(glm::ivec2 size, SDL_Window* win) {
		discription_mouse = new MouseMovement(size, win);
		return discription_mouse;
	}

	void MouseMovement::DeleteDisc() {
		if (discription_mouse)
			delete discription_mouse;
	}


	// Constructor
	//------------------------------
	MouseMovement::MouseMovement(glm::ivec2 size, SDL_Window* win) {
		active_window = win;
		cursor = SDL_GetCursor();

		SDL_SetWindowRelativeMouseMode(active_window, true);

	}

	void MouseMovement::UpdatePosition() {

		SDL_GetRelativeMouseState(&position.x, &position.y);

		EventMove();
	}
}