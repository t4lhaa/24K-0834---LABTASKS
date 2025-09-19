#include <iostream>
using namespace std;

class InterpolationSearch {
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

    int interpolationSearch(int x) {
        int low = 0, high = n - 1;
        while (low <= high && x >= arr[low] && x <= arr[high]) {
            if (low == high) {
                if (arr[low] == x) return low;
                return -1;
            }
            int pos = low + ((x - arr[low]) * (high - low)) / (arr[high] - arr[low]);
            if (arr[pos] == x) return pos;
            if (arr[pos] < x) low = pos + 1;
            else high = pos - 1;
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

        int result = interpolationSearch(x);
        if (result != -1)
            cout << "Element found at index " << result << endl;
        else
            cout << "Element not found." << endl;
    }
};

int main() {
    InterpolationSearch obj;
    obj.input();
    obj.run();
    return 0;
}
