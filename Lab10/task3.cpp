#include <iostream>
using namespace std;

class Hash
{
private:
    int size;
    int *table;

public:
    Hash(int s = 10)
    {
        size = s;
        table = new int[size];

        for (int i = 0; i < size; i++)
            table[i] = -1;
    }

    // Hash function
    int hashFunction(int key)
    {
        return key % size;
    }

    void insert(int key)
    {
        int index = hashFunction(key);

        for (int i = 0; i < size; i++)
        {
            int probe = (index + i) % size;

            if (table[probe] == -1)
            {
                table[probe] = key;
                cout << "Inserted: " << key << endl;
                return;
            }
        }

        cout << "Hash Table FULL! Cannot insert.\n";
    }

    bool search(int key)
    {
        int index = hashFunction(key);

        for (int i = 0; i < size; i++)
        {
            int probe = (index + i) % size;

            if (table[probe] == key)
                return true;

            if (table[probe] == -1)
                return false;
        }

        return false;
    }

    void deleteKey(int key)
    {
        int index = hashFunction(key);

        for (int i = 0; i < size; i++)
        {
            int probe = (index + i) % size;

            if (table[probe] == key)
            {
                table[probe] = -2;
                cout << "Deleted: " << key << endl;
                return;
            }

            if (table[probe] == -1)
            {
                cout << "Key Not Found!\n";
                return;
            }
        }

        cout << "Key Not Found!\n";
    }

    void display()
    {
        cout << "\nHash Table:\n";
        for (int i = 0; i < size; i++)
        {
            cout << i << ": ";
            if (table[i] == -1)
                cout << "EMPTY\n";
            else if (table[i] == -2)
                cout << "DELETED\n";
            else
                cout << table[i] << endl;
        }
        cout << endl;
    }
};

int main()
{
    Hash h(10);

    h.insert(12);
    h.insert(22);
    h.insert(32);
    h.insert(42);

    h.display();

    cout << "Searching 22: "
         << (h.search(22) ? "Found" : "Not Found") << endl;

    h.deleteKey(22);

    h.display();

    return 0;
}
