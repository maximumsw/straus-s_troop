#include <iostream>

using namespace std;

int main() {
    int num1, num2;
    char operation;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the operation (+, -, *, /): ";
    cin >> operation;

    cout << "Enter the second number: ";
    cin >> num2;

    int* ptrNum1 = &num1;
    int* ptrNum2 = &num2;

    int result;
    switch (operation) {
    case '+':
        result = *ptrNum1 + *ptrNum2;
        break;
    case '-':
        result = *ptrNum1 - *ptrNum2;
        break;
    case '*':
        result = *ptrNum1 * *ptrNum2;
        break;
    case '/':
        if (*ptrNum2 == 0) {
            cout << "Division by zero!" << endl;
            return 1;
        }
        result = *ptrNum1 / *ptrNum2;
        break;
    }

    cout << "Result: " << result << endl;

    return 0;
}
