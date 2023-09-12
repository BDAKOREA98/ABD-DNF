
#include "framework.h"
#include "Player.h"

Player::Player()
{
	ui = make_shared<UI>();

	_Hp = 1000.0f;
	_Damage = 20.0f;

	_col = make_shared<CircleCollider>(50);
	_playercol2 = make_shared<CircleCollider>(40);
	_trans = make_shared<Transform>();

	CreateAction("Idle_L", L"Resource/DNF/Player/");
	CreateAction("Walk_L", L"Resource/DNF/Player/");
	CreateAction("Run_L", L"Resource/DNF/Player/");
	CreateAction("ATTACK_L", L"Resource/DNF/Player/");
	CreateAction("ATTACK_L2", L"Resource/DNF/Player/");
	CreateAction("ATTACK_L3", L"Resource/DNF/Player/");
	CreateAction("ATTACK_L4", L"Resource/DNF/Player/");
	CreateAction("Taken", L"Resource/DNF/Player/");

	CreateAction("Skill", L"Resource/DNF/Player/");


	_playercol2->GetTransform()->SetParent(_col->GetTransform());

	_trans->SetParent(_col->GetTransform());
	_col->GetTransform()->SetPosition(CENTER);
	
	
	ChangePS(L"Shader/DNF_Player_PS.hlsl");

	_item = make_shared<Item>();
	_inven = make_shared<Inventory>();

	_inven->_rect->GetTransform()->AddVector2({ 100.0f,0.0f });
	SetLEFT();

	_inven->_haven[3][0]->SetQuad(L"Resource/DNF/Inventory/chaewon.png");
	_inven->_haven[3][0]->SetType(Item::BELT);
	_inven->_haven[3][0]->SetAbility(10);
	
	_inven->_haven[3][1]->SetQuad(L"Resource/DNF/Inventory/chaewon.png");
	_inven->_haven[3][1]->SetType(Item::SHOES);
	_inven->_haven[3][1]->SetAbility(5);

	_inven->_haven[3][2]->SetQuad(L"Resource/DNF/Inventory/chaewon.png");
	_inven->_haven[3][2]->SetType(Item::PANTS);
	_inven->_haven[3][2]->SetAbility(15);

	_inven->_haven[3][3]->SetQuad(L"Resource/DNF/Inventory/chaewon.png");
	_inven->_haven[3][3]->SetType(Item::HEAD);
	_inven->_haven[3][3]->SetAbility(7);

	_inven->_haven[3][4]->SetQuad(L"Resource/DNF/Inventory/chaewon.png");
	_inven->_haven[3][4]->SetType(Item::ARMOR);
	_inven->_haven[3][4]->SetAbility(30);

	_inven->_haven[3][5]->SetQuad(L"Resource/DNF/Inventory/chaewon.png");
	_inven->_haven[3][5]->SetType(Item::WEAPON);
	_inven->_haven[3][5]->SetAbility(30);
	
	
	

}

Player::~Player()
{
}

void Player::Update()
{
	_item->Update();
	_inven->Update();
	SetCharactor();

	

	

	ui->hp->ChangeRatio(1 - (_Hp / 1000.0f));
	ui->mp->ChangeRatio(1 - (_Mp / 1000.0f));
	ui->Update();


	if (_Hp > 0.0f)
	{
		_playercol2->SetColorBlue();
		_actions[_curState]->Update();

		_sprites[_curState]->SetCurClip(_actions[_curState]->GetCurClip());
		_sprites[_curState]->Update();

		_col->Update();
		_trans->Update();
		_playercol2->Update();


		if (_curState != IDLE)
		{
			_key += DELTA_TIME;
		}

		if (_curState == ATTACK1 || _curState == ATTACK2 || _curState == ATTACK3 || _curState == ATTACK4)
		{
			_attackkey += DELTA_TIME;
		}
		if (_curState != SKILL)
		{
			timer = 0;
		}


		if (_key >= 0.3f && _curState == IDLE)
			_key = 0;


		
		MOVE();

		Backstep();

	}
	else if (_Hp <= 0.0f)
	{
		_col->GetTransform()->SetPosition({ -1000.0f,-1000.0f });
	}

	if (KEY_DOWN('I') && _inven->active == false && SetAbility==false)
	{
		_inven->_rect->GetTransform()->SetPosition(_col->GetWorldPos());
		//_item->_rect->GetTransform()->SetPosition(_col->GetWorldPos());
		_inven->active = true;
		SetAbility = true;
		
	}
	else if (KEY_DOWN('I') && _inven->active == true && SetAbility==true)
	{
		_inven->active = false;
		SetAbility = false;
		SetDamage();

	}
}

