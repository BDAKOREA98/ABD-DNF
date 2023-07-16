#include "framework.h"
#include "Effect.h"

Effect::Effect(string name, wstring file, Vector2 maxFrame, Vector2 size, float speed, Action::Type type)
	: _name(name)
{
	_transform = make_shared<Transform>();
	CreateAction_ByFrame(name, file, maxFrame, size, speed, type);
	End();
}

Effect::Effect(string name, wstring file, wstring xmlPath, Vector2 size, float speed, Action::Type type)
	: _name(name)
{
	_transform = make_shared<Transform>();
	CreateAction_ByXML(name, file, xmlPath, size, speed, type);
	End();
}

Effect::~Effect()
{
}

void Effect::Update()
{
	if (_isActive == false)
		return;

	_transform->Update();
	_action->Update();
	_sprite->SetCurClip(_action->GetCurClip());
	_sprite->Update();
}

void Effect::Render()
{
	if (_isActive == false)
		return;

	_transform->SetWorldBuffer(0);
	_sprite->Render();
}

void Effect::Play(Vector2 pos)
{
	_isActive = true;
	_transform->SetPosition(pos);
	_action->Play();
}

void Effect::End()
{
	_isActive = false;
	_transform->SetPosition(Vector2(-10000, -10000));
}

void Effect::CreateAction_ByFrame(string name, wstring file, Vector2 maxFrame, Vector2 size, float speed, Action::Type type)
{
	_sprite = make_shared<Sprite_Frame>(file, maxFrame, size);
	shared_ptr<SRV> srv = ADD_SRV(file);

	Vector2 clipSize = _sprite->GetImageSize();
	clipSize.x /= maxFrame.x;
	clipSize.y /= maxFrame.y;

	vector<Action::Clip> clips;

	for (int y = 0; y < maxFrame.y; y++)
	{
		for (int x = 0; x < maxFrame.x; x++)
		{
			Action::Clip clip = Action::Clip(x * clipSize.x, y * clipSize.y, clipSize.x, clipSize.y, srv);
			clips.push_back(clip);
		}
	}

	_action = make_shared<Action>(clips, name, type, speed);
	_action->SetEndEvent(std::bind(&Effect::End, this));
}

void Effect::CreateAction_ByXML(string name, wstring file, wstring xmlPath, Vector2 size, float speed, Action::Type type)
{ 
	
	
	
}
