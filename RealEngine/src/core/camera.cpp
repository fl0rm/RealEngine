
#include "camera.h"

#define GLM_ENABLE_EXPERIMENTAL

#include <iostream>
#include <gtc/matrix_transform.hpp>
#include <gtx/vector_angle.hpp>

#include "event_handler/mouse_movement.h"

namespace Core {

	Camera::Camera() : win_size{800, 600}, position { 0.0f, -2.0f, 2.0f, 1.0f }, direction{ 0.0f, 1.0f, -1.0f , 0.0f }, camera_up{ 0.0f, 0.0f, 1.0f, 0.0f }, fov{ 60.0f } {

		CreateAViewMat();
	
	}

	Camera::Camera(glm::ivec2 win_size) : win_size{win_size}, position { 0.0f, 5.0f, 2.0f, 1.0f }, direction{ 0.0f, -1.0f, 0.0f , 0.0f }, camera_up{ 0.0f, 0.0f, 1.0f, 0.0f }, fov{ 60.0f } {

		CreateAViewMat();
	
	}

	Camera::Camera(glm::vec4 position_, glm::vec4 direction_) : position{ position_ }, direction{ direction_ }, camera_up{ 0.0f, 0.0f, 1.0f, 0.0f }, fov{ 60.0f } {

		CreateAViewMat();

	}


	//------------------------------------------------------------
	// 
	//				This block is resposible for
	//							math
	// 
	//------------------------------------------------------------

	void Camera::SetCord(glm::vec4 pos) {

		position = pos;

		CreateAViewMat();
	}
	void Camera::SetDirection(glm::vec4 direction) {

		this->direction = direction;

		CreateAViewMat();
	}
	void Camera::MoveTheCamera(GLfloat x, GLfloat y, GLfloat z) {

		position.x = position.x + x;
		position.y = position.y + y;
		position.z = position.z + z;

		CreateAViewMat();
	}

	void Camera::RotationAsixXY(GLfloat x, GLfloat y) {

		GLfloat anglX =  - glm::atan((x * glm::tan(fov / 2)) / win_size.x);
		GLfloat anglY = glm::atan((y * glm::tan(fov / 2)) / win_size.y);


		glm::mat4 rotX(1.0f);
		glm::mat4 rotY(1.0f);
		
		rotX[0][0] = glm::cos(anglX);
		rotX[1][1] = glm::cos(anglX);
		rotX[0][1] = -glm::sin(anglX);
		rotX[1][0] = glm::sin(anglX);

		if (glm::angle(glm::normalize(glm::vec3(direction)), glm::normalize(glm::vec3(direction.x, direction.y, 0))) + anglY < 90.0f) {
			
			rotY[2][2] = glm::cos(anglY);
			rotY[1][1] = glm::cos(anglY);
			rotY[2][1] = glm::sin(anglY);
			rotY[1][2] = -glm::sin(anglY);
		}

		direction = rotX * rotY * direction;

		CreateAViewMat();
	}

	void Camera::CreateAViewMat() {
		view = glm::lookAt(glm::vec3(position), glm::vec3(position) + glm::vec3(direction), glm::vec3(camera_up));
		proj = glm::perspective(glm::radians(fov), static_cast<GLfloat>(win_size.x / win_size.y), 0.1f, 20.0f);


		outputmat = proj * view;
	}


	//------------------------------------------------------------
	// 
	//				This block is resposible for
	//						event support
	// 
	//------------------------------------------------------------

	void Camera::UpdateCameraDirection() {
		RotationAsixXY(MouseMovement::GetDisc()->GetPositionMouse().x, MouseMovement::GetDisc()->GetPositionMouse().y);
	}

	void Camera::ConnectMouseTraking() {
		MouseMovement::GetSlot().connect([=] { this->UpdateCameraDirection(); });
	}

	void Camera::DisconnectMouseTraking() {
		//MouseMovement::GetSlot().disconnect([=] { this->Update(); });
	}

	void Camera::UpdateCameraPosition() {
		
	}
}