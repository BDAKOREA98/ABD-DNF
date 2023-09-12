#pragma once
class Loading : public Scene
{
public:
	Loading();
	~Loading();

	void Update();
	void Render();

private:

	shared_ptr<Quad> _mapquad;
	shared_ptr<Transform> _maptrans;

};

