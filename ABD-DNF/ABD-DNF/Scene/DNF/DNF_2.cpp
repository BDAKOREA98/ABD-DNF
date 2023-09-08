#include "framework.h"
#include "DNF_2.h"

DNF_2::DNF_2()
{
	_map = make_shared<Map2>();
	
	//PLAYER->GetCol()->GetTransform()->SetPosition(Vector2(_map->mapX, PlayerScenePos.y));
	
	
}

DNF_2::~DNF_2()
{
}

void DNF_2::Update()
{
	//CAMERA->SetTarget(PLAYER->GetCol()->GetTransform());
	_map->Update();
	//PLAYER->Update();
	CAMERA->Update();

}

void DNF_2::Render()
{
	_map->Render();
	//PLAYER->Render();
}

void DNF_2::PostRender()
{
	
	//PLAYER->PostRender();
	//_map1->PostRender();
}

void DNF_2::Monstermove()
{
	//if (PLAYER->Hp() > 0.0f);
	
}

void DNF_2::MapCollision()
{
	
}

void DNF_2::Attack()
{
	



}
