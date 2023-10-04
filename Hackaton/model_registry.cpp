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

	Mesh mesh;

	switch (type) {
		case 2:
			shape = "cube";
			mesh = GenMeshCube(a, b, c);
			break;
		case 1:
		default:
			shape = "sphere";
			mesh = GenMeshSphere(a, b, c);
			break;
	}

	if (models.find(shape.c_str()) == models.end()) {
		models[shape.c_str()] = LoadModelFromMesh(mesh);
	}
	// TODO Add a recent textures folder that keeps the texture loaded to the gpu in case of instancing
	return models[shape.c_str()];
}