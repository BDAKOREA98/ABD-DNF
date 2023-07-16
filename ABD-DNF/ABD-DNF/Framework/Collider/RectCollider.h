#pragma once
#include "../../Types.h"

class RectCollider : public Collider
{
public:
	struct AABB_Info
	{
		float left = 0;
		float top = 0;
		float right = 0;
		float bottom = 0;
	};

	struct OBB_Info
	{
		Vector2 pos;
		Vector2 direction[2];
		float length[2];
	};

	RectCollider(Vector2 size);
	virtual ~RectCollider();

	virtual void Update() override;
	virtual void Render() override;

	void CreateVertices();
	void CreateData();

	virtual bool IsCollision(const Vector2& pos) override;
	virtual bool IsCollision(shared_ptr<class CircleCollider> col) override;
	virtual bool IsCollision(shared_ptr<RectCollider> col)override;

	bool IsOBB(shared_ptr<RectCollider> col);
	bool IsOBB(shared_ptr<CircleCollider> col);

	void SetScale(Vector2 scale);
	float SeperateAxis(Vector2 separate, Vector2 e1, Vector2 e2);

	bool Block(shared_ptr<RectCollider> col);
	bool Block(shared_ptr<CircleCollider> col);

	AABB_Info GetAABB_Info();
	OBB_Info GetOBB_info();

private:
	Vector2 _size;

};

