#pragma once
class Player;
class Monster_mad;
class DNF :public Scene
{

public:
	DNF();
	~DNF();


	// Scene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender();

	void Monstermove();
	void MapCollision();
	void MonsterAttack();
	void PlayerAttack();

	float Taken = 0.0f;
	float monsterTaken = 0.5f;
	float playerTaken = 0.5f;
private:


	shared_ptr<Map> _map1;
	
	shared_ptr<Monster_mad> _mob1;


	
	bool _mobMove = true;
	
};

