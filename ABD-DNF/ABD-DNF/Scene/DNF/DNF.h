#pragma once
class Player;
class DNF :public Scene
{

public:
	DNF();
	~DNF();


	// Scene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender();

private:

	shared_ptr<Map> _map1;
	shared_ptr<Player> _player;
	
};

