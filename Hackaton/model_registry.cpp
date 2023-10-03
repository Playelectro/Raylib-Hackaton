#include "model_registry.h"

ModelRegistry* ModelRegistry::instancePtr = NULL;

void ModelRegistry::LoadMdl(const char* path) {

	Model pot = LoadModel(path);

	models[path] = pot;
}

Model ModelRegistry::GrabModel(const char* path) {

	if (models.find(path) == models.end()) {
		ModelRegistry::getInstance()->LoadMdl(path);
	}
	// TODO Add a recent textures folder that keeps the texture loaded to the gpu in case of instancing
	return models[path];
}

Model ModelRegistry::GrabModel(int type, float a, float b, float c) {

	std::string shape;

	switch (type) {
		case 1:
			default:
				shape = "sphere";
	}

	if (models.find(shape.c_str()) == models.end()) {
		models[shape.c_str()] = LoadModelFromMesh(GenMeshSphere(a, b, c));
	}
	// TODO Add a recent textures folder that keeps the texture loaded to the gpu in case of instancing
	return models[shape.c_str()];
}