#include "framework.h"
#include "DNF.h"

DNF::DNF()
{
	
	_map1 = make_shared<Map>();
	_player = make_shared<Player>();
	_mob1 = make_shared<Monster_mad>();


	CAMERA->SetTarget(_player->GetTrans());
	CAMERA->SetLeftBottom(_map1->leftBottom());
	CAMERA->SetRightTop(_map1->rightTop());
	
}

DNF::~DNF()
{
}

void DNF::Update()
{
	_mob1->GetMobcol()->GetTransform()->SetPosition(Vector2(0.0f, 0.0f));
	Monstermove();
	MapCollision();
	Attack();
	
	_map1->Update();

	_mob1->Update();

	_player->Update();
	
	

	
	
	


}

void DNF::Render()
{
	_map1->Render();
	_player->Render();
	_mob1->Render();
}

void DNF::PostRender()
{
	_mob1->PostRender();
	_player->PostRender();
	_map1->PostRender();
}

void DNF::Monstermove()
{

	if (_mob1->GetCol()->IsCollision(_player->GetCol()) == false)
	{
		_mob1->SetAction(_mob1->Mob_RUN);

		Vector2 Direction;
		Vector2 MobPos;
		Vector2 PlayerPos;
		MobPos = _mob1->GetCol()->GetTransform()->GetPos();
		PlayerPos = _player->GetCol()->GetTransform()->GetPos();

		Direction = PlayerPos - MobPos;
		Direction.Normalize();



		if (MobPos.x >= PlayerPos.x)
		{
			_mob1->SetLEFT();
		}
		else if (MobPos.x < PlayerPos.x)
		{
			_mob1->SetRIGHT();
		}


		_mob1->GetCol()->GetTransform()->AddVector2(Direction * DELTA_TIME * 250.0f);

	}
	else if (_mob1->GetCol()->IsCollision(_player->GetCol()))
	{

		_mob1->Attack();
	}




	

}

void DNF::MapCollision()
{
	if (_map1->GetBottom()->Block(_player->GetCol()))
	{


		_player->GetCol()->GetTransform()->SetPosition({ _player->GetCol()->GetTransform()->GetPos().x, 2.0 });

	}
	if (_map1->GetLeft()->Block(_player->GetCol()))
	{


	}
	if (_map1->GetRight()->Block(_player->GetCol()))
	{


	}
	if (_map1->GetTop()->Block(_player->GetCol()))
	{


	}

	{
		_player->GetAttack()->SetColorGreen();

	}

}

void DNF::Attack()
{
	Vector2 Direction;
	Vector2 MobPos;
	Vector2 PlayerPos;
	MobPos = _mob1->GetCol()->GetTransform()->GetPos();
	PlayerPos = _player->GetCol()->GetTransform()->GetPos();

	Direction =  MobPos - PlayerPos;
	Direction.Normalize();
	if (_player->AttackT_F() && _player->GetCol()->IsCollision(_mob1->GetCol()))
	{
		_mob1->SetAction(_mob1->Mob_TAKENDAMAGE);
		_mob1->GetCol()->GetTransform()->AddVector2(Direction * 10.0f);

	}
	



}
