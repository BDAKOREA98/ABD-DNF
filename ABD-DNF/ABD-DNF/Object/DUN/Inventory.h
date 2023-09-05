#pragma once
class Inventory
{
public:


	Inventory();
	virtual ~Inventory();

	virtual void Update();
	virtual void Render();
	void Drag();
	void Equipment();
	void CreateInven();

	void PostRender();

	int GetItem();
	void SetEquipment();


	bool itemdrag = false;
	bool active = false;
public:
	shared_ptr<RectCollider> _rect;
	shared_ptr<RectCollider> _dragbar;
	shared_ptr<Transform>	 _trans;
	shared_ptr<Quad>		_quad;



	//vector<shared_ptr<RectCollider>> _slots;
	UINT _poolCountX = 8;
	UINT _poolCountY = 4;

	vector<vector<shared_ptr<Item>>> _items;
	vector<vector<shared_ptr<Item>>> _haven;

	vector<shared_ptr<Item>> _equipment;

	shared_ptr<Transform> oldpos;

};

