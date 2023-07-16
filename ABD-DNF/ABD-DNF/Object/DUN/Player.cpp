#include "framework.h"
#include "Player.h"

Player::Player()
{




	_playercol = make_shared<CircleCollider>(70);
	_trans = make_shared<Transform>();

	CreateAction_1("Idle_L");
	CreateAction_1("Idle_R");
	CreateAction_1("Walk_L");
	CreateAction_1("Walk_R");
	CreateAction_1("Run_L");
	CreateAction_1("Run_R");

	CreateAction_2("ATTACK_L");
	

	_playercol->GetTransform()->SetPosition(CENTER);
	_trans->SetParent(_playercol->GetTransform());
	

	// 재생
	{_actions[State::L_IDLE]->Play();
	_actions[State::R_IDLE]->Play();
	_actions[State::L_WALK]->Play();
	_actions[State::R_WALK]->Play();
	_actions[State::L_RUN]->Play();
	_actions[State::R_RUN]->Play();
	}

	

}

Player::~Player()
{
}

void Player::Update()
{
	
	_actions[_curState]->Update();

	_sprites[_curState]->SetCurClip(_actions[_curState]->GetCurClip());
	_sprites[_curState]->Update();

	//_playercol->GetTransform()->SetPosition(W_MOUSE_POS);
	_playercol->Update();
	_trans->Update();

	if (_key >= 1.0f)
		_key = 0;

	if (_curState != State::L_IDLE && _curState != State::R_IDLE)
			_key += DELTA_TIME;
	

	if (KEY_DOWN(VK_LBUTTON))
	{
		SetAction(ATTACK);
	}


	
	MOVE();

}

void Player::Render()
{
	
	_trans->SetWorldBuffer(0);
	_sprites[_curState]->Render();
	_playercol->Render();

}

void Player::PostRender()
{
	ImGui::Text("_key : %1f", _key);

}

void Player::MOVE()
{
#pragma region KEY입력


	if (KEY_DOWN(VK_LEFT) && _curState == L_IDLE)
	{
		SetAction(L_WALK);
	}
	else if (KEY_DOWN(VK_LEFT) && _curState == R_IDLE)
	{
		SetAction(L_WALK);
	}
	else if (KEY_UP(VK_LEFT) && _curState == L_WALK)
	{
		SetAction(L_IDLE);
	}
	else if (KEY_DOWN(VK_RIGHT) && _curState == L_WALK)
	{
		return;
	}

	if (KEY_DOWN(VK_RIGHT) && _curState == R_IDLE)
	{
		SetAction(R_WALK);
	}
	else if (KEY_DOWN(VK_RIGHT) && _curState == L_IDLE)
	{
		SetAction(R_WALK);
	}
	else if (KEY_UP(VK_RIGHT) && _curState == R_WALK)
	{
		SetAction(R_IDLE);
	}
	else if (KEY_DOWN(VK_LEFT) && _curState == R_WALK)
	{
		return;
	}


	if (KEY_DOWN(VK_UP))
	{
		if (_curState == L_IDLE)
		{
			SetAction(L_WALK);
		}
		else if (_curState == R_IDLE)
		{
			SetAction(R_WALK);
		}

	}
	else if (KEY_UP(VK_UP) && _curState == L_WALK)
	{
		SetAction(L_IDLE);
	}
	else if (KEY_UP(VK_UP) && _curState == R_WALK)
	{
		SetAction(R_IDLE);
	}

	if (KEY_DOWN(VK_DOWN))
	{
		if (_curState == L_IDLE)
		{
			SetAction(L_WALK);
		}
		if (_curState == R_IDLE)
		{
			SetAction(R_WALK);
		}
	}
	else if (KEY_UP(VK_DOWN) && _curState == L_WALK )
	{
		SetAction(L_IDLE);
	}
	else if (KEY_UP(VK_DOWN) && _curState == R_WALK )
	{
		SetAction(R_IDLE);
	}


#pragma endregion


#pragma region RUN

	/*if (KEY_DOWN(VK_LEFT) && _curState == L_WALK && _key >= 0.05)
	{
		_key = 0;
		SetAction(L_RUN);
	}
	else if (KEY_UP(VK_LEFT))
	{
		_key = 0;
		SetAction(L_IDLE);
	}
	if (KEY_DOWN(VK_RIGHT) && _curState == R_WALK && _key >= 0.05)
	{
		_key = 0;
		SetAction(R_RUN);
	}
	else if (KEY_UP(VK_RIGHT))
	{
		_key = 0;
		SetAction(R_IDLE);
	}

	if (KEY_DOWN(VK_DOWN) && _key >= 0.05)
	{
		if (_curState == L_WALK)
		{
			SetAction(L_RUN);
		}
		if (_curState == R_WALK)
		{
			SetAction(R_RUN);
		}
	}
	else if (KEY_UP(VK_DOWN) && _curState == L_RUN)
	{
		_key = 0;
		SetAction(L_IDLE);
	}
	else if (KEY_UP(VK_DOWN) && _curState == R_RUN)
	{
		_key = 0;
		SetAction(R_IDLE);
	}*/

#pragma endregion 



	if (_curState == L_WALK || _curState == R_WALK)
	{
		if (KEY_PRESS(VK_LEFT) && _curState == L_WALK)
		{
			_playercol->GetTransform()->AddVector2(-RIGHT_VECTOR * _speed * DELTA_TIME);
		}
		if (KEY_PRESS(VK_RIGHT) && _curState == R_WALK)
		{
			_playercol->GetTransform()->AddVector2(RIGHT_VECTOR * _speed * DELTA_TIME);
		}
		if (KEY_PRESS(VK_UP))
		{
			_playercol->GetTransform()->AddVector2(UP_VECTOR * _speed * DELTA_TIME);
		}
		if (KEY_PRESS(VK_DOWN))
		{
			_playercol->GetTransform()->AddVector2(-UP_VECTOR * _speed * DELTA_TIME);
		}
	}
	if (_curState == L_RUN || _curState == R_RUN)
	{
		if (KEY_PRESS(VK_LEFT) && _curState == L_RUN)
		{
			_playercol->GetTransform()->AddVector2(-RIGHT_VECTOR * _speed * 2.0f * DELTA_TIME);
		}
		if (KEY_PRESS(VK_RIGHT) && _curState == R_RUN)
		{
			_playercol->GetTransform()->AddVector2(RIGHT_VECTOR * _speed * 2.0f * DELTA_TIME);
		}
		if (KEY_PRESS(VK_UP))
		{
			_playercol->GetTransform()->AddVector2(UP_VECTOR * _speed * 2.0f * DELTA_TIME);
		}
		if (KEY_PRESS(VK_DOWN))
		{
			_playercol->GetTransform()->AddVector2(-UP_VECTOR * _speed * 2.0f * DELTA_TIME);
		}
	}


}

void Player::Attack()
{
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

