#include "framework.h"
#include "DNF.h"

DNF::DNF()
{
	_mob1 = make_shared<Monster_mad>();

	_map1 = make_shared<Map>();
	PlayerManager::Create();

	_mob1->GetCol()->GetTransform()->SetPosition({150.0f, 150.0f });

	
}

DNF::~DNF()
{

}

void DNF::Update()
{

	if (KEY_DOWN(VK_LBUTTON))
	{
		_mob1->TakenDamage(10000);
	}

	CAMERA->SetTarget(PLAYER->GetCol()->GetTransform());
	CAMERA->SetLeftBottom(_map1->leftBottom());
	CAMERA->SetRightTop(_map1->rightTop());
	

	PLAYER->_playercol3->Block(_mob1->GetCol());
	_mob1->GetMobcol()->GetTransform()->SetPosition(Vector2(0.0f, 0.0f));
	MapCollision();


	if (_mob1->GetcurState() == _mob1->Mob_TAKEN)
	{
		monsterTaken += DELTA_TIME;
	}
	if (PLAYER->GetCurState() == PLAYER->Taken)
	{
		playerTaken += DELTA_TIME;
		
	}


	if (monsterTaken >= 0.4f)
	{
		Monstermove();
		MonsterAttack();
	}

	if (playerTaken >= 0.5f)
	{
		PlayerAttack();
	}

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
	_map1->Render();
	
	PLAYER->Render();
	_mob1->Render();
	
	
	
		
}

void DNF::PostRender()
{
	ImGui::Text("taken : %f",Taken);
	ImGui::Text("playertaken : %f",playerTaken);
	ImGui::Text("monstertaken : %f",monsterTaken);
	_mob1->PostRender();
	//_map1->PostRender();
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

	if (_map1->GetRoom()->IsCollision(PLAYER->GetCol()))
	{
		SCENE->PrevScene();
	}
}

void DNF::MonsterAttack()
{
	if (_mob1->Hp() > 0.0f)
	{
		if (PLAYER->AttackT_F() && PLAYER->GetAttack()->IsCollision(_mob1->GetCol()))
		{


			_mob1->SetAction(_mob1->Mob_TAKEN);


			_mob1->TakenDamage(PLAYER->Damage());
			PLAYER->GetAttack()->GetTransform()->SetPosition(Vector2(0.0f, 0.0f));
			
			monsterTaken = 0.0f;
		}
		if (PLAYER->sillTF && PLAYER->skillcol->IsCollision(_mob1->GetCol()))
		{
			_mob1->SetAction(_mob1->Mob_TAKEN);


			_mob1->TakenDamage(500);
			PLAYER->skillcol->GetTransform()->SetPosition(Vector2(0.0f, 0.0f));
			monsterTaken = 0.0f;
		}
	}
}

void DNF::PlayerAttack()
{
	if (PLAYER->Hp() > 0.0f)
	{
		if (_mob1->AttackT_F() && _mob1->GetMobcol()->IsCollision(PLAYER->GetCol()))
		{
			
			
			PLAYER->invincibility += DELTA_TIME;

			if (PLAYER->invincibility > 0.5)
			{
				PLAYER->SetAction(PLAYER->Taken);
				PLAYER->TakenDamage(_mob1->Damage());
				_mob1->GetMobcol()->GetTransform()->SetPosition(Vector2(0.0f, 0.0f));
				_mob1->AttackChange(false);
			}


		}
	}
}

