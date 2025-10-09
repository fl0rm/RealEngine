#pragma once

#include <GL\glew.h>
#include <glm.hpp>

namespace Object {

	class BasicObject {
	protected:

		BasicObject() : center{} {}

		BasicObject(glm::vec3 center) : center{ center } {}

	private:
		glm::vec3 center;
	};
}