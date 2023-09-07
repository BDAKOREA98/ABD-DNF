#pragma once

#include "../../Types.h"

class Camera
{
private:
	Camera();
	~Camera();

public:
	static void Create()
	{
		if (_instance == nullptr)
			_instance = new Camera();
	}

	static void Delete()
	{
		if (_instance != nullptr)
			delete _instance;
	}

	static Camera* GetInstance()
	{
		if (_instance != nullptr)
			return _instance;

		return nullptr;
	}

	void Update();
	void PostRender();

	void ShakeStart(float magnitude, float duration, float reduceDamping = 1.0f);

	void SetViewPort(UINT width = WIN_WIDTH, UINT height = WIN_HEIGHT);

	void SetViewBuffer();
	void SetUIViewBuffer();
	void SetProjectionBuffer();

	void SetTarget(shared_ptr<Transform> target) { _target = target; }
	void OffTarget() {  _target.reset(); }
	void SetLeftBottom(Vector2 value) { _leftBottom = value; }
	void SetRightTop(Vector2 value) { _rightTop = value; }
	void SetOffset(Vector2 value) { _offset = value; }

	void SetPosition(Vector2 pos);
	void SetScale(Vector2 scale);
	void SetAngle(float angle);

	void AddVector2(Vector2 pos);
	void AddScale(Vector2 scale);
	void AddAngle(float angle);

	Vector2 GetWorldMousePos();
	Vector2 GetScreenMousePos();

private:
	void Shake();
	void FreeMode();
	void FollowMode();

	static Camera* _instance;

	shared_ptr<Transform> _view;
	shared_ptr<Transform> _uiView;

	shared_ptr<MatrixBuffer> _projection;

	// Free Mode
	float _speed = 500.0f;

	// Follow Mode
	weak_ptr<Transform> _target;
	Vector2 _offset;

	Vector2 _leftBottom;
	Vector2 _rightTop;

	// Shake
	float _duration = 0.0f;
	float _magnitude = 0.0f;
	float _reduceDamping = 0.0f;

	Vector2 _originPos;
	Vector2 _winSize;
};

