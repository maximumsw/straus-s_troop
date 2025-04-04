#include <iostream>
using namespace std;



void biger_num(int* a, int* b)
{
    
    if (*a > *b)
    {
        cout << *a << ">" << *b;
    }
    else if (*a < *b)
    {
        cout << *a << "<" << *b;
    }
    else
    {
        cout << *a << "=" << *b;
    }
    
}



int main()
{

    int a, b;

    cout << "Enter num a: ";
    cin >> a;
    cout << "Enter num b: ";
    cin >> b;

    int* num1 = &a;
    int* num2 = &b;

    
    biger_num(num1, num2);
    

    return 0;
}