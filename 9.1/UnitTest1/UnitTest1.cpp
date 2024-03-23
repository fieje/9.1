#include "pch.h"
#include "CppUnitTest.h"
#include "../9.1/Source.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestCalculateMinAverageGrade)
		{
			// Arrange
			Student students[3];
			students[0].physics_grade = 80;
			students[0].math_grade = 70;
			students[1].physics_grade = 90;
			students[1].math_grade = 85;
			students[2].physics_grade = 75;
			students[2].math_grade = 60;

			// Act
			double minAverage = calculateMinAverageGrade(students, 3);

			// Assert
			Assert::AreEqual(67.5, minAverage);
		}

		TEST_METHOD(TestCountGoodGrades)
		{
			// Arrange
			Student students[3];
			students[0].physics_grade = 3;
			students[0].math_grade = 4;
			students[1].physics_grade = 4;
			students[1].math_grade = 5;
			students[2].physics_grade = 5;
			students[2].math_grade = 3;

			// Act
			int goodPhysicsGrades = countGoodGrades(students, 3, "Physics");
			int goodMathGrades = countGoodGrades(students, 3, "Mathematics");
			int goodAdditionalGrades = countGoodGrades(students, 3, "Additional");

			// Assert
			Assert::AreEqual(2, goodPhysicsGrades);
			Assert::AreEqual(2, goodMathGrades);
			Assert::AreEqual(0, goodAdditionalGrades);
		}
	};
}
