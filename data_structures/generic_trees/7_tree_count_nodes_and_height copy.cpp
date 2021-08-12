#include<iostream>
#include<vector>
#include<queue>
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


TreeNode<int>* takeInput()
{
   int rootData;
   cout << "Enter data"<<endl;
   cin >> rootData;
   TreeNode<int>* root = new TreeNode<int>(rootData);

   int numberOfChildren;
   cout << "Enter num of children of " << rootData << endl;
   cin >> numberOfChildren;

   for(int i=1; i <= numberOfChildren; i++)
   {
     TreeNode<int>* child = takeInput();
     
     root->children.push_back(child);
   }
   return root;
}

TreeNode<int>* takeInputLevelWise()
{

    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    
    queue<TreeNode<int>*> q;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    q.push(root);

    while(!q.empty())
    {
        TreeNode<int>* frontOfQueue = q.front();
        q.pop();

        cout << "Enter no of children of " << frontOfQueue->data << endl;
        int numberOfChildren;
        cin >> numberOfChildren;

        for(int i=1; i<=numberOfChildren; i++)
        {
            int childData;
            cout << "Enter " << i << " th child of " << frontOfQueue->data << endl;
            cin >> childData;

            TreeNode<int>* child = new TreeNode<int>(childData);
            q.push(child);

            frontOfQueue->children.push_back(child);
        }
    }
    return root;
}


void printLevelWise(TreeNode<int>* root)
{
    // add root to queue   
    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty())
    {

        TreeNode<int>* frontOfQueue = q.front();
        q.pop();
        cout << frontOfQueue->data << ": ";

        for(int i=0; i<frontOfQueue->children.size(); i++)
        {
            TreeNode<int>* currentChild = frontOfQueue->children[i];
            cout << currentChild->data << ", ";
            q.push(currentChild);
        }
        cout << endl;
    }
}


int countNodes(TreeNode<int>* root){
    
    // if tree doesn't exist
    if(root==NULL)
    {  
        return 0; // edge case because here there would be no recursion.
    }

    int nodeCount = 1;
    for(int i=0; i < root->children.size(); i++)
    {
        // nodeCount += (nodeCount1 + nodeCount2 + ... + nodeCountLeaf) 
        // down to leaf nodes acting as base case
        nodeCount += countNodes(root->children[i]);
    }
    return nodeCount;
}

// Looks at children down to leaf node. The leaf nodes
// returns 0+1 as there are no children.
//
// Then e.g. if we have no other children the next level
// up we add 1 again to get 2.
//
// Now if that next level up has another child which is a
// leaf node we check the height of that other child which
// is 1. We compare 2vs1 so take 2 and add 1 to it to make 3,
// and move another level up.
//
// And so on until we are at the root.
int height(TreeNode<int>* root)
{
   if(root==NULL)
   {  
      return 0; // edge case
   }

   // go to each child and find its height. We then take the maximum
   // height of the current child we are on and all its child heights.
   int maxHeight = 0;
   for(int i=0;i<root->children.size();i++)
   {
     // if the child height is greater than the maximum height then
     // we update the maximum height.
     maxHeight = max(maxHeight, height(root->children[i]));
   }
   return maxHeight + 1;
}


int main()
{
  
  TreeNode<int>* root = new TreeNode<int>(1);
  TreeNode<int>* n1 = new TreeNode<int>(2);
  TreeNode<int>* n2 = new TreeNode<int>(3);
  TreeNode<int>* n3 = new TreeNode<int>(4);
  TreeNode<int>* n4 = new TreeNode<int>(5);
  TreeNode<int>* n5 = new TreeNode<int>(6);
  TreeNode<int>* n6 = new TreeNode<int>(7);
  TreeNode<int>* n7 = new TreeNode<int>(8);

  root->children.push_back(n1);
  root->children.push_back(n2);
  root->children.push_back(n3);

  n1->children.push_back(n4);
  n1->children.push_back(n5);

  n2->children.push_back(n6);

  n3->children.push_back(n7);

  cout << countNodes(root) << endl; // 8 as expected.
  cout << height(root); // 3 as expected.
  
  return 0;
}
