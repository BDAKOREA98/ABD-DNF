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
	
	_player->Attack();


	if (_player->invincibility >= 0.5f)
	{
		_player->invincibility = 0.0f;
	}
	if (_mob1->Hp() > 0.0f)
	{
		_mob1->Update();
	}
	else if (_mob1->Hp() <= 0.0f)
	{

		_mob1->GetCol()->GetTransform()->SetPosition({-1000.0f, -1000.0f});
	}
	if (_player->Hp() > 0.0f)
	{
		_player->Update();
	}
	
		
		_map1->Update();
		
		

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
		SCENE->NextScene();
		PlayerScenePos = _player->GetCol()->GetTransform()->GetPos();

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
