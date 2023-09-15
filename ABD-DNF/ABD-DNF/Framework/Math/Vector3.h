#pragma once
typedef XMMATRIX Matrix;
#define V_LEFT		Vector3(-1.0f, +0.0f , +0.0f)
#define V_RIGHT		Vector3(+1.0f, +0.0f , +0.0f)
#define V_DOWN		Vector3(+0.0f, -1.0f , +0.0f)
#define V_UP		Vector3(+0.0f, +1.0f , +0.0f)
#define V_BACKWARD	Vector3(+0.0f, +0.0f , -1.0f)
#define V_FORWARD	Vector3(+0.0f, +0.0f , +1.0f)

struct Vector3
{


	Vector3()
	{
	}
	Vector3(float x, float y, float z)
		: x(x), y(y), z(z)
	{

	}
	Vector3(XMFLOAT3 value)
		: x(value.x), y(value.y), z(value.z)
	{

	}
	Vector3(XMVECTOR vector)
	{
		x = XMVectorGetX(vector);
		y = XMVectorGetY(vector);
		z = XMVectorGetZ(vector);
	}

	// 대입연산자 오버로딩
	operator XMVECTOR()
	{
		XMVECTOR vector;

		vector = XMVectorSet(x, y, z, 0.0f);

		return vector;
	}
	operator XMFLOAT3()
	{
		return XMFLOAT3(x, y, z);
	}




	float Length() { return XMVectorGetX(XMVector3Length(*this)); }
	// Vector 를 노말라이즈함
	void Normalize() { *this = XMVector3Normalize(*this); }
	// 노말라이즈한 값을 받음
	Vector3 GetNormalize() { return XMVector3Normalize(*this); }

	static Vector3 Cross(Vector3& v1, Vector3& v2)
	{
		return XMVector3Cross(v1, v2);
	}
	static float Dot(Vector3& v1, Vector3& v2)
	{
		return XMVectorGetX(XMVector3Dot(v1, v2));
	}


	Vector3 operator* (const float& value)
	{
		return Vector3(this->x * value, this->y * value, this->z * value);
	}
	Vector3 operator/ (const float& value)
	{
		return Vector3(this->x / value, this->y / value, this->z / value);
	}
	Vector3 operator+ (const Vector3& other)
	{
		return Vector3(this->x + other.x, this->y + other.y, this->z + other.z);
	}
	Vector3 operator+ (const XMVECTOR& other)
	{
		return XMVECTOR(*this) + other;
	}
	Vector3 operator- (const Vector3& other)
	{
		return Vector3(this->x - other.x, this->y - other.y, this->z - other.z);
	}
	void operator *= (const float& value)	
	{  
		this->x *= value; 
		this->y *= value; 
		this->z *= value; 
	}
	void operator /= (const float& value)	
	{
		this->x /= value;
		this->y /= value;
		this->z /= value;
	}
	void operator += (const Vector3& other) 
	{
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;
	}
	void operator -= (const Vector3& other) 
	{
		this->x -= other.x;
		this->y -= other.y;
		this->z -= other.z;
	}

	
	

	Vector3 operator*(const Matrix& value)
	{
		Vector3 result;

		result = XMVector3TransformNormal(*this, value);

		return result;
		// TODO : 
	}

	





	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
	

	

};

