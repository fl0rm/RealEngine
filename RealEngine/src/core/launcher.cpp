
#include "launcher.h"

#include <SDL3/SDL_opengl.h>

#include "event_handler/mouse_movement.h"

namespace Core {

	// Defualt Constructor
	//------------------------------
	Launcher::Launcher() {

		// Instanse main elements
		//------------------------------
		window = Window::Instance();

		mouse_listener = MouseMovement::Instance(window->GetWinSize(), window->GetWinDisc());

		output_frame = RenderingFrame::InstanseDiscription(window->GetWinSize());

		window->UpdateEventListener();
	}

	// Destuctor
	//------------------------------
	Launcher::~Launcher() {
		
		MouseMovement::DeleteDisc();

		RenderingFrame::DeleteDiscription();

		Window::Delete();
	}

	// Main executable func
	//------------------------------
	int Launcher::exec() {

		// Main cycle
		//------------------------------
		bool is_running = true;
		while (is_running) {
			glClearColor(0.852f, 0.965f, 0.965f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			window->EventHandler(is_running);

			output_frame->Draw();

			window->SwapWinBuf();
		}

		return 0;
	}
}