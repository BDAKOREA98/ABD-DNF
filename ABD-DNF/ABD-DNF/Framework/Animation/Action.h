#pragma once
class Action
{
public:
	struct Clip
	{
		Vector2 startPos;
		Vector2 size;
		weak_ptr<SRV> srv;

		Clip(float x, float y, float w, float h, shared_ptr<SRV> srv)
			: startPos(x, y)
			, size(w, h)
			, srv(srv)
		{

		}

		
		
	};

	enum Type
	{
		END,
		LOOP,
		PINGPONG
	};

	Action(vector<Clip> clips, string name = "", Type type = Type::LOOP, float speed = 0.1f);
	~Action();

	

	void Update();

	void ChangeType();

	void Play();
	void Pause();
	void Stop();
	void Reset();

	Clip GetCurClip() { return _clips[_curClipIndex]; }

	Vector2  GetStartPos()
	{
		return _clips[_curClipIndex].startPos;
	}

	void SetEndEvent(CallBack event_) { _endEvent = event_; }
	float GetTime() { return _time; }
private:
	string _name;
	vector<Clip> _clips;

	Type _repeatType;
	bool _isPlay = false;

	UINT _curClipIndex = 0;

	float _time = 0.0f;
	float _speed = 0.0f;

	bool _isReverse = false;

	// ������ ����, ������ ����
	// => Delegate
	CallBack _endEvent = nullptr;

	// �Ű������� int���� ���� �ݹ��Լ�
};

