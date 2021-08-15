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

    void inOrderTraversal(TreeNode* root, std::vector<int> &ans)
    {
        // base case
        if(root==NULL) return;
        
        // order of left, root data, right.
        // calling recursively so this order is called
        // on all subtrees in the binary tree.
        inOrderTraversal(root->left,ans);   // left
        ans.push_back(root->val);           // data
        inOrderTraversal(root->right,ans);  // right
    }
    
    // execute the above by prividing a vector
    // that will store the data of the tree.
    std::vector<int> executeInOrderTraversal(TreeNode* root)
    {
        std::vector<int> tree;
        inOrderTraversal(root, tree);
        return tree;
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

   // printing the tree out "inOrder".
   // 42513
   for(int i : soln.executeInOrderTraversal(root))
   {
       std::cout << i;
   }



}