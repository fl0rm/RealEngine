#pragma once

#include <iostream>

#include <GL\glew.h>

namespace Shader {

	class Generator {
	public:
		static GLuint GetShader(std::string name = "defualt");
	private:
		static GLuint CompileShader(GLenum shader_type, std::string dir);
		static std::string ReadFile(std::string dir);
	};
}