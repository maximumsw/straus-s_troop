#include <iostream>
using namespace std;

int main() {
    // Кількість рядків в масиві (3)
    const int ROWS = 3;
    // Кількість стовпців в масиві (2)
    const int COLS = 2;
    // Змінна для суми елементів масиву
    float sum = 0;
    float average;



    // Ініціалізація двовимірного масиву із числами float
    float mass[ROWS][COLS] = {
      {4.5, 3.6},
      {6.7, 7.9},
      {5, 9},
    };
    // Змінні для зберігання мінімального та максимального значень
    int min_item = mass[0][0];
    int max_item = mass[0][0];

    

    // Перебір рядків масиву
    for (int i = 0; i < ROWS; i++) {
        // Перебір елементів рядка
        for (int j = 0; j < COLS; j++) {
            // Додавання значення елемента до суми
            sum += mass[i][j];
            // Оновлення мінімального значення, якщо знайдено менше
            if (mass[i][j] < min_item) {
                min_item = mass[i][j];
            }

            // Оновлення максимального значення, якщо знайдено більше
            else if (mass[i][j] > max_item) {
                max_item = mass[i][j];
            }
        }
    }

    // Розрахунок середнього арифметичного
    average = sum / (ROWS * COLS);

    
    
    // Вивід результатів
    cout << "The sum of all elements: " << sum << endl;
    cout << "Arithmetic mean of all elements of the array: " << average << endl;
    cout << "A minimal element: " << min_item << endl;
    cout << "Maximum element: " << max_item << endl;

    return 0;
}
