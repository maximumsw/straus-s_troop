#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 4;

int main() {
    int array[ROWS][COLS] = {
        {4, 3, 1, 123},
        {5, 0, 11, 2},
        {110, 47, 55, 6}
    };

    int sum_row[ROWS] = { 0 };
    int sum_col[COLS] = { 0 };
    int answerSum = 0;
    int cell = 10;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            sum_row[i] += array[i][j];
            sum_col[j] += array[i][j];
            answerSum += array[i][j];
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << array[i][j] << "\t";
        }
        cout << "|  " << sum_row[i] << endl;
    }
    for (int i = 0; i < COLS * cell; i++) {
        cout << "=";
    }
    cout << endl;
    for (int i = 0; i < COLS; i++) {
        cout << sum_col[i] << "\t";
    }
    cout << "|  " << answerSum << endl;
}

