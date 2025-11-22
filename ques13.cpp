// Program 13: Program to implement queue using two stacks.
#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks {
    stack<int> s1, s2;
public:
    void enqueue(int x) {
        s1.push(x);
        cout << "Enqueued " << x << endl;
    }

    void dequeue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue Underflow" << endl;
            return;
        }
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        cout << "Dequeued " << s2.top() << endl;
        s2.pop();
    }

    void display() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        stack<int> temp1 = s1, temp2 = s2;
        cout << "Queue elements (front to rear): ";
        while (!temp2.empty()) {
            cout << temp2.top() << " ";
            temp2.pop();
        }
        int n = temp1.size();
        int *a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = temp1.top();
            temp1.pop();
        }
        for (int i = n - 1; i >= 0; i--) {
            cout << a[i] << " ";
        }
        delete[] a;
        cout << endl;
    }
};

int main() {
    QueueUsingStacks q;
    int choice, value;
    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
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
            q.display();
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
