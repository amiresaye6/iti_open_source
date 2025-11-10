#include <iostream>

using namespace std;

int main()
{
    float base, power, sign = 1;
    double result;
    cout << "Calculate Power" << endl;
    cin >> base >> power;

    if (power < 0)
    {
        sign = -1;
        power *= -1;
    }
    result = base;
    for (int i = 0; i < power - 1; i++)
    {
        result *= base;
    }
    if (sign < 0)
        result = 1 / result;
    if (power == 0)
        result = 1;
    cout << "result of " << base << " power " << power * sign << " is " << result;
    return 0;
}
