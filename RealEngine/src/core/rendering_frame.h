#pragma once

#include <GL\glew.h>
#include <glm.hpp>

namespace Core {

	namespace {
		GLfloat* vertices;
		GLuint count_of_vertices;
	}

	class RenderingFrame {
	public:
		RenderingFrame();

		RenderingFrame(glm::uvec2 win_size);

		~RenderingFrame();

		void Draw();

	private:
		GLuint vbo;
		GLuint vao;
	};
}