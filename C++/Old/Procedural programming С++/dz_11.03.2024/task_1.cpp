#include <iostream>
#include <cstring> 
using namespace std;

void adding_in_two_dimensional_array(char** array2D, char* array1D, int COLS, int i) {
    for (int j = 0; j <= COLS; ++j) {
        array2D[i][j] = array1D[j];
        if (j == COLS) {
            array2D[i][j] = '\0';
        }
    }
}

bool my_compare(char* n1, char* n2) {
    int i = 0;
    while (n1[i] != '\0' && n2[i] != '\0') {
        if (n1[i] > n2[i]) {
            return true;
        }
        else if (n1[i] < n2[i]) {
            return false;
        }
        i++;
    }
    return (n1[i] == '\0' && n2[i] != '\0');
}

void sorting(char** array2D, int ROWS) {
    for (int i = 0; i < ROWS - 1; i++) {
        for (int j = 0; j < ROWS - i - 1; j++) {
            if (my_compare(array2D[j], array2D[j + 1])) {
                char* temp = array2D[j];
                array2D[j] = array2D[j + 1];
                array2D[j + 1] = temp;
            }
        }
    }
}

int main() {
    const int ROWS = 5;
    const int COLS = 100;
    char** array_of_surnames = new char* [ROWS];
    for (int i = 0; i < ROWS; ++i) {
        array_of_surnames[i] = new char[COLS];
    }
    char array_for_add[COLS];

    for (int i = 0; i < ROWS; i++) {
        cout << "Input surname:\n";
        cin.getline(array_for_add, COLS);
        adding_in_two_dimensional_array(array_of_surnames, array_for_add, strlen(array_for_add), i);
    }

    sorting(array_of_surnames, ROWS);

    cout << "Sorted array:\n";
    for (int i = 0; i < ROWS; i++) {
        cout << array_of_surnames[i] << endl;
    }

    for (int i = 0; i < ROWS; ++i) {
        delete[] array_of_surnames[i];
    }
    delete[] array_of_surnames;

    return 0;
}

