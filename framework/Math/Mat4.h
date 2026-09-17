#pragma once

#include <array>

struct Mat4 {
	Mat4() {
		matrix = {0.0f};
		matrix[0] = 1.0f;
		matrix[5] = 1.0f;
		matrix[10] = 1.0f;
		matrix[15] = 1.0f;
	}

	std::array<float, 4 * 4> matrix;

    Mat4 operator*(const Mat4& other) const {
        Mat4 result;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    result.matrix[i * 4 + j] +=
                        matrix[i * 4 + k] * other.matrix[k * 4 + j];
                }
            }
        }

        return result;
    }
};