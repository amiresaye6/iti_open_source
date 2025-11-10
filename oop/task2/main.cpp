#include <iostream>

using namespace std;
#include <conio.h>

int main()
{
    // task 2
    int degree;

    cout << "enter student degree\n";
    do {
        cin >> degree;
        if (degree < 0)
            cout << "Degree must be +ve or 0:\n";
        else if (degree > 100)
            cout << "Degree must be less than or equal 100\n";
        else
            break;
    } while( degree < 0 || degree > 100);
    if (degree >= 85)
        cout << "Student Grade is: Excellent\n";
    else if(degree >= 75)
        cout << "Student Grade is: Very Good\n";
    else if(degree >= 65)
        cout << "Student Grade is: Good\n";
    else if(degree >= 50)
        cout << "Student Grade is: Acceptable\n";
    else
        cout << "student Grade is: Failed\n";
    return 0;
}
