#include "../OpenGLGame/Vector2.h"
#include "../OpenGLGame/Vector3.h"
#include "../OpenGLGame/Vector4.h"

#include "gtest/gtest.h"

namespace Vec2 {
	TEST(Vector2, Constructor)
	{
		Vector2 v1;
		Vector2 v2(2, 5);

		ASSERT_EQ(v1.x, 0);
		ASSERT_EQ(v1.y, 0);
		ASSERT_EQ(v2.x, 2);
		ASSERT_EQ(v2.y, 5);
	}

	TEST(Vector2, CopyConstructor)
	{
		Vector2 v1(2, 5);
		Vector2 v2 = v1;

		ASSERT_EQ(v2.x, 2);
		ASSERT_EQ(v2.y, 5);
	}

	TEST(Vector2, Set)
	{
		Vector2 v1;

		v1[0] = 2;
		v1[1] = 5;

		ASSERT_EQ(v1.x, 2);
		ASSERT_EQ(v1.y, 5);
	}

	TEST(Vector2, Assign)
	{
		Vector2 v1(1, 2);
		Vector2 v2;
		v2 = v1;

		ASSERT_EQ(v2.x, 1);
		ASSERT_EQ(v2.y, 2);
	}

	TEST(Vector2, Add)
	{
		Vector2 v1(1, 2);
		Vector2 v2(3, 4);

		Vector2 v3 = v1 + v2;

		ASSERT_EQ(v3.x, 4);
		ASSERT_EQ(v3.y, 6);

		v1 += v2;

		ASSERT_EQ(v1.x, 4);
		ASSERT_EQ(v1.y, 6);
	}

	TEST(Vector2, Sub)
	{
		Vector2 v1(5, 10);
		Vector2 v2(3, 4);

		Vector2 v3 = v1 - v2;

		ASSERT_EQ(v3.x, 2);
		ASSERT_EQ(v3.y, 6);

		v1 -= v2;

		ASSERT_EQ(v1.x, 2);
		ASSERT_EQ(v1.y, 6);

	}

	TEST(Vector2, Cross)
	{
		Vector2 v1(5, -10);
		Vector2 v2(3, 4);

		Vector3 v3 = v1.Cross(v2);

		ASSERT_EQ(v3.z, 50);
	}

	TEST(Vector2, Dot)
	{
		Vector2 v1(1, 2);
		Vector2 v2(3, 4);

		float value = v1.Dot(v2);

		ASSERT_EQ(value, 11);
	}

	TEST(Vector2, MulScalar)
	{
		Vector2 v1(5, 10);

		Vector2 v2 = v1 * 2;

		ASSERT_EQ(v2.x, 10);
		ASSERT_EQ(v2.y, 20);

		v1 *= 2;

		ASSERT_EQ(v1.x, 10);
		ASSERT_EQ(v1.y, 20);

	}

	TEST(Vector2, DivScalar)
	{
		Vector2 v1(5, 10);

		Vector2 v2 = v1 / 5;

		ASSERT_EQ(v2[0], 1);
		ASSERT_EQ(v2[1], 2);

		v1 /= 5;

		ASSERT_EQ(v1.x, 1);
		ASSERT_EQ(v1.y, 2);
	}

	TEST(Vector2, Equals)
	{
		Vector2 v1(1, 2);
		Vector2 v2(1, 2);
		Vector2 v3(2, 1);

		ASSERT_TRUE(v1 == v1);
		ASSERT_TRUE(v1 == v2);
		ASSERT_FALSE(v1 == v3);
	}

	TEST(Vector2, NotEquals)
	{
		Vector2 v1(1, 2);
		Vector2 v2(1, 2);
		Vector2 v3(2, 1);

		ASSERT_FALSE(v1 != v1);
		ASSERT_FALSE(v1 != v2);
		ASSERT_TRUE(v1 != v3);
	}
};

namespace Vec3
{
	TEST(Vector3, Constructor)
	{
		Vector3 v1;
		Vector3 v2(2, 5);
		Vector3 v3(1, 3, 4);

		ASSERT_EQ(v1.x, 0);
		ASSERT_EQ(v1.y, 0);
		ASSERT_EQ(v1.z, 0);

		ASSERT_EQ(v2.x, 2);
		ASSERT_EQ(v2.y, 5);
		ASSERT_EQ(v2.z, 0);
		
		ASSERT_EQ(v3.x, 1);
		ASSERT_EQ(v3.y, 3);
		ASSERT_EQ(v3.z, 4);
	}

	TEST(Vector3, CopyConstructor)
	{
		Vector3 v1(1, 2, 3);
		Vector3 v2 = v1;

		ASSERT_EQ(v2.x, 1);
		ASSERT_EQ(v2.y, 2);
		ASSERT_EQ(v2.z, 3);
	}

