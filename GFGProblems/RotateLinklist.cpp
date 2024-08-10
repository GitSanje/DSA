//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

// Leetcode solution

// if(head==nullptr || k==0){
//             return head;
//         }
//         ListNode* temp = head;
//         int n =1;
//         while(temp->next != nullptr){
//             n++;
//             temp = temp->next;
//         }
//         k = k%n;
//         if(k==0){
//             return head;
//         }
//         k= n-k;
//         ListNode* newTail=head;
//         while(k>1){
//             newTail = newTail->next;
//             k--;
//         }
//         ListNode* newHead = newTail->next;
//         newTail->next = nullptr;
//         temp->next = head;
//         return newHead;


class Solution {
  public:
    // Function to rotate a linked list.
    Node* rotate(Node* head, int k) {
    if (!head || !head->next || k == 0) return head;

    // Step 1: Find the length of the list
    Node* current = head;
    int length = 1;  // Start counting from the head

    while (current->next != NULL) {
        current = current->next;
        length++;
    }

    // Step 2: Make the list circular
    current->next = head;

    // Step 3: Compute the actual number of rotations needed
    k = k % length;
    int stepsToNewHead = length - k;

    // Step 4: Find the new head and the new tail
    Node* newTail = head;
    for (int i = 1; i < stepsToNewHead; i++) {
        newTail = newTail->next;
    }

    Node* newHead = newTail->next;

    // Step 5: Break the circular list
    newTail->next = NULL;

    return newHead;
}

    
    
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        Node* head = nullptr;

        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.rotate(head, k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends