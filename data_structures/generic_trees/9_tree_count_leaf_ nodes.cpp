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


int countNodes(TreeNode<int>* root)
{    
    if(root==NULL)
    {  
        return 0;
    }

    int nodeCount = 1;
    for(int i=0; i < root->children.size(); i++)
    {
        nodeCount += countNodes(root->children[i]);
    }
    return nodeCount;
}

int height(TreeNode<int>* root)
{
   if(root==NULL)
   {  
      return 0;
   }

   int maxHeight = 0;
   for(int i=0;i<root->children.size();i++)
   {
     maxHeight = max(maxHeight, height(root->children[i]));
   }
   return maxHeight + 1;
}

void printAtLevelK(TreeNode<int>* root, int k)
{
    if(root==NULL)
    {   
        return;
    }

    if(k==0)
    {
       cout << root->data << endl;
       return;
    }

    for(int i=0; i < root->children.size(); i++)
    {
       printAtLevelK(root->children[i], k-1);
    }
}

int countLeafNodes(TreeNode<int>* root)
{
    if(root==NULL)
    {
        return 0; // edge case
    }

    // there is only one leaf node if the root node
    // has no children.
    if(root->children.size()==0)
    {
        return 1;
    }

    // for each child call countLeafNodes again. Similar
    // to previous techniques, recursion goes all the way to the
    // end of the tree until the leaf nodes where 1 is returned.
    // So for each leaf node 1 is added to the "ans".
    int ans = 0;
    for(int i=0; i < root->children.size(); i++)
    {
        ans +=  countLeafNodes(root->children[i]);
    }
    return ans;
}

// same implementation as above except passing an answer
// variable by reference rather than copying it into each
// recursive function call.
void countLeafNodesOtherWay(TreeNode<int>* root, int &ans)
{
    if(root==NULL)
    {
        return; // edge case
    }
    if(root->children.size()==0)
    {
        ans++;
        return;
    }
    for(int i=0; i < root->children.size(); i++)
    {
        countLeafNodesOtherWay(root->children[i], ans);
    }
}

// Similar to original way but instead of decrementing the
// level k variable to zero to find the leaf nodes and print them,
// we increase a levelCount counter from zero until we reach the
// level specified. We print the nodes each time we reach that level in
// a particular sub tree.
void printAtLevelKOtherWay(TreeNode<int>* root, int k,int levelCount=0)
{
    if(root==NULL)
    {
        return ;
    }
    if(k==levelCount)
    {
        cout << root->data << endl;
        return;
    }
    for(int i=0; i < root->children.size();i++)
    {
        printAtLevelKOtherWay(root->children[i], k, levelCount+1);
    }
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


  // Counting the leaf nodes in the two different
  // ways:

  cout << countLeafNodes(root) << endl; // 4
  
  int leafNodes = 0;
  countLeafNodesOtherWay(root, leafNodes);
  cout << leafNodes; // 4

  // alternative way for printing nodes at level k.
  // gives expected result.
  printAtLevelKOtherWay(root, 0); // 1
  printAtLevelKOtherWay(root, 1); // 2,3,4
  printAtLevelKOtherWay(root, 2); // 5,6,7,8
  

  return 0;
}
