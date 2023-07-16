#include "framework.h"
#include "Sprite_Clip.h"

Sprite_Clip::Sprite_Clip(wstring path)
	: Sprite(path)
{
	Sprite::CreateVertices();
	Sprite::CreateData(path);
}

Sprite_Clip::Sprite_Clip(wstring path, Vector2 size)
	: Sprite(path, size)
{
	Sprite::CreateVertices();
	Sprite::CreateData(path);
}

Sprite_Clip::~Sprite_Clip()
{
}

void Sprite_Clip::Update()
{
	Sprite::Update();
}

void Sprite_Clip::Render()
{
	Sprite::Render();
}

void Sprite_Clip::SetCurClip(Action::Clip clip)
{
	_actionBuffer->_data.size = clip.size;
	_actionBuffer->_data.startPos = clip.startPos;
}
