#include <iostream>
#include <ctime>

using namespace std;

// Function to determine if a number is composite (not prime)
bool isNotPrime(int num) {
    if (num <= 1) {
        return true;  // 1 and less are considered not prime for simplicity
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return true;
        }
    }
    return false;
}

// Function to create a new array containing only prime numbers from the original array
int filterPrimes(int* originalArray, int originalSize, int*& filteredArray) {
    int filteredCount = 0;
    for (int i = 0; i < originalSize; i++) {
        if (!isNotPrime(originalArray[i])) {  // Use isNotPrime for clarity
            filteredArray[filteredCount++] = originalArray[i];
        }
    }
    return filteredCount;
}

int main() {
    srand(time(NULL));

    int numElements, primeCount = 0;
    cout << "Enter the size of the array: ";
    cin >> numElements;

    int* originalArray = new int[numElements];
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < numElements; i++) {
        cin >> originalArray[i];
    }

    // Count prime numbers in original array (optional for efficiency)
    for (int i = 0; i < numElements; i++) {
        if (!isNotPrime(originalArray[i])) {
            primeCount++;
        }
    }

    // Allocate memory for the filtered array (considering potential prime count)
    int* filteredArray = new int[primeCount > 0 ? primeCount : numElements];  // Handle empty or all-prime cases

    int newSize = filterPrimes(originalArray, numElements, filteredArray);

    delete[] originalArray;

    cout << "New array containing only prime numbers:\n";
    for (int i = 0; i < newSize; i++) {
        cout << filteredArray[i] << " ";
    }
    cout << endl;

    delete[] filteredArray;

    return 0;
}
