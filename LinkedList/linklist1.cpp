#include <iostream>

// Define a Node structure for the linked list
struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

// Define a LinkedList class
class LinkedList {
private:
    Node* head;


    public:
    // Constructor
    LinkedList() : head(nullptr) {}
     // Destructor to free memory when the list is destroyed
    ~LinkedList() {
        Node* current = head;
        Node* next;

        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
    }

    // Function to add a new node to the end of the list
    void append(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Function to display the elements of the list
    void display() {
        Node* current = head;

        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }

        std::cout << std::endl;
    }
};

int main() {
    // Create a linked list
    LinkedList myList;

    // Append some elements to the list
    myList.append(1);
    myList.append(2);
    myList.append(3);

    // Display the elements of the list
    std::cout << "Linked List: ";
    myList.display();

    return 0;
}