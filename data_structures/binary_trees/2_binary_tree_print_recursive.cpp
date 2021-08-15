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
   
   // If the node root or child is empty
   // then return. This is the base case as it is
   // met during recursion.
   //
   // As usual we are using root->... so we need
   // to make this check fo root == NULL.
   if(root==NULL)
   {
      return;
   }

   // print the data in the form Parent: Position-Children  
   cout << root->data << ": ";
    
   // print child to the left of the root
   // print child to the right of the root.
   if(root->left != NULL)
   {
      cout << "L" << root->left->data;
   }
   if(root->right != NULL)
   {
      cout << "R" << root->right->data;
   }

   // new line for next root, and call recursion
   // on both left and right subtrees.
   cout<<endl;
   printTreeRecursive(root->left);
   printTreeRecursive(root->right);
}


int main()
{
 
  BTNode<int>* root = new BTNode<int>(1);
  BTNode<int>* n1 = new BTNode<int>(2);
  BTNode<int>* n2 = new BTNode<int>(3);
  
  root->left = n1;
  root->right = n2;

  // SO we print every node here, and for each node
  // next to it we print the nodes that are left and right
  // of it:
  // 1: L2R3
  // 2:
  // 3:  
  printTreeRecursive(root);

  return 0;
}
