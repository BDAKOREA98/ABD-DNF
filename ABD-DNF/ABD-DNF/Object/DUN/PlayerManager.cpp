#include "framework.h"
#include "PlayerManager.h"
#include "Player.h"
PlayerManager* PlayerManager::_instance = nullptr;
Player* PlayerManager::player = nullptr;



void PlayerManager::Update()
{
	player->Update();
}

void PlayerManager::PostRender()
{
	player->PostRender();
}

void PlayerManager::Render()
{
	player->Render();
}
