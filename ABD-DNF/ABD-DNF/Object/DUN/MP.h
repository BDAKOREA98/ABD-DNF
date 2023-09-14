#pragma once
class MP
{
public:
	MP();
	~MP();


	void Update();
	void PostRender();

	void SetPosition(Vector2 pos) { _quadTransform->SetPosition(pos); }
	void SetEvent(CallBack fn) { _event = fn; }
	void SetRatio(float ratio) { _buffer->_data.ratio = ratio; _buffer->Update_Resource(); }
	void ChangeRatio(float A) { _ratio = A; }

	float _ratio = 0.0f;




private:
	shared_ptr<Transform> _quadTransform;
	shared_ptr<Transform> _quadTransform2;
	shared_ptr<Transform> _quadTransform3;
	shared_ptr<Transform> _mainTransform;
	shared_ptr<Quad> _quad;
	shared_ptr<Quad> _quad2;
	shared_ptr<Quad> _quad3;

	shared_ptr<BarBuffer> _buffer;


	CallBack _event;

};

