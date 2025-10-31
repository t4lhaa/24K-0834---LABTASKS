#include <iostream>
#include <string>
using namespace std;

class TourPackage {
public:
    string name;
    TourPackage* left;
    TourPackage* right;

    TourPackage(string n) {
        name = n;
        left = NULL;
        right = NULL;
    }
};

class TourTree {
private:
    TourPackage* root;

    TourPackage* insertPackage(TourPackage* node, string name) {
        if (node == NULL) {
            node = new TourPackage(name);
            return node;
        }

        char choice;
        cout << "Add " << name << " to the (L)eft or (R)ight of " << node->name << ": ";
        cin >> choice;
        choice = toupper(choice);

        if (choice == 'L')
            node->left = insertPackage(node->left, name);
        else
            node->right = insertPackage(node->right, name);

        return node;
    }

    void displayTree(TourPackage* node, int level) {
        if (node == NULL)
            return;

        for (int i = 0; i < level; i++)
            cout << "   ";
        cout << "- " << node->name << endl;

        displayTree(node->left, level + 1);
        displayTree(node->right, level + 1);
    }

public:
    TourTree() {
        root = NULL;
    }

    void addPackage() {
        string name;
        cout << "\nEnter package name: ";
        cin.ignore();
        getline(cin, name);

        if (root == NULL)
            root = new TourPackage(name);
        else
            root = insertPackage(root, name);

        cout << "Package added successfully!\n";
    }

    void display() {
        if (root == NULL)
            cout << "No tour packages added yet.\n";
        else {
            cout << "\nTour Packages Hierarchy:\n";
            displayTree(root, 0);
        }
    }
};

int main() {
    TourTree tree;
    int choice;

    do {
        cout << "\n===== TOUR PACKAGE MANAGEMENT =====";
        cout << "\n1. Add Tour Package";
        cout << "\n2. Display Tour Hierarchy";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            tree.addPackage();
            break;
        case 2:
            tree.display();
            break;
        case 3:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}
