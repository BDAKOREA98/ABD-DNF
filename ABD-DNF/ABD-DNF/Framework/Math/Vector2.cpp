#include "framework.h"
#include "Vector2.h"

bool Vector2::operator==(const Vector2& other) const
{
    return (x == other.x) && (y == other.y);
}

bool Vector2::operator!=(const Vector2& other) const
{
    return !this->operator==(other);
}

bool Vector2::operator<(const Vector2& other) const
{
    if (y != other.y)
        return y < other.y;

    return x < other.x;
}

bool Vector2::IsBetween(Vector2 a, Vector2 b)
{
    float crossA = this->Cross(a);
    float crossB = this->Cross(b);

    return crossA * crossB < 0;
}

int Vector2::ManhattenDistance(const Vector2& other) const
{
    return abs(other.x - x) + abs(other.y - y);
}

Vector2 Vector2::TransformCoord(XMMATRIX matrix)
{
    XMVECTOR temp = XMLoadFloat2(this);

    temp = XMVector2TransformCoord(temp, matrix);
    Vector2 result;
    XMStoreFloat2(&result, temp);

    return result;
}
