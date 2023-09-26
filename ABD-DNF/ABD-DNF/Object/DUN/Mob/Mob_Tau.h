#pragma once
class Mob_Tau : public Creature
{
public:
	enum State
	{
		
	
		Tau_IDLE,
		Tau_WALK,
		Tau_ATTACK1,
		Tau_DAMAGED,
		Tau_DOWN

	};
	


	Mob_Tau();
	virtual ~Mob_Tau();
	// Creature을(를) 통해 상속됨
	virtual void Update() override;

	virtual void Render() override;

	virtual void PostRender() override;

	virtual float Damage() override;

	void Input();
	void SetAction(State state);


	void TakenDamage();

	
private:

	bool _isAttack = false;
	float _attackKey = 0.0f;


	State _state = State::Tau_IDLE;

	State _curState = State::Tau_IDLE;
	State _oldState = State::Tau_IDLE;




};

