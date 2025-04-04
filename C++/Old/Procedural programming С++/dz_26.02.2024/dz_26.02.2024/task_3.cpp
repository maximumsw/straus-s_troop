#include <iostream>
using namespace std;



struct Integers
{
    short negative = 0, positive = 0, zero = 0;
};


void gap(int x = 1)
{
    for (int i = 0; i < x; i++)
        cout << endl;
}

template <typename T>
void num_counter(T arr[], int size)
{
    Integers nums;
    for (int i = 1; i < size + 1; i++)
    {
        if (arr[i] < 0)
            nums.negative += 1;
        else if (arr[i] > 0)
            nums.positive += 1;
        else
            nums.zero += 1;
    }
    cout << "Number of negative nums = " << nums.negative << endl;
    cout << "Number of positive nums = " << nums.positive << endl;
    cout << "Number of zero nums = " << nums.zero << endl;
}

template <typename T>
T print_arr(T arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    gap(2);
    return 0;
}


int main()
{
    int const N = 5;


    int arr[N] = { -2,0,2,2,2 };

    print_arr(arr, N);
    num_counter(arr, N);
    
    
    return 0;
}