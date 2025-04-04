#include <iostream>
using namespace std;

const int MAX_ROWS = 100; 
const int MAX_COLS = 100;

void deleteRow(int array[][MAX_COLS], int& rowCount, int colCount, int rowNumber) {
    if (rowNumber >= 0 && rowNumber < rowCount) {
        for (int i = rowNumber; i < rowCount - 1; ++i) {
            for (int j = 0; j < colCount; ++j) {
                array[i][j] = array[i + 1][j];
            }
        }

        --rowCount; 
    }
    else {
        cout << "Invalid number of ROW" << endl;
    }
}

int main() {
    int array[MAX_ROWS][MAX_COLS] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} }; 
    int rowCount = 3; 
    int colCount = 3; 
    int rowNumber = 1; 

    deleteRow(array, rowCount, colCount, rowNumber);

    cout << "Two-dimensional array after deleting row number " << rowNumber << ":\n";
    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < colCount; ++j) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
