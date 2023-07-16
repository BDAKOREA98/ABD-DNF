#pragma once
class Transform
{
public:
	Transform();
	~Transform();

	void Update();
	void Update_SRT();
	void Update_WorldBuffer();
	void SetWorldBuffer(UINT slot);

	void SetPosition(Vector2 pos) { _pos = pos; Update_SRT(); }
	void SetScale(Vector2 scale) { _scale = scale; Update_SRT(); }
	void SetAngle(float angle) { _angle = angle; Update_SRT(); }

	void AddVector2(Vector2 pos) { _pos += pos; }
	void AddScale(Vector2 scale) { _scale += scale; }
	void AddAngle(float angle) { _angle += angle; }

	const Vector2& GetPos() { return _pos; }
	const Vector2& GetScale() { return _scale; }
	const float& GetAngle() { return _angle; }

	Vector2 GetWorldPos() const;
	Vector2 GetWorldScale() const;

	void SetParent(shared_ptr<Transform> parent) { _parent = parent; }

	const XMMATRIX& GetSRT() { return _srtMatrix; }

private:
	Vector2 _pos;
	Vector2 _scale = { 1.0f, 1.0f };
	float _angle = 0.0f;

	XMMATRIX _scaleM = XMMatrixIdentity();
	XMMATRIX _rotateM = XMMatrixIdentity();
	XMMATRIX _translateM = XMMatrixIdentity();

	XMMATRIX _srtMatrix = XMMatrixIdentity();

	shared_ptr<class MatrixBuffer> _world;
	weak_ptr<Transform> _parent;
};

