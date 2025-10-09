
#include "launcher.h"




namespace Core {

	// Defualt Constructor
	//------------------------------
	Launcher::Launcher() {

		// Instanse GLFW
		//------------------------------
		if (!glfwInit())
			return;

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		// Instanse description monitor
		//------------------------------
		used_monitor = glfwGetPrimaryMonitor();
		if (!used_monitor)
			return;

		// Instanse monitor size
		//------------------------------
		const GLFWvidmode* vid_mode = glfwGetVideoMode(used_monitor);
		if (!vid_mode)
			return;

		width	= vid_mode->width;
		height	= vid_mode->height;

		// Create window
		//------------------------------
		window = glfwCreateWindow(width, height, "Real Engine", nullptr, nullptr);

		if (!window)
			return ;

		glfwMakeContextCurrent(window);

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
		glfwTerminate();
		if (output_frame)
			delete output_frame;
	}

	int Launcher::exec() {

		

		// Main cycle
		//------------------------------
		while (!glfwWindowShouldClose(window)) {
			glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			output_frame->Draw();

			glfwSwapBuffers(window);
			glfwPollEvents();
		}

		return 0;
	}
}