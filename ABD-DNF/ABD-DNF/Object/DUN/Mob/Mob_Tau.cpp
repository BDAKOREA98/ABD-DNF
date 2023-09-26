#include "framework.h"
#include "Mob_Tau.h"

Mob_Tau::Mob_Tau()
{
	_Hp = 1000.0f;
	_Damage = 10.0f;

	_col = make_shared<CircleCollider>(50);


	_trans = make_shared<Transform>();
	
	_trans->SetParent(_col->GetTransform());
	_trans->SetScale({ 1.5f, 1.5f });

	_col->GetTransform()->SetScale({ 1.5f, 1.5f });

	CreateAction("Tau_IDLE", L"Resource/DNF/Mob/");
	CreateAction("Tau_WALK", L"Resource/DNF/Mob/");
	CreateAction("Tau_ATTACK1", L"Resource/DNF/Mob/");
	CreateAction("Tau_DAMAGED", L"Resource/DNF/Mob/");
	CreateAction("Tau_DOWN", L"Resource/DNF/Mob/");

	ChangePS(L"Shader/DNF_Player_PS.hlsl");
}

Mob_Tau::~Mob_Tau()
{
}

void Mob_Tau::Update()
{
	_actions[_curState]->Update();

	_sprites[_curState]->SetCurClip(_actions[_curState]->GetCurClip());
	_sprites[_curState]->Update();

	Input();

	_col->Update();
	
	_trans->Update();

}

void Mob_Tau::Render()
{
	_trans->SetWorldBuffer(0);

	_sprites[_curState]->Render();
	_col->Render();
	

}

void Mob_Tau::PostRender()
{
	ImGui::Text("POS.x %f", _col->GetTransform()->GetPos().x);
	ImGui::Text("POS.y %f", _col->GetTransform()->GetPos().y);

}

float Mob_Tau::Damage()
{
    return _Damage;
}

void Mob_Tau::Input()
{
	if (KEY_DOWN(VK_NUMPAD1))
	{
		SetAction(Tau_IDLE);
	}
	if (KEY_DOWN(VK_NUMPAD2))
	{
		SetAction(Tau_WALK);
	}
	if (KEY_DOWN(VK_NUMPAD3))
	{
		SetAction(Tau_ATTACK1);
	}
	if (KEY_DOWN(VK_NUMPAD4))
	{
		SetAction(Tau_DAMAGED);
	}
	if (KEY_DOWN(VK_NUMPAD5))
	{
		SetAction(Tau_DOWN);
	}

	if (KEY_DOWN('O'))
	{
		_actions[_curState]->Pause();
	}
	else if (KEY_DOWN('P'))
	{
		_actions[_curState]->Play();
	}
}

void Mob_Tau::SetAction(State state)
{
	if (_curState == state)
		return;

	_curState = state;

	_actions[_oldState]->Reset();
	_actions[_oldState]->Pause();

	_actions[_curState]->Play();

	_oldState = _curState;
}

void Mob_Tau::TakenDamage()
{
	
	
	SetAction(Tau_DAMAGED);

}
