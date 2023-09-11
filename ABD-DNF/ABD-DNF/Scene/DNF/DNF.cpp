#include "framework.h"
#include "DNF.h"

DNF::DNF()
{

	_map1 = make_shared<Map>();

	_mob1 = make_shared<Monster_mad>();



	
	
		PLAYER->GetCol()->GetTransform()->SetPosition(CENTER);
	
}

DNF::~DNF()
{
	
}

void DNF::Update()
{

	

	CAMERA->SetTarget(PLAYER->GetCol()->GetTransform());
	CAMERA->SetLeftBottom(_map1->leftBottom());
	CAMERA->SetRightTop(_map1->rightTop());
	


	_mob1->GetMobcol()->GetTransform()->SetPosition(Vector2(0.0f, 0.0f));
	Monstermove();
	MapCollision();
	Attack();
	
	PLAYER->Attack();


	if (PLAYER->invincibility >= 0.5f)
	{
		PLAYER->invincibility = 0.0f;
	}
	if (_mob1->Hp() > 0.0f)
	{
		_mob1->Update();
	}
	else if (_mob1->Hp() <= 0.0f)
	{

		_mob1->GetCol()->GetTransform()->SetPosition({-1000.0f, -1000.0f});
	}
	if (PLAYER->Hp() > 0.0f)
	{
		PLAYER->Update();
	}
	
		
		_map1->Update();
		
		

}

void DNF::Render()
{
	//_map1->Render();
	
		PLAYER->Render();
		_mob1->Render();
	
}

void DNF::PostRender()
{
	_mob1->PostRender();
//	_map1->PostRender();
	PLAYER->PostRender();
}

void DNF::Monstermove()
{
	if (PLAYER->Hp() > 0.0f)
	{
		if (_mobMove == true)
		{
			if (_mob1->GetMovecol()->IsCollision(PLAYER->GetCol()) == false)
			{
				_mob1->SetAction(_mob1->Mob_RUN);

				Vector2 Direction;
				Vector2 MobPos;
				Vector2 PlayerPos;
				MobPos = _mob1->GetCol()->GetTransform()->GetPos();
				PlayerPos = PLAYER->GetCol()->GetTransform()->GetPos();

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
			else if (_mob1->GetMovecol()->IsCollision(PLAYER->GetCol()))
			{

				_mob1->Attack(PLAYER->GetCol());
			}


		}

	}
	else if (PLAYER->Hp() <= 0.0f)
	{
		_mob1->SetAction(_mob1->Mob_IDLE);
	}

}

void DNF::MapCollision()
{
	if (_map1->GetBottom()->Block(PLAYER->GetCol()))
	{


		PLAYER->GetCol()->GetTransform()->SetPosition({ PLAYER->GetCol()->GetTransform()->GetPos().x, 2.0 });


	}
	if (_map1->GetLeft()->Block(PLAYER->GetCol()))
	{


	}
	if (_map1->GetRight()->Block(PLAYER->GetCol()))
	{
		SCENE->NextScene();
		PlayerScenePos = PLAYER->GetCol()->GetTransform()->GetPos();

	}
	if (_map1->GetTop()->Block(PLAYER->GetCol()))
	{


	}

	{
		PLAYER->GetAttack()->SetColorGreen();

	}

}

void DNF::Attack()
{
	Vector2 Direction;
	Vector2 MobPos;
	Vector2 PlayerPos;
	MobPos = _mob1->GetCol()->GetTransform()->GetPos();
	PlayerPos = PLAYER->GetCol()->GetTransform()->GetPos();

	Direction =  MobPos - PlayerPos;
	Direction.Normalize();

	if (_mob1->Hp() > 0.0f)
	{
		if (PLAYER->AttackT_F() && PLAYER->GetAttack()->IsCollision(_mob1->GetCol()))
		{
			//Direction = MobPos - PlayerPos;
			//Direction.Normalize();
			_mob1->SetAction(_mob1->Mob_TAKENDAMAGE);

			_mob1->TakenDamage(PLAYER->Damage());
			PLAYER->GetAttack()->GetTransform()->SetPosition(Vector2(0.0f, 0.0f));
		}
	}
	if (PLAYER->Hp() > 0.0f)
	{
		if (_mob1->AttackT_F() && _mob1->GetMobcol()->IsCollision(PLAYER->GetCol()))
		{

			//Direction = PlayerPos - MobPos;
			//Direction.Normalize();

			PLAYER->invincibility += DELTA_TIME;

			if (PLAYER->invincibility > 0.5)
			{
				PLAYER->TakenDamage(_mob1->Damage());
				
				_mob1->GetMobcol()->GetTransform()->SetPosition(Vector2(0.0f, 0.0f));
				_mob1->AttackChange(false);
			}


		}
	}
	


}
