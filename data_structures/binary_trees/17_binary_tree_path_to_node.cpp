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
        return 0;
    }

    if(root->left==NULL && root->right==NULL)
    {
        return 1;
    }

    return countLeafNode(root->left) + countLeafNode(root->right);
}

void countLeafNodeOtherWay(BTNode<int>* root,int &ans)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL && root->right==NULL)
    {
        ans++;
    }
    countLeafNodeOtherWay(root->left,ans);
    countLeafNodeOtherWay(root->right,ans);
}


bool getPath(BTNode<int>* root, int destValue, vector<int> &pathTaken)
{
   // BASE CASE: return false at end of tree.
   if(root==NULL)
   {
      return false;
   }

   // add the current node we are on to the vector
   // of the path we have taken
   pathTaken.push_back(root->data);
   if(root->data == destValue)
   {
      // return true if we have found the destination
      // node
      return true;
   }

   // recursive calls to go down the left/right subtrees
   // adding the nodes to the path vector as we go.
   bool leftPath = getPath(root->left, destValue, pathTaken);
   bool rightPath = getPath(root->right, destValue, pathTaken);

   // return true if we find the destination node in either
   // the left or right subtree.
   if(leftPath || rightPath)
   {
      return true;
   }

   // if we do not find the destination in either the
   // left or the right subtree then we pop the current
   // root from the vector.
   pathTaken.pop_back();
   return false;

}

int main()
{

  // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
  BTNode<int>* root = takeInputLevelWise();

  // OUTPUT:
    // 1: L2R3
    // 2: L4R5
    // 4:
    // 5:
    // 3: L6R7
    // 6: L8R9
    // 8:
    // 9:
    // 7:
    // 1 3 6 9
  printTreeRecursive(root);
  vector<int> path;
  if(getPath(root, 9, path))
  {
      for (int i=0; i<path.size(); i++)
      {
          cout << path[i] << " ";
      }
  }
  else
  {
      cout << "No path found for value 9!";
  }

  return 0;
}
