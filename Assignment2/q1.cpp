#include <iostream>
using namespace std;

int main()
{
    cout << "Enter the length of the array: \n";
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << i + 1 << " : ";
        cin >> arr[i];
    }
    cout << "The array elements are: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // Sorted array
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    int start = 0;
    int end = size - 1;
    cout << "Which element you want to find\n";
    int ele;
    cin >> ele;
    bool found = false;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (ele == arr[mid])
        {
            cout << "Found element at index: " << mid << endl;
            found = true;
            break;
        }
        else if (ele < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    if (!found)
    {
        cout << "Element not found\n";
    }
}