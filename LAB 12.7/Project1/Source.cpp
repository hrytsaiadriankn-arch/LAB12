#include <iostream>
using namespace std;

// ---------------- NODE ----------------
struct Node {
    int data;
    Node* next;
};

// ---------------- CREATE NODE ----------------
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// ---------------- APPEND ----------------
void append(Node*& head, int value) {
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

// ---------------- PRINT ----------------
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// ---------------- DELETE EVEN VALUES ----------------
void deleteEven(Node*& head) {
    while (head != nullptr && head->data % 2 == 0) {
        Node* t = head;
        head = head->next;
        delete t;
    }

    Node* cur = head;

    while (cur != nullptr && cur->next != nullptr) {
        if (cur->next->data % 2 == 0) {
            Node* t = cur->next;
            cur->next = cur->next->next;
            delete t;
        }
        else {
            cur = cur->next;
        }
    }
}

// ---------------- DOUBLE ODD POSITIONS (1,3,5...) ----------------
void doubleOddPositions(Node* head) {
    int pos = 1;
    Node* temp = head;

    while (temp != nullptr) {
        if (pos % 2 == 1) {   // 1,3,5...
            temp->data *= 2;
        }
        temp = temp->next;
        pos++;
    }
}

// ---------------- CREATE SUBLIST ----------------
Node* createSublist(int n) {
    Node* head = nullptr;

    cout << "Enter " << n << " elements for sublist:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        append(head, x);
    }

    return head;
}

// ---------------- INSERT SUBLIST (1-based) ----------------
void insertSublist(Node*& head, Node* sublist, int position) {
    if (!sublist) return;

    if (position == 1) {
        Node* tail = sublist;
        while (tail->next != nullptr)
            tail = tail->next;

        tail->next = head;
        head = sublist;
        return;
    }

    Node* cur = head;

    for (int i = 1; i < position - 1 && cur != nullptr; i++) {
        cur = cur->next;
    }

    if (!cur) return;

    Node* tail = sublist;
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    tail->next = cur->next;
    cur->next = sublist;
}

// ---------------- DELETE LIST ----------------
void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* t = head;
        head = head->next;
        delete t;
    }
}

// ---------------- MAIN ----------------
int main() {
    Node* head = nullptr;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        append(head, x);
    }

    cout << "\nOriginal list:\n";
    printList(head);

    // 1. delete even values
    deleteEven(head);

    // 2. double elements on odd positions (1,3,5...)
    doubleOddPositions(head);

    cout << "\nAfter processing:\n";
    printList(head);

    // 3. sublist
    int m, pos;

    cout << "\nEnter sublist size: ";
    cin >> m;

    Node* sublist = createSublist(m);

    cout << "Enter position to insert sublist: ";
    cin >> pos;

    insertSublist(head, sublist, pos);

    cout << "\nFinal list:\n";
    printList(head);

    deleteList(head);

    return 0;
}