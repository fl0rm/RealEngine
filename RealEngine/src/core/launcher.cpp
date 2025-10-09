
#include "launcher.h"


namespace Core {

	Launcher::Launcher() : window{} {

		if (!glfwInit())
			return;

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		glewExperimental = GL_TRUE;
		if (glewInit() != GLEW_OK)
			return;

	}

	Launcher::~Launcher() {
		glfwTerminate();
	}

	int Launcher::exec() {


		window = glfwCreateWindow(600, 400, "Real Engine", nullptr, nullptr);

		if (!window)
			return -1;

		glfwMakeContextCurrent(window);

		while (!glfwWindowShouldClose(window)) {


			glfwSwapBuffers(window);
			glfwPollEvents();
		}

		return 0;
	}
}