#pragma once

#include <string>
#include <unordered_map>

#include "shader.h"

class ResourceManager
{
public:
	ResourceManager(ResourceManager& resourceManager) = delete;
	void operator=(const ResourceManager&) = delete;

	static void loadShader(const char *vPath, const char *fPath, const char *sName);
	static Shader& getShader(const char* shaderName);

private:
	ResourceManager();

private:
	static std::unordered_map<std::string, Shader> m_shaders;

};

