#pragma once
class Item
{

public:

	enum TYPE
	{
		NONE,
		WEAPON,
		ARMOR,
		PANTS,
		BELT,
		SHOES,
		HEAD
		

	};

	Item();
	Item(wstring path, TYPE type);
	virtual ~Item();
	virtual void Update();
	virtual void Render();

	void SetType(TYPE type) { type = type; }


	
public:
	shared_ptr<RectCollider> _rect;
	shared_ptr<Transform>	 _trans;
	shared_ptr<Quad>		_quad;
	
	TYPE type = NONE;

};

