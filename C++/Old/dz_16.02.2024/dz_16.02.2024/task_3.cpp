#include <iostream>

using namespace std;

int main() {
    int num;
    cin >> num;

    int result = 0;
    int pow10 = 1;

    // Перебрати всі цифри числа
    while (num > 0) {
        int digit = num % 10;

        // Якщо цифра не 3 і не 6, додати її до нового числа
        if (digit != 3 && digit != 6) {
            result = result + digit * pow10;
            pow10 *= 10;
        }

        num /= 10;
    }

    cout << result << endl;

    return 0;
}
