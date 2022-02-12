#pragma once

#include <string>
#include <unordered_map>

#include "shader.h"

class ResourceManager
{
public:
	ResourceManager(ResourceManager& resourceManager) = delete;
	void operator=(const ResourceManager&) = delete;

	void loadShader(const char *sPath, const char *sName);
	Shader getShader(const char* shaderName);
private:
	ResourceManager();
	static std::unordered_map<std::string, Shader> shaders;

};

