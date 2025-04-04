#include <iostream>
#include <conio.h>
using namespace std;

float discount(float value, int percent) {
    /*cout << value << " " << percent;*/
    float finally_value;

    finally_value = value - ((value / 100) * percent); 
    
    return finally_value;
}



int main()
{
    float user_value;
    cout << "Enter value: ";
    cin >> user_value;

    const int discount_5p[2] = {1000,2000};
    const int discount_10p[2] = {2000,5000};

    if (user_value > discount_5p[0] and user_value < discount_5p[1]) {
        cout << "\nYour discount is 5%!\nFinaly value: " << discount(user_value, 5) << endl;
    }
    else if (user_value > discount_10p[0] and user_value < discount_10p[1]) {
        cout << "\nYour discount is 10%!\nFinaly value: " << discount(user_value, 10) << endl;
    }
    else {
        cout << "\nFinaly value: " << user_value << endl;
    }



    _getch();
    return 0;
}