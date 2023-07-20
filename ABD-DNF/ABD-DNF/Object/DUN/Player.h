#pragma once




class Player : public Creature
{
public:

	enum State
	{
		IDLE,
		WALK,
		RUN,
		ATTACK1,
		ATTACK2,
		ATTACK3,
		ATTACK4,
		SKILL
	};
	Player();
	~Player();
	// Creature을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender() override;

	void MOVE();
	void Attack();
	
	//void CreateAction(string name, float speed = 0.1f, Action::Type type = Action::Type::LOOP, CallBack callBack = nullptr);
	void CreateAction_1(string name, float speed = 0.1f, Action::Type type = Action::Type::LOOP, CallBack callBack = nullptr);
	void CreateAction_2(string name, float speed = 0.1f, Action::Type type = Action::Type::LOOP, CallBack callBack = nullptr);
	
	void SetAction(State state);
	


	void SetLEFT()
	{
		for (auto sprite : _sprites)
		{
			sprite->SetLeft();
		}
	}
	void SetRIGHT()
	{
		for (auto sprite : _sprites)
		{
			sprite->SetRight();
		}
	}


private:
	bool _isAttack = false;

	unsigned int _value = 0;
	
	float _key = 0.0f;
	float _attackkey = 0.0f;
	float _speed = 300.0f;

	shared_ptr<CircleCollider> _playercol;
	shared_ptr<CircleCollider> _playercol2;
	vector<shared_ptr<Action>> _actions;
	
	State _state = State::IDLE;
	shared_ptr<Transform> _trans;
	vector<shared_ptr<Sprite_Clip>> _sprites;



	State _curState = State::IDLE;
	State _oldState = State::IDLE;
	

};

