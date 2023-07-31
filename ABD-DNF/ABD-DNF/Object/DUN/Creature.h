#pragma once
class Creature
{
public:
	Creature();
	virtual ~Creature();

	virtual void Update() abstract;

	virtual void Render() abstract;

	virtual void PostRender() abstract;

	virtual void CreateAction(string name, wstring file, float speed = 0.1f, Action::Type type = Action::Type::LOOP, CallBack callBack = nullptr);
	


	virtual shared_ptr<Transform> GetTrans() { return _trans; }
	virtual shared_ptr<CircleCollider> GetCol() { return _col; }

	virtual void SetLEFT()
	{
		for (auto sprite : _sprites)
		{
			sprite->SetLeft();
		}
	}
	virtual void SetRIGHT()
	{
		for (auto sprite : _sprites)
		{
			sprite->SetRight();
		}
	}

protected:

	vector<shared_ptr<Action>> _actions;
	shared_ptr<CircleCollider> _col;
	shared_ptr<Transform> _trans;
	vector<shared_ptr<Sprite>> _sprites;
};

