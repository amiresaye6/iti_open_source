#include <iostream>

using namespace std;

class Stack
{
    int* arr;
    int size;
    int tos;

public:
    Stack(int _size = 5)
    {
        if (_size <= 0)
        {
            cout << "size must be positive greater than 0" << endl;
        }
        else
        {
            size = _size;
            arr = new int[size];
            if (arr == NULL)
            {
                cout << "failed to allocate the stack" << endl;
            }
        }
        tos = -1;
    }
    ~Stack()
    {
        cout << "your Stack of size " << size << " is deleted" << endl;
        delete[] arr;
    }

    // lab 8 udpate, adding copy construcuor
    Stack(Stack& cs)
    {
        tos = cs.tos;
        size = cs.size;
        arr = new int[size];
        for (int i = 0; i <= tos; i++)
        {
            arr[i] = cs.arr[i];
        }
        cout << "deep copy completed" << endl;

    }
    int push(int _val)
    {
        if (tos + 1 == size)
        {
            cout << "your stack is full" << endl;
            return 0;
        }
        else
        {
            tos++;
            arr[tos] = _val;
            cout << "pushed value " << _val << endl;
        }
        return 1;
    }

    int pop(int& data)
    {
        if (tos - 1 == -2 )
        {
            cout << "your stack is empty" << endl;
            return 0;
        }
        else
        {
            data = arr[tos];
            tos--;
        }
        return 1;
    }
    void clearStask()
    {
        while(tos != -1)
            arr[tos--]  = 0;

    }
// update from lab 8
    void print()
    {
        for (int i = 0; i <= tos; i++)
            cout << "idx " << i << ", val: " << arr[i] << endl;
    }

};

int main()
{
    Stack s1(5), s2(3);

    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);

// update from lab 8

    s2.push(30);
    s2.push(40);
    s2.push(50);


    cout << "==================start lab 8 update==================" << endl;
    Stack s3(s1), s4 = s2;
    s3.print();
    cout << "second new stack" << endl;
    s4.print();
    cout << "==================end lab 8 update==================" << endl;

    int d = 0;
    for (int i = 0; i < 5; i++)
    {

        if (s1.pop(d) == 1)
            cout << "successfully poped, value is " << d << endl;
    }

    if (s1.pop(d) == 1)
            cout << "successfully poped, value is " << d << endl;



    s2.push(10);
    s2.push(10);
    s2.push(10);
    cout << "clearing stack 2" << endl;
    s2.clearStask();


    int temp;
    s2.pop(temp);

    return 0;
}
