#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    // task 1
    long long int num;

    cout << "input number to check (even, odd)\n";
    cin >> num;

    if (num % 2 == 0)
        cout << "number is even\n";
    else if (num == 0)
        cout << "number is 0 :)";
    else
        cout << "number is odd\n";
    return 0;
}
