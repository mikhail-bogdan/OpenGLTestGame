#include "Vector4.h"

Vector4 Vector4::zero	=	Vector4(0, 0, 0, 0);
Vector4 Vector4::one	=	Vector4(1, 1, 1, 1);

Vector4::Vector4() : x(0), y(0), z(0), w(0) {}

Vector4::Vector4(float x, float y) : x(x), y(y), z(0), w(0) {}

Vector4::Vector4(float x, float y, float z) : x(x), y(y), z(z), w(0) {}

Vector4::Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

Vector4::Vector4(const Vector2& value, float z, float w) : x(value.x), y(value.y), z(z), w(w) {}

Vector4::Vector4(const Vector3& value, float w) : x(value.x), y(value.y), z(value.z), w(w) {}

Vector4::Vector4(const Vector4& value) : x(value.x), y(value.y), z(value.z), w(value.w) {}

Vector4& Vector4::operator=(const Vector4& value)
{
	this->x = value.x;
	this->y = value.y;
	this->z = value.z;
	this->w = value.w;
	return *this;
}

float& Vector4::operator[](int index)
{
	return (&x)[index];
}

Vector4 Vector4::operator+(const Vector2& value) const
{
	return Vector4(this->x + value.x, this->y + value.y, this->z, this->w);
}

Vector4 Vector4::operator+(const Vector3& value) const
{
	return Vector4(this->x + value.x, this->y + value.y, this->z + value.z, this->w);
}

Vector4 Vector4::operator+(const Vector4& value) const
{
	return Vector4(this->x + value.x, this->y + value.y, this->z + value.z, this->w + value.w);
}

Vector4 Vector4::operator-(const Vector2& value) const
{
	return Vector4(this->x - value.x, this->y - value.y, this->z, this->w);
}

Vector4 Vector4::operator-(const Vector3& value) const
{
	return Vector4(this->x - value.x, this->y - value.y, this->z - value.z, this->w);
}

Vector4 Vector4::operator-(const Vector4& value) const
{
	return Vector4(this->x - value.x, this->y - value.y, this->z - value.z, this->w - value.w);
}

Vector4 Vector4::operator*(float value) const
{
	return Vector4(this->x * value, this->y * value, this->z * value, this->w * value);
}

Vector4 Vector4::operator/(float value) const
{
	return Vector4(this->x / value, this->y / value, this->z / value, this->w / value);
}

Vector4& Vector4::operator+=(const Vector2& value)
{
	this->x += value.x;
	this->y += value.y;
	return *this;
}

Vector4& Vector4::operator+=(const Vector3& value)
{
	this->x += value.x;
	this->y += value.y;
	this->z += value.z;
	return *this;
}

Vector4& Vector4::operator+=(const Vector4& value)
{
	this->x += value.x;
	this->y += value.y;
	this->z += value.z;
	this->w += value.w;
	return *this;
}

Vector4& Vector4::operator-=(const Vector2& value)
{
	this->x -= value.x;
	this->y -= value.y;
	return *this;
}

Vector4& Vector4::operator-=(const Vector3& value)
{
	this->x -= value.x;
	this->y -= value.y;
	this->z -= value.z;
	return *this;
}

Vector4& Vector4::operator-=(const Vector4& value)
{
	this->x -= value.x;
	this->y -= value.y;
	this->z -= value.z;
	this->w -= value.w;
	return *this;
}

Vector4& Vector4::operator*=(float value)
{
	this->x *= value;
	this->y *= value;
	this->z *= value;
	this->w *= value;
	return *this;
}

Vector4& Vector4::operator/=(float value)
{
	this->x /= value;
	this->y /= value;
	this->z /= value;
	this->w /= value;
	return *this;
}

bool Vector4::operator==(const Vector4& value) const
{
	return this->x == value.x && this->y == value.y && this->z == value.z && this->w == value.w;
}

bool Vector4::operator!=(const Vector4& value) const
{
	return this->x != value.x || this->y != value.y || this->z != value.z || this->w != value.w;
}

float Vector4::Dot(const Vector4& value) const
{
	return this->x * value.x + this->y * value.y + this->z * value.z + this->w * value.w;
}
