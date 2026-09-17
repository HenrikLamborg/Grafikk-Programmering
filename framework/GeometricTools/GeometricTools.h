#pragma once

#include <array>

namespace GeometricTools {

	constexpr std::array<float, 3 * 2> Triangle2D = {
		-0.5f, -0.5f,
		 0.5f, -0.5f,
		 0.0f,  0.5f
	};

	// 2D Square with vertex color (rgb)
	constexpr std::array<float, 6 * 5> Square2D = {
		-0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
		 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
		 0.5f,  0.5f, 0.0f, 0.0f, 1.0f,

		 0.5f,  0.5f, 0.0f, 0.0f, 1.0f,
		-0.5f,  0.5f, 0.0f, 1.0f, 0.0f,
		-0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
	};

	constexpr std::array<float, 4 * 5> Square2DIndexed = {
		-0.5f, -0.5f,  1.0f, 0.0f, 0.0f, // 0
		0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  // 1
		-0.5f,  0.5f,  0.0f, 0.0f, 1.0f, // 2
		0.5f,  0.5f,  1.0f, 1.0f, 0.0f   // 3

	};

	constexpr std::array<unsigned int, 6> Square2DIndices = {
	0, 1, 3,
	0, 3, 2
	};
}