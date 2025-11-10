#include <iostream>

using namespace std;

class fraction
{
    int num;
    int denum;

    int getGdc(int a, int b)
    {
        int temp;
        while(b != 0)
        {
            temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    fraction(int _num = 1, int _denum = 1)
    {
        num = _num;
        if (_denum == 0)
        {

            cout << "forbidden behaviour" << endl;

            denum = 1;
        }
        else
            denum = _denum;
    }

    void print()
    {
        int g = getGdc(num, denum);
        int newnum, newdenum;

        newnum = num / g;
        newdenum = denum / g;

        if (newnum == newdenum)
            cout << 1 << endl;
        else
            cout << newnum  << "/" << newdenum << endl;
    }

    int add(int _num, int _denum)
    {
        int outnum, outdenum;
        if (_denum == 0 )
        {
            cout << "forbidden" << endl;

            return 0;
        }

        else
        {
            outnum = (num * _denum) + (denum * _num);
            outdenum = denum * _denum;
            int g = getGdc(outnum, outdenum);
            outnum /= g;
            outdenum /= g;
            if (outnum == outdenum)
                cout << 1 << endl;
            else
                cout << outnum << "/" << outdenum << endl;

        }
    }
};

int main()
{
    fraction f1(4, 10);
    f1.print();
    f1.add(5, 10);
    return 0;
}
