#include <iostream>
#include <vector>
#include <queue>

/// https://leetcode.com/problems/binary-tree-preorder-traversal/
/// https://leetcode.com/problems/binary-tree-postorder-traversal/
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

    // recursive calls in the order root data, left, right.
    //
    // T=O(n), S=O(n)
    void preOrderTraversal(TreeNode* root, std::vector<int> &ans)
    {
        if(root==NULL) return; // base case - end of tree.
        
        ans.push_back(root->val);            // data
        preOrderTraversal(root->left, ans);   // left
        preOrderTraversal(root->right, ans);  // right
    } 
        
    std::vector<int> executePreOrderTraversal(TreeNode* root)
    {
        std::vector<int> ans;
        preOrderTraversal(root, ans);
        
        return ans;
    }

    // same as above except for the order left, right, root data.
    void postOrderTraversal(TreeNode* root, std::vector<int> &ans)
    {
        if(root==NULL) return; // base case
        
        postOrderTraversal(root->left,ans); // left
        postOrderTraversal(root->right,ans); // right
        ans.push_back(root->val);           // data
    }
    std::vector<int> executePostOrderTraversal(TreeNode* root)
    {
        std::vector<int> ans;
        postOrderTraversal(root, ans);
        
        return ans;
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

   // OUTPUT:
   //
   // Pre Order is top down - prints root then children
   // Post Order is bottom up - prints children then root.
   //
    // Pre Order: 
    // 12453
    // Post Order:
    // 45231

   std::cout << "Pre Order: " << std::endl;
   for(int i : soln.executePreOrderTraversal(root))
   {
       std::cout << i;
   }
   std::cout << std::endl;

   std::cout << "Post Order: " << std::endl;
   for(int i : soln.executePostOrderTraversal(root))
   {
       std::cout << i;
   }

}