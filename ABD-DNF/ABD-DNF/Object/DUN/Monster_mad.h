#pragma once
class Monster_mad : public Creature
{
public:

	enum State
	{
		Mob_IDLE,
		Mob_RUN,
		Mob_ATTACK1,
		Mob_ATTACK2,
		Mob_TAKENDAMAGE
		
	};
	Monster_mad();
	~Monster_mad();


	// Creature을(를) 통해 상속됨
	virtual void Update() override;

	virtual void Render() override;

	virtual void PostRender() override;
	
	void SetAction(State state);
	
	void Input();
	void Attack(shared_ptr<CircleCollider> other);
	bool AttackT_F() { return _isAttack; }
	State GetcurState() { return _curState; }

	shared_ptr<CircleCollider> GetMobcol() { return _mobcol; }
	shared_ptr<CircleCollider> GetMovecol() { return _movecol; }

private:

	bool _isAttack = false;
	float _attackKey = 0.0f;



	State _state = State::Mob_IDLE;


	shared_ptr<CircleCollider> _mobcol;
	shared_ptr<CircleCollider> _movecol;

	Vector2 _direction = { 0.0f,0.0f };

	State _curState = State::Mob_IDLE;
	State _oldState = State::Mob_IDLE;
	//shared_ptr<FilterBuffer> _filter;


};

