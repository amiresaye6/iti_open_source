#include <iostream>
using namespace std;

template <class T>
class Stack
{
    T* arr;
    int size;
    int tos;

public:
    Stack(int _size = 5)
    {
        if (_size <= 0)
        {
            cout << "size must be positive greater than 0" << endl;
            _size = 5;
        }
        size = _size;
        arr = new T[size];
        tos = -1;
    }

    ~Stack()
    {
        cout << "your Stack of size " << size << " is deleted" << endl;
        delete[] arr;
    }

    Stack(const Stack<T>& cs)
    {
        tos = cs.tos;
        size = cs.size;
        arr = new T[size];
        for (int i = 0; i <= tos; i++)
            arr[i] = cs.arr[i];
        cout << "deep copy completed" << endl;
    }

    int push(T _val)
    {
        if (tos + 1 == size)
        {
            cout << "your stack is full" << endl;
            return 0;
        }
        arr[++tos] = _val;
        cout << "pushed value " << _val << endl;
        return 1;
    }

    int pop(T& data)
    {
        if (tos == -1)
        {
            cout << "your stack is empty" << endl;
            return 0;
        }
        data = arr[tos--];
        return 1;
    }

    void clearStack()
    {
        while (tos != -1)
            tos--;
        cout << "stack cleared" << endl;
    }

    void print()
    {
        for (int i = 0; i <= tos; i++)
            cout << "idx " << i << ", val: " << arr[i] << endl;
    }
    Stack& operator=(const Stack& s)
    {
        if (this != &s)
        {
            delete[] arr;
            size = s.size;
            tos = s.tos;
            arr = new T[size];
            for (int i = 0; i <= tos; i++)
                arr[i] = s.arr[i];
        }
        return *this;
    }


    Stack operator+(Stack&  s)
    {
        Stack newS(size + s.size);
        for (int i = 0; i <= tos; i++)
            newS.push(arr[i]);
        for (int i = 0; i <= s.tos; i++)
            newS.push(s.arr[i]);
        return newS;
    }
};
int main()
{
    Stack<int> s1(3);
    s1.push(10);
    s1.push(20);
    s1.push(30);

    Stack<int> s2(2);
    s2.push(40);
    s2.push(50);

    Stack<int> s3 = s1 + s2;
    cout << "Combined stack contents:\n";
    s3.print();

    return 0;
}
