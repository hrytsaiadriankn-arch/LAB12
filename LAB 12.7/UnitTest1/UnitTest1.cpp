#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// ---------------- NODE ----------------
struct Node {
    int data;
    Node* next;
};

// ---------------- HELPERS ----------------
Node* createNode(int value)
{
    Node* n = new Node;
    n->data = value;
    n->next = nullptr;
    return n;
}

void append(Node*& head, int value)
{
    Node* n = createNode(value);

    if (!head) {
        head = n;
        return;
    }

    Node* cur = head;
    while (cur->next)
        cur = cur->next;

    cur->next = n;
}

Node* createList(std::initializer_list<int> vals)
{
    Node* head = nullptr;
    for (int v : vals)
        append(head, v);
    return head;
}

std::string toString(Node* head)
{
    std::string s;
    while (head)
    {
        s += std::to_string(head->data) + " ";
        head = head->next;
    }
    return s;
}

// ---------------- FUNCTIONS ----------------
void deleteEven(Node*& head)
{
    while (head && head->data % 2 == 0)
    {
        Node* t = head;
        head = head->next;
        delete t;
    }

    Node* cur = head;

    while (cur && cur->next)
    {
        if (cur->next->data % 2 == 0)
        {
            Node* t = cur->next;
            cur->next = cur->next->next;
            delete t;
        }
        else
            cur = cur->next;
    }
}

void doubleOddPositions(Node* head)
{
    int pos = 1;
    while (head)
    {
        if (pos % 2 == 1)
            head->data *= 2;

        head = head->next;
        pos++;
    }
}

void insertSublist(Node*& head, Node* sub, int pos)
{
    if (!sub) return;

    if (pos == 1)
    {
        Node* tail = sub;
        while (tail->next) tail = tail->next;

        tail->next = head;
        head = sub;
        return;
    }

    Node* cur = head;

    for (int i = 1; i < pos - 1 && cur; i++)
        cur = cur->next;

    if (!cur) return;

    Node* tail = sub;
    while (tail->next) tail = tail->next;

    tail->next = cur->next;
    cur->next = sub;
}

// ---------------- TESTS ----------------
namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestDeleteEven)
        {
            Node* head = createList({ 1,2,3,4,5 });
            deleteEven(head);

            Assert::AreEqual(std::string("1 3 5 "), toString(head));
        }

        TEST_METHOD(TestDoubleOddPositions)
        {
            Node* head = createList({ 1,3,5 });
            doubleOddPositions(head);

            Assert::AreEqual(std::string("2 3 10 "), toString(head));
        }

        TEST_METHOD(TestInsertSublist)
        {
            Node* head = createList({ 2,3,10 });

            Node* sub = nullptr;
            append(sub, 10);
            append(sub, 20);
            append(sub, 30);

            insertSublist(head, sub, 2);

            Assert::AreEqual(std::string("2 10 20 30 3 10 "), toString(head));
        }

        TEST_METHOD(TestVariant14Full)
        {
            Node* head = createList({ 1,2,3,4,5 });

            deleteEven(head);
            doubleOddPositions(head);

            Node* sub = nullptr;
            append(sub, 10);
            append(sub, 20);
            append(sub, 30);

            insertSublist(head, sub, 2);

            Assert::AreEqual(std::string("2 10 20 30 3 10 "), toString(head));
        }
    };
}