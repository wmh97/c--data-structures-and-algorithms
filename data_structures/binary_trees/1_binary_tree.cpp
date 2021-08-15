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
      left = NULL;  // default left and right to NULL.
      right = NULL;
    }
    
    // recursive destructor. Use delete as we
    // use dynamic allocation.
    //
    // This will call delete on left then right, then
    // delete yourself. This will go down through the
    // whole tree recursively.
    ~BTNode()
    {
      delete left;
      delete right;
    }
};

int main()
{
 
  BTNode<int>* root = new BTNode<int>(1);
  BTNode<int>* n1 = new BTNode<int>(2);
  BTNode<int>* n2 = new BTNode<int>(3);
  
  root->left = n1;
  root->right = n2;
  
  delete root;

  return 0;
}
