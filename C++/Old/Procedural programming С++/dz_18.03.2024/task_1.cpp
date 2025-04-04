#include <iostream>
using namespace std;

#define SQUARE
#define calculateArea(length, width)  length * width
#define calculatePerimeter(length, width)  2 * (length + width)

int main()
{
    double length = 3;
    double width = 7;

    #ifdef SQUARE
    cout << calculatePerimeter(length, width);
    #else 
    cout << calculatePerimeter(length, width);
    #endif
    return 0;
}