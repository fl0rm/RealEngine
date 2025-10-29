
#include "camera.h"

#include <gtc/matrix_transform.hpp>

namespace Core {

	Camera::Camera() : position{0.0f, -2.0f, 2.0f ,1.0f }, direction{ 0.0f, 1.0f, -1.0f , 0.0f }, camera_up { 0.0f, 0.0f, 1.0f, 0.0f }, fov { 60.0f } {

		FormedViewMat();
	
	}

	Camera::Camera(glm::vec4 position_, glm::vec4 direction_) : position{ position_ }, direction{ direction_ }, camera_up{ 0.0f, 0.0f, 1.0f, 0.0f }, fov{ 60.0f } {

		FormedViewMat();

	}

	void Camera::Transformation(glm::mat4 transformation_matrix_) {
		position = transformation_matrix_ * position;
		direction = transformation_matrix_ * direction;

		FormedViewMat();
	}

	void Camera::FormedViewMat() {
		view = glm::lookAt(glm::vec3(position), glm::normalize(glm::vec3(position)) + glm::normalize(glm::vec3(direction)), glm::vec3(camera_up));
		proj = glm::perspective(glm::radians(fov), 1920.0f / 1080.0f, 0.1f, 20.0f);


		outputmat = proj * view;
	}

}