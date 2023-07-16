#pragma once
class Map
{

public:
	Map();
	~Map();

	void Update();
	void Render();
	void PostRender();






private:

	shared_ptr<Quad> _mapquad;
	shared_ptr<Transform> _maptrans;




};

