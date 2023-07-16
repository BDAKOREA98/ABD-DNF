#pragma once
class CircleCollider : public enable_shared_from_this<CircleCollider>, public Collider
{
public:
	CircleCollider(float radius);
	virtual ~CircleCollider();

	virtual void Update() override;
	virtual  void Render() override;

	void CreateVertices();
	void CreateData();

	virtual bool IsCollision(const Vector2& pos) override;
	virtual bool IsCollision(shared_ptr<CircleCollider> col) override;
	virtual bool IsCollision(shared_ptr<RectCollider> col) override;

	bool Block(shared_ptr<CircleCollider> col);
	bool Block(shared_ptr<RectCollider> col) { return false; }

	float GetRadius() { return _radius; }
	float GetWorldRadius();

private:
	float _radius;
};

