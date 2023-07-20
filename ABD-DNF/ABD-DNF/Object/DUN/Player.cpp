#include "framework.h"
#include "Player.h"

Player::Player()
{




	_playercol = make_shared<CircleCollider>(50);
	_playercol2 = make_shared<CircleCollider>(50);
	_trans = make_shared<Transform>();

	CreateAction_1("Idle_L");
	CreateAction_1("Walk_L");
	CreateAction_1("Run_L");
	CreateAction_2("ATTACK_L");
	CreateAction_2("ATTACK_L2");
	CreateAction_2("ATTACK_L3");
	CreateAction_2("ATTACK_L4");
	

	_playercol->GetTransform()->SetPosition(CENTER);
	_playercol2->GetTransform()->SetParent(_playercol->GetTransform());
	
	_trans->SetParent(_playercol->GetTransform());
	
	_actions[WALK]->Play();
	_actions[RUN]->Play();
	_actions[ATTACK1]->Play();
	_actions[ATTACK2]->Play();
	_actions[ATTACK3]->Play();
	_actions[IDLE]->Play();
	


}

Player::~Player()
{
}

void Player::Update()
{

	_actions[_curState]->Update();

	_sprites[_curState]->SetCurClip(_actions[_curState]->GetCurClip());
	_sprites[_curState]->Update();

	_playercol->Update();
	_playercol2->Update();
	
	_trans->Update();

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
	_playercol->Render();
	_playercol2->Render();

}

void Player::PostRender()
{
	ImGui::Text("_key : %1f", _key);
	ImGui::Text("_attackkey : %1f", _attackkey);
	ImGui::Text("_value : %d", _value);
	ImGui::Text("_curState : %d", _curState);

}

void Player::MOVE()
{
#pragma region MOVE
	if (KEY_DOWN(VK_LEFT))
	{	
		
		SetRIGHT();
		SetAction(WALK);
	}
	else if (KEY_UP(VK_LEFT) && _curState == WALK)
	{
		
		SetAction(IDLE);
	}
	if (KEY_DOWN(VK_RIGHT))
	{
		SetLEFT();
		SetAction(WALK);
	}
	else if (KEY_UP(VK_RIGHT) && _curState == WALK)
	{
		SetAction(IDLE);
	}

	if (_key >= 0.01f && KEY_DOWN(VK_LEFT))
	{
		SetRIGHT();
		SetAction(RUN);
	}
	else if (KEY_UP(VK_LEFT) && _curState == RUN)
	{
		SetAction(IDLE);
	}

	if (_key >= 0.01f && KEY_DOWN(VK_RIGHT))
	{
		SetLEFT();
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
	/*else if (KEY_UP(VK_UP))
	{
		SetAction(IDLE);
	}*/

	if (_curState == IDLE && KEY_DOWN(VK_DOWN))
	{
		SetAction(WALK);
	}
	/*else if (KEY_UP(VK_DOWN))
	{
		SetAction(IDLE);
	}*/

	


	
#pragma endregion



}

void Player::Attack()
{





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
		}
		else if (KEY_DOWN('X') && _value == 2 && _attackkey >= 1.5f)
		{
			SetAction(ATTACK3);
			_value++;
		}
		else if (KEY_DOWN('X') && _value == 3 && _attackkey >= 2.2f)
		{
			SetAction(ATTACK4);
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
	}
	
}

//void Player::CreateAction(string name, float speed, Action::Type type, CallBack callback)
//{
//	
//	wstring wName = wstring(name.begin(), name.end());
//	wstring srvPath = L"Resource/DNF/Player/" + wName + L".bmp";
//	shared_ptr<SRV> srv = ADD_SRV(wName);
//
//	// xmldocument 만들기
//	string xmlPath = "Resource/DNF/Player/" + name + ".xml";
//	shared_ptr<tinyxml2::XMLDocument> document = make_shared<tinyxml2::XMLDocument>();
//	document->LoadFile(xmlPath.c_str());
//
//	tinyxml2::XMLElement* textureAtlas = document->FirstChildElement();
//	tinyxml2::XMLElement* parent = textureAtlas->FirstChildElement();
//	tinyxml2::XMLElement* row = parent->FirstChildElement();
//
//	vector<Action::Clip> clips;
//	
//
//
//	float averageW = 0;
//	float averageH = 0;
//	int count = 0;
//
//	
//
//
//	
//
//	while (true)
//	{
//		if (row == nullptr)
//		{
//			
//			
//
//		
//		
//
//			if (parent->NextSiblingElement() == nullptr)
//			{
//				break;
//			}
//			else
//			{
//				
//				parent = parent->NextSiblingElement();
//				row = parent->FirstChildElement();
//			}
//
//		}
//
//
//
//		// row에서 필요한 값을 인트형 변환 후 클립에 담기
//		int x = row->FindAttribute("x")->IntValue();
//		int y = row->FindAttribute("y")->IntValue();
//		int w = row->FindAttribute("w")->IntValue();
//		int h = row->FindAttribute("h")->IntValue();
//
//		averageW += w;
//		averageH += h;
//		count++;
//
//
//		Action::Clip clip = Action::Clip(x, y, w, h, srv);
//		clips.push_back(clip);
//		// 다음 자식으로 넘어가기
//		row = row->NextSiblingElement();
//	}
//
//	
//	shared_ptr<Action> action = make_shared<Action>(clips, name, type, speed);
//	action->SetEndEvent(callback);
//
//
//	_actions.push_back(action);
//
//
//
//	shared_ptr<Sprite_Clip> sprite;
//	sprite = make_shared<Sprite_Clip>(srvPath, Vector2(averageW / count, averageH / count));
//	sprite->SetPS(ADD_PS(L"Shader/ActionPS.hlsl"));
//	_sprites.push_back(sprite);
//	
//	
//
//
//}

