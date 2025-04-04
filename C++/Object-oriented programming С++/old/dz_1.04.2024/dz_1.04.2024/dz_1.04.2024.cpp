#include <iostream>
#include <locale.h>
using namespace std;

void gap(int x = 1)
{
    while (x != 0)
    {
        cout << endl;
        x--;
    }
}


class Fraction
{
    int numerator;
    int bannister;

public:
    Fraction() //конструктор за замовчуванням
    {
        numerator = 0;
        bannister = 0;
    }
    Fraction(int a, int b) //конструктор за замовчуванням з можливістю введення данних дробу у вигляді параметрів 
    {
        numerator = a;
        bannister = b;
    }


    void enter_fraction() // метод для вводу даних дробу з консолі
    {
        cout << "Введіть чисельник дробу(int): ";
        cin >> numerator;
        cout << "Введіть знаменник дробу(int): ";
        cin >> bannister;
    }
    void show() // метод для виводу дробу в консоль
    {
        cout << numerator << "/" << bannister;
    }

    int get_numerator() // геттер чисельника
    {
        return numerator;
    }
    
    int get_bannister() // геттер знаменника
    {
        return bannister;
    }


    void summ(Fraction other_fraction) // метод додавання двох дробів(працює виключно у випадку коли знаменники однакові)
    {
        if (bannister == other_fraction.get_bannister())
        {
            int sum = numerator + other_fraction.get_numerator();
            show();
            cout << " + ";  
            other_fraction.show();
            cout << " = " << sum << "/" << bannister << endl;
        }
        else
            cout << "Функція працює виключно у випадку коли знаменники однакові!";
    }

    void minus(Fraction other_fraction) // метод віднімання двох дробів(працює виключно у випадку коли знаменники однакові)
    {
        if (bannister == other_fraction.get_bannister())
        {
            int minus = numerator - other_fraction.get_numerator();
            show();
            cout << " - ";
            other_fraction.show();
            cout << " = " << minus << "/" << bannister << endl;
        }
        else
            cout << "Функція працює виключно у випадку коли знаменники однакові!";
    }


    void multiply(Fraction other_fraction) // метод множення двох дробів
    {
        int answer_numenator = numerator * other_fraction.get_numerator();
        int answer_bannister = bannister * other_fraction.get_bannister();

        show(); 
        cout << " * "; 
        other_fraction.show(); 
        cout << " = " << answer_numenator << "/" << answer_bannister;
    }

    void division(Fraction other_fraction) // метод множення двох дробів
    {
        int answer_numenator = numerator * other_fraction.get_bannister();
        int answer_bannister = bannister * other_fraction.get_numerator();

        show();
        cout << " / ";
        other_fraction.show();
        cout << " = " << answer_numenator << "/" << answer_bannister;
    }
};



int main()
{
    Fraction fr_1;
    fr_1.enter_fraction();
    Fraction fr_2(2,4);
    
    fr_1.summ(fr_2);
    gap(2);
    fr_1.minus(fr_2);
    gap(2);
    fr_1.multiply(fr_2);
    gap(2);
    fr_1.division(fr_2);

}