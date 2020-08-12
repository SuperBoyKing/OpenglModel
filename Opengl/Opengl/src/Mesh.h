#pragma once
#ifndef MESH_H
#define MESH_H

#include <glm/glm.hpp>
#include <GL/glew.h>

#include <string>
#include <vector>

#include "Shader.h"
#include "Renderer.h"


using namespace std;

struct Vertex {
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
	glm::vec3 Tangent;
	glm::vec3 Bitangent;
};

struct Texture {
	unsigned int id;
	string type;
	string path;
};

class Mesh {
public:
	vector<Vertex>		 vertices;
	vector<unsigned int> indices;
	vector<Texture>      textures;
	unsigned int m_VAO;

	Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures);
	void Draw(Shader& shader);

private:
	unsigned int m_VBO, m_EBO;
	void setupMesh();
};

#endif

