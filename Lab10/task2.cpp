#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string word;
    Node *next;

    Node(string w)
    {
        word = w;
        next = nullptr;
    }
};

class Dictionary
{
private:
    static const int TABLE_SIZE = 100;
    Node *table[TABLE_SIZE];

    int hashFunction(string key)
    {
        int sum = 0;
        for (char c : key)
            sum += int(c);
        return sum % TABLE_SIZE;
    }

public:
    Dictionary()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = nullptr;
    }

    void Add_Record(string word)
    {
        int index = hashFunction(word);

        Node *newNode = new Node(word);
        newNode->next = table[index];
        table[index] = newNode;

        cout << "Record Added Successfully!\n";
    }

    void Word_Search(string word)
    {
        int index = hashFunction(word);
        Node *temp = table[index];

        while (temp != nullptr)
        {
            if (temp->word == word)
            {
                cout << "Word '" << word << "' Found in Dictionary.\n";
                return;
            }
            temp = temp->next;
        }

        cout << "Error: Word '" << word << "' NOT Found!\n";
    }

    void Print_Dictionary()
    {
        cout << "\n----- ASCII Dictionary -----\n";
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            cout << "Bucket " << i << ": ";
            Node *temp = table[i];

            if (!temp)
            {
                cout << "NULL\n";
            }
            else
            {
                while (temp != nullptr)
                {
                    cout << temp->word << " -> ";
                    temp = temp->next;
                }
                cout << "NULL\n";
            }
        }
        cout << "----------------------------\n";
    }
};

int main()
{
    Dictionary dict;

    int choice;
    string word;

    do
    {
        cout << "\nDictionary Menu\n";
        cout << "1. Add Record\n";
        cout << "2. Search Word\n";
        cout << "3. Print Dictionary\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Word to Add: ";
            cin >> word;
            dict.Add_Record(word);
            break;

        case 2:
            cout << "Enter Word to Search: ";
            cin >> word;
            dict.Word_Search(word);
            break;

        case 3:
            dict.Print_Dictionary();
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}