	TEST(Vector3, Set)
	{
		Vector3 v1;

		v1[0] = 2;
		v1[1] = 5;
		v1[2] = 10;

		ASSERT_EQ(v1.x, 2);
		ASSERT_EQ(v1.y, 5);
		ASSERT_EQ(v1.z, 10);
	}

	TEST(Vector3, Assign)
	{
		Vector3 v1(1, 2, 3);
		Vector3 v2;
		v2 = v1;

		ASSERT_EQ(v2.x, 1);
		ASSERT_EQ(v2.y, 2);
		ASSERT_EQ(v2.z, 3);
	}

	TEST(Vector3, Add)
	{
		Vector3 v1(1, 2, 3);
		Vector3 v2(4, 5, 6);

		Vector3 v3 = v1 + v2;

		ASSERT_EQ(v3.x, 5);
		ASSERT_EQ(v3.y, 7);
		ASSERT_EQ(v3.z, 9);

		v1 += v2;

		ASSERT_EQ(v1.x, 5);
		ASSERT_EQ(v1.y, 7);
		ASSERT_EQ(v1.z, 9);
	}

	TEST(Vector3, Sub)
	{
		Vector3 v1(5, 10, 20);
		Vector3 v2(3, 4, 15);

		Vector3 v3 = v1 - v2;

		ASSERT_EQ(v3.x, 2);
		ASSERT_EQ(v3.y, 6);
		ASSERT_EQ(v3.z, 5);

		v1 -= v2;

		ASSERT_EQ(v1.x, 2);
		ASSERT_EQ(v1.y, 6);
		ASSERT_EQ(v1.z, 5);
	}

	TEST(Vector3, Cross)
	{
		Vector3 v1(5, -10, 20);
		Vector3 v2(3, 4, 1);

		Vector3 v3 = v1.Cross(v2);

		ASSERT_EQ(v3.x, -90);
		ASSERT_EQ(v3.y, 55);
		ASSERT_EQ(v3.z, 50);
	}

	TEST(Vector3, Dot)
	{
		Vector3 v1(1, 2, 3);
		Vector3 v2(4, 5, 6);

		float value = v1.Dot(v2);

		ASSERT_EQ(value, 32);
	}

	TEST(Vector3, MulScalar)
	{
		Vector3 v1(5, 10, 15);

		Vector3 v2 = v1 * 2;

		ASSERT_EQ(v2.x, 10);
		ASSERT_EQ(v2.y, 20);
		ASSERT_EQ(v2.z, 30);

		v1 *= 2;

		ASSERT_EQ(v1.x, 10);
		ASSERT_EQ(v1.y, 20);
		ASSERT_EQ(v1.z, 30);
	}

	TEST(Vector3, DivScalar)
	{
		Vector3 v1(5, 10, 15);

		Vector3 v2 = v1 / 5;

		ASSERT_EQ(v2.x, 1);
		ASSERT_EQ(v2.y, 2);
		ASSERT_EQ(v2.z, 3);

		v1 /= 5;

		ASSERT_EQ(v1.x, 1);
		ASSERT_EQ(v1.y, 2);
		ASSERT_EQ(v1.z, 3);
	}

	TEST(Vector3, Equals)
	{
		Vector3 v1(1, 2, 3);
		Vector3 v2(1, 2, 3);
		Vector3 v3(3, 2, 1);

		ASSERT_TRUE(v1 == v1);
		ASSERT_TRUE(v1 == v2);
		ASSERT_FALSE(v1 == v3);
	}

	TEST(Vector3, NotEquals)
	{
		Vector3 v1(1, 2, 3);
		Vector3 v2(1, 2, 3);
		Vector3 v3(3, 2, 1);

		ASSERT_FALSE(v1 != v1);
		ASSERT_FALSE(v1 != v2);
		ASSERT_TRUE(v1 != v3);
	}
}

namespace Vec4
{
	TEST(Vector4, Constructor)
	{
		Vector4 v1;
		Vector4 v2(2, 5);
		Vector4 v3(1, 3, 4);
		Vector4 v4(1, 2, 3, 4);

		ASSERT_EQ(v1.x, 0);
		ASSERT_EQ(v1.y, 0);
		ASSERT_EQ(v1.z, 0);
		ASSERT_EQ(v1.w, 0);
		
		ASSERT_EQ(v2.x, 2);
		ASSERT_EQ(v2.y, 5);
		ASSERT_EQ(v2.z, 0);
		ASSERT_EQ(v2.w, 0);

		ASSERT_EQ(v3.x, 1);
		ASSERT_EQ(v3.y, 3);
		ASSERT_EQ(v3.z, 4);
		ASSERT_EQ(v3.w, 0);
		
		ASSERT_EQ(v4.x, 1);
		ASSERT_EQ(v4.y, 2);
		ASSERT_EQ(v4.z, 3);
		ASSERT_EQ(v4.w, 4);
	}

