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
	Item(wstring path, TYPE type = NONE);
	virtual ~Item();
	virtual void Update();
	virtual void Render();

	void SetType(TYPE type) { type = type; }
	void SetQuad(wstring path);

	bool colision(Vector2 mouse, shared_ptr<RectCollider> rect);
	bool dragactive = false;
	
public:
	int ability = 0;

	shared_ptr<RectCollider> _rect;
	shared_ptr<Transform>	 _trans;
	shared_ptr<Quad>		_quad;
	
	TYPE type = NONE;

};

