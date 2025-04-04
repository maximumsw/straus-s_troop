#include <iostream>
using namespace std;

int main()
{
    srand(time(0));

    const int SIZE = 5;
    int array1[SIZE] = {};
    int array2[SIZE] = {};
    int result[2 * SIZE] = {};

    int result_index = 0;

    for (int i = 0; i < SIZE; i++) {
        array1[i] = rand() % (10 - 0) + 0;
        array2[i] = rand() % (10 - 0) + 0;
    }


    for (int i = 0; i < SIZE; i++) {
        if (array1[i] > 0) {
            result[result_index++] = array1[i];
        }
    }
    for (int i = 0; i < SIZE; i++) {
        if (array2[i] > 0) {
            result[result_index++] = array2[i];
        }
    }


    for (int i = 0; i < SIZE; i++) {
        if (array1[i] == 0) {
            result[result_index++] = array1[i];
        }
    }
    for (int i = 0; i < SIZE; i++) {
        if (array2[i] == 0) {
            result[result_index++] = array2[i];
        }
    }


    for (int i = 0; i < SIZE; i++) {
        if (array1[i] < 0) {
            result[result_index++] = array1[i];
        }
    }
    for (int i = 0; i < SIZE; i++) {
        if (array2[i] < 0) {
            result[result_index++] = array2[i];
        }
    }


    cout << "Array: ";
    for (int i = 0; i < 2 * SIZE; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
