#pragma once

#include <cmath>

struct Vec3
{
	float x;
	float y;
	float z;

	Vec3 operator-(const Vec3& other) const
	{
		float x1 = x - other.x;
		float y1 = y - other.y;
		float z1 = z - other.z;

		Vec3 result = { x1, y1, z1 };
	
		return result;
	}

	float Length() const {
		
		float len = sqrt(x * x + y * y + z * z);
		return len;
	}

	Vec3 Normalize() const {
		float len = Length();

		if (len == 0.0f) {
			return *this;
		}

		float xN = x / len;
		float yN = y / len;
		float zN = z / len;

		return { xN, yN, zN };
	}

	float Dot(const Vec3& other) const {
		float res =
			(x * other.x) +
			(y * other.y) +
			(z * other.z);

		return res;
	}

	Vec3 Cross(const Vec3& other) const {
		Vec3 product = {
			(y * other.z) - (z * other.y),
			(z * other.x) - (x * other.z),
			(x * other.y) - (y * other.x)
		};
		return product;
	}

};