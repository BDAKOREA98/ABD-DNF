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
}

StateManager::~StateManager()
{
}
