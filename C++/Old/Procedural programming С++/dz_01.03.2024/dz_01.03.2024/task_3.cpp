#include <iostream>
using namespace std;

// Функція для сортування масиву за знаком чисел
void sort_by_sign(int* array, int* zeroes_arr, int* positive_arr, int* negative_arr, int N);

int main() {
    const int N = 5;
    int counter_zeroes = 0, counter_positive = 0, counter_negative = 0;
    int array[] = { -0, 0, -96, 2, 8 };

    // Підрахунок кількості елементів кожного знаку
    for (int i = 0; i < N; i++) {
        if (array[i] == 0) {
            counter_zeroes++;
        }
        else if (array[i] > 0) {
            counter_positive++;
        }
        else if (array[i] < 0) {
            counter_negative++;
        }
    }

    // Динамічне виділення пам'яті для масивів
    int* zeroes_arr = new int[counter_zeroes] {};
    int* positive_arr = new int[counter_positive] {};
    int* negative_arr = new int[counter_negative] {};

    int* ptr_array = array;
    int* ptr_zeroes_arr = zeroes_arr;
    int* ptr_positive_arr = positive_arr;
    int* ptr_negative_arr = negative_arr;

    // Функція сортування за викликом за посиланнями
    sort_by_sign(ptr_array, ptr_zeroes_arr, ptr_positive_arr, ptr_negative_arr, N);

    cout << "Zero: ";
    for (int i = 0; i < counter_zeroes; i++) {
        cout << zeroes_arr[i] << " ";
    }
    cout << endl;

    cout << "Positive nums: ";
    for (int i = 0; i < counter_positive; i++) {
        cout << positive_arr[i] << " ";
    }
    cout << endl;

    cout << "Negative nums: ";
    for (int i = 0; i < counter_negative; i++) {
        cout << negative_arr[i] << " ";
    }
    cout << endl;

    // Звільнення динамічно виділеної пам'яті
    delete[] zeroes_arr;
    delete[] positive_arr;
    delete[] negative_arr;

    return 0;
}

// Функція сортування масиву за знаком чисел
void sort_by_sign(int* array, int* zeroes_arr, int* positive_arr, int* negative_arr, int N) {
    int counter_zeroes = 0;
    int counter_positive = 0;
    int counter_negative = 0;

    for (int i = 0; i < N; i++) {
        if (array[i] == 0) {
            zeroes_arr[counter_zeroes++] = array[i];
        }
        else if (array[i] > 0) {
            positive_arr[counter_positive++] = array[i];
        }
        else if (array[i] < 0) {
            negative_arr[counter_negative++] = array[i];
        }
    }
}
