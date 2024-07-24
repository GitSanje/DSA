#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <string>
using namespace std;


struct Node
{
    int data;
    Node* left;
    Node* right;

    Node( int val){
        data= val;
        left = right = nullptr;
    }
};

class CheckBST
{
private:
    /* data */
public:
   bool isBSTUtil(Node* node, Node* left, Node* right){
       
       if(node == NULL)
        return true;
       

       if( left != NULL && node->data <= left->data)
           return false;
       if( right != NULL && node->data >= right->data)
          return false;

      return isBSTUtil(node->left, left, node) && isBSTUtil(node->right, node, right);

   }

   bool isBST(Node* root){

     return isBSTUtil(root, NULL, NULL);
   }
    
};




Node* BuildTree(string str){
    if (str.length() == 0 || str[0] == 'N')
        return NULL;
    
   
   // creating vector of strings from input
   //string after splitting by space
    vector<string> ip;
    istringstream iss(str);
    
    for (string str; iss >> str;)
        ip.push_back(str);
    
    Node* root = new Node(stoi(ip[0]));
    
    queue<Node*> queue;
    queue.push(root);

    int i =1;

    while (!queue.empty() && i < ip.size())
    {
     Node* currNode = queue.front();
     queue.pop();

     string currVal = ip[i];

     if( currVal != "N"){
        currNode->left = new Node(stoi(currVal));
        queue.push(currNode->left);
        
     }
      i++;

      if( i >= ip.size())
         break;

      currVal = ip[i];

        if( currVal != "N"){
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
            
        }
       i++;



    }
    
    return root;

             

}

void inorder(Node* root, vector<int>&v){
    if (root == NULL)
       return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main(){

    int t;
    string tc;
    getline(cin, tc);
    t= stoi(tc);
    
    
    while(t--){
        string s;
        getline(cin, s);
        Node *root = BuildTree(s);
        vector<int> values;
        inorder(root, values);
        
        // int n = sizeof(values) / sizeof(values[0]);
        // for (int i=0; i<n; i++)
        //     cout << values[i] << " ";
        // cout << endl;

         for (int val : values)
         
            cout << val << " ";
        cout << endl;

        CheckBST check;
        if( check.isBST(root))
           cout << "true\n";
        else
          cout << "false\n";
        
    }
    return 0;
}
