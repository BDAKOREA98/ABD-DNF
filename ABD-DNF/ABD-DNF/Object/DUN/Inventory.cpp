#include "framework.h"
#include "Inventory.h"

Inventory::Inventory()
{
	_quad = make_shared<Quad>(L"Resource/DNF/Inventory/inventory.png");
	_trans = make_shared<Transform>();
	_rect = make_shared<RectCollider>(Vector2(50.0f, 50.0f));

	_trans->SetParent(_rect->GetTransform());

	
	

	_slots.reserve(32);
	
	for (int i = 0; i < 32; i++)

	{
		_slots.push_back(_slots[i] = make_shared<RectCollider>(26.0f, 26.0f));
	}


	
	for (int i = 0; i < 32; i++)
	{
		_slots[i]->GetTransform()->SetParent(_rect->GetTransform());
		_slots[i]->GetTransform()->SetPosition(Vector2(0.0f, 10.0f * i));
	}
}

Inventory::~Inventory()
{
}

void Inventory::Update()
{
	_rect->Update();
	_quad->Update();
	_trans->Update();

	for (int i = 0; i < _slots.size(); i++)
	{
		_slots[i]->Update();
	}
	
}

void Inventory::Render()
{
	if (active)
	{
		_trans->SetWorldBuffer(0);
		_quad->Render();
		_rect->Render();
		for (int i = 0; i < _slots.size(); i++)
		{
			_slots[i]->Render();
		}
	}


}
