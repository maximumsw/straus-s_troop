#include <iostream>

using namespace std;

void insertChar(char str[], int pos, char ch) {
    int i = strlen(str);
    for (; i >= pos; --i) {
        str[i + 1] = str[i];
    }
    str[pos] = ch;
}

int main() {
    char str[100];
    int pos;
    char ch;

    cout << "Enter the line:  ";
    cin.getline(str, 100);

    cout << "Enter the position number where you want to insert the symbol: ";
    cin >> pos;

    cout << "Type the symbol you want to insert: ";
    cin >> ch;

    insertChar(str, pos - 1, ch);

    cout << "The line after insertion: " << str << endl;

    return 0;
}
