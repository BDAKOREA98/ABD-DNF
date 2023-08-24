#pragma once
class Item
{

public:

	Item();
	Item(wstring path);
	virtual ~Item();
	virtual void Update();
	virtual void Render();

	


	
public:
	shared_ptr<RectCollider> _rect;
	shared_ptr<Transform>	 _trans;
	shared_ptr<Quad>		_quad;
	
};

