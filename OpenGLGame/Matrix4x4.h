#pragma once

class Matrix4x4
{
public:
	float data[16];


	Matrix4x4();

	const float* getPtr() const { return data; }
	float& get(int row, int column) { return data[row + (column * 4)]; }
	const float& get(int row, int column)const { return data[row + (column * 4)]; };

	Matrix4x4& setIdentity();
	Matrix4x4& setOrtho(float left, float right, float bottom, float top, float zNear, float zFar);

	static Matrix4x4 zero;
	static Matrix4x4 identity;

	static Matrix4x4 genIdentity();
};