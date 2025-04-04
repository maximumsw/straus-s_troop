#include <iostream>
using namespace std;

void bigger_num(double num1, double num2)
{
    if (num1 > num2)
        cout << num1 << ">" << num2 << endl;
    else if (num1 < num2)
        cout << num1 << "<" << num2 << endl;
    else
        cout << num1 << "=" << num2 << endl;

}

void bigger_num(int num1, int num2)
{
    if (num1 > num2)
        cout << num1 << ">" << num2 << endl;
    else if (num1 < num2)
        cout << num1 << "<" << num2 << endl;
    else
        cout << num1 << "=" << num2 << endl;

}

void bigger_num(char num1, char num2)
{
    if (num1 > num2)
        cout << num1 << ">" << num2 << endl;
    else if (num1 < num2)
        cout << num1 << "<" << num2 << endl;
    else
        cout << num1 << "=" << num2 << endl;

}



int main()
{
    double double_1 = 2.3, double_2 = 4.33;
    int int_1 = 123, int_2 = 312;
    char char_1 = 'A', char_2 = 'j';



    bigger_num(double_1, double_2);
    bigger_num(int_1, int_2);
    bigger_num(char_1, char_2);
}