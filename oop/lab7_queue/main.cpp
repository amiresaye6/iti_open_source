#include <iostream>

using namespace std;

class Queue
{
    int* arr;
    int size;
    int in, out;

public:
    Queue(int _size = 5)
    {
        if (_size <= 0)
        {
            cout << "size must be positive greater than 0" << endl;
        }
        else
        {
            size = _size + 1;
            arr = new int[size];
            if (arr == NULL)
            {
                cout << "failed to allocate the queue" << endl;
            }
        }
        in = out = 0;
    }
    ~Queue()
    {
        cout << "your queue of size " << size << " is deleted" << endl;
        delete[] arr;
    }

    int enqueue(int _val)
    {
//        if ((in + 1 == size && out == 0) || (in + 1 == out))
        if ((in + 1) % size == out)
        {
            cout << "queue is full" << endl;
            return 0;
        }
        else
        {
            arr[in] = _val;
            in = (in + 1) % size;

            cout << "input value " << _val << endl;
        }
        return 1;
    }

    int dequeue(int& data)
    {
        if (out == in)
        {
            cout << "queue is empty" << endl;
            return 0;
        }
        else
        {
            data = arr[out];
            out = (out + 1) % size;

        }
        return 1;
    }


};

int main()
{
    int d;
    Queue a(5);
    a.enqueue(10);
    a.enqueue(20);
    a.enqueue(30);
    if (a.dequeue(d) == 1)
        cout << "output value " << d << endl;
    if (a.dequeue(d) == 1)
        cout << "output value " << d << endl;
    a.enqueue(40);
    a.enqueue(50);
    a.enqueue(50);
    if (a.dequeue(d) == 1)
        cout << "output value " << d << endl;
    if (a.dequeue(d) == 1)
        cout << "output value " << d << endl;
    a.enqueue(60);
    a.enqueue(70);
    a.enqueue(80);

    for (int i = 0; i < 5; i++)
    {

        if (a.dequeue(d) == 1)
            cout << "output value " << d << endl;
    }

    return 0;
}
