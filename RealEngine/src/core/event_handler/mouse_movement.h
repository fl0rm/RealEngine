#pragma once

#include <glm.hpp>
#include <GL/glew.h>
#include <SDL3/SDL.h>
#include <boost/signals2.hpp>

namespace Core {

	using SigMove = boost::signals2::signal<void()>;
	
	class MouseMovement {
	public:
		static MouseMovement* Instance(glm::ivec2 size, SDL_Window* win);
		static MouseMovement* GetDisc();
		static SigMove& GetSlot();
		static void DeleteDisc();

		MouseMovement(glm::ivec2 size, SDL_Window* win);

		void UpdatePosition();

		glm::vec2 GetPositionMouse() const { return position; }
	private:
		SDL_Cursor* cursor			= nullptr;
		SDL_Window* active_window	= nullptr;

		glm::vec2	position{};
	};
}