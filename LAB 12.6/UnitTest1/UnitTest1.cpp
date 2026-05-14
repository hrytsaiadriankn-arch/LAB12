#include "pch.h"
#include "CppUnitTest.h"
#include "D:/1 курс 2 семестр/LAB 12.6/Project1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// підключаємо функцію з основного файлу
extern bool simulate(int n);

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		// n = 1 завжди повертає false
		TEST_METHOD(Test_N_Equals_1)
		{
			bool result = simulate(1);
			Assert::IsFalse(result);
		}

		// n = 2 також завжди повертає false
		TEST_METHOD(Test_N_Equals_2)
		{
			bool result = simulate(2);
			Assert::IsFalse(result);
		}

		// перевірка, що функція взагалі виконується без падіння
		TEST_METHOD(Test_Function_Runs_For_Larger_N)
		{
			for (int i = 0; i < 100; i++)
			{
				bool result = simulate(50);
				Assert::IsTrue(result == true || result == false);
			}
		}
	};
}