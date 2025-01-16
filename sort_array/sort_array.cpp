// Given this single-linked list data structure class, implement a delete function that uses recursion to erase the whole data structure.

#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

class SingleLinkedList {
private:
    int size;

public:
    Node* head;
    SingleLinkedList() {
        head = nullptr;
        size = 0;

    }

    void insert(int value) {
        Node* newNode = new Node;
        newNode->value = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }


        size++;
    }

    // Function to print the contents of the list
    void print() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    void recursivePrint(Node* n) {
        if (n == nullptr) {
            cout << endl;
            return;
        }

        // Recursively call the function for the next node first
        recursivePrint(n->next);

        // Print the current node value after recursion
        cout << n->value << " ";
    }


    int getSize() {
        return size;
    }

    // Recursive function to delete the entire list
    void deleteList(Node* n) {
        if (n == nullptr) {
            return; // Base case: if the node is nullptr, stop recursion
        }

        // Recursively delete the next node first
        deleteList(n->next);

        // After the recursive call returns, delete the current node
        delete n;
    }

    // Public method to call the recursive deleteList function from the head
    void deleteList() {
        deleteList(head);
        head = nullptr; // After deletion, the list should be empty
        size = 0; // Reset size to 0
    }

};

int main() {
    SingleLinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.print(); // Output: 3 2 1
    list.recursivePrint(list.head);
    cout << "Size: " << list.getSize() << endl; // Output: Size: 3
    return 0;
}