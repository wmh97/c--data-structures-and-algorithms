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

    // T=O(n), S=O(n)
    int countNodes(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }

        // recursive calls keep executing until we reach
        // the base case where root is NULL. For each call 1 is added.
        return countNodes(root->left) + countNodes(root->right) + 1;
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

   Solution soln;

   std::cout << soln.countNodes(root); // 5

}