#pragma once



class PlayerManager
{
private:
	PlayerManager() {};
		
	~PlayerManager() {};

public:
	static void Create()
	{
		if (_instance == nullptr)
		{
			_instance = new PlayerManager();
			player = new Player();
		}

	}

	static void Delete()
	{
		if (_instance != nullptr)
		{
			delete _instance;
			delete player;
		}
			
	}

	static PlayerManager* GetInstance()
	{
		if (_instance != nullptr)
			return _instance;

		return nullptr;
	}
	static Player* GetPlayer()
	{
		if (player != nullptr)
			return player;

		return nullptr;
	}


	


	void Update();
	void PostRender();
	void Render();
private:
	static Player* player;

	static PlayerManager* _instance;


};

