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

	constexpr std::array<float, 8 * 6> Cube3D = {
		// position            // color
		-0.5f, -0.5f, -0.5f,   1.0f, 0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,   0.0f, 1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,   0.0f, 0.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,   1.0f, 1.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,   1.0f, 0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,   0.0f, 1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,   1.0f, 1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,   0.5f, 0.5f, 0.5f
	};

	constexpr std::array<unsigned int, 36> Cube3DIndices = {
		0, 1, 2,  2, 3, 0, // back
		4, 5, 6,  6, 7, 4, // front
		0, 4, 7,  7, 3, 0, // left
		1, 5, 6,  6, 2, 1, // right
		3, 2, 6,  6, 7, 3, // top
		0, 1, 5,  5, 4, 0  // bottom
	};

	constexpr std::array<float, 24 * 8> Cube3DV2 = {
		// position              // color              // UV
		// Back
		-0.5f, -0.5f, -0.5f,     1.0f, 0.0f, 0.0f,    0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,     0.0f, 1.0f, 0.0f,    1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,     0.0f, 0.0f, 1.0f,    1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,     1.0f, 1.0f, 0.0f,    0.0f, 1.0f,

		// Front
		-0.5f, -0.5f,  0.5f,     1.0f, 0.0f, 1.0f,    0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,     0.0f, 1.0f, 1.0f,    1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,     1.0f, 1.0f, 1.0f,    1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,     0.5f, 0.5f, 0.5f,    0.0f, 1.0f,

		// Left
		-0.5f, -0.5f, -0.5f,     1.0f, 0.0f, 0.0f,    0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,     1.0f, 1.0f, 0.0f,    1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,     0.5f, 0.5f, 0.5f,    1.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,     1.0f, 0.0f, 1.0f,    0.0f, 1.0f,

		// Right
		 0.5f, -0.5f, -0.5f,     0.0f, 1.0f, 0.0f,    0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,     0.0f, 1.0f, 1.0f,    1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,     1.0f, 1.0f, 1.0f,    1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,     0.0f, 0.0f, 1.0f,    0.0f, 1.0f,

		 // Top
		 -0.5f,  0.5f, -0.5f,     1.0f, 1.0f, 0.0f,    0.0f, 0.0f,
		  0.5f,  0.5f, -0.5f,     0.0f, 0.0f, 1.0f,    1.0f, 0.0f,
		  0.5f,  0.5f,  0.5f,     1.0f, 1.0f, 1.0f,    1.0f, 1.0f,
		 -0.5f,  0.5f,  0.5f,     0.5f, 0.5f, 0.5f,    0.0f, 1.0f,

		 // Bottom
		 -0.5f, -0.5f, -0.5f,     1.0f, 0.0f, 0.0f,    0.0f, 0.0f,
		 -0.5f, -0.5f,  0.5f,     1.0f, 0.0f, 1.0f,    1.0f, 0.0f,
		  0.5f, -0.5f,  0.5f,     0.0f, 1.0f, 1.0f,    1.0f, 1.0f,
		  0.5f, -0.5f, -0.5f,     0.0f, 1.0f, 0.0f,    0.0f, 1.0f
	};

	constexpr std::array<unsigned int, 36> Cube3DV2Indices = {
	0, 1, 2,   2, 3, 0,       // back
	4, 5, 6,   6, 7, 4,       // front
	8, 9, 10,  10, 11, 8,     // left
	12, 13, 14, 14, 15, 12,  // right
	16, 17, 18, 18, 19, 16,  // top
	20, 21, 22, 22, 23, 20   // bottom
	};

}