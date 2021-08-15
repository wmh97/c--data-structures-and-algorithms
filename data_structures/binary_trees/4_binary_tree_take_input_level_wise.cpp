#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class BTNode
{
public:
    
    T data;
    BTNode* left;
    BTNode* right;
    
    BTNode(T data)
    {
      this->data = data;
      left = NULL;
      right = NULL;
    }

    ~BTNode()
    {
      delete left;
      delete right;
    }
};


void printTreeRecursive(BTNode<int>* root){

   if(root==NULL)
   {
      return;
   }
   cout << root->data << ": ";

   if(root->left != NULL)
   {
      cout << "L" << root->left->data;
   }
   if(root->right != NULL)
   {
      cout << "R" << root->right->data;
   }

   cout<<endl;
   printTreeRecursive(root->left);
   printTreeRecursive(root->right);
}


BTNode<int>* takeInputRecursive()
{
     int rootData;
     cout << "Enter data" << endl;
     cin >> rootData;

     if(rootData == -1)
     {
        return NULL;
     }

     BTNode<int>* root = new BTNode<int>(rootData);

     BTNode<int>* leftChild = takeInputRecursive();
     BTNode<int>* rightChild = takeInputRecursive();

     root->left = leftChild;
     root->right = rightChild;

     return root;
}

// Remember for Binary Tree we have only two children per
// root node.
// RETURNS the root.
//
// Steps:
// 1) Create child node
// 2) Push to queue
// 3) Connect to root
BTNode<int>* takeInputLevelWise()
{
    // Take user input for root data.
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;

    // make new root node with the data input by the
    // user and push it to a new queue.
    BTNode<int>* root = new BTNode<int>(rootData);
    queue<BTNode<int>*> q;
    q.push(root);

    // keep looping until the queue is empty.
    while(!q.empty())
    {
        // get the front of the queue into a variable and then
        // remove it from the queue.
        BTNode<int>* frontOfQueue = q.front();
        q.pop();

        // Get user input for the left child of the root node,
        // make a new node for it and push it to the queue.
        // (-1 if there is no left child)
        cout << "Enter left child of " << frontOfQueue->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if(leftChildData != -1)
        {
           BTNode<int>* child = new BTNode<int>(leftChildData);
           q.push(child);
           frontOfQueue->left = child;
        }

        // Same as above but for right child.
        cout << "Enter right child of " << frontOfQueue->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if(rightChildData != -1)
        {
           BTNode<int>* child = new BTNode<int>(rightChildData);
           q.push(child);
           frontOfQueue->right = child;
        }
    }

    return root;
}



int main()
{

   // Enter root data
   // 1
   // Enter left child of 1
   // 2
   // Enter right child of 1
   // 3
   // Enter left child of 2
   // 4
   // Enter right child of 2
   // 5
   // Enter left child of 3
   // 6
   // Enter right child of 3
   // 7
   // Enter left child of 4
   // -1
   // Enter right child of 4
   // -1
   // Enter left child of 5
   // -1
   // Enter right child of 5
   // -1
   // Enter left child of 6
   // -1
   // Enter right child of 6
   // -1
   // Enter left child of 7
   // -1
   // Enter right child of 7
   // -1
   // 1: L2R3
   // 2: L4R5
   // 4:
   // 5:
   // 3: L6R7
   // 6:
   // 7:
//   BTNode<int>* root3 = takeInputLevelWise();
//   printTreeRecursive(root3);

  // OR we can give input in one go:
  // 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
  //
  // OUTPUT:
   // Enter root data
   // 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
   // Enter left child of 1
   // Enter right child of 1
   // Enter left child of 2
   // Enter right child of 2
   // Enter left child of 3
   // Enter right child of 3
   // Enter left child of 4
   // Enter right child of 4
   // Enter left child of 5
   // Enter right child of 5
   // Enter left child of 6
   // Enter right child of 6
   // Enter left child of 7
   // Enter right child of 7
   // 1: L2R3
   // 2: L4R5
   // 4:
   // 5:
   // 3: L6R7
   // 6:
   // 7:
  BTNode<int>* root4 = takeInputLevelWise();
  printTreeRecursive(root4);


  return 0;
}
