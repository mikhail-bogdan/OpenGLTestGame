#pragma once

#include "Vector3.h"

class Vector3;

class Vector2
{
public:
	float x, y;


	Vector2();
	Vector2(float x, float y);
	Vector2(const Vector2& value);

	const float* getPtr() const { return (&x); }

	Vector2& operator=(Vector2& value);

	float& operator[](int index);

	Vector2 operator+(Vector2& value) const;
	Vector2 operator-(Vector2& value) const;
	Vector2 operator*(float value) const;
	Vector2 operator/(float value) const;

	Vector2& operator+=(Vector2& value);
	Vector2& operator-=(Vector2& value);
	Vector2& operator*=(float value);
	Vector2& operator/=(float value);

	bool operator==(Vector2& value) const;
	bool operator!=(Vector2& value) const;

	Vector3 Cross(Vector2 value) const;
	float Dot(Vector2 value) const;

	static Vector2 zero;
	static Vector2 one;
	static Vector2 right;
	static Vector2 left;
	static Vector2 up;
	static Vector2 down;
};