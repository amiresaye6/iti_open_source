#include <iostream>

using namespace std;

int main()
{
    // limit
    int input, mirror, pow = 1;
    cout << "mirror|rorrim" << endl;
    cout << "enter +ve number" << endl;

    while (true)
    {
        cin >> input;
        if (input < 0)
            cout << "invalid value, try again:" << endl;
        else
            break;
    }
    //calc pow
    while (input % pow != input)
    {
        pow *= 10;
    }

    pow /= 10;

    while (input != 0)
    {
        mirror += (input % 10) * pow;
        input /= 10;
        pow /= 10;
    }

    cout << mirror;


    return 0;
}
