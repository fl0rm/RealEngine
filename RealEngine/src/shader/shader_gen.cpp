
#include "shader_gen.h"

#include <fstream>
#include <sstream>
#include <string>

#include <GL\glew.h>

namespace Shader {

	GLuint Generator::GetShader(std::string name) {

		GLuint vertex_shader = CompileShader(GL_VERTEX_SHADER, "src\\shader\\" + name + ".vert");

		GLuint fragment_shader = CompileShader(GL_FRAGMENT_SHADER, "src\\shader\\" + name + ".frag");

		GLuint shader = glCreateProgram();

		glAttachShader(shader, vertex_shader);
		glAttachShader(shader, fragment_shader);
		glBindFragDataLocation(shader, 0, "outColor");
		glLinkProgram(shader);

		glDeleteShader(vertex_shader);
		glDeleteShader(fragment_shader);

		return shader;
	}

	GLuint Generator::CompileShader(GLenum shader_type, std::string dir) {
		std::string str_code = ReadFile(dir);
		const GLchar* sourse_code = str_code.c_str();

		GLuint shader = glCreateShader(shader_type);
		glShaderSource(shader, 1, &sourse_code, NULL);
		glCompileShader(shader);

		return shader;
	}


	std::string Generator::ReadFile(std::string dir) {
		std::ifstream file(dir);
		std::stringstream text;
		std::string str;

		text << file.rdbuf();
		
		file.close();

		str = text.str();

		return str;
	}

}