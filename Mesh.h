#pragma once
#include <glm\glm.hpp>
#include <GL\glew.h>

class Vertex {
public:
	Vertex(glm::vec3 pos) {
		this->pos = pos;
	}
private:
	glm::vec3 pos;
};

class Mesh
{
public:
	Mesh(Vertex* vertices, unsigned int num_Vertices);

	virtual ~Mesh();

	void Draw();
private:
	Mesh(const Mesh& other);
	void operator=(const Mesh& other);

	GLuint VAO;
	GLuint VBO;
};

