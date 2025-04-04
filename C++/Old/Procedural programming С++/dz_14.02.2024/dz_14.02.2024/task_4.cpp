#include <iostream>
#include <conio.h>
using namespace std;

float discount(float value, int percent) {
    /*cout << value << " " << percent;*/
    float finally_value;

    finally_value = value - ((value / 100) * percent);

    return finally_value;
}




using namespace std;

int main() {
    int n;
    cout << "Enter a natural number: ";
    cin >> n;

    if (n % 2 == 0) {
        cout << "The number " << n << " is even." << endl;
    }
    else {
        cout << "The number " << n << " is odd." << endl;
    }

    if (n % 10 == 3) {
        cout << "The number " << n << " ends in 3." << endl;
    }
    else {
        cout << "The number " << n << " does not end in 3." << endl;
    }

    return 0;
}

