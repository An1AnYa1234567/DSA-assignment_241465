// Program 2: Recursive computation of factorial for a given number.
#include <iostream>
using namespace std;

long long factorial(int n) {
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (n < 0) {
        cout << "Factorial is not defined for negative numbers.";
    } else {
        cout << "Factorial of " << n << " is " << factorial(n);
    }
    return 0;
}
