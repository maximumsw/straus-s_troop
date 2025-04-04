#include <iostream>
using namespace std;

const int MAX_ROWS = 100;
const int MAX_COLS = 100;

void addRowToPosition(int array[][MAX_COLS], int& rowCount, int colCount, int position, int newRow[]) {
    if (position >= 0 && position <= rowCount && rowCount < MAX_ROWS) {
        for (int i = rowCount; i > position; --i) {
            for (int j = 0; j < colCount; ++j) {
                array[i][j] = array[i - 1][j];
            }
        }

        for (int i = 0; i < colCount; ++i) {
            array[position][i] = newRow[i];
        }

        ++rowCount;
    }
    else {
        cout << "Invalid position or maximum number of rows exceeded" << endl;
    }
}

int main() {
    int array[MAX_ROWS][MAX_COLS] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int rowCount = 3;
    int colCount = 3;
    int newRow[] = { 10, 11, 12 };
    int position = 2;

    addRowToPosition(array, rowCount, colCount, position, newRow);

    cout << "Two dimensional array after adding a row to position " << position << ":\n";
    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < colCount; ++j) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
