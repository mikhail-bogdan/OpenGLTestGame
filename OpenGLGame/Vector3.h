#pragma once

#include "Vector2.h"

class Vector2;

class Vector3
{
public:
	float x, y, z;


	Vector3();
	Vector3(float x, float y);
	Vector3(float x, float y, float z);
	Vector3(const Vector2& value, float z);
	Vector3(const Vector3& value);

	const float* getPtr() const { return (&x); }

	Vector3& operator=(const Vector3& value);

	float& operator[](int index);

	Vector3 operator+(const Vector2& value) const;
	Vector3 operator+(const Vector3& value) const;
	Vector3 operator-(const Vector2& value) const;
	Vector3 operator-(const Vector3& value) const;
	Vector3 operator*(float value) const;
	Vector3 operator/(float value) const;

	Vector3& operator+=(const Vector2& value);
	Vector3& operator+=(const Vector3& value);
	Vector3& operator-=(const Vector2& value);
	Vector3& operator-=(const Vector3& value);
	Vector3& operator*=(float value);
	Vector3& operator/=(float value);

	bool operator==(const Vector3& value) const;
	bool operator!=(const Vector3& value) const;

	Vector3 Cross(const Vector3& value) const;
	float Dot(const Vector3& value) const;

	static Vector3 zero;
	static Vector3 one;
	static Vector3 right;
	static Vector3 left;
	static Vector3 up;
	static Vector3 down;
	static Vector3 forward;
	static Vector3 backward;
};