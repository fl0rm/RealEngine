#pragma once

#include <GL/glew.h>
#include <SDL3/SDL.h>

#include "main_window.h"
#include "rendering_frame.h"
#include "event_handler/mouse_movement.h"

namespace Core {

	class Launcher {
	public:
		Launcher();

		~Launcher();

		int exec();

	private:
		Window*			window			= nullptr;
		RenderingFrame* output_frame	= nullptr;
		MouseMovement*	mouse_listener	= nullptr;
	};
}