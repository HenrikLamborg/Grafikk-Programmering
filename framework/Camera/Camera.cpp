#include "Camera.h"

Camera::Camera(){
	mPosition = glm::vec3( 0.0f, 0.0f, 3.0f );
	mFront = glm::vec3(0.0f, 0.0f, -1.0f);
	mUp = glm::vec3(0.0f, 1.0f, 0.0f);
    mYaw = -90.0f;
    mPitch = 0.0f;
    mWorldUp = glm::vec3(0.0f, 1.0f, 0.0f);
    mMovementSpeed = 2.0f;
    mMouseSensitivity = 0.05f;
    mZoom = 45.0f;

    UpdateCameraVectors();
}

glm::mat4 Camera::GetViewMatrix() const
{
    return glm::lookAt(
        mPosition,
        mPosition + mFront,
        mUp
    );
}

float Camera::GetZoom() const
{
    return mZoom;
}

void Camera::MoveForward(float distance) {
    mPosition += mFront * distance;
}

void Camera::MoveBackward(float distance) {
    mPosition -= mFront * distance;
}

void Camera::MoveRight(float distance)
{
    mPosition += mRight * distance;
}

void Camera::MoveLeft(float distance)
{
    mPosition -= mRight * distance;
}

void Camera::MoveUp(float distance)
{
    mPosition += mUp * distance;
}

void Camera::MoveDown(float distance)
{
    mPosition -= mUp * distance;
}

void Camera::ProcessMouseMovement(float xOffset, float yOffset)
{
    float sensitivity = 0.05f;

    xOffset *= sensitivity;
    yOffset *= sensitivity;

    mYaw += xOffset;
    mPitch += yOffset;

    if (mPitch > 89.0f)
        mPitch = 89.0f;

    if (mPitch < -89.0f)
        mPitch = -89.0f;

    UpdateCameraVectors();
}

void Camera::UpdateCameraVectors(){
    glm::vec3 front;

    front.x = cos(glm::radians(mYaw)) * cos(glm::radians(mPitch));
    front.y = sin(glm::radians(mPitch));
    front.z = sin(glm::radians(mYaw)) * cos(glm::radians(mPitch));

    mFront = glm::normalize(front);

    mRight = glm::normalize(glm::cross(mFront, mWorldUp));

    mUp = glm::normalize(glm::cross(mRight, mFront));
}

void Camera::ProcessMouseScroll(float yOffset)
{
    mZoom -= yOffset;

    if (mZoom < 1.0f)
        mZoom = 1.0f;

    if (mZoom > 45.0f)
        mZoom = 45.0f;
}