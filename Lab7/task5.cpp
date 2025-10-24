#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int comparisons = 0;

int partition(int arr[], int low, int high, int pivotIndex)
{
    swap(arr[pivotIndex], arr[high]);
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        comparisons++;
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int selectPivot(int arr[], int low, int high, int pivotPos)
{
    switch (pivotPos)
    {
    case 1:
        return low;
    case 2:
        return low + rand() % (high - low + 1);
    case 3:
        return (low + high) / 2;
    case 4:
    {
        int mid = (low + high) / 2;
        int a = arr[low], b = arr[mid], c = arr[high];
        if ((a > b) != (a > c))
            return low;
        else if ((b > a) != (b > c))
            return mid;
        else
            return high;
    }
    default:
        return low;
    }
}

void quickSort(int arr[], int low, int high, int pivotPos)
{
    if (low < high)
    {
        int pivotIndex = selectPivot(arr, low, high, pivotPos);
        int pi = partition(arr, low, high, pivotIndex);
        quickSort(arr, low, pi - 1, pivotPos);
        quickSort(arr, pi + 1, high, pivotPos);
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int checkPivotPos(int original[], int n, int pivotPos, const string &name)
{
    int arr[100];
    for (int i = 0; i < n; i++)
        arr[i] = original[i];

    comparisons = 0;
    quickSort(arr, 0, n - 1, pivotPos);
    cout << name << " Pivot Sorted: ";
    print(arr, n);
    cout << "Comparisons: " << comparisons << endl
         << endl;
    return comparisons;
}

int main()
{
    srand(time(0));

    int arr[] = {10, 7, 8, 9, 1, 5, 3, 15, 12, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    print(arr, n);
    cout << endl;

    int c1 = checkPivotPos(arr, n, 1, "First Element");
    int c2 = checkPivotPos(arr, n, 2, "Random Element");
    int c3 = checkPivotPos(arr, n, 3, "Middle Element");
    int c4 = checkPivotPos(arr, n, 4, "Median of Three");

    cout << "Comparison Summary\n";
    cout << "First Element Pivot:  " << c1 << " comparisons\n";
    cout << "Random Element Pivot: " << c2 << " comparisons\n";
    cout << "Middle Element Pivot: " << c3 << " comparisons\n";
    cout << "Median of Three Pivot: " << c4 << " comparisons\n";

    cout << "\nMore balanced pivot selections (Random / Median of Three) usually give fewer comparisons and better performance." << endl;

    return 0;
}
