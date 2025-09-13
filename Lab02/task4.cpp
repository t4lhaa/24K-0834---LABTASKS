#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value)
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
        head = tail = NULL;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "EMPTY LIST!!!!!!!!!" << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "  ";
            temp = temp->next;
        }
        cout << endl;
    }
    void insert(int value)
    {
        Node *newNode = new Node(value);
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

    Node *middleNode()
    {
        Node *slow = head;
        Node *fast = head->next;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    Node *mergeTwoLists(Node *head1, Node *head2)
    {
        if (head1 == NULL || head2 == NULL)
        {
            return head1 == NULL ? head2 : head1;
        }
        if (head1->data <= head2->data)
        {
            head1->next = mergeTwoLists(head1->next, head2);
            return head1;
        }
        else
        {
            head2->next = mergeTwoLists(head1, head2->next);
            return head2;
        }
    }
    Node *concat(Node *H2)
    {
        Node *T1 = tail;
        Node *t2 = H2;
        T1->next = t2;
    }

    void sort()
    {
        if (head == NULL)
        {
            return;
        }
        int n = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            n++;
            temp = temp->next;
        }
        int *arr = new int[n];
        temp = head;
        for (int i = 0; i < n; i++)
        {
            arr[i] = temp->data;
            temp = temp->next;
        }

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int t = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = t;
                }
            }
        }

        temp = head;
        for (int i = 0; i < n; i++)
        {
            temp->data = arr[i];
            temp = temp->next;
        }
        delete[] arr;
        delete arr;
    }

    void removeDuplicate()
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        while (temp != NULL && temp->next != NULL)
        {
            if (temp->data == temp->next->data)
            {
                Node *dup = temp->next;
                temp->next = temp->next->next;
                delete dup;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
};

int main()
{
    List List1;
    List1.insert(1);
    List1.insert(3);
    List1.insert(2);
    List1.insert(5);
    List1.insert(4
    );
    cout << "Before Sort: " << endl;
    List1.display();

    cout << "After Sort: " << endl;
    List1.sort();
    List1.display();

    cout << "Middle of the List1: " << endl;
    cout << List1.middleNode()->data << endl;
    cout << endl;

    List L1;
    L1.insert(3);
    L1.insert(5);
    L1.insert(4);
    List L2;
    L2.insert(1);
    L2.insert(2);
    L2.insert(0);

    cout << "Two list: " << endl;
    L1.display();
    L2.display();

    cout << "Concating Them " << endl;
    L1.concat(L2.head);
    L1.display();
    cout << endl;

    List L3;
    L3.insert(45);
    L3.insert(76);
    L3.insert(8);
    List L4;
    L4.insert(80);
    L4.insert(71);
    L4.insert(92);

    cout << "Two list: " << endl;
    L3.display();
    L4.display();

    cout << "Sorted Merging: " << endl;
    L3.mergeTwoLists(L3.head, L4.head);
    L3.display();

    cout << "Removing duplicate from this list" << endl;
    L3.removeDuplicate();
    L3.display();
}
