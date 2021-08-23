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

    return ( searchNode(root->left, key) || searchNode(root->right, key) );

}

int minValue(BTNode<int>* root)
{
    if(root==NULL)
    {
        return INT_MAX; 
    }

    int leftMin = minValue(root->left);
    int rightMin = minValue(root->right);

    return min(root->data, min(leftMin, rightMin));
}


void minValueOtherWay(BTNode<int>* root, int &ans){
    
    if(root==NULL)
    {
        return; 
    }
    
    ans = min(ans, root->data);

    minValueOtherWay(root->left, ans);
    minValueOtherWay(root->right, ans);
}

// finding max is the same as finding min. Just switch
// min comparisons to max comparisons and make sure we
// return INT_MIN instead of INT_MAX at the end of the tree.
int maxValue(BTNode<int>* root)
{
    if(root==NULL)
    {
        return INT_MIN; 
    }

    int leftMin = maxValue(root->left);
    int rightMin = maxValue(root->right);

    return max(root->data, max(leftMin, rightMin));
}
void maxValueOtherWay(BTNode<int>* root, int &ans){
    
    if(root==NULL)
    {
        return; 
    }
    
    ans = max(ans, root->data);

    maxValueOtherWay(root->left, ans);
    maxValueOtherWay(root->right, ans);
}


int countLeafNode(BTNode<int>* root)
{
    if(root==NULL)
    {
        return 0; // return 0 if the root itself is null as we are not looking at a node.
    }
    
    // return 1 when we get to the end - ie get to a leaf node.
    if(root->left==NULL && root->right==NULL)
    {
        return 1;
    }

    // recursive calls, adding up all the 1s from the left and right
    // together to give the number of leaf nodes.
    return countLeafNode(root->left) + countLeafNode(root->right);
}

// this method is passing an answer which will be incremented when
// a leaf node is found.
void countLeafNodeOtherWay(BTNode<int>* root,int &ans)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL && root->right==NULL)
    {
        ans++;
        ///return; optional
    }
    countLeafNodeOtherWay(root->left,ans);
    countLeafNodeOtherWay(root->right,ans);
}



int main()
{

  // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
  BTNode<int>* root = takeInputLevelWise();
  printTreeRecursive(root);

  // ----------MAX VAL----------------------

  cout << "MAX VAL: " << maxValue(root) << endl;
  
  int ans = INT_MIN;
  maxValueOtherWay(root, ans); //9 as expected
  cout << "MAX VAL OTH WAY: " << ans << endl; //9 again

  
  // ----------LEAF NODES-------------------

  cout << "LEAF NODES: " << countLeafNode(root) << endl;
  
  int leafans = 0;
  countLeafNodeOtherWay(root, leafans); //5 as expected
  cout << "LEAF NODES OTH WAY: " << leafans << endl; //5 again




  delete root;

  return 0;
}
