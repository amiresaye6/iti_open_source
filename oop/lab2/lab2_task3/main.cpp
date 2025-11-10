#include <iostream>

using namespace std;

int main()
{
    // validation
    double sum = 0, input;

    cout << "input 5 numbers to calc its sum:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "input number " << i + 1 << endl;
        cin >> input;
        sum += input;
    }

    cout << "Your Sum is: " << sum;
    return 0;
}
