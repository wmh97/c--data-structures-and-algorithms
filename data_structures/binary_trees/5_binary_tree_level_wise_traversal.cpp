#include <iostream>
#include <vector>
#include <queue>

/// https://leetcode.com/problems/binary-tree-level-order-traversal/
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution 
{
public:
    // T=O(n) as we are basically going to each node in the
    // tree and printing it.
    // S=O(n) as we are creating a queue.
    std::vector<std::vector<int>> levelOrderTraversal(TreeNode* root)
    {
        
        // creating the overall vector to contain the individual
        // level vectors. Returning it empty if the tree doesnt exist.
        std::vector<std::vector<int>> vectorOfLevels;
        if(root==NULL)
        {
            return vectorOfLevels;
        }
        

        // vector to store the nodes in the current level.
        std::vector<int> currentLevel;   
        
        // Making a queue.
        //
        // Pushing the root node AND pushing NULL to the queue.
        std::queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        // Keep going until queue is empty.
        while(!q.empty())
        {
            
            // Get front of queue and then pop it from
            // queue.
            TreeNode* frontOfQueue = q.front();
            q.pop();


            // Before we entered this while loop we pushed NULL
            // to the queue after the root node (as a king of
            // level separator).
            //
            // When we reach NULL we have got to the end of the
            // first level. If the queue is empty at this point
            // that means the root node had no children so we just
            // push the current level (which is just the root node)
            // to the overall vector of levels, and we clear the
            // current level.
            //
            // If, however, the queue is not empty it means we have
            // added the roots children to the queue. We then push
            // NULL to the queue as a level separator again.
            if(frontOfQueue == NULL)
            {
                vectorOfLevels.push_back(currentLevel);
                currentLevel.clear();
                if(!q.empty())
                {
                    q.push(NULL);
                }
            }

            // if the front of our queue is a valid node,
            // add the value it contains to the "currentLevel"
            // vector. 
            //
            // THEN push the left and right children of the
            // node we are looking at to the queue to be reached
            // later (also checking they exist to do this).
            else
            {
                currentLevel.push_back(frontOfQueue->val);
                if(frontOfQueue->left)
                {
                    q.push(frontOfQueue->left);
                }
                if(frontOfQueue->right)
                {
                    q.push(frontOfQueue->right);
                }
            }
        }

        // Once the queue has been cleared we have successfully
        // built up our tree in vectors, so return it.
        return vectorOfLevels;
    }
};

int main()
{
   
   TreeNode* root = new TreeNode(1);
   TreeNode* node2 = new TreeNode(2);
   TreeNode* node3 = new TreeNode(3);
   root->left = node2;
   root->right = node3;

   TreeNode* node4 = new TreeNode(4);
   TreeNode* node5 = new TreeNode(5);
   node2->left = node4;
   node2->right = node5;
   
   // Storing the tree in levels in a vector of vectors.
   // Each vector within the overall vector is a level of the tree.
   Solution soln;
   std::vector<std::vector<int>> traversedTree = soln.levelOrderTraversal(root);

   // OUTPUT:
   // Level 1: 1
   // Level 2: 23
   // Level 3: 45
   int levelCounter = 0;
   for (std::vector<int> vector : traversedTree)
   {
      levelCounter++;
      std::cout << "Level " << levelCounter << ": ";
      for(int i : vector)
      {
         std::cout << i;
      }
      std::cout << std::endl;
   }
}