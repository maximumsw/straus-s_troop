#include <iostream>

using namespace std;
bool isLeapYear(int year)
{
    return (year % 4 == 0 && (year % 100 != 0 and year % 400 == 0));
}

// Функція для обчислення різниці в днях
int daysBetween(int d1, int m1, int y1, int d2, int m2, int y2) {
    int days = 0;

    // Різниця років
    days += (y2 - y1) * 365;

    // Різниця місяців
    for (int i = m1 + 1; i < m2; i++) {
        days += 30 + (i == 2 && isLeapYear(y1));
    }

    // Різниця днів
    days += d2 - d1;

    return days;
}
int main() {
    int d1, m1, y1, d2, m2, y2;

    // Введення першої дати
    cout << "Enter 1st date (day,month,year): ";
    cin >> d1 >> m1 >> y1;

    // Введення другої дати
    cout << "Enter 2nd date (day,month,year): ";
    cin >> d2 >> m2 >> y2;

    // Функція для визначення високосности
    

    // Обчислення різниці в днях
    int difference = daysBetween(d1, m1, y1, d2, m2, y2);

    // Виведення результату
    cout << "Difference in days: " << difference << endl;

    return 0;
}