void Player::Render()
{


	
	if (_Hp > 0.0f)
	{
		_trans->SetWorldBuffer(0);
		_sprites[_curState]->Render();
		_col->Render();
		_playercol2->Render();
	}
	else
		return;

	

	_item->Render();
}

void Player::PostRender()
{
	ImGui::Text("Player");
	ImGui::Text("adddamage : %d", damage);
	ImGui::Text("adddefense : %d", defense);
	ImGui::Text("tatalDamage : %f", _Damage);
	ImGui::Text("HP : %f", _Hp);
	ImGui::Text("pos.x : %f", _col->GetTransform()->GetPos().x);
	ImGui::Text("pos.y : %f", _col->GetTransform()->GetPos().y);
	ImGui::Text("WorldPos.x : %f", _col->GetTransform()->GetWorldPos().x);
	ImGui::Text("WorldPos.y : %f", _col->GetTransform()->GetWorldPos().y);
	
	
	_inven->PostRender();

	_inven->Render();
	ui->PostRender();
}

void Player::SetCharactor()
{
	int defensearr[5] = { 0 };
	int damagearr[5] = { 0 };

	for (auto _havenarr : _inven->_haven)
	{
		for (auto haven : _havenarr)
		{
			if (haven->used && haven->type == Item::BELT)
			{
				defensearr[0] = haven->GetAbility();
			}
			if (haven->used && haven->type == Item::SHOES)
			{
				defensearr[1] = haven->GetAbility();
			}
			if (haven->used && haven->type == Item::HEAD)
			{
				defensearr[2] = haven->GetAbility();
			}
			if (haven->used && haven->type == Item::ARMOR)
			{
				defensearr[3] = haven->GetAbility();
			}
			if (haven->used && haven->type == Item::PANTS)
			{
				defensearr[4] = haven->GetAbility();
			}
			if (haven->used && haven->type == Item::WEAPON)
			{
				damagearr[0] = haven->GetAbility();
			}

		}
	}

	

	defense = defensearr[0] + defensearr[1] + defensearr[2] + defensearr[3] + defensearr[4];
	damage = damagearr[0] + damagearr[1] + damagearr[2] + damagearr[3] + damagearr[4];

	


}


void Player::MOVE()
{
#pragma region MOVE

	if (_Hp > 0.0f)
	{
		if (KEY_DOWN(VK_LEFT))
		{
			SetAction(WALK);
			_col->GetTransform()->SetScale({ -1, +1 });
		}
		else if (KEY_UP(VK_LEFT) && _curState == WALK)
		{
			SetAction(IDLE);
		}
		if (KEY_DOWN(VK_RIGHT))
		{

			SetAction(WALK);
			_col->GetTransform()->SetScale({ +1, +1 });


		}
		else if (KEY_UP(VK_RIGHT) && _curState == WALK)
		{
			SetAction(IDLE);
		}

		if (_key >= 0.01f && KEY_DOWN(VK_LEFT))
		{

			SetAction(RUN);

		}
		else if (KEY_UP(VK_LEFT) && _curState == RUN)
		{
			SetAction(IDLE);
		}

		if (_key >= 0.01f && KEY_DOWN(VK_RIGHT))
		{

			SetAction(RUN);

		}
		else if (KEY_UP(VK_RIGHT) && _curState == RUN)
		{
			SetAction(IDLE);
		}

		if (_curState == IDLE && KEY_DOWN(VK_UP))
		{
			SetAction(WALK);
		}
		else if (KEY_UP(VK_UP) && KEY_UP(VK_LEFT))
		{
			SetAction(IDLE);
		}
		else if (KEY_UP(VK_UP) && KEY_UP(VK_RIGHT))
		{
			SetAction(IDLE);
		}
		else if (KEY_UP(VK_UP) && KEY_UP(VK_RIGHT) && KEY_UP(VK_LEFT))
		{
			SetAction(IDLE);
		}

		if (_curState == IDLE && KEY_DOWN(VK_DOWN))
		{
			SetAction(WALK);
		}
		else if (KEY_UP(VK_DOWN) && KEY_UP(VK_LEFT))
		{
			SetAction(IDLE);
		}
		else if (KEY_UP(VK_DOWN) && KEY_UP(VK_RIGHT))
		{
			SetAction(IDLE);
		}
		else if (KEY_UP(VK_DOWN) && KEY_UP(VK_RIGHT) && KEY_UP(VK_LEFT))
		{
			SetAction(IDLE);
		}






#pragma endregion

		if (_curState == WALK)
		{
			if (KEY_PRESS(VK_LEFT))
			{

				_col->GetTransform()->AddVector2(-RIGHT_VECTOR * DELTA_TIME * 100.0f);
			}
			if (KEY_PRESS(VK_RIGHT))
			{
				_col->GetTransform()->AddVector2(RIGHT_VECTOR * DELTA_TIME * 100.0f);
			}
			if (KEY_PRESS(VK_UP))
			{
				_col->GetTransform()->AddVector2(UP_VECTOR * DELTA_TIME * 100.0f);
			}
			if (KEY_PRESS(VK_DOWN))
			{

				_col->GetTransform()->AddVector2(-UP_VECTOR * DELTA_TIME * 100.0f);
			}
		}
		else if (_curState == RUN)
		{
			if (KEY_PRESS(VK_LEFT))
			{
				_col->GetTransform()->AddVector2(-RIGHT_VECTOR * DELTA_TIME * 300.0f);
			}
			if (KEY_PRESS(VK_RIGHT))
			{
				_col->GetTransform()->AddVector2(RIGHT_VECTOR * DELTA_TIME * 300.0f);
			}
			if (KEY_PRESS(VK_UP))
			{
				_col->GetTransform()->AddVector2(UP_VECTOR * DELTA_TIME * 300.0f);
			}
			if (KEY_PRESS(VK_DOWN))
			{
				_col->GetTransform()->AddVector2(-UP_VECTOR * DELTA_TIME * 300.0f);
			}
		}
	}
}

