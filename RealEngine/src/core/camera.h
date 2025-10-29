#pragma once

#include <GL/glew.h>
#include <glm.hpp>

namespace Core {

	class Camera {
	public:
		Camera();

		Camera(glm::vec4 position_, glm::vec4 direction_);

		~Camera() {}

		void Transformation	(glm::mat4 transformation_matrix_);

		glm::mat4 GetView() { return outputmat; }
	private:

		void FormedViewMat();

		glm::vec4 position;
		glm::vec4 direction;
		glm::vec4 camera_up;

		glm::mat4 view;
		glm::mat4 proj;
		glm::mat4 outputmat;

		GLfloat	fov;

		
	};
}