#include <iostream>
#include <string>
using namespace std;

class Product
{
public:
    string name;
    int price;
    int orderID;
};
class Store
{
private:
    Product products[3];
    int n;

    int partition(Product arr[], int low, int high)
    {
        int pivot = arr[high].price;
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (arr[j].price < pivot)
            {
                i++;
                Product temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        Product temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        return (i + 1);
    }

    void quickSort(Product arr[], int low, int high)
    {
        if (low < high)
        {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

public:
    Store()
    {
        n = 3;
    }

    void input()
    {
        for (int i = 0; i < n; i++)
        {
            cout << "\nEnter details of Order 1:\n";
            cout << "OrderID: ";
            cin >> products[i].orderID;
            cout << "Customer Name ";
            cin >> products[i].name;
            cout << "Price: ";
            cin >> products[i].price;
        }
    }

    void sort()
    {
        quickSort(products, 0, n - 1);
    }

    void display()
    {
        cout << "\nSorted Product List (by Price - Ascending):\n";
        cout << "orderID\t\tCustome Name\t\tPrice" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << products[i].orderID << "\t\t";
            cout << products[i].name << "\t\t\t";
            cout << products[i].price << endl;
        }
    }
};

int main()
{
    Store s;
    s.input();
    s.sort();
    s.display();
    return 0;
}
