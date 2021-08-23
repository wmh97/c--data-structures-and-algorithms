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
    
    // go to the bottom most subtree and evaluate it
    // to true or false based on these conditions. Then 'cascade'
    // that result upwards to evaluate all subtrees up to the
    // root.
    //
    // NOTE: Looks at left and right side of centre line
    //       of tree simultaneously.
    //
    // T=O(n), S=O(n)
    bool helper(TreeNode *leftTree, TreeNode* rightTree)
    {
        // return false if either the left or right tree does
        // not exist beyond the current node, and the other one does.
        if(leftTree==NULL && rightTree!=NULL) return false;
        if(leftTree!=NULL && rightTree==NULL) return false;
        
        // return true if both the left and right tree do not
        // exist beyond the current node.
        if(leftTree==NULL && rightTree==NULL) return true;
        
        // return false if the values of the left and right
        // tree are not the same.
        //
        // This check goes last so that we are sure left and
        // right trees exist when we do this check (this will
        // avoid runtime errors).
        if(leftTree->val != rightTree->val) return false;
        
        // recursive call - returning true if both of these expressions
        // are true, ie left of left = right of right and 
        // right of left = left of right.
        return helper(leftTree->left, rightTree->right) &&
               helper(leftTree->right, rightTree->left);
    }
    
    bool isSymmetric(TreeNode* root) 
    {
        
        // base case where root is null - ie at
        // the end of the tree.
        if(root==NULL) return true;
        
        // start off recursion passing the left and the
        // right of the root node.
        return helper(root->left, root->right);
    
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

    //      1
    //     / \
    //    2   3
    //   / \
    //   4  5
    // IF ANY OF THE SUBTRESS returns false for being
    // not symmetric, that false will propogate upwards
    // through the recursive calls and mean the to level
    // will return false.
   std::cout << soln.isSymmetric(root); // 0

   TreeNode* root2 = new TreeNode(1);
   TreeNode* otherNode2 = new TreeNode(2);
   TreeNode* otherNode3 = new TreeNode(2);
   root->left = otherNode2;
   root->right = otherNode3;

   TreeNode* otherNode4 = new TreeNode(4);
   TreeNode* otherNode5 = new TreeNode(5);
   otherNode2->left = otherNode4;
   otherNode2->right = otherNode5;

   TreeNode* otherNode6 = new TreeNode(5);
   TreeNode* otherNode7 = new TreeNode(4);
   otherNode3->left = otherNode6;
   otherNode3->right = otherNode7;


    //      1
    //     / \
    //    2   2
    //   / \ / \
    //   4 5 5  4
    //
    // first recurses down to leaf nodes 4s and 5s here:
    //    2       2
    //   / \ vs  / \  
    //  4  5     5  4
    // 1) for leaf nodes - no children on both sides.
    // 2) return true and go up a level to 2.
    // 3) check left of left vs right of right (4 vs 4). Equal therefore true.
    // 4) check right of left vs left of right (5 vs 5). Equal so true.
    //
    // In a larger tree this would keep going up until
    // we get to the top of the tree where
    // leftTree = 2 and rightTree = 2 and we have verified
    // that all trees down are symmetric.
    // We can therefore say the whole tree is symmetric.
    //      1
    //     / \
    //    2   2
   std::cout << soln.isSymmetric(root2); // 1

}