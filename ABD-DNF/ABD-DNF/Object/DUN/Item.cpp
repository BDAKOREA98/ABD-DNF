#include "framework.h"
#include "Item.h"

Item::Item()
{
	_quad = make_shared<Quad>(L"Resource/DNF/Inventory/chaewon.png", Vector2(26.0f, 26.0f));
	_trans = make_shared<Transform>();
	_rect = make_shared<RectCollider>(Vector2(30.0f, 30.0f));

	_trans->SetParent(_rect->GetTransform());

}

Item::Item(wstring path)
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
