#pragma once

#include <GL\glew.h>
#include <glm.hpp>

#include "camera.h"

namespace Core {

	namespace {
		GLfloat* vertices;
		GLuint count_of_vertices;
	}

	class RenderingFrame {
	public:
		RenderingFrame(glm::uvec2 win_size);

		~RenderingFrame();

		void Draw();

	private:
		GLuint vbo;
		GLuint vao;

		GLuint view;

		Camera* source_video_stream;
	};
}