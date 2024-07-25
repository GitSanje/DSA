#include<iostream>
#include<vector>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

struct Node
{
  int data;
   Node * left, * right;
   Node(int val): data(val), left(NULL),right(NULL) {}
};

class Solution{

    public:
    bool BSTUtil(Node* root, Node* min, Node* max){
        if(root == NULL){
            return true;
        }

        if(min != NULL && root->data < min->data)
            return false;
        if(max != NULL && root->data > max->data)
            return false;
        bool left = BSTUtil( root->left, min,  root);
        bool right = BSTUtil( root->right, root,  max);
        return left && right;

    }
    int height(Node*root){
        if(root == NULL)
           return 0;

        int leftheight = height(root->left);
        int rightheight = height(root->right);
        if( leftheight == -1 || rightheight == -1 || abs(leftheight-rightheight) > 1)
          return -1;
        return max( leftheight, rightheight) + 1;

    }

    bool isBalanced(Node * root){
        if(root == NULL)
           return true;
        
        if(height(root) == -1)
           return false;
        return true;
    }

    bool isBST(Node* root){
        return BSTUtil(root, NULL,NULL);
    }

     Node* utilBST(vector<int> &nums, int start, int end)
    {
       if( start > end){
           return NULL;
       }
       int mid = (start + end) / 2;
       
       Node * root = new Node( nums[mid]);
       root->left = utilBST(nums, start, mid-1);
       root->right = utilBST(nums, mid+1, end);
       
       return root;
    }
    
    Node* sortedArrayToBST(vector<int>& nums) {
        // Code here
        Node* root = utilBST(nums, 0, nums.size() -1 );
        
        return root;
        
        
    }

    Node* BuildTree( string str){
            
        if(str.length() == 0 || str[0] == 'N'){
            return NULL;
        }
        vector<string> vals;
        istringstream iss(str);
        for ( string str; iss >> str;)
                vals.push_back(str);

        
        Node* root = new Node(stoi(vals[0]));
        
        queue<Node*> queue;
        queue.push(root);
        int i =1;
        while ( !queue.empty() && i < vals.size())
        {
            
            Node* currNode = queue.front();
            queue.pop();
            
            if( vals[i] != "N"){

                currNode->left = new Node(stoi(vals[i]));
                queue.push(currNode->left);
            }
            i++;
            if( i >= vals.size())
               break;

            if(  vals[i] != "N"){

                currNode->right = new Node(stoi(vals[i]));
                queue.push(currNode->right);
            }
            i++;


        }
        
    return root;

    }
};


void inorder(Node*root, vector<int>&v){
    if(root == NULL) return;
    

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main()
{
     vector<int> arr;
    string input;
    cout << "Enter the string of sorted values to build the balance tree: ";
    getline(cin, input);

    stringstream ss(input);
    int number;
    while (ss >> number)
    {  
        arr.push_back(number);
        
    }
    
    Solution ob;
    Node* root =  ob.sortedArrayToBST(arr);
    vector<int> v;
    inorder(root, v);
    if(!ob.isBST(root) or v!= arr){
        cout << "false" << endl;
        return 0;
    }

    bool f = ob.isBalanced(root);
    if(f)
      cout << "true";
    else
      cout << "false";
    
    cout << "\n";

//     vector <int> res;
//     inorder(root, res);

//     cout << "Inorder traversal: ";
//     for (int val : res) {
//         cout << val << " ";
//     }
   
//    int h = ob.height(root);
//    cout << "Height of the tree: " << h << endl;



    
    return 0;
}