void Player::Attack()
{
	if (_Hp > 0.0f)
	{
		if (_curState == IDLE || _curState == WALK || _curState == RUN)
		{
			_playercol2->GetTransform()->SetPosition({ 0.0f,0.0f });
			_value = 0;
			_isAttack = false;
		}

		_isAttack = false;

		if (_curState != RUN)
		{
			if (KEY_DOWN('X') && _value == 0 && _attackkey >= 0.00f)
			{
				SetAction(ATTACK1);
				_value++;
				_playercol2->GetTransform()->SetPosition(Vector2(40.0f, 0.0f));
				_isAttack = true;
			}
			else if (KEY_DOWN('X') && _value == 1 && _attackkey >= 0.8f)
			{
				SetAction(ATTACK2);
				_value++;
				_playercol2->GetTransform()->SetPosition(Vector2(40.0f, 0.0f));

			}
			else if (KEY_DOWN('X') && _value == 2 && _attackkey >= 1.5f)
			{
				SetAction(ATTACK3);
				_value++;
				_playercol2->GetTransform()->SetPosition(Vector2(40.0f, 0.0f));

			}
			else if (KEY_DOWN('X') && _value == 3 && _attackkey >= 2.2f)
			{
				SetAction(ATTACK4);
				_playercol2->GetTransform()->SetPosition(Vector2(60.0f, 0.0f));
				_value++;

			}
			else if (KEY_DOWN('X') && _value >= 4 && _attackkey >= 2.9f)
			{
				_value = 0;
				_attackkey = 0;

			}


		}

		if (KEY_DOWN('X') && _curState == RUN)
		{
			SetAction(ATTACK4);
			_playercol2->GetTransform()->SetPosition(Vector2(60.0f, 0.0f));
			_isAttack = true;

		}


	}
	
}

void Player::Backstep()
{
	if (_Hp > 0.0f)
	{
		if (KEY_DOWN(('C')) && timer == 0)
		{
			SetAction(SKILL);

		}
		if (_curState == State::SKILL)
		{
			_attackkey = 0.0f;
			timer += DELTA_TIME;
			if (timer > 0.4f)
			{
				SetAction(IDLE);
			}
			if (_col->GetTransform()->GetScale().x < 0.0f)
			{
				_col->GetTransform()->AddVector2(RIGHT_VECTOR * 8.0);
				_playercol2->GetTransform()->SetPosition(Vector2(0, 0));
			}
			else if (_col->GetTransform()->GetScale().x > 0.0f)
			{
				_col->GetTransform()->AddVector2(-RIGHT_VECTOR * 8.0);
				_playercol2->GetTransform()->SetPosition(Vector2(0, 0));
			}
		}
	}
}



void Player::SetAction(State state)
{

	if (_curState == state)
		return;

	_curState = state;

	_actions[_oldState]->Reset();
	_actions[_oldState]->Pause();

	_actions[_curState]->Play();
	_oldState = _curState;
}

void Player::deda()
{
}


Player::State Player::GetCurState()
{
	return _curState;
}

void Player::SetDamage()
{
	_Damage =  10000 + damage;

}

void Player::SetHP()
{
}

