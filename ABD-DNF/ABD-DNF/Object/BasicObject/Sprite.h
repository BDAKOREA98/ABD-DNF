#pragma once
class Sprite : public Quad
{
protected:
	// TODO: �и��ϱ�
	Sprite(wstring path); // -> Frame ���� �� ������������ ��
	Sprite(wstring path, Vector2 size); // -> Action�� �̿��Ͽ� Ŭ������ ������ ��
	virtual ~Sprite();

public:
	virtual void Update() override;
	virtual void Render() override;

	virtual void CreateVertices() override;
	virtual void CreateData(wstring path) override;

	void SetRight() { _reverseBuffer->_data.value1 = 0; }
	void SetLeft() { _reverseBuffer->_data.value1 = 1; }

	Vector2 GetClipSize() { return _actionBuffer->_data.size; }

	virtual void SetCurClip(Action::Clip clip) {};
	virtual void SetCurClip(Vector2 frame) {};

protected:
	shared_ptr<ActionBuffer> _actionBuffer;
	shared_ptr<IntBuffer> _reverseBuffer;
};

