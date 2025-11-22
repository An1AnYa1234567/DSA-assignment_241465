// Program 11: Program to implement queue using arrays with enqueue, dequeue, peek, and display.
#include <iostream>
using namespace std;

#define MAX 100

class Queue {
    int arr[MAX];
    int front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int x) {
        if (rear == MAX - 1) {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = x;
        cout << "Enqueued " << x << endl;
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow" << endl;
            return;
        }
        cout << "Dequeued " << arr[front++] << endl;
    }

    void peek() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
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