	TEST(Vector4, CopyConstructor)
	{
		Vector4 v1(1, 2, 3, 4);
		Vector4 v2 = v1;

		ASSERT_EQ(v2.x, 1);
		ASSERT_EQ(v2.y, 2);
		ASSERT_EQ(v2.z, 3);
		ASSERT_EQ(v2.w, 4);
	}

	TEST(Vector4, Set)
	{
		Vector4 v1;

		v1[0] = 2;
		v1[1] = 5;
		v1[2] = 10;
		v1[3] = 20;

		ASSERT_EQ(v1.x, 2);
		ASSERT_EQ(v1.y, 5);
		ASSERT_EQ(v1.z, 10);
		ASSERT_EQ(v1.w, 20);
	}

	TEST(Vector4, Assign)
	{
		Vector4 v1(1, 2, 3, 4);
		Vector4 v2;
		v2 = v1;

		ASSERT_EQ(v2.x, 1);
		ASSERT_EQ(v2.y, 2);
		ASSERT_EQ(v2.z, 3);
		ASSERT_EQ(v2.w, 4);
	}

	TEST(Vector4, Add)
	{
		Vector4 v1(1, 2, 3, 4);
		Vector4 v2(5, 6, 7, 8);

		Vector4 v3 = v1 + v2;

		ASSERT_EQ(v3.x, 6);
		ASSERT_EQ(v3.y, 8);
		ASSERT_EQ(v3.z, 10);
		ASSERT_EQ(v3.w, 12);

		v1 += v2;

		ASSERT_EQ(v1.x, 6);
		ASSERT_EQ(v1.y, 8);
		ASSERT_EQ(v1.z, 10);
		ASSERT_EQ(v1.w, 12);
	}

	TEST(Vector4, Sub)
	{
		Vector4 v1(5, 10, 20, 50);
		Vector4 v2(3, 4, 15, 25);

		Vector4 v3 = v1 - v2;

		ASSERT_EQ(v3.x, 2);
		ASSERT_EQ(v3.y, 6);
		ASSERT_EQ(v3.z, 5);
		ASSERT_EQ(v3.w, 25);


		v1 -= v2;

		ASSERT_EQ(v1.x, 2);
		ASSERT_EQ(v1.y, 6);
		ASSERT_EQ(v1.z, 5);
		ASSERT_EQ(v1.w, 25);
	}

	TEST(Vector4, Dot)
	{
		Vector4 v1(1, 2, 3, 4);
		Vector4 v2(5, 6, 7, 8);

		float value = v1.Dot(v2);

		ASSERT_EQ(value, 70);
	}

	TEST(Vector4, MulScalar)
	{
		Vector4 v1(5, 10, 15, 20);

		Vector4 v2 = v1 * 2;

		ASSERT_EQ(v2.x, 10);
		ASSERT_EQ(v2.y, 20);
		ASSERT_EQ(v2.z, 30);
		ASSERT_EQ(v2.w, 40);

		v1 *= 2;

		ASSERT_EQ(v1.x, 10);
		ASSERT_EQ(v1.y, 20);
		ASSERT_EQ(v1.z, 30);
		ASSERT_EQ(v1.w, 40);
	}

	TEST(Vector4, DivScalar)
	{
		Vector4 v1(5, 10, 15, 20);

		Vector4 v2 = v1 / 5;

		ASSERT_EQ(v2.x, 1);
		ASSERT_EQ(v2.y, 2);
		ASSERT_EQ(v2.z, 3);
		ASSERT_EQ(v2.w, 4);

		v1 /= 5;

		ASSERT_EQ(v1.x, 1);
		ASSERT_EQ(v1.y, 2);
		ASSERT_EQ(v1.z, 3);
		ASSERT_EQ(v1.w, 4);
	}

	TEST(Vector4, Equals)
	{
		Vector4 v1(1, 2, 3, 4);
		Vector4 v2(1, 2, 3, 4);
		Vector4 v3(4, 3, 2, 1);

		ASSERT_TRUE(v1 == v1);
		ASSERT_TRUE(v1 == v2);
		ASSERT_FALSE(v1 == v3);
	}

	TEST(Vector4, NotEquals)
	{
		Vector4 v1(1, 2, 3, 4);
		Vector4 v2(1, 2, 3, 4);
		Vector4 v3(4, 3, 2, 1);

		ASSERT_FALSE(v1 != v1);
		ASSERT_FALSE(v1 != v2);
		ASSERT_TRUE(v1 != v3);
	}
}

namespace Quat
{

}

namespace Mat3x3
{

}

namespace Mat4x4
{

}
