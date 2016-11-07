#pragma once
#include <glm\glm.hpp>
#include <tga.h>
#include <GL\glew.h>
#include <vector>
#include <stdint.h>
#include "Utils.h"

class Color {
	Color();
	Color(uint8 r, uint8 g, uint8 b, uint8 a = 255);

	uint8 r;
	uint8 g;
	uint8 b;
	uint8 a;
};

class Texture
{
public:
	Texture();
	Texture(const Texture& other);
	
	void openTGA(const char* path);
	glm::vec2 getSize();

	void flipHorizontally();
	void flipVertically();

private:
	glm::vec2 m_size;
	bool m_isRepeated;
	bool m_isXFlipped;
	bool m_isYFlipped;
	bool m_hasMipmap;
	std::vector<uint8> m_pixels;
};

