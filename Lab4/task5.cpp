#include <iostream>
using namespace std;

class BinarySearch {
private:
    int arr[100], n;

public:
    void input() {
        cout << "Enter number of elements: ";
        cin >> n;
        cout << "Enter elements: ";
        for (int i = 0; i < n; i++)
            cin >> arr[i];
    }

    void sortArray() {
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (arr[j] > arr[j + 1])
                    swap(arr[j], arr[j + 1]);
    }

    int binarySearch(int x) {
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == x) return mid;
            else if (arr[mid] < x) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }

    void run() {
        sortArray();
        cout << "Sorted Array: ";
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << endl;

        int x;
        cout << "Enter value to search: ";
        cin >> x;

        int result = binarySearch(x);
        if (result != -1)
            cout << "Element found at index " << result << endl;
        else
            cout << "Element not found." << endl;
    }
};

int main() {
    BinarySearch obj;
    obj.input();
    obj.run();
    return 0;
}
