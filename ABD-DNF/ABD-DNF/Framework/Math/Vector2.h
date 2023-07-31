#pragma once
class Vector2 : public XMFLOAT2
{
public:
	Vector2()
		: XMFLOAT2(0.0f, 0.0f)
	{
	}

	Vector2(int x, int y)
		: XMFLOAT2(x, y)
	{
	}

	Vector2(float x, float y)
		: XMFLOAT2(x, y)
	{

	}

	Vector2(const Vector2& other) = default;

	Vector2 operator+(const Vector2& other) const
	{
		Vector2 result;
		result.x = (*this).x + other.x;
		result.y = this->y + other.y;

		return result;
	}

	Vector2 operator-(const Vector2& other) const
	{
		Vector2 result;
		result.x = (*this).x - other.x;
		result.y = this->y - other.y;

		return result;
	}

	Vector2 operator*(const float& value) const
	{
		Vector2 result;
		return result = Vector2(this->x * value, this->y * value);
	}

	Vector2 operator*(const double& value) const
	{
		Vector2 result;

		return result = Vector2(float(this->x * value), float(this->y * value));
	}

	Vector2& operator=(const Vector2& other)
	{
		x = other.x;
		y = other.y;

		return *this;
	}
	Vector2& operator+=(const Vector2& other)
	{
		x += other.x;
		y += other.y;

		return *this;
	}

	Vector2& operator-()
	{
		this->x *= -1.0f;
		this->y *= -1.0f;

		return *this;
	}

	bool operator==(const Vector2& other) const;
	bool operator!=(const Vector2& other) const;
	bool operator<(const Vector2& other) const;

	float Length()const
	{
		float result = sqrtf(x * x + y * y);

		return result;
	}
	float Distance(const Vector2& other) const
	{
		Vector2 result = *this - other;

		return result.Length();
	}

	float Dot(const Vector2& other) const
	{
		float result = x * other.x + y * other.y;
		return result;
	}

	float Cross(const Vector2& other) const
	{
		float result = x * other.y - other.x * y;

		return result;
	}

	float Angle() const
	{
		float result = atan2f(y, x);
		return result;
	}

	Vector2 NorMalVector2() const
	{
		Vector2 result;
		float length = Length();
		result.x = x / length;
		result.y = y / length;

		return result;
	}

	void Normalize()
	{
		float length = Length();
		x /= length;
		y /= length;
	}

	void DNF()
	{
		float direction;
		this->x *= -1;
	}

	void DNF_A()
	{
		this->x *= 1.02f;
	}


	bool IsBetween(Vector2 a, Vector2 b);

	int ManhattenDistance(const Vector2& other) const;

	Vector2 TransformCoord(XMMATRIX matrix);
};
