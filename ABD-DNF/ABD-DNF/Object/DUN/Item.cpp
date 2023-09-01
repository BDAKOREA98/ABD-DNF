#include "framework.h"
#include "Item.h"

Item::Item()
{
	_quad = make_shared<Quad>(L"", Vector2(26.0f, 26.0f));
	_trans = make_shared<Transform>();
	_rect = make_shared<RectCollider>(Vector2(30.0f, 30.0f));

	_trans->SetParent(_rect->GetTransform());

	
}

Item::Item(wstring path, TYPE type)
	: type(type)
{
	_quad = make_shared<Quad>(path, Vector2(26.0f, 26.0f));
	_trans = make_shared<Transform>();
	_rect = make_shared<RectCollider>(Vector2(26.0f, 26.0f));

	_trans->SetParent(_rect->GetTransform());
}

Item::~Item()
{
}

void Item::Update()
{
	_quad->	Update();
	_rect->	Update();
	_trans->Update();

}

void Item::Render()
{
		_trans->SetWorldBuffer(0);
		_quad->	Render();
		_rect-> Render();
}
void Item::SetQuad(wstring path)
{
	_quad = make_shared<Quad>(path, Vector2(26.0f, 26.0f));
}

void Item::ChangeAbility(TYPE type, int ability)
{
	type = type;
	ability = ability;

}

bool Item::colision(Vector2 mouse, shared_ptr<RectCollider> rect)
{
	
	if (_rect->IsCollision(mouse))
	{
		dragactive = true;
	}

	if (_rect->IsCollision(mouse) && _rect->IsCollision(rect))
	{
		dragactive = false;
	}
	
	return dragactive;

}

