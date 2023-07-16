#include "framework.h"
#include "ShaderManager.h"

ShaderManager* ShaderManager::_instance = nullptr;
ShaderManager::ShaderManager()
{
}

ShaderManager::~ShaderManager()
{
}

shared_ptr<PixelShader> ShaderManager::Add_Ps(wstring path)
{
	if (_shaderTable.count(path) != 0)
		return dynamic_pointer_cast<PixelShader>(_shaderTable[path]);

	shared_ptr<PixelShader> ps = make_shared<PixelShader>(path);
	_shaderTable[path] = ps;

	return ps;
}

shared_ptr<VertexShader> ShaderManager::Add_Vs(wstring path)
{
	if (_shaderTable.count(path) != 0)
		return dynamic_pointer_cast<VertexShader>(_shaderTable[path]);

	shared_ptr<VertexShader> vs = make_shared<VertexShader>(path);
	_shaderTable[path] = vs;

	return vs;
}
