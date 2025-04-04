#include <iostream>
#include <ctime>
using namespace std;

int main() {
    const int ROWS1 = 5;
    const int COLS1 = 10;
    const int ROWS2 = 5;
    const int COLS2 = 5;
    srand(time(nullptr));

    // Объявление и инициализация первого массива
    int array1[ROWS1][COLS1];
    cout << "1st array:" << endl;
    for (int i = 0; i < ROWS1; ++i) {
        for (int j = 0; j < COLS1; ++j) {
            array1[i][j] = rand() % 51; // генерируем числа от 0 до 50
            cout << array1[i][j] << "\t";
        }
        cout << endl;
    }

    // Объявление и инициализация второго массива
    int array2[ROWS2][COLS2];
    cout << endl << "2nd array:" << endl;
    for (int i = 0; i < ROWS2; ++i) {
        for (int j = 0; j < COLS2; ++j) {
            // Считаем сумму двух соседних элементов из первого массива
            array2[i][j] = array1[i][2 * j] + array1[i][2 * j + 1];
            cout << array2[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
