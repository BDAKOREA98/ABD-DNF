#include "framework.h"
#include "Monster_mad.h"

Monster_mad::Monster_mad()
{

	Hp = 500.0f;
	Damage = 30.0f;

	_col = make_shared<CircleCollider>(50);
	
	
	_mobcol = make_shared<CircleCollider>(40);

	_trans = make_shared<Transform>();
	_col->GetTransform()->SetPosition(CENTER);
	_trans->SetParent(_col->GetTransform());
	_trans->SetScale({ 1.5f, 1.5f });
	_mobcol->GetTransform()->SetParent(_col->GetTransform());
	
	CreateAction("Mob_IDLE", L"Resource/DNF/Mob/");
	CreateAction("Mob_RUN", L"Resource/DNF/Mob/");
	CreateAction("Mob_ATTACK1", L"Resource/DNF/Mob/");
	CreateAction("Mob_ATTACK2", L"Resource/DNF/Mob/");
	CreateAction("Mob_TAKENDAMAGE", L"Resource/DNF/Mob/");

	
	

	_mobcol->SetColorWhite();

	



	

}

Monster_mad::~Monster_mad()
{
}

void Monster_mad::Update()
{
	_actions[_curState]->Update();

	_sprites[_curState]->SetCurClip(_actions[_curState]->GetCurClip());
	_sprites[_curState]->Update();

	Input();
	
	_col->Update();
	_mobcol->Update();
	_trans->Update();
}

void Monster_mad::Render()
{

	//ADDITIVE->SetState();
	_trans->SetWorldBuffer(0);
	//_filter->SetPS_Buffer(2);
	_sprites[_curState]->Render();
	_col->Render();
	_mobcol->Render();

}

void Monster_mad::PostRender()
{
	ImGui::Text("----------------");
	ImGui::Text("Mob");
	//ImGui::Text("_curStateStartPos.x : %f", _actions[_curState]->GetStartPos().x);
	//ImGui::Text("_curStateStartPos.y : %f", _actions[_curState]->GetStartPos().y);
	ImGui::Text("Pos.x : %f", _col->GetTransform()->GetPos().x);
	ImGui::Text("Pos.y : %f", _col->GetTransform()->GetPos().y);
	ImGui::Text("Hp : %f", Hp);
	ImGui::Text("Damage : %f", Damage);
	//ImGui::Text("_attack : %f", _attackKey);
	
}


void Monster_mad::SetAction(State state)
{
	if (_curState == state)
		return;

	_curState = state;

	_actions[_oldState]->Reset();
	_actions[_oldState]->Pause();

	_actions[_curState]->Play();

	_oldState = _curState;
}

void Monster_mad::Input()
{
	if (KEY_DOWN(VK_NUMPAD1))
	{
		SetAction(Mob_IDLE);
	}
	if (KEY_DOWN(VK_NUMPAD2))
	{
		SetAction(Mob_RUN);
	}
	if (KEY_DOWN(VK_NUMPAD3))
	{
		SetAction(Mob_ATTACK1);
	}
	if (KEY_DOWN(VK_NUMPAD4))
	{
		SetAction(Mob_ATTACK2);
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

void Monster_mad::Attack()
{
	
	_attackKey += DELTA_TIME;
	
	if (_attackKey >= 1.0f)
	{
		_attackKey = 0.0f;
		
	}





	if (_attackKey >= 0.9)
	{
		_attackKey = 0.0f;
	}
	if (_attackKey >= 0.0f && _attackKey <= 0.4f)
	{
		Damage = 30.0f;
		SetAction(Mob_ATTACK1);
		_mobcol->GetTransform()->SetPosition(Vector2(40.0f, 0.0f));
	}
	else if (_attackKey >= 0.5f && _attackKey <= 0.9f)
	{
		SetAction(Mob_ATTACK2);
		_mobcol->GetTransform()->SetPosition(Vector2(40.0f, 0.0f));
		Damage = 40.0f;
	}

	
}	



