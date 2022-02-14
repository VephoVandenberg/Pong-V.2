#include "resourceManager.h"

std::unordered_map<std::string, Shader> ResourceManager::m_shaders;


void ResourceManager::loadShader(const char* vPath, const char *fPath, const char* sName)
{
	Shader shader(vPath, fPath);
	m_shaders[sName] = shader;
}


Shader& ResourceManager::getShader(const char* sName)
{
	return m_shaders[sName];
}
