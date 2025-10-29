
#include "rendering_frame.h"

#include <gtc/type_ptr.hpp>

#include "../shader/shader_gen.h"

namespace Core {

	RenderingFrame::RenderingFrame(glm::uvec2 win_size) : source_video_stream{} {
		glGenVertexArrays(1, &vao);
		glGenBuffers(1, &vbo);

		count_of_vertices = 18;
		vertices = new GLfloat[18];
		vertices[0] = 1.0f;
		vertices[1] = 1.0f;
		vertices[2] = 0.0f;
		vertices[3] = 1.0f;
		vertices[4] = 0.0f;
		vertices[5] = 0.0f;
		vertices[6] = 0.0f;
		vertices[7] = 0.0f;
		vertices[8] = 0.0f;
		vertices[9] = 1.0f;
		vertices[10] = 1.0f;
		vertices[11] = 0.0f;
		vertices[12] = 0.0f;
		vertices[13] = 1.0f;
		vertices[14] = 0.0f;
		vertices[15] = 0.0f;
		vertices[16] = 0.0f;
		vertices[17] = 0.0f;
		

		glBindVertexArray(vao);

		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, 18 * sizeof(GLfloat), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
		glEnableVertexAttribArray(0);

		GLuint shader = Shader::Generator::GetShader();
		glUseProgram(shader);

		view = glGetUniformLocation(shader, "view");

		source_video_stream = new Camera();

		glUniformMatrix4fv(view, 1, GL_FALSE, glm::value_ptr(source_video_stream->GetView()));

	}

	RenderingFrame::~RenderingFrame() {

		glDeleteVertexArrays(1, &vao);
		glDeleteBuffers(1, &vbo);

		delete [] vertices;
		delete [] source_video_stream;
		count_of_vertices = 0;
	}

	void RenderingFrame::Draw() {

		glDrawArrays(GL_TRIANGLES, 0, 6);

	}
}