#pragma once

class Quaternion
{
public:
	float x, y, z, w;


	Quaternion();
	Quaternion(float x, float y, float z, float w);

	const float* getPtr() const { return (&x); }

	Quaternion Normalized() const;
	//Quaternion NormalizeSafe(const Quaternionf& q);

	float Dot(const Quaternion& q) const;

	Quaternion Conjugate() const;
	Quaternion Inverse() const;

	float SqrMagnitude() const;
	float Magnitude() const;

	bool operator == (const Quaternion& q)const { return x == q.x && y == q.y && z == q.z && w == q.w; }
	bool operator != (const Quaternion& q)const { return x != q.x || y != q.y || z != q.z || w != q.w; }

	Quaternion& operator=(const Quaternion& value);

	Quaternion& operator += (const Quaternion& aQuat);
	Quaternion& operator -= (const Quaternion& aQuat);
	Quaternion& operator *= (const float     	aScalar);
	Quaternion& operator *= (const Quaternion& aQuat);
	Quaternion& operator /= (const float     	aScalar);

	Quaternion operator + (const Quaternion& rhs)
	{
		Quaternion q(*this);
		return q += rhs;
	}

	Quaternion	operator - (const Quaternion& rhs)
	{
		Quaternion t(*this);
		return t -= rhs;
	}

	Quaternion operator - () const
	{
		return Quaternion(-x, -y, -z, -w);
	}

	Quaternion	operator * (const float s) const
	{
		return Quaternion(x * s, y * s, z * s, w * s);
	}

	friend Quaternion	operator * (const float s, const Quaternion& q)
	{
		Quaternion t(q);
		return t *= s;
	}

	Quaternion	operator / (const float s)
	{
		Quaternion t(*this);
		return t /= s;
	}

	inline Quaternion operator * (const Quaternion& rhs)
	{
		return Quaternion(
			this->w * rhs.x + this->x * rhs.w + this->y * rhs.z - this->z * rhs.y,
			this->w * rhs.y + this->y * rhs.w + this->z * rhs.x - this->x * rhs.z,
			this->w * rhs.z + this->z * rhs.w + this->x * rhs.y - this->y * rhs.x,
			this->w * rhs.w - this->x * rhs.x - this->y * rhs.y - this->z * rhs.z);
	}

	static Quaternion identity;
};