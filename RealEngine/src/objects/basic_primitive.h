#pragma once

#include <GL\glew.h>
#include <glm.hpp>

namespace Object {

	class BasicPrimitive {
	protected:

		BasicPrimitive() : center{} {}

		BasicPrimitive(glm::vec3 center) : center{ center } {}

	private:
		glm::vec3 center;
	};
}