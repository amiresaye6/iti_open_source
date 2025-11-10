#include <iostream>
#include <string.h>

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

    void Print()
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
        cout << "=========static counter===========: " << counter << endl;
    }

    void Add(Complex num2)
    {
        SetReal(real + num2.GetReal());
        SetImg(img + num2.GetImg());
    }
};


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
    // lab 11 update.
    cout << "number of complex objects so far " <<  Complex::getCount() << endl;
    Complex c1(1, 2);
    cout << "number of complex objects so far " <<  Complex::getCount() << endl;
    Complex c2(10, 20);
    cout << "number of complex objects so far " <<  Complex::getCount() << endl;
    {

        cout << "adding new object inside another scope " << endl;
        Complex c3(4, 6);
    cout << "number of complex objects before the scope ends " <<  Complex::getCount() << endl;

    }
    cout << "number of complex objects after the scope ends " <<  Complex::getCount() << endl;

    // copy one
    Complex c4(c2);
    cout << "number of complex objects after a copy constructor test " <<  Complex::getCount() << endl;

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
