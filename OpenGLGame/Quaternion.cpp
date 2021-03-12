#include "Quaternion.h"

Quaternion Quaternion::identity = Quaternion(0, 0, 0, 1);

Quaternion::Quaternion() : x(0), y(0), z(0), w(1) {}

Quaternion::Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

Quaternion Quaternion::Normalized() const
{
	Quaternion q(*this);
	return q / q.Magnitude();
}

float Quaternion::Dot(const Quaternion& q) const
{
	return (this->x * q.x + this->y * q.y + this->z * q.z + this->w * q.w);;
}

Quaternion Quaternion::Conjugate() const
{
	return Quaternion(-this->x, -this->y, -this->z, this->w);
}

Quaternion Quaternion::Inverse() const
{
	return this->Conjugate();
}

float Quaternion::SqrMagnitude() const
{
	return Dot(*this);
}

float Quaternion::Magnitude() const
{
	return this->SqrMagnitude();
}

Quaternion& Quaternion::operator=(const Quaternion& value)
{
		this->x = value.x;
		this->y = value.y;
		this->z = value.z;
		this->w = value.w;
		return *this;
}

Quaternion& Quaternion::operator+=(const Quaternion& aQuat)
{
	this->x += aQuat.x;
	this->y += aQuat.y;
	this->z += aQuat.z;
	this->w += aQuat.w;
	return *this;
}

Quaternion& Quaternion::operator-=(const Quaternion& aQuat)
{
	this->x -= aQuat.x;
	this->y -= aQuat.y;
	this->z -= aQuat.z;
	this->w -= aQuat.w;
	return *this;
}

Quaternion& Quaternion::operator*=(const float aScalar)
{
	this->x *= aScalar;
	this->y *= aScalar;
	this->z *= aScalar;
	this->w *= aScalar;
	return *this;
}

Quaternion& Quaternion::operator*=(const Quaternion& aQuat)
{
	float tempx = w * aQuat.x + x * aQuat.w + y * aQuat.z - z * aQuat.y;
	float tempy = w * aQuat.y + y * aQuat.w + z * aQuat.x - x * aQuat.z;
	float tempz = w * aQuat.z + z * aQuat.w + x * aQuat.y - y * aQuat.x;
	float tempw = w * aQuat.w - x * aQuat.x - y * aQuat.y - z * aQuat.z;
	x = tempx; y = tempy; z = tempz; w = tempw;
	return *this;
}

Quaternion& Quaternion::operator/=(const float aScalar)
{
	this->x /= aScalar;
	this->y /= aScalar;
	this->z /= aScalar;
	this->w /= aScalar;
	return *this;
}

