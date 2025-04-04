#include <iostream>

using namespace std;

int countChar(char str[], char ch) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == ch) {
            count++;
        }
    }
    return count;
}

int main() {
    char str[100];
    char ch;

    cout << "Enter the line: ";
    cin.getline(str, 100);

    cout << "Enter the character you want to find: ";
    cin >> ch;

    int count = countChar(str, ch);

    cout << "Symbol '" << ch << "' meets " << count << " times." << endl;

    return 0;
}
