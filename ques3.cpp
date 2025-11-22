// Program 3: Program to insert, delete, and traverse elements in a one-        dimensional array.
#include <iostream>
using namespace std;

int main() {
    int arr[100], n, choice, pos, value;
    cout << "Enter initial number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    do {
        cout << "\n1. Traverse\n2. Insert\n3. Delete\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Array elements: ";
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;

        case 2:
            cout << "Enter position (0 to " << n << "): ";
            cin >> pos;
            cout << "Enter value: ";
            cin >> value;
            if (pos < 0 || pos > n) {
                cout << "Invalid position!" << endl;
            } else {
                for (int i = n; i > pos; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[pos] = value;
                n++;
                cout << "Element inserted." << endl;
            }
            break;

        case 3:
            cout << "Enter position (0 to " << n - 1 << "): ";
            cin >> pos;
            if (pos < 0 || pos >= n) {
                cout << "Invalid position!" << endl;
            } else {
                for (int i = pos; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                n--;
                cout << "Element deleted." << endl;
            }
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
