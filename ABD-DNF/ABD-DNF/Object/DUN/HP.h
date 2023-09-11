#pragma once
class HP
{
public:
	HP();
	~HP();

	
	void Update();
	void PostRender();

	void SetPosition(Vector2 pos) { _quadTransform->SetPosition(pos); }
	void SetEvent(CallBack fn) { _event = fn; }
	void SetRatio(float ratio) { _buffer->_data.ratio = ratio; _buffer->Update_Resource(); }
private:
	shared_ptr<Transform> _quadTransform;
	shared_ptr<Quad> _quad;
	
	shared_ptr<BarBuffer> _buffer;

	CallBack _event;

};

