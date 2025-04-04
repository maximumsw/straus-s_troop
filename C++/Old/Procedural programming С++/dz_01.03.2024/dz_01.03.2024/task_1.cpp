#include <iostream>
#include <ctime>
#include <cstdlib> // For the exit() function
using namespace std;

int* allocateArray(int size) {
    int* array = new int[size];
    return array;
}

void initializeArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        arr[i] = rand() % 10;
    }
}

void printArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
}

void deleteArray(int arr[]) {
    delete[] arr;
}

int* addElementToEnd(int arr[], int& length, int element) {
    int* newArray = new int[length + 1];
    for (int i = 0; i < length; i++) {
        newArray[i] = arr[i];
    }
    newArray[length] = element;
    length++;
    delete[] arr;
    return newArray;
}

int* insertElementAtIndex(int arr[], int& length, int index, int element) {
    if (index < 0 || index > length) {
        cout << "Invalid index!";
        return arr;
    }
    int* newArray = new int[length + 1];
    for (int i = 0; i < index; i++) {
        newArray[i] = arr[i];
    }
    newArray[index] = element;
    for (int i = index + 1; i < length + 1; i++) {
        newArray[i] = arr[i - 1];
    }
    length++;
    delete[] arr;
    return newArray;
}

int* deleteElementAtIndex(int arr[], int& length, int index) {
    if (index < 0 || index >= length) {
        cout << "Invalid index!";
        return arr;
    }
    int* newArray = new int[length - 1];
    for (int i = 0; i < index; i++) {
        newArray[i] = arr[i];
    }
    for (int i = index; i < length - 1; i++) {
        newArray[i] = arr[i + 1];
    }
    length--;
    delete[] arr;
    return newArray;
}

int main() {
    setlocale(LC_ALL, "English"); // Change locale to English
    srand(time(0));
    int size, choice = 1;
    bool isHaveArray = false;
    int* dynamicArray = nullptr;
    int arrayLength = 0;

    cout << "Enter size: ";
    cin >> size;
    while (choice != 0) {
        cout << "Menu" <<
            "\n1) Dynamic memory allocation function" <<
            "\n2) Dynamic array initialization function" <<
            "\n3) Dynamic array printing function" <<
            "\n4) Dynamic array deletion function" <<
            "\n5) Function to add an element to the end of the array" <<
            "\n6) Function to insert an element at a specified index" <<
            "\n7) Function to delete an element at a specified index\n";
        cin >> choice;

        switch (choice) {
        case 1:
            dynamicArray = allocateArray(size);
            isHaveArray = true;
            break;
        case 2:
            if (isHaveArray) {
                initializeArray(dynamicArray, size);
            }
            else {
                cout << "Create an array first!\n";
            }
            break;
        case 3:
            if (isHaveArray) {
                printArray(dynamicArray, size);
            }
            else {
                cout << "Create and initialize an array first!\n";
            }
            break;
        case 4:
            if (isHaveArray) {
                deleteArray(dynamicArray);
                isHaveArray = false;
            }
            else {
                cout << "Array is already deleted or not created!\n";
            }
            break;
        case 5:
            if (isHaveArray) {
                int element;
                cout << "Enter element to add to the end: ";
                cin >> element;
                dynamicArray = addElementToEnd(dynamicArray, size, element);
            }
            else {
                cout << "Create an array first!\n";
            }
            break;
        case 6:
            if (isHaveArray) {
                int index, element;
                cout << "Enter index to insert: ";
                cin >> index;
                cout << "Enter element to insert: ";
                cin >> element;
                dynamicArray = insertElementAtIndex(dynamicArray, size, index, element);
            }
            else {
                cout << "Create an array first!\n";
            }
            break;
        case 7:
            if (isHaveArray) {
                int index;
                cout << "Enter index to delete: ";
                cin >> index;
                dynamicArray = deleteElementAtIndex(dynamicArray, size, index);
            }
            else {
                cout << "Create an array first!\n";
            }
            break;
        default:
            cout << "Incorrect choice!\n";
            break;
        }
    }
    return 0;
}
