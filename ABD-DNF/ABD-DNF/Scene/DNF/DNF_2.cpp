#include "framework.h"
#include "DNF_2.h"

DNF_2::DNF_2()
{
	_map = make_shared<Map2>();
	
	
	
	
}

DNF_2::~DNF_2()
{
}

void DNF_2::Update()
{
	
	
	
	_map->Update();
	PLAYER->Update();
	CAMERA->Update();

}

void DNF_2::Render()
{
	_map->Render();
	PLAYER->Render();
}

void DNF_2::PostRender()
{
	
	PLAYER->PostRender();
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
