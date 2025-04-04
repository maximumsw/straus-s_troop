#include <iostream>

using namespace std;

// Функція для друку двовимірного масиву
void printArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Функція для додавання рядка в кінець двовимірного масиву
void addRowAtEnd(int** arr, int& rows, int cols, int* newRow) {
    // Збільшити розмір рядків на 1
    rows++;

    // Перерозподілити пам'ять для нового масиву
    int** temp = new int* [rows];
    for (int i = 0; i < rows; i++) {
        temp[i] = new int[cols];
    }

    // Скопіювати дані з старого масиву в новий
    for (int i = 0; i < rows - 1; i++) {
        for (int j = 0; j < cols; j++) {
            temp[i][j] = arr[i][j];
        }
    }

    // Додати новий рядок в кінець
    for (int j = 0; j < cols; j++) {
        temp[rows - 1][j] = newRow[j];
    }

    // Вивільнити пам'ять старого масиву
    for (int i = 0; i < rows - 1; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    // Зробити temp новим масивом
    arr = temp;
}

int main() {
    int rows = 3, cols = 4;
    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

    // Заповнити масив даними
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = i * cols + j;
        }
    }

    // Рядок, який потрібно додати
    int newRow[cols] = { 4, 5, 6, 7 };

    // Додати рядок в кінець
    addRowAtEnd(arr, rows, cols, newRow);

    // Вивести масив
    cout << "Масив після додавання рядка в кінець:" << endl;
    printArray(arr, rows, cols);

    return 0;
}
