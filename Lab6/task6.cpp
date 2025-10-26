#include <iostream>
using namespace std;
class Order {
public:
    string itemName;
    int quantity;
};

class Queue {
    Order* o; 
    int front, rear;   
    int n;

public:
    Queue(int n):n(n) {
        o=new Order[n];
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == n-1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(string name, int qty) {
        if (isFull()) {  
            cout << "Queue Overflow"<<endl;
            return;
        }

        if (front == -1){
            front = 0;
        }
        rear++;
        o[rear].itemName = name;
        o[rear].quantity = qty;

        cout << "Order added: " << name << " (x" << qty << ")\n";
    }

    void dequeue() {
        if (isEmpty()) { 
            cout << "Queue Underflow! No orders to process.\n";
            return;
        }

        cout << "Processing order: " << o[front].itemName
             << " (x" << o[front].quantity << ")"<<endl;

        front++;
    }

    void display() {
        if (isEmpty()) {
            cout << "No processed orders to display.\n";
            return;
        }
        cout <<endl<<"Processed Orders in order received:"<<endl;
        for (int i = front; i <= rear; i++) {
            cout << i - front + 1 << ". " << o[i].itemName<< " (x" << o[i].quantity << ")\n";
        }
    }
};


int main() {
    Queue restaurant(3);  

    restaurant.enqueue("Burger", 2);
    restaurant.enqueue("Pizza", 1);
    restaurant.enqueue("Pasta", 3);
    restaurant.display();

    restaurant.dequeue();  
    restaurant.dequeue();  

    restaurant.display();  

    return 0;
}

