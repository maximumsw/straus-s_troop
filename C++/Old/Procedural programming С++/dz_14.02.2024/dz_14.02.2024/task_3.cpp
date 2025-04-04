#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;

void indent(int value) {
    
}

int main()
{
    const float negative_nums = 0.11;
    float user_nums[3]  = {};
    cout << "Enter 1st num:";
    cin >> user_nums[0];
    
    cout << "Enter 2nd num:";
    cin >> user_nums[1];

    cout << "Enter 3rd num:";
    cin >> user_nums[2];

    for (int i = 0; i != 3; i++) {
        if (user_nums[i] < 0) {
            user_nums[i] = negative_nums;
        }
        else if (user_nums[i] > 0) {
            user_nums[i] = pow(user_nums[i], 3);
        }

    }
    
    for (int i = 0; i != 3; i++) {
        cout << user_nums[i] << " ";

    }
    
    return 0;
}