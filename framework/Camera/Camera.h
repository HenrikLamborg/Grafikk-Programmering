#pragma once

#include "Vec3.h"
#include "Mat4.h"

class Camera {
public: 
	Camera();
	Vec3 GetDirection() const;
	Mat4 GetViewMatrix() const;
	Vec3 GetRight() const;
	Vec3 GetUp() const;

private:
	Vec3 mPos;
	Vec3 mTarget;
};