#include <iostream>

using namespace std;
long long int fib(int x);

int main()
{
    int flag = 0;
    long long int in;
    cout << "Lets Calculate Fibonacci series :__:" << endl;

    while(flag == 0)
    {
        cin >> in;
        if (in < 0 || in > 20)
        {
            cout << "invalind input, must be +ve an less than 21";
        }
        else
            flag = 1;
    }

    cout << "Resutlt is : " ;
    cout << fib(in);
    return 0;
}

long long int fib(int x)
{
    if (x == 0 || x == 1)
        return x;
    else
    {

        return (fib(x - 1) + fib(x - 2));
    }
}
