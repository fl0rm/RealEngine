#pragma once

#include <GL\glew.h>
#include <glm.hpp>

#include "camera.h"
//#include "mouse_movement.h"

namespace Core {

	class RenderingFrame;

	namespace {
		RenderingFrame* discription_frame = nullptr;

		GLfloat* vertices;
		GLuint count_of_vertices;
	}

	class RenderingFrame {
	public:

		static RenderingFrame* InstanseDiscription(glm::ivec2 size);
		static void DeleteDiscription();

		RenderingFrame(glm::ivec2 win_size);

		~RenderingFrame();

		void Draw();

	private:
		GLuint vbo;
		GLuint vao;

		GLuint view;

		Camera* source_video_stream;
	};
}