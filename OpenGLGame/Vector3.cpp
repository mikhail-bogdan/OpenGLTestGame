#include "Vector3.h"

Vector3 Vector3::zero		=	Vector3(0,	0,	0);
Vector3 Vector3::one		=	Vector3(1,	1,	1);
Vector3 Vector3::right		=	Vector3(1,	0,	0);
Vector3 Vector3::left		=	Vector3(-1, 0,	0);
Vector3 Vector3::up			=	Vector3(0,	1,	0);
Vector3 Vector3::down		=	Vector3(0, -1,	0);
Vector3 Vector3::forward	=	Vector3(0,	0,	1);
Vector3 Vector3::backward	=	Vector3(0,	0, -1);

Vector3::Vector3() : x(0), y(0), z(0) {}

Vector3::Vector3(float x, float y) : x(x), y(y), z(0) {}

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

Vector3::Vector3(const Vector2& value, float z) : x(value.x), y(value.y), z(z) {}

Vector3::Vector3(const Vector3& value) : x(value.x), y(value.y), z(value.z) {}

Vector3& Vector3::operator=(const Vector3& value)
{
	this->x = value.x;
	this->y = value.y;
	this->z = value.z;
	return *this;
}

float& Vector3::operator[](int index)
{
	return (&x)[index];
}

Vector3 Vector3::operator+(const Vector2& value) const
{
	return Vector3(this->x + value.x, this->y + value.y, this->z);
}

Vector3 Vector3::operator+(const Vector3& value) const
{
	return Vector3(this->x + value.x, this->y + value.y, this->z + value.z);
}

Vector3 Vector3::operator-(const Vector2& value) const
{
	return Vector3(this->x - value.x, this->y - value.y, this->z);
}

Vector3 Vector3::operator-(const Vector3& value) const
{
	return Vector3(this->x - value.x, this->y - value.y, this->z - value.z);
}

Vector3 Vector3::operator*(float value) const
{
	return Vector3(this->x * value, this->y * value, this->z * value);
}

Vector3 Vector3::operator/(float value) const
{
	return Vector3(this->x / value, this->y / value, this->z / value);
}

Vector3& Vector3::operator+=(const Vector2& value)
{
	this->x += value.x;
	this->y += value.y;
	return *this;
}

Vector3& Vector3::operator+=(const Vector3& value)
{
	this->x += value.x;
	this->y += value.y;
	this->z += value.z;
	return *this;
}

Vector3& Vector3::operator-=(const Vector2& value)
{
	this->x -= value.x;
	this->y -= value.y;
	return *this;
}

Vector3& Vector3::operator-=(const Vector3& value)
{
	this->x -= value.x;
	this->y -= value.y;
	this->z -= value.z;
	return *this;
}

Vector3& Vector3::operator*=(float value)
{
	this->x *= value;
	this->y *= value;
	this->z *= value;
	return *this;
}

Vector3& Vector3::operator/=(float value)
{
	this->x /= value;
	this->y /= value;
	this->z /= value;
	return *this;
}

bool Vector3::operator==(const Vector3& value) const
{
	return this->x == value.x && this->y == value.y && this->z == value.z;
}

bool Vector3::operator!=(const Vector3& value) const
{
	return this->x != value.x || this->y != value.y || this->z != value.z;
}

Vector3 Vector3::Cross(const Vector3& value) const
{
	return Vector3(this->y * value.z - this->z * value.y,
		this->z * value.x - this->x * value.z,
		this->x * value.y - this->y * value.x);
}

float Vector3::Dot(const Vector3& value) const
{
	return this->x * value.x + this->y * value.y + this->z * value.z;
}