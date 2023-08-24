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

	vector<shared_ptr<RectCollider>> _slots;

	bool active = false;

};

