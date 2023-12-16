#include "pch.h"
#include "CppUnitTest.h"
#include "..\ConsoleApplication1\rectangle.h"
#include "..\ConsoleApplication1\rectangle.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(RectangleTests)
	{
	public:

		TEST_METHOD(TestMove)
		{
			Rectangle rect(1, 1, 4, 4);

			rect.move(2, 3);

			Assert::AreEqual(3.0, rect.getX1());
			Assert::AreEqual(4.0, rect.getY1());
			Assert::AreEqual(6.0, rect.getX2());
			Assert::AreEqual(7.0, rect.getY2());
		}

		TEST_METHOD(TestResize)
		{
			Rectangle rect(1, 1, 4, 4);

			rect.resize(2, 3);

			Assert::AreEqual(1.0, rect.getX1());
			Assert::AreEqual(1.0, rect.getY1());
			Assert::AreEqual(6.0, rect.getX2());
			Assert::AreEqual(7.0, rect.getY2());
		}

		TEST_METHOD(TestMinimumBoundingRectangle)
		{
			Rectangle rect1(1, 1, 4, 4);
			Rectangle rect2(3, 2, 6, 5);

			Rectangle boundingRect = rect1.minimumBoundingRectangle(rect2);

			Assert::AreEqual(1.0, boundingRect.getX1());
			Assert::AreEqual(1.0, boundingRect.getY1());
			Assert::AreEqual(6.0, boundingRect.getX2());
			Assert::AreEqual(5.0, boundingRect.getY2());
		}

		TEST_METHOD(TestIntersection)
		{
			Rectangle rect1(1, 1, 4, 4);
			Rectangle rect2(3, 2, 6, 5);

			Rectangle intersectionRect = rect1.intersection(rect2);

			Assert::AreEqual(3.0, intersectionRect.getX1());
			Assert::AreEqual(2.0, intersectionRect.getY1());
			Assert::AreEqual(4.0, intersectionRect.getX2());
			Assert::AreEqual(4.0, intersectionRect.getY2());
		}
	};
}
