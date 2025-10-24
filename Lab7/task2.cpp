#include <iostream>
#include <string>
using namespace std;

class Runner
{
public:
    string name;
    int time;
};

class Race
{
private:
    Runner runners[10];
    int n;

    void merge(Runner arr[], int first, int m, int last)
    {
        int n1 = m - first + 1;
        int n2 = last - m;

        Runner *L = new Runner[n1];
        Runner *R = new Runner[n2];

        for (int i = 0; i < n1; i++)
            L[i] = arr[first + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[m + 1 + j];

        int i = 0;
        int j = 0;
        int k = first;

        while (i < n1 && j < n2)
        {
            if (L[i].time <= R[j].time)
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }

        delete[] L;
        delete[] R;
    }

    void mergeSort(Runner arr[], int first, int last)
    {
        if (first < last)
        {
            int m = (first + last) / 2;
            mergeSort(arr, first, m);
            mergeSort(arr, m + 1, last);
            merge(arr, first, m, last);
        }
    }

public:
    Race()
    {
        n = 10;
    }

    void input()
    {
        cout << "Enter names and finish times (in seconds):\n";
        for (int i = 0; i < n; i++)
        {
            cout << "Runner " << i + 1 << " name: ";
            cin >> runners[i].name;
            cout << "Finish time (in seconds): ";
            cin >> runners[i].time;
        }
    }

    void sort()
    {
        mergeSort(runners, 0, n - 1);
    }

    void display()
    {
        cout << "\nTop 5 Fastest Runners:\n";
        cout << "Rank       Name        Time(seconds)\n";
        for (int i = 0; i < 5; i++)
        {
            cout << i + 1 << "      " << runners[i].name << "       " << runners[i].time << endl;
        }
    }
};

int main()
{
    Race m;
    m.input();
    m.sort();
    m.display();
    return 0;
}
