#include <iostream>

using namespace std;

void replaceChar(char str[]) {
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '.') {
            str[i] = '!';
        }
    }
}

int main() {
    char str[100];

    cout << "Enter the line:  ";
    cin.getline(str, 100);

    replaceChar(str);

    cout << "The line after insertion: " << str << endl;

    return 0;
}
