#include <iostream>
#include <ctime>

using namespace std;

int main() {
    // Seed the random number generator for creating a random array
    srand(time(0));

    // Define the size of the array (change as needed)
    const unsigned int SIZE = 10;

    // Create an array of integers
    int array[SIZE];

    // Fill the array with random values between 0 and 9
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 10;
    }

    cout << "Source array: ";
    for (int i = 0; i < SIZE; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    // Count the number of zeros to be moved
    int move = 0;
    for (int i = 0; i < SIZE; i++) {
        if (array[i] == 0) {
            move++; // Increment move for each zero encountered
        }
    }

    // Shift non-zero elements to the left, overwriting zeros
    for (int i = 0; i < SIZE - move; i++) {
        array[i] = array[i + move]; // Move non-zero elements left
    }

    // Fill the remaining elements with a placeholder value (optional)
    for (int i = SIZE - move; i < SIZE; i++) {
        array[i] = -1; // Or any other desired value to indicate removed elements
    }

    cout << "Modified array: ";
    for (int i = 0; i < SIZE; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
