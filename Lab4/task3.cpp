#include <iostream>
using namespace std;

class ShellSort {
private:
    int arr[100];
    int n;

public:
    void input() {
        cout << "Enter number of elements: ";
        cin >> n;
        cout << "Enter " << n << " elements: ";
        for (int i = 0; i < n; i++)
            cin >> arr[i];
    }

    void sortAndDisplay() {
        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                int temp = arr[i];
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                    arr[j] = arr[j - gap];
                arr[j] = temp;
            }
        }
        cout << "Sorted Array: ";
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
    }
};

int main() {
    ShellSort ss;
    ss.input();
    ss.sortAndDisplay();
    return 0;
}
