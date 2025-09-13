#include <iostream>
using namespace std;

class Node
{
public:
    string data;
    Node *next;

    Node()
    {
        next = NULL;
    }
    Node(string data) : data(data)
    {
        next = NULL;
    }
};

class List
{
public:
    Node *head;
    Node *tail;

    List()
    {
        head = NULL;
        tail = NULL;
    }

    void insertAtFront(string data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtEnd(string data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void insert(string data, string pos)
    {
        Node *newNode = new Node(data);
        Node *temp = head;
        while (temp->data != pos)
        {
            temp = temp->next;
        }

        Node *t2 = temp->next;
        temp->next = newNode;
        newNode->next = t2;
    }

    void search(string data)
    {
        int idx = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == data)
            {
                cout << "Yes Found: " << temp->data << endl;
                return;
            }
            temp = temp->next;
            idx++;
        }
        cout << "Not found" << endl;
    }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "  ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    List list1;
    list1.insertAtFront("Data Structures");
    list1.insertAtEnd("Operating System");
    list1.insertAtEnd("Computer Network");
    list1.insertAtEnd("Database Systems");
    cout << "First List: " << endl;
    list1.display();

    cout << "Inserting at front:" << endl;
    list1.insertAtFront("Artificiall Intelligence");
    list1.display();

    cout << "Inserting at end " << endl;
    list1.insertAtEnd("Machine Learning");
    list1.display();

    cout << "Inserting After OS " << endl;
    list1.insert("Cyber Security", "Operating System");

    cout << "Searching for DS " << endl;
    list1.search("Database Systems");

    cout << "Second List: " << endl;
    list1.display();
    
    return 0;
}
