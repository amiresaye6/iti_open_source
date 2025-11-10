#include <iostream>

using namespace std;

void swap(int* x, int* y);
void swapper();
void arrayPtr();
void dynamicArray();
int main()
{
    //swapper();

    //arrayPtr();

    dynamicArray();
    return 0;
};

void swapper()
{
    int x = 1, y = 2;
    cout << "before swap" << endl;
    cout << "x is : " << x << " and y is : " << y << endl;

    swap(&x, &y);

    cout << "before swap" << endl;
    cout << "x is : " << x << " and y is : " << y << endl;
}

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
};

void arrayPtr()
{
    int size = 5;
    int arr[size] = {6, 7, 8, 9, 10};
    int* ptr = arr;


    for (int i = 0; i < size; i++)
    {
        cout << "*(ptr + i) :\t" << *(ptr + i) << endl;
        cout << "*(arr + i) :\t" << *(arr + i) <<  endl;
        cout << "arr[i] :\t" << arr[i] <<  endl;
        cout << "ptr[i] :\t" << ptr[i] << endl;
    }

}

void dynamicArray()
{
    int size = 1, flag = 0;
    int* a;
    cout << "welcome to dynamic array :__:" << endl;
    cout << "Please size the dynamic array size to allocate. [int value larger than 1]" << endl;
    while (flag == 0)
    {
        cin >> size;
        if (size < 1 )
            cout << "invalid inpult, [int value larger than 1]" << endl;
        else
            flag = 1;
    }

    a = new int[size];
    if (a == NULL)
    {
        cout << "could not allocate the space you requiredd \n";
        return;
    }
    cout << "lets size the data:" << endl;
    for (int i = 0; i < size; i++)
        cin >> a[i];
    for (int i = 0; i < size; i++)
        cout <<  a[i] << ", ";


}
