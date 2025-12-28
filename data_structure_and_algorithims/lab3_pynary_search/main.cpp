#include <iostream>
#include <vector>

using namespace std;


int binarySearch(const vector<int>& arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}


int binarySearch(const vector<int>& arr, int target, int low, int high)
{
    if (low > high)
    {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] < target)
    {
        return binarySearch(arr, target, mid + 1, high);
    }
    else
    {
        return binarySearch(arr, target, low, mid - 1);
    }
}


int main() {
    vector<int> testArray = {10, 20, 30, 40, 50, 60, 70, 80};

    cout << "Itrative Search Tests" << endl;
    int resIdx = binarySearch(testArray, 40);
    cout << "  result at index " << resIdx  << endl;

    resIdx = binarySearch(testArray, 45);
    cout << "  result at index " << resIdx  << endl;

    cout << "Recursive Binary Search Tests" << endl;

    resIdx = binarySearch(testArray, 40, 0, testArray.size() - 1);
    cout << "  result at index " << resIdx << endl;
    resIdx = binarySearch(testArray, 45,0, testArray.size() - 1);
    cout << "  result at index " << resIdx  << endl;

    return 0;
}
