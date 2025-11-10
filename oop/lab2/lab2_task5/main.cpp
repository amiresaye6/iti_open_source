#include <iostream>

using namespace std;

int main()
{
    // add limit
    int input;
    long long int result = 1;
    cout << "Let's Calculate Factorial:" << endl;
    while (true)
    {
        cin >> input;
        if (input < 0)
            cout << "plz input valid number +ve / 0" << endl;
        else
            break;
    }
    for (int i = input; i > 0; i--)
    {
        result *= i;
    }

    cout << "Factorial of " << input << " is " << result << endl;
    return 0;
}
