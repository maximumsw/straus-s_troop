#include <iostream>
using namespace std;

void gap(int x = 1)
{
    for (int i = 0; i < x; i++)
    {
        cout << endl;
    }
}

void show_arr(int* array_, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array_[i] << " ";
    }
}

void sum_of_arr(int* array1, int* array2, int* array3, int size)
{
    for (int i = 0; i < size; i++)
    {
        array3[i] = array1[i] + array2[i];
    }
    
}

//int* arr3 = new int[N3] {3, 98};
int main()
{
    const unsigned int N = 3;
    int* arr1 = new int[N] {1, 1000, 2};
    int* arr2 = new int[N] {1, 95, 1};
    int* arr3 = new int[N] {};
    
    sum_of_arr(arr1, arr2, arr3, N);

    cout << "A: "; show_arr(arr1, N);
    gap();
    cout << "B: "; show_arr(arr2, N);
    gap();
    cout << "C: "; show_arr(arr3, N);
    gap();
    




    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
}