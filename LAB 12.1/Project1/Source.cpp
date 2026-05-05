#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* a;
    Node* b;
};

// створення структури
Node* CreateStructure()
{
    // створюємо вузли
    Node* n1 = new Node{ 1, nullptr, nullptr };
    Node* n2 = new Node{ 2, nullptr, nullptr };
    Node* n3 = new Node{ 3, nullptr, nullptr };
    Node* n4 = new Node{ 4, nullptr, nullptr };

    // будуємо зв’язки (по схемі)

    // p -> 1
    Node* p = n1;

    // 1
    n1->a = nullptr;   // перекреслений блок
    n1->b = n2;

    // 2
    n2->a = n1;
    n2->b = n4;

    // 3
    n3->a = n2;
    n3->b = nullptr;

    // 4
    n4->a = n1;
    n4->b = n3;

    return p;
}

// вивід (обмежений, щоб не зациклитись)
void Print(Node* p)
{
    cout << "Start node: " << p->data << endl;

    if (p->b)
        cout << "p->b: " << p->b->data << endl;
}

// знищення структури
void DeleteStructure(Node*& p)
{
    // вручну видаляємо всі вузли
    // (бо структура НЕ лінійна!)

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

int main()
{
    Node* p = CreateStructure();

    Print(p);

    DeleteStructure(p);

    return 0;
}