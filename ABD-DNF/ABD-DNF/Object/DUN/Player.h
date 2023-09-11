#pragma once




class Player : public Creature
{
public:





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
		Taken,
		SKILL
	};
	Player();
	~Player();
	// Creature을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender() override;

	void SetCharactor();

	void MOVE();
	void Attack();
	void Backstep();
	
	void SetAction(State state);
	
	void deda();


	shared_ptr<CircleCollider> GetAttack() {return _playercol2;	}

	State GetCurState();

	virtual float Damage() { return _Damage; };
	void SetDamage();
	void SetHP();

	bool SetAbility = false;
	bool AttackT_F() { return _isAttack; }
	float invincibility = 0.0f;
	shared_ptr<UI> ui;



private:
	bool _isAttack = false;

	
	float MP = 1000.0f;
	

	float timer = 0.0f;

	unsigned int _value = 0;
	
	float _key = 0.0f;
	float _attackkey = 0.0f;
	float _speed = 300.0f;

	
	shared_ptr<CircleCollider> _playercol2;
	
	State _state = State::IDLE;
	
	

	Vector2 _direction = {0.0f,0.0f};

	State _curState = State::IDLE;
	State _oldState = State::IDLE;
	
	shared_ptr<Item> _item;
	shared_ptr<Inventory> _inven;

};

