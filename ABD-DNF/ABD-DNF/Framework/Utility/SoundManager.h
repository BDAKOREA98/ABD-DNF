#pragma once
class SoundManager
{
private:
	struct SoundInfo
	{
		FMOD::Sound* sound = nullptr;
		FMOD::Channel* channel = nullptr;

		SoundInfo() {}
		~SoundInfo() {}
	};

	SoundManager();
	~SoundManager();

public:
	static void Create()
	{
		if (_instance == nullptr)
			_instance = new SoundManager();
	}

	static void Delete()
	{
		if (_instance != nullptr)
			delete _instance;
	}

	static SoundManager* GetInstance()
	{
		if (_instance != nullptr)
			return _instance;

		return nullptr;
	}

	void Update();
	void Add(string key, string file, bool bgm = false);
	void Play(string key, float volume = 1.0f);
	void Stop(string key);
	void Pause(string key);
	void Resume(string key);
	void SetVolume(string key, float volume);

	bool IsPlayingSound(string key);

private:
	static SoundManager* _instance;

	FMOD::System* _soundSystem = nullptr;

	unordered_map<string, SoundInfo> _soundMap;
	const int MAX_CHANNEL = 15;
};

