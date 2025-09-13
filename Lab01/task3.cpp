#include <iostream>
using namespace std;

int main()
{
    int teams;
    cout << "Enter Number of teams: ";
    cin >> teams;

    int **scores = new int *[teams];
    int *n = new int[teams];

    for (int i = 0; i < teams; i++)
    {
        cout << "Enter number of player in team " << (i + 1) << ": ";
        cin >> n[i];
        scores[i] = new int[n[i]];

        cout << "Enter score: ";
        for (int j = 0; j < n[i]; j++)
        {
            cin >> scores[i][j];
        }
    }

    cout << endl
         << "Team Score's Sum: " << endl;
    for (int i = 0; i < teams; i++)
    {
        int sum = 0;
        for (int j = 0; j < n[i]; j++)
        {
            sum += scores[i][j];
        }
        cout << "Team " << i + 1 << "'s Score: " << sum << endl;
    }

    for (int i = 0; i < teams; i++)
    {
        delete[] scores[i];
    }
    delete[] scores;
    delete scores;
    delete[] n;
    delete n;

    return 0;
}
