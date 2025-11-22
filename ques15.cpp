// Program 15: Program to delete a node from a singly linked list by value or position.
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void traverse(Node* head) {
    cout << "List: ";
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void insertAtEnd(Node*& head, int value) {
    Node* temp = new Node;
    temp->data = value;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
        return;
    }
    Node* t = head;
    while (t->next != NULL) {
        t = t->next;
    }
    t->next = temp;
}

void deleteByValue(Node*& head, int value) {
    if (head == NULL) return;
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* t = head;
    while (t->next != NULL && t->next->data != value) {
        t = t->next;
    }
    if (t->next == NULL) {
        cout << "Value not found" << endl;
        return;
    }
    Node* temp = t->next;
    t->next = t->next->next;
    delete temp;
}

void deleteByPosition(Node*& head, int pos) {
    if (head == NULL) return;
    if (pos == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* t = head;
    for (int i = 0; t != NULL && i < pos - 1; i++) {
        t = t->next;
    }
    if (t == NULL || t->next == NULL) {
        cout << "Position out of range" << endl;
        return;
    }
    Node* temp = t->next;
    t->next = t->next->next;
    delete temp;
}

int main() {
    Node* head = NULL;
    int choice, val, pos;
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    do {
        cout << "\n1. Traverse\n2. Delete by value\n3. Delete by position\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            traverse(head);
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> val;
            deleteByValue(head, val);
            break;
        case 3:
            cout << "Enter position to delete: ";
            cin >> pos;
            deleteByPosition(head, pos);
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);
    return 0;
}
