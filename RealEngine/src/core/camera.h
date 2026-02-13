#pragma once

#include <GL/glew.h>
#include <glm.hpp>

namespace Core {

	class Camera {
	public:
		Camera();

		Camera(glm::ivec2 win_size);

		Camera(glm::vec4 position_, glm::vec4 direction_);

		//~Camera() {}

		//------------------------------------------------------------
		//						Get block
		//------------------------------------------------------------

		glm::vec4 GetPosition() const { return position; }
		glm::vec4 GetDirection() const { return direction; }
		glm::mat4 GetView() const { return outputmat; }

		//------------------------------------------------------------
		//						Control block
		//------------------------------------------------------------

		void RotationAsixXY(GLfloat x, GLfloat y);
		void MoveTheCamera(GLfloat x, GLfloat y, GLfloat z);
		void SetCord(glm::vec4 pos);
		void SetDirection(glm::vec4 direction);

		//------------------------------------------------------------
		//						Event block
		//------------------------------------------------------------

		void UpdateCameraPosition();
		void UpdateCameraDirection();
		void ConnectMouseTraking();
		void DisconnectMouseTraking();


	private:

		void CreateAViewMat();

		glm::ivec2 win_size;

		glm::vec4 position;
		glm::vec4 direction;
		glm::vec4 camera_up;

		glm::mat4 view;
		glm::mat4 proj;
		glm::mat4 outputmat;

		GLfloat	fov;

		
	};
}