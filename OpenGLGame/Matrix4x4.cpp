#include "Matrix4x4.h"

Matrix4x4::Matrix4x4()
{
	for (int i = 0; i < 16; i++) data[i] = 0;
	get(0, 0) = 1;
	get(1, 1) = 1;
	get(2, 2) = 1;
	get(3, 3) = 1;
}

Matrix4x4 Matrix4x4::genIdentity()
{
	return Matrix4x4();
}

Matrix4x4& Matrix4x4::setIdentity() {
	get(0, 0) = 1.0;	get(0, 1) = 0.0;	get(0, 2) = 0.0;	get(0, 3) = 0.0;
	get(1, 0) = 0.0;	get(1, 1) = 1.0;	get(1, 2) = 0.0;	get(1, 3) = 0.0;
	get(2, 0) = 0.0;	get(2, 1) = 0.0;	get(2, 2) = 1.0;	get(2, 3) = 0.0;
	get(3, 0) = 0.0;	get(3, 1) = 0.0;	get(3, 2) = 0.0;	get(3, 3) = 1.0;
	return *this;
}

Matrix4x4& Matrix4x4::setOrtho(
	float left,
	float right,
	float bottom,
	float top,
	float zNear,
	float zFar)
{
	setIdentity();

	float deltax = right - left;
	float deltay = top - bottom;
	float deltaz = zFar - zNear;

	get(0, 0) = 2.0F / deltax;
	get(0, 3) = -(right + left) / deltax;
	get(1, 1) = 2.0F / deltay;
	get(1, 3) = -(top + bottom) / deltay;
	get(2, 2) = -2.0F / deltaz;
	get(2, 3) = -(zFar + zNear) / deltaz;
	return *this;
}