#pragma once

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include "rendering_frame.h"

namespace Core {

	namespace {
		GLuint width;
		GLuint height;
	}

	class Launcher {
	public:
		Launcher();

		~Launcher();

		int exec();

	private:
		GLFWwindow* window				= nullptr;
		GLFWmonitor* used_monitor		= nullptr;

		RenderingFrame* output_frame	= nullptr;
	};
}