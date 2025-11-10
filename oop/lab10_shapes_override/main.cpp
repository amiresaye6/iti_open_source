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

    // made it virtual so i can override it in square and circle
    virtual void setD1(float _d)
    {
        if (_d <= 0)
            cout << "invalind dimention" << endl;
        else
            d1 = _d;
    }
    virtual void setD2(float _d)
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
    // pure vertual function
    virtual float calcArea() = 0;
};


class rectangle: public shape
{
    float area;
public:
    rectangle(): shape(1, 1) {};
    rectangle(float _d): shape(_d) {};
    rectangle(float _d1, float _d2): shape(_d1, _d2) {};

    float calcArea() override
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

    float calcArea() override
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
    void setD1(float _d) override
    {
        if (_d <= 0)
            cout << "invalid dimention" << endl;
        else
        {
            d1 = _d;
            d2 = _d;
        }
    }
    void setD2(float _d) override
    {
        if (_d <= 0)
            cout << "invalid dimention" << endl;
        else
        {
            d1 = _d;
            d2 = _d;
        }
    }
    float calcArea() override
    {
        return d1 * d2 * PI;
    }


    void print()
    {
        cout << "Circle area = " << calcArea() << endl;
    }
};

class square: public rectangle
{
public:
    square(float _x = 1): rectangle(_x, _x) {}

    void setD1(float _d) override
    {
        if (_d <= 0)
            cout << "invalind dimention" << endl;
        else
            d1 = _d;
        d2 = _d;
    }
    void setD2(float _d) override
    {
        if (_d <= 0)
            cout << "invalind dimention" << endl;
        else
            d2 = _d;
        d1 = _d;
    }

    float calcArea() override
    {
        return d1 * d1;
    }
};

float myfun(shape* s);

int main()
{
    shape* arr[4];

    arr[0] = new rectangle(10, 20);
    arr[1] = new triangle(10, 20);
    arr[2] = new circle(10);
    arr[3] = new square(10);

    float arrSum = 0;
    for (int i = 0; i < 4; i++)
    {
        arrSum += arr[i]->calcArea();
        arr[i]->print();
        cout << "area is " << arr[i]->calcArea() << endl;

    }
    cout << "sum of areas of the 4 shapes is: " << arrSum << endl;


    cout << "trying to update d1, d2 in circle, square." << endl;

    cout << "chanign d1 with 10 and d2 with 15" << endl;
    arr[2]->setD1(10);
    arr[2]->setD2(15);

    myfun(arr[2]);


    cout << "chanign d1 with 10 and d2 with 15" << endl;
    arr[3]->setD1(10);
    arr[3]->setD2(15);

    myfun(arr[3]);


    return 0;
}

float myfun(shape* s)
{
    s->print();
    float res = s->calcArea() ;
    cout << res << endl;
    return res;
}
