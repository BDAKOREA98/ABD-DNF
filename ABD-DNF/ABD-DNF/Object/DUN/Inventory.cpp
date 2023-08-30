#include "framework.h"
#include "Inventory.h"

Inventory::Inventory()
{
	_quad = make_shared<Quad>(L"Resource/DNF/Inventory/inventory.png");
	_trans = make_shared<Transform>();
	_rect = make_shared<RectCollider>(_quad->GetImageSize());
	_dragbar = make_shared<RectCollider>(Vector2(_quad->GetImageSize().x , 15.0f));


	_trans->SetParent(_rect->GetTransform());

	_rect->GetTransform()->SetPosition(Vector2(100, 100));
	
	_dragbar->GetTransform()->SetParent(_rect->GetTransform());
	_dragbar->GetTransform()->SetPosition({ 0.0f, 200.0f });


	_items.resize(32);
	
	_equipment.resize(10);
	
	_haven.resize(32);


	CreateInven();
}

Inventory::~Inventory()
{
}

void Inventory::Update()
{
	_rect->Update();
	_quad->Update();
	_trans->Update();
	_dragbar->Update();
	Drag();
	Equipment();
	for (int i = 0; i < _equipment.size(); i++)
	{
		_equipment[i]->Update();
	}

	for (auto itemarr : _items)
	{
		for (auto item : itemarr)
		{
			item->Update();
			item->dragactive = false;
		}
	}
	for (auto havenarr : _haven)
	{
		for (auto haven : havenarr)
		{
			haven->Update();
			
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
		_dragbar->Render();

		for (auto itemarr : _items)
		{
			for (auto item : itemarr)
			{
				item->Render();
			}
		}

		for (int i = 0; i < _equipment.size(); i++)
		{
			_equipment[i]->Render();
		}

		for (auto havenarr : _haven)
		{
			for (auto haven : havenarr)
			{
				haven->Render();
			}
		}

	}

	


}

void Inventory::Drag()
{
	if (_dragbar->IsCollision(W_MOUSE_POS) && KEY_PRESS(VK_LBUTTON))
	{
		_rect->GetTransform()->SetPosition({W_MOUSE_POS.x, W_MOUSE_POS.y - 200.0f});
	}
	for (auto havenarr : _haven)
	{
		for (auto haven : havenarr)
		{
			if (KEY_UP(VK_LBUTTON))
			{
				itemdrag = false;
			}
			if (KEY_PRESS(VK_LBUTTON)&&haven->_rect->IsCollision(W_MOUSE_POS))
			{
				
				itemdrag = true;
			}
			if (itemdrag)
			{
				if (haven->_rect->IsCollision(W_MOUSE_POS))
				{
					haven->_rect->GetTransform()->SetPosition({ S_MOUSE_POS.x, S_MOUSE_POS.y });
				}
			}
			
		}
	}



}

void Inventory::Equipment()
{
	_equipment[0]->_rect->GetTransform()->SetPosition(Vector2(-50.0f , 144.0f)); // 바지
	_equipment[0]->SetType(Item::PANTS);
	_equipment[1]->_rect->GetTransform()->SetPosition(Vector2(-82.0f , 144.0f)); // 상의
	_equipment[0]->SetType(Item::ARMOR);
	_equipment[2]->_rect->GetTransform()->SetPosition(Vector2(-114.0f, 144.0f)); // 머리
	_equipment[0]->SetType(Item::HEAD);
	_equipment[3]->_rect->GetTransform()->SetPosition(Vector2(-82.0f,  110.0f)); // 벨트
	_equipment[0]->SetType(Item::BELT);
	_equipment[4]->_rect->GetTransform()->SetPosition(Vector2(-114.0f, 110.0f)); // 신발
	_equipment[0]->SetType(Item::SHOES);
	_equipment[5]->_rect->GetTransform()->SetPosition(Vector2(+48.0f, 144.0f));
	_equipment[6]->_rect->GetTransform()->SetPosition(Vector2(+80.0f, 144.0f));
	_equipment[7]->_rect->GetTransform()->SetPosition(Vector2(+112.0f, 144.0f));
	_equipment[8]->_rect->GetTransform()->SetPosition(Vector2(+80.0f, 110.0f)); // 무기
	_equipment[0]->SetType(Item::WEAPON);
	_equipment[9]->_rect->GetTransform()->SetPosition(Vector2(+112.0f, 110.0f));


}

void Inventory::CreateInven()
{
	for (int i = 0; i < _equipment.size(); i++)
	{
		_equipment[i] = make_shared<Item>();
		_equipment[i]->_rect->GetTransform()->SetParent(_rect->GetTransform());
	}



	for (int y = 0; y < _poolCountY; y++)
	{
		_items.reserve(32);

		for (int x = 0; x < _poolCountX; x++)
		{
			shared_ptr<Item> item = make_shared<Item>();
			item->_rect->GetTransform()->SetParent(_rect->GetTransform());

			item->_rect->GetTransform()->SetPosition(Vector2((x * 32) - 115, (y * 32) - 80));

			_items[y].push_back(item);
		}
	}

	for (int y = 0; y < _poolCountY; y++)
	{
		_haven.reserve(32);

		for (int x = 0; x < _poolCountX; x++)
		{
			shared_ptr<Item> item = make_shared<Item>();
			item->_rect->GetTransform()->SetParent(_rect->GetTransform());

			item->_rect->GetTransform()->SetPosition(Vector2((x * 32) - 115, (y * 32) - 80));

			_haven[y].push_back(item);
		}
	}
	
}
