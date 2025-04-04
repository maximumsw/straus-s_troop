#include <iostream>

using namespace std;

void deleteChar(char str[], int pos) {
    for (int i = pos; str[i] != '\0'; ++i) {
        str[i] = str[i + 1];
    }
}

int main() {
    char str[100];
    int pos;

    cout << "Enter the line: ";
    cin.getline(str, 100);

    cout << "Enter the number of the character you want to delete: ";
    cin >> pos;

    deleteChar(str, pos - 1);

    cout << "The line after deletion: " << str << endl;

    return 0;
}
