#include <iostream>
#include <cmath>

using namespace std;

// Function to check conditions and print B values
void print_B(int a) {
    // Find square root of A
    int sqrtA = sqrt(a);
    bool done = false;
    // Iterate over all values of B from 1 to sqrtA
    for (int b = 1; b <= sqrtA; ++b) {
        // Check if A is divisible by B*B
        if (a % (b * b) == 0) {
            // Check if A is not divisible by B*B*B
            if (a % (b * b * b) != 0) {
                // Print B value
                cout << b << " ";
                done = true;
            }
            
        }
    }
    if (done == false)
        cout << "None";
}

int main() {
    int a;
    cin >> a;

    cout << "All integers B such that A is divisible by B*B and not divisible by B*B*B: ";

    
    print_B(a);

    cout << endl;

    return 0;
}
