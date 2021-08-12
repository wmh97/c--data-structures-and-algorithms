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

       // Called when we use the delete keyword.
       // This is a recursive destructor.
       ~TreeNode()
       {
           // Simply delete the children.
           // After the destructor code has been executed
           // the root will be deleted so we don't need to
           // write that explicitly here.
           for(int i=0; i<children.size(); i++)
           {
               delete children[i];
           }
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
        return 0;
    }

    if(root->children.size()==0)
    {
        return 1;
    }

    int ans = 0;
    for(int i=0; i < root->children.size(); i++)
    {
        ans +=  countLeafNodes(root->children[i]);
    }
    return ans;
}

void countLeafNodesOtherWay(TreeNode<int>* root, int &ans)
{
    if(root==NULL)
    {
        return;
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


void preOrderTraversalPrint(TreeNode<int>* root)
{
   if(root==NULL)
   {
       return ;
   }

   cout << root->data << " ";
   for(int i=0; i < root->children.size(); i++)
   {
       preOrderTraversalPrint(root->children[i]);
   }
}


void postOrderTraversalPrint(TreeNode<int>* root)
{
   if(root==NULL)
   {
       return;
   }

   for(int i=0; i < root->children.size(); i++)
   {
       postOrderTraversalPrint(root->children[i]);
   }
   cout << root->data << " ";
}

// Since all of our nodes were assigned with the "new"
// keyword, and were hence created dynamically, we need
// to deallocate the memory, so we need to delete them.
//
// Note we are not worrying about freeing up any
// of the pointers that are asscocaited with the nodes.
// They will be deleted automatically as the scope is deleted?
void deleteTree(TreeNode<int>* root)
{
    if(root==NULL)
    {  
        return; // edge case
    }

    // recurse into each child and grandchild etc until
    // we get to the leafnode (acting as base case).
    for(int i=0; i < root->children.size(); i++)
    {
        deleteTree(root->children[i]);
    }

    // when we have no children (leaf node), we will skip
    // the above and delete the node.
    delete root;
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

  deleteTree(root);


  return 0;
}
