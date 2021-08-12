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

// Steps:
// 1. Create the node
// 2. Push the node to queue
// 3. Make the connection between node and children
// ... repeat per level.
TreeNode<int>* takeInputLevelWise()
{
    
    // Enter the data you want to store in the root node
    // and then create the node with that data in it and push
    // it to a queue.
    
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    
    queue<TreeNode<int>*> q;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    q.push(root);

    // repeat steps until queue is empty - ie until all input
    // has been given down to leaf nodes.
    while(!q.empty())
    {
        // get the current root node from the front of the queue.
        TreeNode<int>* frontOfQueue = q.front();
        q.pop(); // remove the current node from the queue once we've got it.

        // user input number of children
        cout << "Enter no of children of " << frontOfQueue->data << endl;
        int numberOfChildren;
        cin >> numberOfChildren;

        // for each child node, user input the data to store in it and
        // make a new node for it with that data.
        // Then push that node to the back of the queue.
        for(int i=1; i<=numberOfChildren; i++)
        {
            int childData;
            cout << "Enter " << i << " th child of " << frontOfQueue->data << endl;
            cin >> childData;

            TreeNode<int>* child = new TreeNode<int>(childData);
            q.push(child);

            // connecting the nodes. Adding the children to the children vector
            // for the current root node.
            frontOfQueue->children.push_back(child);
        }
    }
    
    // after all input has been completed return the root node.
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


  // BETTER WAY TO TAKE INPUT. Takes input on a per
  // level basis as seen below. 
   // Enter root data
   // 1
   // Enter no of children of 1
   // 3
   // Enter 1 th child of 1
   // 2
   // Enter 2 th child of 1
   // 3
   // Enter 3 th child of 1
   // 4
   // Enter no of children of 2
   // 2
   // Enter 1 th child of 2
   // 5
   // Enter 2 th child of 2
   // 6
   // Enter no of children of 3
   // 1
   // Enter 1 th child of 3
   // 7
   // Enter no of children of 4
   // 1
   // Enter 1 th child of 4
   // 8
   // Enter no of children of 5
   // 0
   // Enter no of children of 6
   // 0
   // Enter no of children of 7
   // 0
   // Enter no of children of 8
   // 0
   // 1: 2 ,3 ,4 ,
   // 2: 5 ,6 ,
   // 5:
   // 6:
   // 3: 7 ,
   // 7:
   // 4: 8 ,
   // 8:
  TreeNode<int>* root3 = takeInputLevelWise();
  printTree(root3);

  return 0;
}
