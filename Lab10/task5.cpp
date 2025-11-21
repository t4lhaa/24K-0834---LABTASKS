#include <iostream>
#include <string>
using namespace std;

class EmployeeHashTable
{
private:
    static const int TABLE_SIZE = 50;
    string table[TABLE_SIZE];
    bool isEmpty[TABLE_SIZE];

    int asciiSum(string s)
    {
        int sum = 0;
        for (char c : s)
            sum += int(c);
        return sum;
    }

    int h1(string name)
    {
        return asciiSum(name) % TABLE_SIZE;
    }

    int h2(string name)
    {
        return 7 - (asciiSum(name) % 7);
    }

public:
    EmployeeHashTable()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
            isEmpty[i] = true;
    }

    void Add_Employee(string name)
    {
        int primary = h1(name);
        int secondary = h2(name);

        int index = primary;

        for (int i = 0; i < TABLE_SIZE; i++)
        {

            int newIndex = (primary + i * secondary) % TABLE_SIZE;

            if (isEmpty[newIndex])
            {
                table[newIndex] = name;
                isEmpty[newIndex] = false;

                cout << "Employee added at index " << newIndex << endl;
                return;
            }
        }
        cout << "Error: Hash table is FULL. Cannot insert.\n";
    }

    void Search_Employee(string name)
    {
        int primary = h1(name);
        int secondary = h2(name);

        for (int i = 0; i < TABLE_SIZE; i++)
        {

            int newIndex = (primary + i * secondary) % TABLE_SIZE;

            if (isEmpty[newIndex])
            {
                cout << "Employee not found in the directory.\n";
                return;
            }

            if (table[newIndex] == name)
            {
                cout << "Employee found at index " << newIndex << endl;
                return;
            }
        }

        cout << "Employee not found in the directory.\n";
    }

    void Display_Table()
    {
        cout << "\n--- Employee Hash Table (Double Hashing) ---\n";
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            cout << i << " : ";
            if (isEmpty[i])
                cout << "EMPTY\n";
            else
                cout << table[i] << "\n";
        }
        cout << "-------------------------------------------\n";
    }
};

int main()
{
    EmployeeHashTable ht;

    ht.Add_Employee("Ali");
    ht.Add_Employee("Sara");
    ht.Add_Employee("John");
    ht.Add_Employee("Amna");

    ht.Display_Table();

    ht.Search_Employee("Sara");
    ht.Search_Employee("Zain");

    return 0;
}
