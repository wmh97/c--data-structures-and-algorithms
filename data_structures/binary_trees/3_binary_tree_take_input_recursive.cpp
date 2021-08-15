#include<iostream>
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

// BAD WAY TO GIVE INPUT.
BTNode<int>* takeInputRecursive()
{
     /*
        This is a complicated way to take input as the user
        needs to know the order in which recursion will be
        called for input to the left and right children.

        (This will get input for all the left children of the
        tree first, until we enter -1 for left and righ children. 
        Then it will get the right child for all those children back 
        to the top. THEN it will take input for the right child at 
        the top and the recursive left children until we enter -1 as 
        before, and then the right children up tothe top.)
     */

     // user input the data.
     int rootData;
     cout << "Enter data" << endl;
     cin >> rootData;

     // exit a recursive call if we input -1 above.
     // (this would mean our tree cant hold -1).
     if(rootData == -1)
     {
        return NULL; // BASE CASE
     }

     // make a new root with the data we have inputted.
     BTNode<int>* root = new BTNode<int>(rootData);
     
     // call recursion for the left child and the right
     // child to take input for them too.
     BTNode<int>* leftChild = takeInputRecursive();
     BTNode<int>* rightChild = takeInputRecursive();

     // store the left and right child in the left and right
     // pointers of the root.
     root->left = leftChild;
     root->right = rightChild;

     return root;
}


int main()
{
   // Enter data
   // 1   
   // Enter data
   // 2
   // Enter data
   // 4
   // Enter data
   // -1
   // Enter data
   // -1
   // Enter data
   // 5
   // Enter data
   // 6
   // Enter data
   // -1
   // Enter data
   // -1
   // Enter data
   // 7
   // Enter data
   // -1
   // Enter data
   // -1
   // Enter data
   // 3
   // Enter data
   // 8
   // Enter data
   // -1
   // Enter data
   // -1
   // Enter data
   // -1
   // 1: L2R3
   // 2: L4R5
   // 4:
   // 5: L6R7
   // 6:
   // 7:
   // 3: L8
   // 8:
  BTNode<int>* root2 = takeInputRecursive();
  printTreeRecursive(root2);

  return 0;
}
