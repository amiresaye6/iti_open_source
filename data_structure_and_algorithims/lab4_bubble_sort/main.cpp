#include <iostream>

using namespace std;

void selectionSort(int arr[], int size);
void bubbleSort(int arr[], int size);
void insertionSort(int arr[], int size);
void printArray(const char* name, const int arr[], int size);

int main()
{
    int arr1[] = {3, 4, 1, 5, 9, 0, 8, 7, 2, 5, 6};
    int arr2[] = {3, 4, 1, 5, 9, 0, 8, 7, 2, 5, 6};
    int arr3[] = {3, 4, 1, 5, 9, 0, 8, 7, 2, 5, 6};

    int n = 10;


    selectionSort(arr1, n);
    printArray("Selection Sort (Ascending)", arr1, n);
    cout << "----------------------------------" << endl;


    bubbleSort(arr2, n);
    printArray("Bubble Sort (Ascending)", arr2, n);
    cout << "----------------------------------" << endl;


    insertionSort(arr3, n);
    printArray("Insertion Sort (Ascending)", arr3, n);

    return 0;
}

void printArray(const char* name, const int arr[], int size)
{
    cout << name << " Result:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}


void selectionSort(int arr[], int size)
{
    int temp;

    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i;

        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }


        if (min_index != i)
        {
            temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}



void bubbleSort(int arr[], int size)
{
    int temp;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int size)
{
    int key;
    int j;

    for (int i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
