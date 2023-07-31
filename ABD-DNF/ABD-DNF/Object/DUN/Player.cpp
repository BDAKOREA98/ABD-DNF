#include "framework.h"
#include "Player.h"

Player::Player()
{




	_col = make_shared<CircleCollider>(50);
	_playercol2 = make_shared<CircleCollider>(50);
	_trans = make_shared<Transform>();

	CreateAction("Idle_L", L"Resource/DNF/Player/");
	CreateAction("Walk_L", L"Resource/DNF/Player/");
	CreateAction("Run_L", L"Resource/DNF/Player/");
	CreateAction("ATTACK_L", L"Resource/DNF/Player/");
	CreateAction("ATTACK_L2", L"Resource/DNF/Player/");
	CreateAction("ATTACK_L3", L"Resource/DNF/Player/");
	CreateAction("ATTACK_L4", L"Resource/DNF/Player/");


	_col->GetTransform()->SetPosition({-100, 350
});
	_playercol2->GetTransform()->SetParent(_col->GetTransform());
	
	_trans->SetParent(_col->GetTransform());
	
	


	SetLEFT();
}

Player::~Player()
{
}

void Player::Update()
{

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
	

	if (_key >= 0.3f &&  _curState == IDLE)
		_key = 0;

	

		MOVE();
	
	
	Attack();

}

void Player::Render()
{
	
	_trans->SetWorldBuffer(0);
	_sprites[_curState]->Render();
	_col->Render();
	_playercol2->Render();

}

void Player::PostRender()
{

	ImGui::Text("Player");
	ImGui::Text("_key : %1f", _key);
	ImGui::Text("_attackkey : %1f", _attackkey);
	ImGui::Text("_value : %d", _value);
	ImGui::Text("_curState : %d", _curState);
	ImGui::Text("Pos.x : %f", _col->GetTransform()->GetPos().x);
	ImGui::Text("Pos.y : %f", _col->GetTransform()->GetPos().y);
	ImGui::Text("WorldPos.x : %f", _col->GetTransform()->GetWorldPos().x);
	ImGui::Text("WorldPos.y : %f", _col->GetTransform()->GetWorldPos().y);

}

void Player::MOVE()
{
#pragma region MOVE
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
	else if (KEY_UP(VK_DOWN) && KEY_UP(VK_LEFT) )
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
		if (KEY_PRESS(VK_RIGHT)  )
		{
			_col->GetTransform()->AddVector2(RIGHT_VECTOR * DELTA_TIME * 100.0f);
		}
		if (KEY_PRESS(VK_UP)   )
		{
			_col->GetTransform()->AddVector2(UP_VECTOR * DELTA_TIME * 100.0f);
		}
		if (KEY_PRESS(VK_DOWN)  )
		{
			
			_col->GetTransform()->AddVector2(-UP_VECTOR * DELTA_TIME * 100.0f);
		}
	}
	else if (_curState == RUN)
	{
		if (KEY_PRESS(VK_LEFT)  )
		{
			_col->GetTransform()->AddVector2(-RIGHT_VECTOR * DELTA_TIME * 300.0f);
		}
		if (KEY_PRESS(VK_RIGHT)  )
		{
			_col->GetTransform()->AddVector2(RIGHT_VECTOR * DELTA_TIME * 300.0f);
		}
		if (KEY_PRESS(VK_UP)  )
		{
			_col->GetTransform()->AddVector2(UP_VECTOR * DELTA_TIME * 300.0f);
		}
		if (KEY_PRESS(VK_DOWN)  )
		{
			_col->GetTransform()->AddVector2(-UP_VECTOR * DELTA_TIME * 300.0f);
		}
	}
}

void Player::Attack()
{

	if (_curState == IDLE || _curState == WALK || _curState == RUN)
	{
		_playercol2->GetTransform()->SetPosition({0.0f,0.0f});
		_value = 0;
	}



	if (_curState != RUN)
	{
		if (KEY_DOWN('X') && _value == 0 && _attackkey >= 0.00f)
		{
			SetAction(ATTACK1);
			_value++;
			_playercol2->GetTransform()->SetPosition(Vector2(40.0f, 0.0f));
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
