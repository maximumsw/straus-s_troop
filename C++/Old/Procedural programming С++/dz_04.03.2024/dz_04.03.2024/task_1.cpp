#include <iostream>
using namespace std;


int plus_(int num1, int num2) 
{
    return num1 + num2;
}

int minus_(int num1, int num2)
{
    return num1 - num2;
}

int multiply_(int num1, int num2)
{
    return num1 * num2;
}

int divide_(int num1, int num2)
{
    return num1 / num2;
}

int (*operations[])(int, int) = { plus_, minus_, multiply_, divide_ };







int main()
{

    int choice;
    
    cout << "Enter operation:\n" << "1)Plus\n2)Minus\n3)Multiply\n4)Divide\nChoice: ";
    cin >> choice;

    float a, b;
    cout << "Enter 1st number: ";
    cin >> a;
    cout << "Enter 2nd number: ";
    cin >> b;
    
    cout << "Answer: " << operations[choice - 1](a, b);


}