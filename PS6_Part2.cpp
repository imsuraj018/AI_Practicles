// Selection Sort using Greedy Technique

#include <iostream>

using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        // Assume minimum element index
        int minIndex = i;

        // Find smallest element
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // Swap smallest element
        swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    int arr[] = {29, 10, 14, 37, 13};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array:\n";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    selectionSort(arr, n);

    cout << "\n\nSorted Array:\n";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}