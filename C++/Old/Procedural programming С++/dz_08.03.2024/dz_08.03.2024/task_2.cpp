using namespace std;

const int MAX_ROWS = 100;
const int MAX_COLS = 100;

void addRowToEnd(int array[][MAX_COLS], int rowCount, int colCount, int newRow[]) {
    if (rowCount < MAX_ROWS) {
        for (int i = 0; i < colCount; ++i) {
            array[rowCount - rowCount][i] = newRow[i];
        }
    }
    else {
        cout << "Maximum number of rows exceeded" << endl;
    }
}

int main() {
    int array[MAX_ROWS][MAX_COLS] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int rowCount = 3;
    int colCount = 3;

    int newRow[] = { 10, 11, 12 };

    addRowToEnd(array, rowCount, colCount, newRow);

    cout << "Two dimensional array after adding a row:\n";
    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < colCount; ++j) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
