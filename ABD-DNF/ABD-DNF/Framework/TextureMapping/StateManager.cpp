#include "framework.h"
#include "StateManager.h"

StateManager* StateManager::_instance = nullptr;

StateManager::StateManager()
{
	_alpha = make_shared<BlendState>();
	_alpha->Alpha();

	_additive = make_shared<BlendState>();
	_additive->Additive();

	_blend = make_shared<BlendState>();

	_sampler = make_shared<SamplerState>();

	
	D3D11_RASTERIZER_DESC desc = {};

	desc.CullMode = D3D11_CULL_NONE;
	desc.FillMode = D3D11_FILL_SOLID;


	DEVICE->CreateRasterizerState(&desc, &_rasterizerstate);

	DC->RSSetState(_rasterizerstate);

}

StateManager::~StateManager()
{
}
