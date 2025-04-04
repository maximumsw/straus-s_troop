#include <iostream>
using namespace std;


int main() {
    const int size = 5;
    int numbers[size] = { 1, 2, 3, 4, 5 };

    int* ptrNumbers = numbers;

    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += *ptrNumbers;

        ptrNumbers++;
    }

    
    cout << "Sum of array elements: " << sum << endl;

    return 0;
}
