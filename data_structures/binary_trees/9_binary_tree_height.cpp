#include <iostream>
#include<math.h>

/// https://leetcode.com/problems/maximum-depth-of-binary-tree/
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
    int maxDepth(TreeNode* root) {
        
        // base case at leaf nodes. We keep calling
        // recursively until we get to this point and
        // then add up all the 1s for each of the nodes
        // we have encountered, through the return
        // statements in each recursive call up from
        // the bottom of the tree.

        if(root==NULL) return 0;
        
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        
        // return whichever is greater, the height of the left
        // subtree of the height of the right subtree. By the
        // Add 1 due to the root node.
        return std::max(left, right) + 1;
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

   std::cout << soln.maxDepth(root); // 3, as expected

}