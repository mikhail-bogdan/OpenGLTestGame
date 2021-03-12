#pragma once

#include "Vector2.h"
#include "Vector3.h"

class Vector4
{
public:
	float x, y, z, w;


	Vector4();
	Vector4(float x, float y);
	Vector4(float x, float y, float z);
	Vector4(float x, float y, float z, float w);
	Vector4(const Vector2& value, float z, float w);
	Vector4(const Vector3& value, float w);
	Vector4(const Vector4& value);

	const float* getPtr() const { return (&x); }

	Vector4& operator=(const Vector4& value);

	float& operator[](int index);

	Vector4 operator+(const Vector2& value) const;
	Vector4 operator+(const Vector3& value) const;
	Vector4 operator+(const Vector4& value) const;
	Vector4 operator-(const Vector2& value) const;
	Vector4 operator-(const Vector3& value) const;
	Vector4 operator-(const Vector4& value) const;
	Vector4 operator*(float value) const;
	Vector4 operator/(float value) const;

	Vector4& operator+=(const Vector2& value);
	Vector4& operator+=(const Vector3& value);
	Vector4& operator+=(const Vector4& value);
	Vector4& operator-=(const Vector2& value);
	Vector4& operator-=(const Vector3& value);
	Vector4& operator-=(const Vector4& value);
	Vector4& operator*=(float value);
	Vector4& operator/=(float value);

	bool operator==(const Vector4& value) const;
	bool operator!=(const Vector4& value) const;

	float Dot(const Vector4& value) const;

	static Vector4 zero;
	static Vector4 one;
};