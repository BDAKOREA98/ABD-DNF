#pragma once
class Player;
class Monster_mad;
class DNF :public Scene
{

public:
	DNF();
	~DNF();


	// Scene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender();

	void Monstermove();
	void MapCollision();
	void Attack();


private:
	bool _mobMove = true;


	shared_ptr<Map> _map1;
	shared_ptr<Player> _player;
	shared_ptr<Monster_mad> _mob1;
	
};

