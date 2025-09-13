#include <iostream>
using namespace std;

class Node
{
public:
    string song;
    Node *next;

    Node(string name)
    {
        song = name;
        next = NULL;
    }
};

class Playlist
{
private:
    Node *head;
    Node *tail;
    Node *current;

public:
    Playlist()
    {
        head = NULL;
        tail = NULL;
        current = NULL;
    }
    void addSong(string name)
    {
        Node *newsong = new Node(name);
        if (head == NULL)
        {
            head = tail = newsong;
            tail->next = head;
        }
        else
        {
            tail->next = newsong;
            tail = newsong;
            tail->next = head;
        }
    }
    void display()
    {
        Node *temp = head;
        cout << temp->song << "  ";
        temp = head->next;
        while (temp != head)
        {
            cout << temp->song << "  ";
            temp = temp->next;
        }
        cout << temp->song << endl;
    }

    void start()
    {
        if (head == NULL)
        {
            cout << "Emptyy Playlist!!!!!!" << endl;
            return;
        }
        current = head;
        cout << "Playing: " << current->song << endl;
    }
    void nextSong()
    {
        if (current == NULL)
        {
            cout << "Playlist is Emptyyy!" << endl;
            return;
        }
        current = current->next;
        cout << "Now playing: " << current->song << endl;
    }
};

int main()
{
    Playlist p;

    p.addSong("Aaoge Jab Tum");
    p.addSong("Sajni");
    p.addSong("Faasle");
    p.addSong("Tu Jaane na");

    cout << "Playlist: " << endl;
    p.display();

    cout << endl;
    p.start();
    p.nextSong();
    p.nextSong();
    p.nextSong();
    p.nextSong();

    return 0;
}
