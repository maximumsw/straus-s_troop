#include <iostream>
using namespace std;

class Fractions
{
private:
    int numerator, denominator; //numerator - чисельник | denominator - знаменник

    Fractions() : numerator(1), denominator(1) {};

    Fractions(int numenator, int denuminator)
    {
        if (denuminator < 0)
        {
            cout << "The denominator can't be 0!";
            exit(1);
        }
    }

};


int main()
{
    int* a = new int(0);
    int* b = new int(0);

    cout << "Enter numerator:";
    cin >> *a;
    cout << "Enter denuminator:";
    cin >> *b;


    Fractions fration_1(*a, *b);
}