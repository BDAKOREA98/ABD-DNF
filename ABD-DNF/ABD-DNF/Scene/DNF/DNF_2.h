#pragma once
class DNF_2 : public Scene
{
public:
	DNF_2();
	~DNF_2();

	virtual void Update() override;
	virtual void Render() override;


	
	virtual void PostRender();

	void Monstermove();
	void MapCollision();
	void Attack();

private:

	shared_ptr<Map2> _map;
	shared_ptr<Player> _player;
	shared_ptr<Monster_mad> _mob1;
	bool _mobMove = true;
};
