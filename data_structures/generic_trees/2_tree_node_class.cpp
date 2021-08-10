#include<iostream>
using namespace std;

template<typename T>
class TreeNode
{
   public:
       T data;
       vector<TreeNode<T>*> children; // vector of addresses of child nodes - 0th child, 1st child, etc
       TreeNode(T data)
       {
          this->data = data;
       }
};


int main()
{
  // making 3 nodes - one of which is a root
  TreeNode<int>* root = new TreeNode<int>(1);
  TreeNode<int>* n1 = new TreeNode<int>(2);
  TreeNode<int>* n2 = new TreeNode<int>(3);
  
  // setting the other two as the children of the root node.
  root->children.push_back(n1);
  root->children.push_back(n2);
  
  return 0;
}
