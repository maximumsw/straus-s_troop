#include <iostream>

using namespace std;

void deleteCharAll(char str[], char ch) {
    int i = 0, j = 0;
    while (str[i] != '\0') {
        if (str[i] != ch) {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}

int main() {
    char str[100];
    char ch;

    cout << "Enter the line:  ";
    cin.getline(str, 100);

    cout << "Enter the number of the character you want to delete: ";
    cin >> ch;

    deleteCharAll(str, ch);

    cout << "The line after deletion: " << str << endl;

    return 0;
}
