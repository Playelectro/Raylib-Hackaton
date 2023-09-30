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