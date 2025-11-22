// Program 14: Program to create a singly linked list and perform insertion at beginning, middle, and end.
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

void insertAtBeginning(Node*& head, int value) {
    Node* temp = new Node;
    temp->data = value;
    temp->next = head;
    head = temp;
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

void insertAtPosition(Node*& head, int value, int pos) {
    if (pos == 0) {
        insertAtBeginning(head, value);
        return;
    }
    Node* temp = new Node;
    temp->data = value;
    Node* t = head;
    for (int i = 0; t != NULL && i < pos - 1; i++) {
        t = t->next;
    }
    if (t == NULL) {
        cout << "Position out of range" << endl;
        delete temp;
        return;
    }
    temp->next = t->next;
    t->next = temp;
}

int main() {
    Node* head = NULL;
    int choice, val, pos;
    do {
        cout << "\n1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. Traverse\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            insertAtBeginning(head, val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            insertAtEnd(head, val);
            break;
        case 3:
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter value: ";
            cin >> val;
            insertAtPosition(head, val, pos);
            break;
        case 4:
            traverse(head);
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);
    return 0;
}
