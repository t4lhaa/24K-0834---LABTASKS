#include <iostream>
using namespace std;

class BubbleSort
{
private:
    int arr[100];
    int n;

public:
    BubbleSort(int a[], int size)
    {
        n = size;
        for (int i = 0; i < n; i++)
            arr[i] = a[i];
    }

    void sortAndDisplay()
    {
        int comparisons = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                comparisons++;
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        cout << "Sorted Array: ";
        for (int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        cout << "\nTotal Comparisons: " << comparisons << endl;
    }
};

int main()
{
    int data[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(data) / sizeof(data[0]);

    cout << "Original Array: ";
        for (int i = 0; i < size; i++){
            cout << data[i] << " ";
        }
    cout << endl;

    BubbleSort bs(data, size);
    bs.sortAndDisplay();

    return 0;
}
