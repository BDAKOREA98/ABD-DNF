#include "framework.h"
#include "Collider.h"

Collider::Collider()
{
	_transform = make_shared<Transform>();
}

Collider::~Collider()
{
}

bool Collider::IsCollision(shared_ptr<Collider> col)
{
	switch (col->_type)
	{
	case Collider::Type::NONE:
		return false;
	case Collider::Type::CIRCLE:
		return IsCollision(dynamic_pointer_cast<CircleCollider>(col));
	case Collider::Type::RECT:
		return IsCollision(dynamic_pointer_cast<RectCollider>(col));
	default:
		return false;
	}
}
