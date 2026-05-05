#include "pch.h"
#include "CppUnitTest.h"

// Підключаєш свій файл з кодом
#include "D:/LAB12.2 Іт/Project1/Source.cpp"  

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Test_HasAdjacent_True)
		{
			Node* head = nullptr;

			appendNode(head, 1);
			appendNode(head, 2);
			appendNode(head, 2);
			appendNode(head, 4);

			bool result = hasEqualAdjacent(head);

			Assert::IsTrue(result);

			deleteList(head);
		}

		TEST_METHOD(Test_HasAdjacent_False)
		{
			Node* head = nullptr;

			appendNode(head, 1);
			appendNode(head, 2);
			appendNode(head, 3);
			appendNode(head, 4);

			bool result = hasEqualAdjacent(head);

			Assert::IsFalse(result);

			deleteList(head);
		}

		TEST_METHOD(Test_EmptyList)
		{
			Node* head = nullptr;

			bool result = hasEqualAdjacent(head);

			Assert::IsFalse(result);
		}

		TEST_METHOD(Test_OneElement)
		{
			Node* head = nullptr;

			appendNode(head, 5);

			bool result = hasEqualAdjacent(head);

			Assert::IsFalse(result);

			deleteList(head);
		}

		TEST_METHOD(Test_AllSame)
		{
			Node* head = nullptr;

			appendNode(head, 7);
			appendNode(head, 7);
			appendNode(head, 7);

			bool result = hasEqualAdjacent(head);

			Assert::IsTrue(result);

			deleteList(head);
		}
	};
}