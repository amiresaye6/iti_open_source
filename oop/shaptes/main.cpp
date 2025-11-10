#include <iostream>

using namespace std;

class Point
{
    int x;
    int y;
public:
    Point(int _x = 0, int _y = 0)
    {
        x = _x;
        y = _y;
    }
    ~Point()
    {
        cout << "point destroied" << endl;
    }

    void SetX(int _x)
    {
        x = _x;
    }

    void SetY(int _y)
    {
        y = _y;
    }

    void SetXY(int _x, int _y)
    {
        x = _x;
        y = _y;
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }

    void print()
    {
        cout << "(" << x << "," << y << ")" << endl;
    }
};

class Rectangle
{
    Point upperLeft;
    Point LowerRight;

public:
    Rectangle(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0)
    {
        upperLeft.SetXY(x1, y1);
        LowerRight.SetXY(x2, y2);
    }
    Rectangle(Point x, Point y)
    {
        upperLeft = x;
        LowerRight = y;
    }

    ~Rectangle()
    {
        cout << "Rectangle destroied" << endl;
    }
    void setUL(int x, int y)
    {
        upperLeft.SetX(x);
        upperLeft.SetY(y);
    }
    void setLR(int x, int y)
    {
        LowerRight.SetX(x);
        LowerRight.SetY(y);
    }
    void setUL(Point a)
    {
        upperLeft = a;
    }
    void setLR(Point b)
    {
        LowerRight = b;
    }

    void getUl(int& x, int& y)
    {
        x = upperLeft.getX();
        y = upperLeft.getY();
    }
    void getLR(int& x, int& y)
    {
        x = LowerRight.getX();
        y = LowerRight.getY();
    }

    void print()
    {
        cout << "Rectangle" << endl;
        upperLeft.print();
        LowerRight.print();
    }
};

class Circle
{
    float radius;
    Point center;

public:
    Circle(float _radius = 1, int cx = 0, int cy = 0)
    {
        if (_radius <= 0)
            cout << "invalid radius" << endl;
        else
            radius = _radius;
        center.SetXY(cx, cy);
    }

    Circle(float _radius, Point c)
    {
        if (_radius <= 0)
            cout << "invalid radius" << endl;
        else
            radius = _radius;
        center = c;
    }


    ~Circle()
    {
        cout << "Circle destroied" << endl;
    }

    void setRadius(float _r)
    {
        if (_r <= 0)
            cout << "invalid radius" << endl;
        else
            radius = _r;

    }

    void setCenter(int cx, int cy)
    {
        center.SetXY(cx, cy);
    }

    float getRadius()
    {
        return radius;
    }

    void getCenter(int& cx, int& cy)
    {
        cx = center.getX();
        cy = center.getY();
    }

    void print()
    {
        cout << "r = " << radius << " c = (" << center.getX() << "," <<  center.getY() << ")" << endl;
    }
};

class Triangle
{
    Point one;
    Point two;
    Point three;
public:
    Triangle(int a = 0, int b = 0, int c = 0, int d = 0, int e = 0, int f = 0): one(a, b), two(c, d), three(e, f)
    {
        cout << "triangle created" << endl;
    }
    Triangle(Point a, Point b, Point c)
    {
        one = a;
        two = b;
        three = c;
    }

    ~Triangle()
    {
        cout << "Triangle Triangle" << endl;
    }
    void setOne(int x, int y)
    {
        one.SetXY(x, y);
    }
    void setTwo(int x, int y)
    {
        two.SetXY(x, y);
    }
    void setThree(int x, int y)
    {
        three.SetXY(x, y);
    }

    void getOne(int&a, int& b)
    {
        a = one.getX();
        b = one.getY();
    }
    void getTwo(int&a, int& b)
    {
        a = two.getX();
        b = two.getY();
    }
    void getThree(int&a, int& b)
    {
        a = three.getX();
        b = three.getY();
    }
    void print()
    {
        one.print();
        two.print();
        three.print();
    }
};

int main()
{
    Point p1(1, 2), p2(3, 4), p3(5, 6);
    cout << "=========================testing Rectangle class======================" << endl;
    Rectangle r1, r2(10, 20, 30, 40), r3(p1, p2);

    cout << "printing rectangles" << endl;

    cout << "r1" << endl;
    r1.print();

    cout << "r2" << endl;
    r2.print();

    cout << "r3" << endl;
    r3.print();

    cout << "updating r3" << endl;
    r3.setLR(p1);
    r3.setUL(7, 7);
    r3.print();

    cout << "=========================testing Circle class======================" << endl;
    Point center(1,1);
    Circle c1(5, center);
    cout << "after creation" << endl;
    c1.print();
    cout << "after updating center and radius" << endl;
    c1.setCenter(10, 20);
    c1.setRadius(15);
    c1.print();

    cout << "=========================testing Triangle class======================" << endl;
    Triangle t1, t2(9, 8, 7, 6, 5, 4), t3(p1, p2, p3);

    cout << "printing Triangles" << endl;

    cout << "triangle 1" << endl;
    t1.print();

    cout << "triangle 2" << endl;
    t2.print();

    cout << "triangle 3" << endl;
    t3.print();

    cout << "updating triangle 1" << endl;
    t1.setOne(4, 4);
    t1.setTwo(4, 4);
    t1.setThree(p1.getX(), p1.getY());
    t1.print();

    cout << "gettign first point from t1" << endl;
    int x, y;
    t1.getOne(x, y);
    cout << x << ", " << y << endl;

    return 0;
}
