#include <iostream>
using namespace std;

void bigger_num(float num1, float num2)
{
    if (num1 > num2)
        cout << num1 << ">" << num2;
    else if (num1 < num2)
        cout << num1 << "<" << num2;
    else
        cout << num1 << "=" << num2;

}



int main()
{
    while (true)
    {
        float number_1, number_2;


        cout << "\nEnter 1st number: ";
        cin >> number_1;
        cout << "Enter 2nd number: ";
        cin >> number_2;


        bigger_num(number_1, number_2);
    }
}