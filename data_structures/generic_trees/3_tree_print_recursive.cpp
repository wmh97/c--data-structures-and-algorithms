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
   // if there is no tree to print just return to avoid
   // runtime error or segmentation fault.
   // This is EDGE CASE, not a base case because in recursion,
   // a base case stops recursion. This does not stop recursion as
   // with this edge case there is no recursion taking place.
   if(root==NULL)
   {
      return ;
   }

   // print the root node and all its children in
   // a comma separated line.
   cout << root->data << ": ";
   for(int i=0; i < root->children.size(); i++)
   {
      cout << root->children[i]->data << " ,";
   }
   cout << endl;

   // for each child, call the function again thereby
   // printing it as 'root' of a the subtree and all of its
   // corresponding children.
   //
   // NOTE we know in recursion we need a base case - but here we
   // have not explicitly stated one. The leaf nodes act
   // as a base case as the size of their vector is zero so we will
   // not go inside the for loops and hence return for them.
   for(int i=0; i < root->children.size(); i++)
   {
      printTree(root->children[i]);
   }
}


int main()
{
  TreeNode<int>* root = new TreeNode<int>(1);
  TreeNode<int>* n1 = new TreeNode<int>(2);
  TreeNode<int>* n2 = new TreeNode<int>(3);
  
  root->children.push_back(n1);
  root->children.push_back(n2);
  
  // Printed tree:
  // We print in the format parent: children so it is clear
  // which nodes have children and which dont.
  // 1: 2 ,3 ,
  // 2:
  // 3:  
  printTree(root); // passing root to the print function.

  return 0;
}
