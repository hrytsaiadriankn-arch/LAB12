#include <iostream>
#include <windows.h>
using namespace std;

// Структура вузла списку
struct Node {
    int data;
    Node* next;
};

// Функція створення нового вузла
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Функція додавання елемента в кінець списку
void appendNode(Node*& head, int value) {
    Node* newNode = createNode(value);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Функція створення списку
Node* createList(int n) {
    Node* head = nullptr;
    int value;

    cout << "Введіть " << n << " елементів списку:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        appendNode(head, value);
    }

    return head;
}

// Функція виводу списку
void printList(Node* head) {
    Node* temp = head;
    cout << "Список: ";

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Функція перевірки
bool hasEqualAdjacent(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return false;

    Node* temp = head;

    while (temp->next != nullptr) {
        if (temp->data == temp->next->data) {
            return true;
        }
        temp = temp->next;
    }

    return false;
}

// Видалення списку
void deleteList(Node*& head) {
    Node* temp;

    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    setlocale(LC_ALL, "ukr");
    // Встановлення української локалі
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    int n;
    cout << "Введіть кількість елементів: ";
    cin >> n;

    Node* list = createList(n);

    printList(list);

    if (hasEqualAdjacent(list)) {
        cout << "У списку є сусідні однакові елементи.\n";
    }
    else {
        cout << "У списку НЕМАЄ сусідніх однакових елементів.\n";
    }

    deleteList(list);

    return 0;
}