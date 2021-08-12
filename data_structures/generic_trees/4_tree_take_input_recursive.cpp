#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class TreeNode
{
   public:
       T data;
       vector<TreeNode<T>*> children;
       TreeNode(T data)
       {
          this->data = data;
       }
};


void printTree(TreeNode<int>* root)
{
   if(root==NULL)
   {
      return ;
   }

   cout << root->data << ": ";
   for(int i=0; i < root->children.size(); i++)
   {
      cout << root->children[i]->data << " ,";
   }
   cout << endl;

   for(int i=0; i < root->children.size(); i++)
   {
      printTree(root->children[i]);
   }
}

// Takes input for the root node, and its children.
// Then for each child, use that as the root node and take
// input for its children. And so on, recursively. 
//
// Each time a child node is entered (leaf node as base case),
// it is added to the vector of the children for its associated
// root/parent node.
TreeNode<int>* takeInput()
{
   // construct the root node.
   int rootData;
   cout << "Enter data"<<endl;
   cin >> rootData;
   TreeNode<int>* root = new TreeNode<int>(rootData);
   
   
   // user inputs how many children the root node will have.
   int numberOfChildren;
   cout << "Enter num of children of " << rootData << endl;
   cin >> numberOfChildren;

   for(int i=1; i <= numberOfChildren; i++)
   {
     // call recursion on each child to use that child
     // as a root and take input for that.
     // Remember that takeInput() returns the root node.
     TreeNode<int>* child = takeInput();
     
     // Add the child to the parent node.
     root->children.push_back(child);
   }
   return root;
}


int main()
{
  TreeNode<int>* root = new TreeNode<int>(1);
  TreeNode<int>* n1 = new TreeNode<int>(2);
  TreeNode<int>* n2 = new TreeNode<int>(3);
  
  root->children.push_back(n1);
  root->children.push_back(n2);

  printTree(root);

  // BAD WAY TO GIVE INPUT.
  // Problem: In order to give input the user needs
  //          to know recursion to track which data we
  //          need to know. Again there is no base case
  //          so the leaf node is acting as the base case.  
    // Enter data
    // 1
    // Enter num of children of 1
    // 2
    // Enter data
    // 2
    // Enter num of children of 2
    // 0
    // Enter data
    // 3
    // Enter num of children of 3
    // 0
    // 1: 2 ,3 ,
    // 2:
    // 3:
  TreeNode<int>* root2 = takeInput();
  printTree(root2);

  return 0;
}
