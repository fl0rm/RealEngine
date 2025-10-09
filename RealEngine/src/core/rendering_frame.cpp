
#include "rendering_frame.h"

#include "../shader/shader_gen.h"

namespace Core {

	RenderingFrame::RenderingFrame() {
		glGenVertexArrays(1, &vao);
		glGenBuffers(1, &vbo);
	}

	RenderingFrame::RenderingFrame(glm::uvec2 win_size) {
		glGenVertexArrays(1, &vao);
		glGenBuffers(1, &vbo);

		count_of_vertices = 3;
		float vertices [] = {
			1.0f,1.0f,
			-1.0f,1.0f,
			-1.0f, -1.0f
		};

		glBindVertexArray(vao);

		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (void*)0);
		glEnableVertexAttribArray(0);

		GLuint shader = Shader::Generator::GetShader();
		glUseProgram(shader);
	}

	RenderingFrame::~RenderingFrame() {

		glDeleteVertexArrays(1, &vao);
		glDeleteBuffers(1, &vbo);

		delete [] vertices;
		count_of_vertices = 0;
	}

	void RenderingFrame::Draw() {

		glDrawArrays(GL_TRIANGLES, 0, 3);

	}
}