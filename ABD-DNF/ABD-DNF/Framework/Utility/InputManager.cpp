#include "framework.h"
#include "InputManager.h"

InputManager* InputManager::_instance = nullptr;

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

void InputManager::Update()
{
	memcpy(_oldState, _curState, sizeof(_oldState));

	GetKeyboardState(_curState);

	for (int i = 0; i < KEY_MAX; i++)
	{
		byte key = _curState[i] & 0x80;

		// key가 true 하면 1반환
		// key가 false 하면 0 반환
		_curState[i] = (key ? 1 : 0);

		byte old = _oldState[i];
		byte cur = _curState[i];

		if (old == 0 && cur == 1)
		{
			_stateMap[i] = State::DOWN;
		}

		else if (old == 1 && cur == 0)
		{
			_stateMap[i] = State::UP;
		}

		else if (old == 1 && cur == 1)
		{
			_stateMap[i] = State::PRESS;
		}

		else
		{
			_stateMap[i] = State::NONE;
		}
	}
}
