#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

class Complex
{
    double real;
    double img;
    static int counter;

public:
    Complex(double _real = 0, double _img = 0)
    {
        real = _real;
        img = _img;
        counter++;
    }
    Complex(Complex& c)
    {
        real = c.GetReal();
        img = c.GetImg();
        counter++;
    }
    ~Complex()
    {
        counter--;
    }
    static int getCount()
    {
        return counter;
    }
    void SetReal(double _real)
    {
        real = _real;
    }
    void SetImg(double _img)
    {
        img = _img;
    }

    double GetReal()
    {
        return real;
    }
    double GetImg()
    {
        return img;
    }

    void print()
    {
        if (real == 0 && img == 0)
            cout << 0 << endl;
        else if (img == 0)
            cout << real << endl;
        else if (real == 0)
            cout << img << "j" << endl;
        else if (img < 0)
            cout << real << img << "j" << endl;
        else
            cout << real << "+" << img << "j" << endl;
//        cout << "=========static counter===========: " << counter << endl;
    }

    void Add(Complex num2)
    {
        SetReal(real + num2.GetReal());
        SetImg(img + num2.GetImg());
    }

    //operators overloading

    Complex& operator+=(Complex& c)
    {
        real += c.GetReal();
        img += c.GetImg();
        return  *this;
    }

    Complex& operator-=(Complex& c)
    {
        real -= c.GetReal();
        img -= c.GetImg();
        return  *this;
    }

    Complex operator+(Complex& c)
    {
        Complex num(real + c.GetReal(), img + c.GetImg());
        return  num;
    }

    Complex operator+(double n)
    {
        Complex num(real + n, img);
        return  num;
    }

    Complex operator-(Complex& c)
    {
        Complex num(real - c.GetReal(), img - c.GetImg());
        return  num;
    }

    Complex operator-(double n)
    {
        Complex num(real - n, img);
        return  num;
    }

    bool operator==(Complex& c)
    {
        return real == c.GetReal() && img == c.GetImg();
    }

    bool operator!=(Complex& c)
    {
        return !(*this == c);
    }

    Complex& operator=(const Complex& c)
    {
        if (this != &c)
        {
            real = c.real;
            img = c.img;
        }
        return *this;
    }


    Complex& operator++()
    {
        real++;
        return *this;
    }

    Complex operator++(int)
    {

        Complex temp = *this;
        real++;
        return temp;
    }
    Complex& operator--()
    {
        real--;
        return *this;
    }

    Complex operator--(int)
    {

        Complex temp = *this;
        real--;
        return temp;
    }

    operator double()
    {
        return sqrt(real * real + img * img);
    }
};

Complex operator+(double x, Complex& y)
{
    Complex res(x + y.GetReal(), y.GetImg());
    return res;

}
Complex operator-(double x, Complex& y)
{
    Complex res(x - y.GetReal(), y.GetImg());
    return res;

}


int Complex::counter = 0;

void PrintComplex(Complex num1);

Complex Sub(Complex num1, Complex num2)
{
    Complex result;

    result.SetReal(num1.GetReal() -  num2.GetReal());
    result.SetImg(num1.GetImg() -  num2.GetImg());
    return result;
}

int main()
{
    Complex a(1, 2), b(3, 4), c;

    cout << "init vals" << endl;
    cout << "a: "; a.print();
    cout << "b: "; b.print();
    cout << "c: "; c.print();

    cout << "\nc = a + b" << endl;
    c = a + b;
    c.print();

    cout << "\nc = a - b" << endl;
    c = a - b;
    c.print();

    cout << "\nc = a + 5.5" << endl;
    c = a + 5.5;
    c.print();

    cout << "\nc = a - 2.5" << endl;
    c = a - 2.5;
    c.print();

    cout << "\nc = 5.5 + a" << endl;
    c = 5.5 + a;
    c.print();

    cout << "\nc = 10.0 - b" << endl;
    c = 10.0 - b;
    c.print();

    cout << "\na += b" << endl;
    a += b;
    a.print();

    cout << "\nb -= a" << endl;
    b -= a;
    b.print();

    cout << "\nc = a" << endl;
    c = a;
    c.print();

    cout << "\nPrefix ++a" << endl;
    (++a).print();

    cout << "\nPostfix temp =  a++" << endl;
    Complex temp1 = a++;
    cout << "Old value: "; temp1.print();
    cout << "After increment: "; a.print();

    cout << "\nPrefix temp =  --a" << endl;
    (--a).print();

    cout << "\nPostfix temp =  a--" << endl;
    Complex temp2 = a--;
    cout << "Old value: "; temp2.print();
    cout << "After decrement: "; a.print();

    cout << "\na == b" << endl;
    cout << ((a == b) ? "true" : "false") << endl;

    cout << "\na != b" << endl;
    cout << ((a != b) ? "true" : "false") << endl;

    cout << "double con = a" << endl;
    double con = a;
    cout << "con = " << con << endl;

    return 0;
}


void PrintComplex(Complex num1)
{
    double real, img;
    cout << "complex number" << endl;

    real = num1.GetReal();
    img = num1.GetImg();
    if ( real == 0 && img == 0)
        cout << 0 << endl;
    else if (img == 0)
        cout << real << endl;
    else if (real == 0)
        cout << img << "j" << endl;
    else if (img < 0)
        cout << real << img << "j" << endl;
    else
        cout << real << "+" << img << "j" << endl;
}
