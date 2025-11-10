#include <iostream>
using namespace std;

// Correct template definition
template <class T>
void mySwap(T& x, T& y)
{
    T temp = x;
    x = y;
    y = temp;
}

int main()
{
    int a = 10, b = 30;
    float c = 3.5, d = 5.4;
    char e = 'a', f = 't';

    cout << "Before swap: a=" << a << ", b=" << b << endl;
    mySwap(a, b);  // Use your renamed template
    cout << "After swap: a=" << a << ", b=" << b << endl;

    cout << "Before swap: c=" << c << ", d=" << d << endl;
    mySwap(c, d);
    cout << "After swap: c=" << c << ", d=" << d << endl;

    cout << "Before swap: e=" << e << ", f=" << f << endl;
    mySwap(e, f);
    cout << "After swap: e=" << e << ", f=" << f << endl;

    return 0;
}
