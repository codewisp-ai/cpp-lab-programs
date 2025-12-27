#include <iostream>
using namespace std;

// Simple bubble sort (no STL)
void sortArray(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
        for(int j = 0; j < n - i - 1; j++)
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

void printSubsetsDup(int arr[], int n, int index, int subset[], int subsetSize)
{
    cout << "{ ";
    for(int i = 0; i < subsetSize; i++)
        cout << subset[i] << " ";
    cout << "}\n";

    for(int i = index; i < n; i++)
    {
        // Skip duplicates at same recursion level
        if(i > index && arr[i] == arr[i - 1])
            continue;

        subset[subsetSize] = arr[i];
        printSubsetsDup(arr, n, i + 1, subset, subsetSize + 1);
        // backtracking happens automatically when function returns
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int* arr = new int[n];
    int* subset = new int[n];

    cout << "Enter elements (duplicates allowed):\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    sortArray(arr, n);   // important

    cout << "\nAll unique subsets are:\n";
    printSubsetsDup(arr, n, 0, subset, 0);

    delete[] arr;
    delete[] subset;

    return 0;
}
