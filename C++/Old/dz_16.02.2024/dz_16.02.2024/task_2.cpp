#include <iostream>
using namespace std;

int main()
{
    const int nums[] = { 100,999 };
    unsigned int counter = 0;
    for (int i = nums[0]; i < (nums[1] + 1); i++) {
        int first_num = i % 10;
        int second_num = (((i % 100) - first_num) / 10);
        int third_num = i / 100;

        if (first_num != second_num and first_num != third_num       and       second_num != first_num and second_num != third_num    and third_num != first_num and third_num != second_num) {
            counter++;
            cout << i << " ";
        }
        /*cout << second_num << " " << first_num << " " << endl;*/


    }
    cout << endl << "Counter: " << counter;
}