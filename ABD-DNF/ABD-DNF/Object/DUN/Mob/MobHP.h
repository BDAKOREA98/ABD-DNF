#pragma once
class MobHP
{
public:
	MobHP();
	~MobHP();

	void Update();
	void PostRender();

	void SetPosition(Vector2 pos) { _quadTransform->SetPosition(pos); }

	void SetRatio(float ratio) { _buffer->_data.ratio = ratio; _buffer->Update_Resource(); }

	
	shared_ptr<Transform> _quadTransform;
private:
	shared_ptr<Quad> _quad;

	shared_ptr<BarBuffer> _buffer;

	
};

