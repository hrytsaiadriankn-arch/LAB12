#include "pch.h"
#include "CppUnitTest.h"
#include "D:/LAB 12.1/Project1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    struct Node
    {
        int data;
        Node* a;
        Node* b;
    };

    // --- ÐÅÀË²ÇÀÖ²ß (ùîá íå áóëî ïîìèëêè) ---
    Node* CreateStructure()
    {
        Node* n1 = new Node{ 1, nullptr, nullptr };
        Node* n2 = new Node{ 2, nullptr, nullptr };
        Node* n3 = new Node{ 3, nullptr, nullptr };
        Node* n4 = new Node{ 4, nullptr, nullptr };

        Node* p = n1;

        n1->a = nullptr;
        n1->b = n2;

        n2->a = n1;
        n2->b = n4;

        n3->a = n2;
        n3->b = nullptr;

        n4->a = n1;
        n4->b = n3;

        return p;
    }

    void DeleteStructure(Node*& p)
    {
        Node* n1 = p;
        Node* n2 = p->b;
        Node* n4 = n2->b;
        Node* n3 = n4->b;

        delete n3;
        delete n4;
        delete n2;
        delete n1;

        p = nullptr;
    }

    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestCreateStructure)
        {
            Node* p = CreateStructure();

            Assert::IsNotNull(p);
            Assert::AreEqual(1, p->data);

            Assert::IsNull(p->a);
            Assert::IsNotNull(p->b);
            Assert::AreEqual(2, p->b->data);

            Node* n2 = p->b;
            Assert::AreEqual(1, n2->a->data);

            Node* n4 = n2->b;
            Assert::AreEqual(4, n4->data);
            Assert::AreEqual(1, n4->a->data);

            Node* n3 = n4->b;
            Assert::AreEqual(3, n3->data);
            Assert::AreEqual(2, n3->a->data);
            Assert::IsNull(n3->b);

            DeleteStructure(p);
        }

        TEST_METHOD(TestDeleteStructure)
        {
            Node* p = CreateStructure();

            DeleteStructure(p);

            Assert::IsNull(p);
        }
    };
}