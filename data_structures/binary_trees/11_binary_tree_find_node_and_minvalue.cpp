#include <iostream>
#include <queue>
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


BTNode<int>* takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;

    BTNode<int>* root = new BTNode<int>(rootData);
    queue<BTNode<int>*> q;
    q.push(root);

    while(!q.empty())
    {
        BTNode<int>* frontOfQueue = q.front();
        q.pop();

        cout << "Enter left child of " << frontOfQueue->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if(leftChildData != -1)
        {
           BTNode<int>* child = new BTNode<int>(leftChildData);
           q.push(child);
           frontOfQueue->left = child;
        }

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


bool searchNode(BTNode<int>* root, int key)
{
    if(root == NULL)
    {
        return false;
    }

    if(root->data == key)
    {
        return true;
    }

    // recursive calls to left and right subtrees.
    // we just need one of these to find the data and return
    // true which will then propogate up to the top and the
    // original function call will return true.
    return ( searchNode(root->left, key) || searchNode(root->right, key) );

}

// think about when it gets to end of tree - min value
// returns the smallest between the root and left and right
// data values (which can be directly compared as theyre at
// the end of the tree).
//
// Then the min value of this tree is returned which is used further
// up the tree as e.g. the left or right of another tree, and the
// same comparison is performed. And so on...
int minValue(BTNode<int>* root)
{
    // if we have no root/base case.
    if(root==NULL)
    {
        // when we get to the end we return +inf so this will
        // always be the the greater value in any of the below
        // comparisons.
        return INT_MAX; 
    }

    int leftMin = minValue(root->left);
    int rightMin = minValue(root->right);

    // return the smallest value betwee the
    // root, and the smallest value between left and
    // right subtrees.
    return min(root->data, min(leftMin, rightMin));
}

// other method is the same - except we pass in an answer
// variable by reference which gets updated each time it encounters
// a smaller value.
//
// Same principal with recursive calls to the left/right subtrees
// but this time we dont need to return as the ans variable
// will be always updated to the smallest value it has found.
void minValueOtherWay(BTNode<int>* root, int &ans){
    
    if(root==NULL)
    {
        // Simply return when root is null eg at end 
        // of tree as L/R is null when passed as root.
        return; 
    }
    
    ans = min(ans, root->data);

    // as ans gets sent down the left and right subtrees 
    // recursively it will be updated continuously with the smallest
    // value it finds in those trees.
    //
    // Then when we compare these values to root (above) and see
    // which one is less - the one that is less gets stored in ans.
    // So by the end ans will contain the smallest value.
    minValueOtherWay(root->left, ans);
    minValueOtherWay(root->right, ans);
}


int main()
{

  // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
  BTNode<int>* root = takeInputLevelWise();
  printTreeRecursive(root);

// Enter left child of 1
// Enter right child of 1
// ...
// ...
// 1: L2R3
// 2: L4R5
// 4:
// 5:
// 3: L6R7
// 6: L8R9
// 8:
// 9:
// 7:
// Found 8 in tree!
  if(searchNode(root, 8))
  {
      cout << "Found 8 in tree!" << endl; // 8 found
  }
  else
  {
      cout << "Not Found!" << endl;
  }

  if(searchNode(root, 11))
  {
      cout << "Found 11 in tree!" << endl;
  }
  else
  {
      cout << "Not Found!" << endl; // 11 not found
  }  


  cout << "MIN VALUE: " << minValue(root) << endl; // 1 as expected.
  cout << "MIN VALUE OTHER WAY: " << minValue(root) << endl; // 1 as expected


  delete root;

  return 0;
}
