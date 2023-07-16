#pragma once
class Sprite_Frame : public Sprite
{
public:
	// TODO: 분리하기
	Sprite_Frame(wstring path, Vector2 maxFrame);
	Sprite_Frame(wstring path, Vector2 maxFrame, Vector2 size);
	virtual ~Sprite_Frame();

	virtual void Update() override;
	virtual void Render() override;

	virtual void SetCurClip(Vector2 frame) override;
	virtual void SetCurClip(Action::Clip clip) override;

private:
	Vector2 _maxFrame;
};

