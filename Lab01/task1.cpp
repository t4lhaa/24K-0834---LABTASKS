#include <iostream>
using namespace std;

class DynamicArray
{
public:
    int n;
    int *arr;
    int count;

    DynamicArray()
    {
        n = 0;
        arr = NULL;
        count = 0;
    }

    DynamicArray(int size)
    {
        n = size;
        arr = new int[n];
        count = 0;
    }

    void push(int value)
    {
        if (count < n)
        {
            arr[count] = value;
            count++;
        }
        else
        {

            int size = n * 2;
            int *temp = new int[n];

            for (int i = 0; i < n; ++i)
            {
                temp[i] = arr[i];
            }

            delete[] arr;
            arr = new int[size];

            for (int i = 0; i < size; ++i)
            {
                arr[i] = temp[i];
            }

            arr[count] = value;
            n = size;
            count++;
        }
    }

    void printing()
    {

        for (int i = 0; i < count; ++i)
        {
            cout << arr[i] << " ";
        }
    }

    ~DynamicArray()
    {
        delete[] arr;
        delete arr;
    }
};
int main()
{

    int size;
    cout << "Enter size of array: " << endl;
    cin >> size;
    
    DynamicArray D(size);

    D.push(17);
    D.push(9);
    D.push(23);
    D.push(1);
    D.push(56);
    D.printing();
    cout << endl;
    D.push(66);
    D.printing();
}
