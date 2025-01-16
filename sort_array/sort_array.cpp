//Implement the most basic sorting algorithm on a fixed array:
//go through the whole array, find the smallest element, copy into a new array.
//
//Find some strategy to mark or remove the copied element from the original, and do the loop again.You can assume that all the elements are greater than zero.
//
//You can also use recursion or use a different sorting strategy.

#include <iostream>
using namespace std;

const int arraySize = 10;

void mysort(int* unsorted, int*& sorted) {
    bool processed[arraySize] = { false };  // This array tracks whether elements are processed

    for (int i = 0; i < arraySize; i++) {
        int minIndex = -1;
        int minValue = 999999;  // A large number to find the minimum value

        // Find the smallest element in the unsorted array that hasn't been processed yet
        for (int j = 0; j < arraySize; j++) {
            if (!processed[j] && unsorted[j] < minValue) {
                minValue = unsorted[j];
                minIndex = j;
            }
        }

        // Copy the smallest element into the sorted array
        sorted[i] = minValue;

        // Mark this element as processed
        processed[minIndex] = true;
    }
}

void printArray(const int* a, int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int u[10]{ 0,8,1,2,4,5,5,9,20,15 };
    int* s = new int[10];

    printArray(u, arraySize);

    mysort(u, s);
    printArray(s, arraySize);

    delete[] s;
}



// Given this single-linked list data structure class, implement a delete function that uses recursion to erase the whole data structure.
/*
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
*/
