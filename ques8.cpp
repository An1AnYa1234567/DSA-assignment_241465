// Program 8: Program to calculate address of an element in a 2D array using row-major and column-major formulas.
#include <iostream>
using namespace std;

int main() {
    int base, rows, cols, i, j, w;
    cout << "Enter base address: ";
    cin >> base;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;
    cout << "Enter element indices (i j): ";
    cin >> i >> j;
    cout << "Enter size of each element (in bytes): ";
    cin >> w;

    int row_major = base + w * (i * cols + j);
    int col_major = base + w * (j * rows + i);

    cout << "Row-major address: " << row_major << endl;
    cout << "Column-major address: " << col_major << endl;
    return 0;
}
