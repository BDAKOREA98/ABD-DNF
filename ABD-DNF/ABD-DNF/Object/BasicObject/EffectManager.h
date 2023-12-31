#pragma once
class EffectManager
{
private:
	EffectManager();
	~EffectManager();

public:
	static void Create()
	{
		if (_instance == nullptr)
			_instance = new EffectManager();
	}

	static void Delete()
	{
		if (_instance != nullptr)
			delete _instance;
	}

	static EffectManager* GetInstance()
	{
		if (_instance != nullptr)
			return _instance;

		return nullptr;
	}

	void Update();
	void Render();

	void AddEffect(string name, wstring file, Vector2 maxFrame, Vector2 size, float speed = 0.03f,
		Action::Type type = Action::Type::END);
	void SetLEFT();
	void SetRight();

	void Play(string name, Vector2 pos);

private:
	UINT _poolCount = 30;

	static EffectManager* _instance;

	unordered_map<string, vector<shared_ptr<Effect>>> _effectTable;
};

