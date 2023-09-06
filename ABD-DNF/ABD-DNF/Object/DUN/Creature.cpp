#include "framework.h"
#include "Creature.h"

Creature::Creature()
{
}

Creature::~Creature()
{
}

void Creature::CreateAction(string name, wstring file, float speed, Action::Type type, CallBack callBack)
{
	wstring wName = wstring(name.begin(), name.end());
	shared_ptr<SRV> srv = ADD_SRV(wName);

	string str = string(file.begin(), file.end());

	wstring srvpath = file + wName + L".png";

	// xmldocument 만들기
	string xmlPath = str + name + ".xml";
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

	shared_ptr<Sprite_Clip> sprite = make_shared<Sprite_Clip>(srvpath, Vector2(averageW / count, averageH / count));
	sprite->SetPS(ADD_PS(L"Shader/ActionPS.hlsl"));
	_sprites.push_back(sprite);
}

void Creature::TakenDamage(int damage)
{
	
	if (damage - defense >= 0)
	{
		_Hp -= damage - defense;
	}
	if (damage - defense < 0)
	{
		_Hp -= 1;
	}

}

void Creature::ChangePS(wstring ps)
{

	for (auto sprite : _sprites)
	{
		sprite->SetPS(ADD_PS(ps));
	}

}
