#include <iostream>
using namespace std;

// class parent has x, y, add(x, y)
// class child inherits from parent, has z, overrides add() to add x + y + z

class parent {
protected:
    float x;
    float y;
public:
    parent(float _x = 0, float _y = 0) {
        x = _x;
        y = _y;
    }

    virtual float add() {
        return x + y;
    }
};

class child : public parent {
    float z;

public:
    child(float _x = 0, float _y = 0, float _z = 0) : parent(_x, _y) {
        z = _z;
    }

    float add() override {
        return x + y + z;
    }
};

int main() {
    parent p(2, 3);
    cout << "Parent add: " << p.add() << endl;

    child c(2, 3, 4);
    cout << "Child add: " << c.add() << endl;

    parent* ptr = &c;
    cout << "Polymorphism (parent* to child): " << ptr->add() << endl;

    return 0;
}
