#include <iostream>

using namespace std;
const double PI = 3.141592653589793;
class shape
{
protected:
    float d1;
    float d2;
public:
    shape()
    {
        d1 = d2 = 1;
    }
    shape(float _d)
    {
        if (_d <= 0)
            cout << "invalind dimention" << endl;
        else
            d1 = d2 = _d;
    }
    shape(float _d1, float _d2)
    {
        if (_d1 <= 0)
            cout << "invalind dimention 1" << endl;
        else
            d1= _d1;
        if (_d2 <= 0)
            cout << "invalind dimention 2" << endl;
        else
            d2 = _d2;

    }

    void setD1(float _d)
    {
        if (_d <= 0)
            cout << "invalind dimention" << endl;
        else
            d1 = _d;
    }
    void setD2(float _d)
    {
        if (_d <= 0)
            cout << "invalind dimention" << endl;
        else
            d2 = _d;
    }

    float getD1()
    {
        return d1;
    };
    float getD2()
    {
        return d2;
    };

    void print()
    {
        cout << "dimention one: " << d1 << ", dimention two: " << d2 << endl;
    }
};


class rectangle: public shape
{
    float area;
public:
    rectangle(): shape(1, 1) {};
    rectangle(float _d): shape(_d) {};
    rectangle(float _d1, float _d2): shape(_d1, _d2) {};

    float calcArea()
    {
        return d1 * d2;
    }
    void print()
    {
        cout << "Rectangle area = " << calcArea() << endl;
    }
};

class triangle: public shape
{
public:

    triangle(): shape(1, 1) {};
    triangle(float _d): shape(_d) {};
    triangle(float _d1, float _d2): shape(_d1, _d2) {};

    float calcArea()
    {
        return d1 * d2 * 0.5;
    }


    void print()
    {
        cout << "Triangle area = " << calcArea() << endl;
    }
};
class circle: public shape
{
public:

    circle(): shape(1, 1) {};
    circle(float _d): shape(_d) {};
    void setD1(int _d)
    {
        if (_d <= 0)
            cout << "invalid dimention" << endl;
        else
        {
            shape::setD1(_d);
            shape::setD2(_d);
        }
    }
    void setD2(int _d)
    {
        if (_d <= 0)
            cout << "invalid dimention" << endl;
        else
        {
            shape::setD1(_d);
            shape::setD2(_d);
        }
    }
    float calcArea()
    {
        return d1 * d2 * PI;
    }


    void print()
    {
        cout << "Circle area = " << calcArea() << endl;
    }
};

int main()
{
    rectangle r1(10, 20);

    triangle t1(4, 5);

    circle c1(5);

    r1.shape::print();
    r1.print();

    t1.shape::print();
    t1.print();

    c1.shape::print();
    c1.print();
    return 0;
}
