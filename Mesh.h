#pragma once
#include <glm\glm.hpp>
#include <GL\glew.h>
#include <vector>
#include "Shader.h"

//TODO: complete mesh handler. write ".dae" loader.
struct Vertex {
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 uvcoord;
};

class Mesh
{
public:
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
	std::vector<Texture> textures;

	Mesh(std::vector<Vertex> vertices, std::vector <GLuint> indices, std::vector<Texture> textures);

	virtual ~Mesh();

	void Draw();
	void setShader(Shader* shader);
private:
	Mesh(const Mesh& other);
	void operator=(const Mesh& other);

	GLuint VAO, VBO, EBO;

	Shader* shader;

	void init();
};

