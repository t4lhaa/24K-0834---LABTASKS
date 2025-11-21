#include <iostream>
#include <string>
using namespace std;

class StudentRecord
{
public:
    int roll;
    string name;
    bool isEmpty;
    bool isDeleted;

    StudentRecord()
    {
        roll = -1;
        name = "";
        isEmpty = true;
        isDeleted = false;
    }
};

class StudentHashTable
{
private:
    static const int TABLE_SIZE = 15;
    StudentRecord table[TABLE_SIZE];

    int hashFunction(int roll)
    {
        return roll % TABLE_SIZE;
    }

public:
    void InsertRecord(int roll, string name)
    {

        int index = hashFunction(roll);

        for (int attempt = 0; attempt < TABLE_SIZE; attempt++)
        {

            int probe = (index + attempt * attempt) % TABLE_SIZE;

            if (table[probe].isEmpty || table[probe].isDeleted)
            {
                table[probe].roll = roll;
                table[probe].name = name;
                table[probe].isEmpty = false;
                table[probe].isDeleted = false;

                cout << "Record Inserted Successfully!\n";
                return;
            }
        }

        cout << "Hash Table is FULL. Cannot insert record.\n";
    }

    void SearchRecord(int roll)
    {

        int index = hashFunction(roll);

        for (int attempt = 0; attempt < TABLE_SIZE; attempt++)
        {

            int probe = (index + attempt * attempt) % TABLE_SIZE;

            if (table[probe].isEmpty && !table[probe].isDeleted)
            {
                cout << "Record not found\n";
                return;
            }

            if (!table[probe].isEmpty && table[probe].roll == roll)
            {
                cout << "Record Found: " << table[probe].name << endl;
                return;
            }
        }

        cout << "Record not found\n";
    }

    void DisplayTable()
    {
        cout << "\nStudent Hash Table:\n";
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            if (table[i].isEmpty)
                cout << i << ": EMPTY\n";
            else
                cout << i << ": Roll " << table[i].roll << ", Name " << table[i].name << endl;
        }
        cout << endl;
    }
};

int main()
{
    StudentHashTable ht;

    ht.InsertRecord(101, "Ali");
    ht.InsertRecord(116, "Sara");
    ht.InsertRecord(131, "Ahmed");
    ht.InsertRecord(146, "Fatima");

    ht.DisplayTable();

    ht.SearchRecord(116);
    ht.SearchRecord(999);

    return 0;
}
