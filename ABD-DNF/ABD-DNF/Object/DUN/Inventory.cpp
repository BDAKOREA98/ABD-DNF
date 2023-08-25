#include "framework.h"
#include "Inventory.h"

Inventory::Inventory()
{
	_quad = make_shared<Quad>(L"Resource/DNF/Inventory/inventory.png");
	_trans = make_shared<Transform>();
	_rect = make_shared<RectCollider>(_quad->GetImageSize());

	_trans->SetParent(_rect->GetTransform());

	_rect->GetTransform()->SetPosition(Vector2(100, 100));
	
	_items.resize(32);

	

	for (int y = 0; y < _poolCountY; y++)
	{
		_items.reserve(32);

		for (int x = 0; x < _poolCountX; x++)
		{
			shared_ptr<Item> item = make_shared<Item>();
			item->_rect->GetTransform()->SetParent(_rect->GetTransform());
			
			item->_rect->GetTransform()->SetPosition(Vector2 ((x * 32) - 115 , (y * 32) - 80));

			_items[y].push_back(item);
		}
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

	
	for (auto itemarr : _items)
	{
		for (auto item : itemarr)
		{
			item->Update();
		}
	}

}

void Inventory::Render()
{
	if (active)
	{
		_trans->SetWorldBuffer(0);
		_quad->Render();
		_rect->Render();
	
		for (auto itemarr : _items)
		{
			for (auto item : itemarr)
			{
				item->Render();
			}
		}
	}

	


}
