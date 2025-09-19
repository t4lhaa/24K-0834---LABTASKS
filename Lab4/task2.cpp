#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Sorting {
private:
    int arr[100];
    int n;

public:
    Sorting(int size) {
        n = size;
        srand(time(0));
        for (int i = 0; i < n; i++)
            arr[i] = rand() % 100 + 1;
    }

    void display() {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    void bubbleSort() {
        int a[100];
        for (int i = 0; i < n; i++) a[i] = arr[i];
        int comparisons = 0;

        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++) {
                comparisons++;
                if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
            }

        cout << "Bubble Sorted: ";
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << "\nComparisons: " << comparisons << endl;
    }

    void insertionSort() {
        int a[100];
        for (int i = 0; i < n; i++) a[i] = arr[i];
        int comparisons = 0;

        for (int i = 1; i < n; i++) {
            int key = a[i], j = i - 1;
            while (j >= 0 && a[j] > key) {
                comparisons++;
                a[j + 1] = a[j];
                j--;
            }
            comparisons++;
            a[j + 1] = key;
        }

        cout << "Insertion Sorted: ";
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << "\nComparisons: " << comparisons << endl;
    }

    void selectionSort() {
        int a[100];
        for (int i = 0; i < n; i++) a[i] = arr[i];
        int comparisons = 0;

        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                comparisons++;
                if (a[j] < a[minIndex])
                    minIndex = j;
            }
            swap(a[i], a[minIndex]);
        }

        cout << "Selection Sorted: ";
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << "\nComparisons: " << comparisons << endl;
    }

    void shellSort() {
        int a[100];
        for (int i = 0; i < n; i++) a[i] = arr[i];
        int comparisons = 0;

        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                int temp = a[i];
                int j;
                for (j = i; j >= gap && a[j - gap] > temp; j -= gap) {
                    comparisons++;
                    a[j] = a[j - gap];
                }
                comparisons++;
                a[j] = temp;
            }
        }

        cout << "Shell Sorted: ";
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << "\nComparisons: " << comparisons << endl;
    }
};

int main() {
    Sorting s(20);

    cout << "Original Array: ";
    s.display();

    s.bubbleSort();
    s.insertionSort();
    s.selectionSort();
    s.shellSort();

    return 0;
}
