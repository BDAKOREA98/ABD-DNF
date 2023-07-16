#include "framework.h"
#include "SoundManager.h"

SoundManager* SoundManager::_instance = nullptr;
SoundManager::SoundManager()
{
	FMOD::System_Create(&_soundSystem);
	_soundSystem->init(MAX_CHANNEL, FMOD_INIT_NORMAL, nullptr);
}

SoundManager::~SoundManager()
{
	for (auto pair : _soundMap)
	{
		pair.second.sound->release();
	}
}

void SoundManager::Update()
{
	_soundSystem->update();
}

void SoundManager::Add(string key, string file, bool bgm)
{
	if (_soundMap.count(key) > 0)
		return;

	SoundInfo info;

	if (bgm)
		_soundSystem->createStream(file.c_str(), FMOD_LOOP_NORMAL, nullptr, OUT & info.sound);
	else
		_soundSystem->createStream(file.c_str(), FMOD_DEFAULT, nullptr, OUT & info.sound);

	assert(info.sound != nullptr);

	_soundMap[key] = info;
}

void SoundManager::Play(string key, float volume)
{
	if (_soundMap.count(key) == 0)
		return;

	_soundSystem->playSound(_soundMap[key].sound, nullptr, false, OUT & _soundMap[key].channel);
	_soundMap[key].channel->setVolume(volume);
}

void SoundManager::Stop(string key)
{
	if (_soundMap.count(key) == 0)
		return;

	if (_soundMap[key].channel == nullptr)
		return;

	_soundMap[key].channel->stop();
}

void SoundManager::Pause(string key)
{
	if (_soundMap.count(key) == 0)
		return;

	if (_soundMap[key].channel == nullptr)
		return;

	_soundMap[key].channel->setPaused(true);
}

void SoundManager::Resume(string key)
{
	if (_soundMap.count(key) == 0)
		return;

	if (_soundMap[key].channel == nullptr)
		return;

	_soundMap[key].channel->setPaused(false);
}

void SoundManager::SetVolume(string key, float volume)
{
	if (_soundMap.count(key) == 0)
		return;

	if (_soundMap[key].channel == nullptr)
		return;

	if (volume < 0.0f)
		volume = 0.0f;

	if (volume > 2.0f)
		volume = 2.0f;

	_soundMap[key].channel->setVolume(volume);
}

bool SoundManager::IsPlayingSound(string key)
{
	if (_soundMap.count(key) == 0)
		return false;

	if (_soundMap[key].channel == nullptr)
		return false;

	bool isPlay = false;
	_soundMap[key].channel->isPlaying(OUT & isPlay);

	return isPlay;
}
