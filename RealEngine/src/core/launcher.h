#pragma once

#include <GL\glew.h>
#include <GLFW\glfw3.h>

namespace Core {

	class Launcher {
	public:
		Launcher();

		~Launcher();

		int exec();

	private:
		GLFWwindow* window;
	};
}