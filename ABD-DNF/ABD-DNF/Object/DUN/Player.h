#pragma once




class Player : public Creature
{
public:

	enum State
	{
		L_IDLE,
		R_IDLE,
		L_WALK,
		R_WALK,
		L_RUN,
		R_RUN,
		ATTACK,
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
	


private:
	bool _isAttack = false;

	
	float _key = 0.0f;
	float _speed = 300.0f;

	shared_ptr<CircleCollider> _playercol;
	vector<shared_ptr<Action>> _actions;
	
	State _state = State::L_IDLE;
	shared_ptr<Transform> _trans;
	vector<shared_ptr<Sprite_Clip>> _sprites;



	State _curState = State::L_IDLE;
	State _oldState = State::L_IDLE;
	

};

