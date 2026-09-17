#include "Camera.h"

Camera::Camera(){
	mPos = Vec3{ 0.0f, 0.0f, 3.0f };
	mTarget = Vec3{ 0.0f, 0.0f, 0.0f };
}

Vec3 Camera::GetDirection() const{
	Vec3 direction = mTarget - mPos;
	Vec3 normalized = direction.Normalize();
	return normalized;
}