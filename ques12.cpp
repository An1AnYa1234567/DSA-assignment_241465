// Program 12: Program to implement queue using linked list with dynamic memory allocation.
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
    Node* front;
    Node* rear;
public:
    Queue() {
        front = rear = NULL;
    }

    void enqueue(int x) {
        Node* temp = new Node;
        temp->data = x;
        temp->next = NULL;
        if (rear == NULL) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
        cout << "Enqueued " << x << endl;
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow" << endl;
            return;
        }
        Node* temp = front;
        cout << "Dequeued " << front->data << endl;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete temp;
    }

    void peek() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Front element: " << front->data << endl;
    }

    void display() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;
    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            q.display();
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
