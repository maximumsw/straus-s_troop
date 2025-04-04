#include <iostream>
using namespace std;


template <typename T>
T arr_avg(T arr[], int size)
{
    T avg = arr[0];
    for (int i = 1; i < size; i++)
    {
        avg += arr[i];
    }
    avg = avg / size;
    return avg;
}

int main() 
{
    int const N = 5;
    
    
    int arr[N] = { 2,2,2,2,2 };
    cout << arr_avg(arr, N) << endl;


    return 0;
}