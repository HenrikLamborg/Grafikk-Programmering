#pragma once

#include "Vec3.h"

class Camera {
public: 
	Camera();
	Vec3 GetDirection() const;

private:
	Vec3 mPos;
	Vec3 mTarget;
};