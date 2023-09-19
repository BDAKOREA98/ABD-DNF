#include "framework.h"
#include "DNF_2.h"

DNF_2::DNF_2()
{
	_map = make_shared<Map2>();
	
	_mob1 = make_shared<Mob_Tau>();
	
	
}

DNF_2::~DNF_2()
{
}

void DNF_2::Update()
{
	///CAMERA->SetTarget(PLAYER->GetCol()->GetTransform());
	///CAMERA->SetLeftBottom(_map->leftBottom());
	///CAMERA->SetRightTop(_map->rightTop());
	MapCollision();
	
	_mob1->Update();
	_map->Update();
	//PLAYER->Update();
	CAMERA->Update();

}

void DNF_2::Render()
{
	_mob1->Render();
	_map->Render();
	PLAYER->Render();
}

void DNF_2::PostRender()
{
	
	PLAYER->PostRender();
	_map->PostRender();
}

void DNF_2::Monstermove()
{
	if (PLAYER->Hp() > 0.0f);
	
}

void DNF_2::MapCollision()
{
	if (_map->GetBottom()->Block(PLAYER->GetCol()))
	{


		


	}
	if (_map->GetLeft()->Block(PLAYER->GetCol()))
	{

		SCENE->PrevScene();
	}
	if (_map->GetRight()->Block(PLAYER->GetCol()))
	{
		

	}
	if (_map->GetTop()->Block(PLAYER->GetCol()))
	{


	}

	{
		PLAYER->GetAttack()->SetColorGreen();

	}
	
}

void DNF_2::Attack()
{
	



}
