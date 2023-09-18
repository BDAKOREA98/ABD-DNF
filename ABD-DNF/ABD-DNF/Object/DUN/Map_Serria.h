#pragma once
class Map_Serria
{

public:
	Map_Serria();
	~Map_Serria();

	void Update();
	void Render();
	void PostRender();

	Vector2 leftBottom();
	Vector2 rightTop();



	shared_ptr<RectCollider> GetBottom() { return _blockcol1; }
	shared_ptr<RectCollider> GetTop() { return _blockcol2; }
	shared_ptr<RectCollider> GetRight() { return _blockcol3; }
	shared_ptr<RectCollider> GetLeft() { return _blockcol4; }


	shared_ptr<Transform> GetTrans() { return _maptrans; }
	shared_ptr<RectCollider> GetCol() { return _mapcol; }

	shared_ptr<Quad> GetQuad() { return _mapquad; }

	shared_ptr<RectCollider> GetNPC() { return _NPC; }

private:
	friend class Player;
	shared_ptr<RectCollider> _mapcol;
	shared_ptr<Quad> _mapquad;
	shared_ptr<Transform> _maptrans;

	shared_ptr<RectCollider> _NPC;


	shared_ptr<RectCollider> _blockcol1;
	shared_ptr<RectCollider> _blockcol2;
	shared_ptr<RectCollider> _blockcol3;
	shared_ptr<RectCollider> _blockcol4;






};

