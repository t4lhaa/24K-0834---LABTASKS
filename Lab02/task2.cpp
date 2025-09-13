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

    void deleteAtFront()
    {
        Node *temp = head;
        if (head == NULL)
        {
            return;
        }
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }

    void insertAtEnd(string data)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = tail = newnode;
            return;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }

    void searchByName(string data)
    {
        int idx = 0;
        Node *temp = head;
        while (temp != NULL)
        {

            if (temp->data == data)
            {
                cout << "Yes Found at idx " << idx << ": " << temp->data << endl;
                return;
            }
            temp = temp->next;
            idx++;
        }
        cout << "Not found" << endl;
    }

    void searchByIndex(int pos)
    {
        int idx = 0;
        Node *temp = head;
        while (temp != NULL)
        {

            if (idx == pos)
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
    list1.insertAtEnd("DS");
    list1.insertAtEnd("Discrete");
    list1.insertAtEnd("LA");
    list1.insertAtEnd("TOA");

    cout << "First List: " << endl;
    list1.display();

    cout << "Inserting at End " << endl;
    list1.insertAtEnd("DS LAB");

    cout << "Deleting from Front" << endl;
    list1.deleteAtFront();

    cout << "Searching by title: " << endl;
    list1.searchByName("Discreteing");

    cout << "Search by index: " << endl;
    list1.searchByIndex(3);

    cout << "Second list: " << endl;
    list1.display();
}
