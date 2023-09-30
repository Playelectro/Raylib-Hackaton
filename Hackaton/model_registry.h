#pragma once

#include <raylib.h>
#include <unordered_map>
#include <iostream>

class ModelRegistry {

private:
    std::unordered_map<const char*, Model> models;

    static ModelRegistry* instancePtr;

    void LoadMdl(const char*);

    ModelRegistry() {}

public:
    ModelRegistry(const ModelRegistry& obj) = delete;

    static ModelRegistry* getInstance()
    {
        if (instancePtr == NULL)
        {
            instancePtr = new ModelRegistry();
            return instancePtr;
        }
        else
        {
            return instancePtr;
        }
    }

    Model GrabModel(const char*);
};