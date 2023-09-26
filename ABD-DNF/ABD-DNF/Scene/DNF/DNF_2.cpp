#include "framework.h"
#include "DNF_2.h"

DNF_2::DNF_2()
{
	_map = make_shared<Map2>();
	
	_mob1 = make_shared<Mob_Tau>();
	_mob1->GetCol()->GetTransform()->SetPosition(_map->GetTrans()->GetPos());
	
}

DNF_2::~DNF_2()
{
}

void DNF_2::Update()
{

	if (KEY_DOWN(VK_LBUTTON))
	{
		PLAYER->GetCol()->GetTransform()->SetPosition(_map->GetTrans()->GetPos() - Vector2(-200, 0));
		PLAYER->MOVE();
	}

	CAMERA->SetTarget(_mob1->GetCol()->GetTransform());
	cameraMove += DELTA_TIME;

	if (cameraMove >= 8.0f)
	{
		CAMERA->SetTarget(PLAYER->GetTrans());
	}

	CAMERA->SetLeftBottom(_map->leftBottom());
	CAMERA->SetRightTop(_map->rightTop());
	MapCollision();
	
	_mob1->Update();
	_map->Update();
	PLAYER->Text = true;
	PLAYER->Update();
	CAMERA->Update();
	Battle();
}

void DNF_2::Render()
{
	_map->Render();
	_mob1->Render();
	PLAYER->Render();
}

void DNF_2::PostRender()
{
	_mob1->PostRender();
	//PLAYER->PostRender();
	//_map->PostRender();
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

void DNF_2::Battle()
{
	if (PLAYER->GetAttack()->IsCollision(_mob1->GetCol()))
	{

		_mob1->TakenDamage();
		//PLAYER->GetAttack()->GetTransform()->SetPosition({ 0.0f,0.0f });
	}
	else
	{
		//_mob1->SetAction(_mob1->Tau_IDLE);
	}

}

