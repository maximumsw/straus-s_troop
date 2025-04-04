#include <ctime> 
using namespace std;

bool findElement(int** arr, int rows, int cols, int target) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (arr[i][j] == target) {
                return true;
            }
        }
    }
    return false;
}

void taskFirst(int** A, int** B, int** C, int* ValueOfArray, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (findElement(A, rows, cols, B[i][j]) && findElement(C, rows, cols, B[i][j])) {
                ValueOfArray[i * cols + j] = B[i][j];
            }
        }
    }
}

void taskSecond(int** A, int** B, int** C, int* ValueOfArray, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!findElement(A, rows, cols, B[i][j]) && !findElement(C, rows, cols, B[i][j])) {
                ValueOfArray[i * cols + j] = B[i][j];
            }
        }
    }
}

void taskThird(int** A, int** C, int* ValueOfArray, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (findElement(A, rows, cols, C[i][j])) {
                ValueOfArray[i * cols + j] = C[i][j];
            }
        }
    }
}

void taskFour(int** A, int** B, int** C, int* ValueOfArray, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (A[i][j] < 0 && C[i][j] < 0) {
                if (findElement(A, rows, cols, B[i][j]) && findElement(C, rows, cols, B[i][j])) {
                    ValueOfArray[i * cols + j] = B[i][j];
                }
            }
        }
    }
}

void fillArray(int** array, int rows, int cols) {
    srand(time(NULL));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = -10 + rand() % 10;
            if (array[i][j] == 0) {
                j--;
                i--;
            }
        }
    }
}

void Print(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int min_of_three(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

int main() {
    int rowsA, rowsB, rowsC;
    int colsA, colsB, colsC;
    cout << "Input row for array A: ";
    cin >> rowsA;
    cout << "Input row for array B: ";
    cin >> rowsB;
    cout << "Input row for array C: ";
    cin >> rowsC;

    cout << "Input colm for array A: ";
    cin >> colsA;
    cout << "Input colm for array B: ";
    cin >> colsB;
    cout << "Input colm for array C: ";
    cin >> colsC;

    int** A = new int* [rowsA];
    for (int i = 0; i < rowsA; ++i) {
        A[i] = new int[colsA];
    }

    int** B = new int* [rowsB];
    for (int i = 0; i < rowsB; ++i) {
        B[i] = new int[colsB];
    }

    int** C = new int* [rowsC];
    for (int i = 0; i < rowsC; ++i) {
        C[i] = new int[colsC];
    }

    fillArray(A, rowsA, colsA);
    fillArray(B, rowsB, colsB);
    fillArray(C, rowsC, colsC);

    cout << "Array A:" << endl;
    Print(A, rowsA, colsA);
    cout << endl;

    cout << "Array B:" << endl;
    Print(B, rowsB, colsB);
    cout << endl;

    cout << "Array C:" << endl;
    Print(C, rowsC, colsC);
    cout << endl;

    int rows = min_of_three(rowsA, rowsB, rowsC);
    int cols = min_of_three(colsA, colsB, colsC);
    int* ValueOfArrayFromFirstTask = new int[rows * cols]();
    int* ValueOfArrayFromSecondTask = new int[rows * cols]();
    int* ValueOfArrayFromThirdTask = new int[rows * cols]();
    int* ValueOfArrayFromFourTask = new int[rows * cols]();

    taskFirst(A, B, C, ValueOfArrayFromFirstTask, rows, cols);

    cout << "Result first task (the result is approximately):" << endl;
    for (int i = 0; i < rows * cols; ++i) {
        if (ValueOfArrayFromFirstTask[i] == 0) {
            continue;
        }
        cout << ValueOfArrayFromFirstTask[i] << " ";
    }
    cout << endl;

    taskSecond(A, B, C, ValueOfArrayFromSecondTask, rows, cols);

    cout << "Result second task (the result is approximately):" << endl;
    for (int i = 0; i < rows * cols; ++i) {
        if (ValueOfArrayFromSecondTask[i] == 0) {
            continue;
        }
        cout << ValueOfArrayFromSecondTask[i] << " ";
    }
    cout << endl;

    taskThird(A, C, ValueOfArrayFromThirdTask, rows, cols);

    cout << "Result third task (the result is approximately):" << endl;
    for (int i = 0; i < rows * cols; ++i) {
        if (ValueOfArrayFromThirdTask[i] == 0) {
            continue;
        }
        cout << ValueOfArrayFromThirdTask[i] << " ";
    }
    cout << endl;

    taskFour(A, B, C, ValueOfArrayFromFourTask, rows, cols);

    cout << "Result fourth task (the result is approximately):" << endl;
    for (int i = 0; i < rows * cols; ++i) {
        if (ValueOfArrayFromFourTask[i] == 0) {
            continue;
        }
        cout << ValueOfArrayFromFourTask[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < rowsA; ++i) {
        delete[] A[i];
    }
    delete[] A;
    for (int i = 0; i < rowsB; ++i) {
        delete[] B[i];
    }
    delete[] B;
    for (int i = 0; i < rowsC; ++i) {
        delete[] C[i];
    }
    delete[] C;
    return 0;
}