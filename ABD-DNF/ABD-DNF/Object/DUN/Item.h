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

	void SetType(TYPE Type) { type = Type; }
	void SetQuad(wstring path);
	void ChangeAbility(TYPE type, int ability);
	void SetAbility(int ability1) { ability = ability1; }

	TYPE GetType() { return type; }

	bool colision(Vector2 mouse, shared_ptr<RectCollider> rect);
	bool dragactive = false;
	bool used = false;

	Vector2 GetOldPos() { return  oldPos; }
	void SetOldPos(Vector2 pos) { oldPos = pos; }

	int GetAbility() { return ability; }

public:
	int ability = 10;

	shared_ptr<RectCollider> _rect;
	shared_ptr<Transform>	 _trans;
	shared_ptr<Quad>		_quad;
	
	Vector2 oldPos = { 0.0f,0.0f };

	TYPE type = NONE;

};

