#include <iostream>
#include <conio.h>
using namespace std;


int main()
{
    float user_seniority;
    cout << "Enter years of seniority: ";
    cin >> user_seniority;

    
    
    const int award_2p[2] = { 5,10 };    //діапазон років стажу відповідно котрому буде надана премія у 2%
    
    const int award_10p[2] = { 10,20};   //діапазон років стажу відповідно котрому буде надана премія у 10%

    
    
    if (user_seniority >= award_2p[0] and user_seniority <= award_2p[1]) {
        cout << "Your award is 2%!\n";
    }
    else if (user_seniority >= award_10p[0] and user_seniority <= award_10p[1]) {
        cout << "Your award is 10%!\n";
    }
    else {
        cout << "You do not have a reward(\n";
    }



    _getch();
    return 0;
}