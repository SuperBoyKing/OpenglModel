#pragma once
#ifndef MODEL_H
#define MODEL_H

#include <iostream>

#include <stb_image/stb_image.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Mesh.h"
#include "Shader.h"

using namespace std;

class Model
{
public:
	vector<Texture> textures_loaded;	// stores all the textures loaded so far, optimization to make sure textures aren't loaded more than once.
	vector<Mesh> meshes;

	Model(string const& path);
	void Draw(Shader& shader);
private:
	string m_directory;
	void loadModel(const string& path);
	void processNode(aiNode* node, const aiScene* scene);
	Mesh processMesh(aiMesh* mesh, const aiScene* scene);
	vector<Texture> loadMeterialTexture(aiMaterial* mat, aiTextureType type, string typeName);
};
#endif
