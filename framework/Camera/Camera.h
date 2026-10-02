#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public: 
	Camera();

	glm::mat4 GetViewMatrix() const;
	float GetZoom() const;

	void MoveForward(float distance);
	void MoveBackward(float distance);
	void MoveLeft(float distance);
	void MoveRight(float distance);
	void MoveUp(float distance);
	void MoveDown(float distance);

	void ProcessMouseMovement(float xOffset, float yOffset);
	void ProcessMouseScroll(float yOffset);
	
private:
	void UpdateCameraVectors();

	glm::vec3 mPosition;
	glm::vec3 mFront;
	glm::vec3 mUp;
	glm::vec3 mRight;
	glm::vec3 mWorldUp;

	float mYaw;
	float mPitch;

	float mMovementSpeed;
	float mMouseSensitivity;
	float mZoom;
};