void Player::CreateAction_1(string name, float speed, Action::Type type, CallBack callBack)
{

	// srv만드는 작업
	// IDLE, RUN

	wstring wName = wstring(name.begin(), name.end());
	wstring srvPath = L"Resource/DNF/Player/IDLEWALKRUN.bmp";
	shared_ptr<SRV> srv = ADD_SRV(wName);

	// xmldocument 만들기
	string xmlPath = "Resource/DNF/Player/" + name + ".xml";
	shared_ptr<tinyxml2::XMLDocument> document = make_shared<tinyxml2::XMLDocument>();
	document->LoadFile(xmlPath.c_str());

	tinyxml2::XMLElement* textureAtlas = document->FirstChildElement();
	tinyxml2::XMLElement* row = textureAtlas->FirstChildElement();

	vector<Action::Clip> clips;

	float averageW = 0;
	float averageH = 0;
	int count = 0;
	while (true)
	{
		if (row == nullptr)
		{
			break;
		}
		// row에서 필요한 값을 인트형 변환 후 클립에 담기
		int x = row->FindAttribute("x")->IntValue();
		int y = row->FindAttribute("y")->IntValue();
		int w = row->FindAttribute("w")->IntValue();
		int h = row->FindAttribute("h")->IntValue();

		averageW += w;
		averageH += h;
		count++;


		Action::Clip clip = Action::Clip(x, y, w, h, srv);
		clips.push_back(clip);
		// 다음 자식으로 넘어가기
		row = row->NextSiblingElement();
	}

	shared_ptr<Action> action = make_shared<Action>(clips, name, type, speed);
	action->SetEndEvent(callBack);

	_actions.push_back(action);

	shared_ptr<Sprite_Clip> sprite = make_shared<Sprite_Clip>(srvPath, Vector2(averageW / count, averageH / count));
	sprite->SetPS(ADD_PS(L"Shader/ActionPS.hlsl"));
	_sprites.push_back(sprite);
}

void Player::CreateAction_2(string name, float speed, Action::Type type, CallBack callBack)
{
	wstring wName = wstring(name.begin(), name.end());
	wstring srvPath = L"Resource/DNF/Player/ATTACK.bmp";
	shared_ptr<SRV> srv = ADD_SRV(wName);

	// xmldocument 만들기
	string xmlPath = "Resource/DNF/Player/" + name + ".xml";
	shared_ptr<tinyxml2::XMLDocument> document = make_shared<tinyxml2::XMLDocument>();
	document->LoadFile(xmlPath.c_str());

	tinyxml2::XMLElement* textureAtlas = document->FirstChildElement();
	tinyxml2::XMLElement* row = textureAtlas->FirstChildElement();

	vector<Action::Clip> clips;

	float averageW = 0;
	float averageH = 0;
	int count = 0;
	while (true)
	{
		if (row == nullptr)
		{
			break;
		}
		// row에서 필요한 값을 인트형 변환 후 클립에 담기
		int x = row->FindAttribute("x")->IntValue();
		int y = row->FindAttribute("y")->IntValue();
		int w = row->FindAttribute("w")->IntValue();
		int h = row->FindAttribute("h")->IntValue();

		averageW += w;
		averageH += h;
		count++;


		Action::Clip clip = Action::Clip(x, y, w, h, srv);
		clips.push_back(clip);
		// 다음 자식으로 넘어가기
		row = row->NextSiblingElement();
	}

	shared_ptr<Action> action = make_shared<Action>(clips, name, type, speed);
	action->SetEndEvent(callBack);

	_actions.push_back(action);

	shared_ptr<Sprite_Clip> sprite = make_shared<Sprite_Clip>(srvPath, Vector2(averageW / count, averageH / count));
	sprite->SetPS(ADD_PS(L"Shader/ActionPS.hlsl"));
	_sprites.push_back(sprite);
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

