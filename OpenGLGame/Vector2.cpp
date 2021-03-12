#include "Vector2.h"

Vector2 Vector2::zero	=	Vector2(0,	0);
Vector2 Vector2::one	=	Vector2(1,	1);
Vector2 Vector2::right	=	Vector2(1,	0);
Vector2 Vector2::left	=	Vector2(-1, 0);
Vector2 Vector2::up		=	Vector2(0,	1);
Vector2 Vector2::down	=	Vector2(0, -1);


Vector2::Vector2() : x(0), y(0) {}

Vector2::Vector2(float x, float y) : x(x), y(y) {}

Vector2::Vector2(const Vector2& value) : x(value.x), y(value.y) {}

Vector2& Vector2::operator=(Vector2& value)
{
	this->x = value.x;
	this->y = value.y;
	return *this;
}

float& Vector2::operator[](int index)
{

	return (&x)[index];
}

Vector2 Vector2::operator+(Vector2& value) const
{
	return Vector2(this->x + value.x, this->y + value.y);
}

Vector2 Vector2::operator-(Vector2& value) const
{
	return Vector2(this->x - value.x, this->y - value.y);
}

Vector2 Vector2::operator*(float value) const
{
	return Vector2(this->x * value, this->y * value);
}

Vector2 Vector2::operator/(float value) const
{
	return Vector2(this->x / value, this->y / value);
}

Vector2& Vector2::operator+=(Vector2& value)
{
	this->x += value.x;
	this->y += value.y;
	return *this;
}

Vector2& Vector2::operator-=(Vector2& value)
{
	this->x -= value.x;
	this->y -= value.y;
	return *this;
}

Vector2& Vector2::operator*=(float value)
{
	this->x *= value;
	this->y *= value;
	return *this;
}

Vector2& Vector2::operator/=(float value)
{
	this->x /= value;
	this->y /= value;
	return *this;
}

bool Vector2::operator==(Vector2& value) const
{
	return this->x == value.x && this->y == value.y;
}

bool Vector2::operator!=(Vector2& value) const
{
	return this->x != value.x || this->y != value.y;
}

Vector3 Vector2::Cross(Vector2 value) const
{
	return Vector3(0, 0,this->x * value.y - this->y * value.x);
}

float Vector2::Dot(Vector2 value) const
{
	return this->x * value.x + this->y * value.y;
}
