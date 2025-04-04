#include <iostream>
using namespace std;

void change_place(int* a , int* b)
{
    cout << *a << "," << *b << endl;
    int temp = *a;
    *a = *b;
    *b = temp;
    cout << *a << "," << *b << endl;
}

void gap(int x)
{
    int i = 0;

    while (i < x)
    {
        i++;
        cout << endl;
    }
}

int main() {
    int a, b;

    cout << "Enter num a: ";
    cin >> a;
    cout << "Enter num b: ";
    cin >> b;

    int* num1 = &a;
    int* num2 = &b;
    gap(2);
    change_place(num1, num2);


    return 0;
}
