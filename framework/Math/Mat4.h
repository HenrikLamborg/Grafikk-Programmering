#pragma once

#include <array>
#include <cmath>

struct Mat4 {
	Mat4() {
		matrix = {0.0f};
		matrix[0] = 1.0f;
		matrix[5] = 1.0f;
		matrix[10] = 1.0f;
		matrix[15] = 1.0f;
	}

	std::array<float, 4 * 4> matrix;

    float& At(int row, int column) {
        return matrix[column * 4 + row];
    }

    float At(int row, int column) const {
        return matrix[column * 4 + row];
    }

    Mat4 operator*(const Mat4& other) const {
        Mat4 result;

        for (int row = 0; row < 4; row++) {
            for (int column = 0; column < 4; column++) {
                for (int k = 0; k < 4; k++) {
                    result.At(row, column) +=
                        At(row, k) * other.At(k, column);
                }
            }
        }

        return result;
    }

    static Mat4 Perspective(
        float fovDegrees,
        float aspect,
        float nearPlane,
        float farPlane
    ) {
        Mat4 result;

        float fovRadians = fovDegrees * 3.14159265359f / 180.0f;
        float tanHalfFov = std::tan(fovRadians / 2.0f);

        result.At(0, 0) = 1.0f / (aspect * tanHalfFov);
        result.At(1, 1) = 1.0f / tanHalfFov;

        result.At(2, 2) =
            -(farPlane + nearPlane) /
            (farPlane - nearPlane);

        result.At(2, 3) =
            -(2.0f * farPlane * nearPlane) /
            (farPlane - nearPlane);

        result.At(3, 2) = -1.0f;
        result.At(3, 3) = 0.0f;

        return result;
    }

};