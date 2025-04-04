#include <iostream>
#include <stdlib.h>
using namespace std;

void gap(int x = 1)
{
    for (int i = 0; i < x; i++)
        cout << endl;
}

template <typename T>
T getMin(T arr[], int size) 
{
    T min = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

template <typename T>
T getMax(T arr[], int size) 
{
    T max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

template <typename T>
T fill_arr(T arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 101; // будь яке значення від 0 до 100
    }
    return 0;
}

template <typename T>
T print_arr(T arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    gap();
    return 0;
}

int main()
{
    const unsigned int N = 4;
    /*int array[N] = { 8, 3, 2, 5 };*/

    float* arr1 = new float[N];
    fill_arr(arr1, N); //заповнення масиву
    cout << "arr1(float): "; print_arr(arr1, N); //вивід масиву
    cout << "Min arr1 == " << getMin(arr1, N) << endl;
    cout << "Max arr1 == " << getMax(arr1, N) << endl;
    //print_arr(arr1, N); //вивід масиву в консоль за для перевірки чи наповнився він
    delete[] arr1;

    gap(2); // кастомна функція відступу

    int* arr2 = new int[N];
    fill_arr(arr2, N); //заповнення масиву
    cout << "arr2(int): "; print_arr(arr2, N); //вивід масиву
    cout << "Min arr2 == " << getMin(arr2, N) << endl;
    cout << "Max arr2 == " << getMax(arr2, N) << endl;
    delete[] arr2;

    gap(2); // кастомна функція відступу

    char* arr3 = new char[N];
    fill_arr(arr3, N); //заповнення масиву
    cout << "arr3(char): "; print_arr(arr3, N); //вивід масиву
    cout << "Min arr3 == " << getMin(arr3, N) << "(" << (int)getMin(arr3, N) << ")" << endl;
    cout << "Max arr3 == " << getMax(arr3, N) << "(" << (int)getMax(arr3, N) << ")" << endl;
    //print_arr(arr3, N); //вивід масиву в консоль за для перевірки чи наповнився він
    delete[] arr3;




    
    


    
}