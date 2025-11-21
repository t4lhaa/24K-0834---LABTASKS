#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string data;
    Node *next;

    Node(string d)
    {
        data = d;
        next = nullptr;
    }
};

class HashTable
{
private:
    int bucketCount;
    Node **table;

    int hashFunction(string key)
    {
        int sum = 0;
        for (char c : key)
            sum += int(c);
        return sum % bucketCount;
    }

public:
    HashTable(int buckets)
    {
        bucketCount = buckets;
        table = new Node *[bucketCount];

        for (int i = 0; i < bucketCount; i++)
            table[i] = nullptr;
    }

    void insert(string key)
    {
        int index = hashFunction(key);

        Node *newNode = new Node(key);

        newNode->next = table[index];
        table[index] = newNode;
    }

    void display()
    {
        cout << "Hash Table:\n";
        for (int i = 0; i < bucketCount; i++)
        {
            cout << "Bucket " << i << ": ";
            Node *temp = table[i];
            if (!temp)
            {
                cout << "NULL\n";
            }
            else
            {
                while (temp)
                {
                    cout << temp->data << " -> ";
                    temp = temp->next;
                }
                cout << "NULL\n";
            }
        }
    }
};

int main()
{
    HashTable ht(10);

    ht.insert("apple");
    ht.insert("mango");
    ht.insert("grapes");
    ht.insert("grapes");
    ht.insert("peach");
    ht.insert("banana");

    ht.display();
    return 0;
}
