#pragma once
class Inventory
{
public:


	Inventory();
	virtual ~Inventory();

	virtual void Update();
	virtual void Render();



public:
	shared_ptr<RectCollider> _rect;
	shared_ptr<Transform>	 _trans;
	shared_ptr<Quad>		_quad;

	//vector<shared_ptr<RectCollider>> _slots;
	UINT _poolCountX = 8;
	UINT _poolCountY = 4;

	vector<vector<shared_ptr<Item>>> _items;

	bool active = false;

};

