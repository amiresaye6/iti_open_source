#include <iostream>
using namespace std;

class fraction
{
    int num;
    int denum;

public:
    fraction(int _num = 1, int _denum = 1)
    {
        setNum(_num);
        setDenum(_denum);
    }

    int getNum()
    {
        return num;
    }
    int getDenum()
    {
        return denum;
    }

    void setNum(int _num)
    {
        num = _num;
    }

    void setDenum(int _denum)
    {
        if (_denum == 0)
        {
            cout << "forbidden behaviour" << endl;
            denum = 1;
        }
        else
        {
            denum = _denum;
        }
    }

    int getGdc(int a, int b)
    {
        int temp;
        while (b != 0)
        {
            temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void print()
    {
        int g = getGdc(num, denum);
        int newnum = num / g;
        int newdenum = denum / g;
        if (newnum == newdenum)
            cout << 1 << endl;
        else
            cout << newnum << "/" << newdenum << endl;
    }

    fraction operator+(fraction &n)
    {
        fraction res;
        res.num = (num * n.denum) + (n.num * denum);
        res.denum = denum * n.denum;
        return res;
    }

    fraction operator-(fraction &n)
    {
        fraction res;
        res.num = (num * n.denum) - (n.num * denum);
        res.denum = denum * n.denum;
        return res;
    }

    fraction operator+(int n)
    {
        fraction res;
        res.num = num + n * denum;
        res.denum = denum;
        return res;
    }

    friend fraction operator+(int n, fraction &f)
    {
        fraction res;
        res.num = f.num + n * f.denum;
        res.denum = f.denum;
        return res;
    }

    fraction &operator=(const fraction &n)
    {
        if (this != &n)
        {
            num = n.num;
            denum = n.denum;
        }
        return *this;
    }

    bool operator==(fraction &n)
    {
        return (num * n.denum) == (n.num * denum);
    }

    bool operator!=(fraction &n)
    {
        return !(*this == n);
    }

    fraction operator++()
    {
        num += denum;
        return *this;
    }
    fraction operator++(int)
    {
        fraction res(*this);
        num += denum;
        return res;
    }
};

int main()
{
    fraction f1(3, 4), f2(1, 2), f3;
    f3 = f1 + f2;
    cout << "f1 + f2 = ";
    f3.print();

    f3 = f1 - f2;
    cout << "f1 - f2 = ";
    f3.print();

    f3 = f1 + 2;
    cout << "f1 + 2 = ";
    f3.print();

    f3 = 3 + f1;
    cout << "3 + f1 = ";
    f3.print();

    cout << "f1 == f2: " << (f1 == f2) << endl;
    cout << "f1 != f2: " << (f1 != f2) << endl;

    ++f1;
    cout << "++f1: ";
    f1.print();

    f1++;
    cout << "f1++: ";
    f1.print();

    return 0;
}
