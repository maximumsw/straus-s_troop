#include <iostream>
using namespace std;



int main() {
    int num;

    
    cout << "Enter a number: ";
    cin >> num;

    
    int* ptrNum = &num;

    
    if (*ptrNum > 0) {
        cout << "The number " << num << " is positive." << endl;
    }
    else if (*ptrNum < 0) {
        cout << "The number " << num << " is negative." << endl;
    }
    else {
        cout << "The number " << num << " is zero." << endl;
    }

    return 0;
}
