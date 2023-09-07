#include "framework.h"
#include "DNF_2.h"

DNF_2::DNF_2()
{
	_map = make_shared<Map2>();
	_player = make_shared<Player>();
	_player->GetCol()->GetTransform()->SetPosition(Vector2(_map->mapX, PlayerScenePos.y));
	
	_mob1 = make_shared<Monster_mad>();
}

DNF_2::~DNF_2()
{
}

void DNF_2::Update()
{
	CAMERA->SetTarget(_player->GetCol()->GetTransform());
	_map->Update();
	_player->Update();
	CAMERA->Update();

}

void DNF_2::Render()
{
	_map->Render();
	_player->Render();
}

void DNF_2::PostRender()
{
	_mob1->PostRender();
	_player->PostRender();
	//_map1->PostRender();
}

void DNF_2::Monstermove()
{
	if (_player->Hp() > 0.0f)
	{
		if (_mobMove == true)
		{
			if (_mob1->GetMovecol()->IsCollision(_player->GetCol()) == false)
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
			else if (_mob1->GetMovecol()->IsCollision(_player->GetCol()))
			{

				_mob1->Attack(_player->GetCol());
			}


		}

	}
	else if (_player->Hp() <= 0.0f)
	{
		_mob1->SetAction(_mob1->Mob_IDLE);
	}

}

void DNF_2::MapCollision()
{
	if (_map->GetBottom()->Block(_player->GetCol()))
	{


		_player->GetCol()->GetTransform()->SetPosition({ _player->GetCol()->GetTransform()->GetPos().x, 2.0 });


	}
	if (_map->GetLeft()->Block(_player->GetCol()))
	{


	}
	if (_map->GetRight()->Block(_player->GetCol()))
	{
		SCENE->NextScene();
		PlayerScenePos = _player->GetCol()->GetTransform()->GetPos();

	}
	if (_map->GetTop()->Block(_player->GetCol()))
	{


	}

	{
		_player->GetAttack()->SetColorGreen();

	}

}

void DNF_2::Attack()
{
	Vector2 Direction;
	Vector2 MobPos;
	Vector2 PlayerPos;
	MobPos = _mob1->GetCol()->GetTransform()->GetPos();
	PlayerPos = _player->GetCol()->GetTransform()->GetPos();

	Direction = MobPos - PlayerPos;
	Direction.Normalize();

	if (_mob1->Hp() > 0.0f)
	{
		if (_player->AttackT_F() && _player->GetAttack()->IsCollision(_mob1->GetCol()))
		{
			//Direction = MobPos - PlayerPos;
			//Direction.Normalize();
			_mob1->SetAction(_mob1->Mob_TAKENDAMAGE);

			_mob1->TakenDamage(_player->Damage());
			_player->GetAttack()->GetTransform()->SetPosition(Vector2(0.0f, 0.0f));
		}
	}
	if (_player->Hp() > 0.0f)
	{
		if (_mob1->AttackT_F() && _mob1->GetMobcol()->IsCollision(_player->GetCol()))
		{

			//Direction = PlayerPos - MobPos;
			//Direction.Normalize();

			_player->invincibility += DELTA_TIME;

			if (_player->invincibility > 0.5)
			{
				_player->TakenDamage(_mob1->Damage());

				_mob1->GetMobcol()->GetTransform()->SetPosition(Vector2(0.0f, 0.0f));
				_mob1->AttackChange(false);
			}


		}
	}



}
