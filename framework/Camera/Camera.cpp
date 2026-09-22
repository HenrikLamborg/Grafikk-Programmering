#include "Camera.h"

Camera::Camera(){
	mPos = Vec3{ 2.0f, 1.0f, 3.0f }; // Camera position
	mTarget = Vec3{ 0.0f, 0.0f, 0.0f };
}

Vec3 Camera::GetDirection() const{
	Vec3 direction = mTarget - mPos;
	Vec3 normalized = direction.Normalize();
	return normalized;
}

Vec3 Camera::GetRight() const {
	Vec3 forward = GetDirection();
	Vec3 worldUp = { 0.0f, 1.0f, 0.0f };

	Vec3 right = forward.Cross(worldUp);

	return right;
}

Vec3 Camera::GetUp() const {
	Vec3 right = GetRight();
	Vec3 forward = GetDirection();

	Vec3 up = right.Cross(forward);

	return up;
}

Mat4 Camera::GetViewMatrix() const
{
    Vec3 forward = GetDirection();
    Vec3 right = GetRight();
    Vec3 up = GetUp();

    Mat4 view;

    view.At(0, 0) = right.x;
    view.At(1, 0) = right.y;
    view.At(2, 0) = right.z;
    view.At(3, 0) = 0.0f;

    view.At(0, 1) = up.x;
    view.At(1, 1) = up.y;
    view.At(2, 1) = up.z;
    view.At(3, 1) = 0.0f;

    view.At(0, 2) = -forward.x;
    view.At(1, 2) = -forward.y;
    view.At(2, 2) = -forward.z;
    view.At(3, 2) = 0.0f;

    view.At(0, 3) = -right.Dot(mPos);
    view.At(1, 3) = -up.Dot(mPos);
    view.At(2, 3) = forward.Dot(mPos);
    view.At(3, 3) = 1.0f;

    return view;
}