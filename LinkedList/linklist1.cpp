#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};


class LinkedList {
private:
    Node* head;


    public:
    LinkedList() : head(nullptr) {}
     
    ~LinkedList() {
        Node* current = head;
        Node* next;

        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
    }

    
    void enquee(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
        } 
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    bool search(int key){
        Node *temp=head;
        while(temp != nullptr){
            if( temp->data == key){
                return true;
             }
             temp = temp -> next;
        }

        return false;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    void deletion(int key){
        if(!search(key)){
            cout<<"The element is not present in the linkedlist."<<endl;
        }
        else

        {   Node* temp = head;
             if (head == nullptr){
                return;
             }
            if(temp->data == key || temp->next == nullptr){
                head = head->next;
                delete temp;
            }
            else{
          
            while (temp->next->data != key)
            {      
                   temp = temp->next;
            }
            Node* dnode=temp->next;
            temp->next = temp->next->next;
            delete dnode;
            }
        }
        


    }

  
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
 
    LinkedList Queue;

    
    Queue.enquee(1);
    Queue.enquee(2);
    Queue.enquee(3);

    std::cout << "Queue: ";
    Queue.display();

     LinkedList stack;
       stack.push(1);
       stack.push(2);
       stack.push(3);
    std::cout << "Stack: ";
    stack.display();
    std::cout << stack.search(1);
    stack.deletion(1);
    std::cout << "After deletion Stack: ";
    stack.display();
    return 0;
}