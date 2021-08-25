/// https://leetcode.com/problems/diameter-of-binary-tree/
#include <iostream>

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution 
{
public:
    
    int height(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }

        return 1 + std::max(height(root->left), height(root->right));
    }
    
    int diameterOfBinaryTree(TreeNode* root) 
    {
        if(root==NULL)
        {
            return 0;
        }
        int option1 = height(root->left) + height(root->right);
        int option2 = diameterOfBinaryTree(root->left);
        int option3 = diameterOfBinaryTree(root->right);
        
        return std::max(option1, std::max(option2, option3));
    }


    /////////////////////////////////////////////////////////////////////


    // We call recursion on left and right subtree so we are
    // going to each and every node.
    // We doing constant work at each node.
    // So T=Nk = O(N).
    // This is much better than the previous solution.
    std::pair<int, int> heightDiameter(TreeNode* root)
    {
        // BASE CASE: when root is null set height and diam to zero.
        if(root==NULL)
        {
            std::pair<int,int> p;
            p.first = 0;
            p.second = 0;
            return p;
        }
        
        // get the height and diameter of left and right subtrees
        // recursively.
        std::pair<int,int> leftAns = heightDiameter(root->left);
        std::pair<int,int> rightAns = heightDiameter(root->right);
        
        // storing variables of the heights and diameters calculated.
        int lh = leftAns.first;
        int ld = leftAns.second;
        int rh = rightAns.first;
        int rd = rightAns.second;
        
        // overall height is 1 height + maximum between left and right subtree heights.
        // overall diameter - max between, lh+rh, ld, and rd as we discussed
        // in the previous diameter calculation.        
        int height = 1 + std::max(lh, rh);
        int diameter = std::max(lh+rh, std::max(ld, rd));
        
        // return overall height and diameter.
        std::pair<int,int> p;
        p.first = height;
        p.second = diameter;
        return p;
    }
    
    int diameterOfBinaryTreeBetterWay(TreeNode* root) 
    {
        // kicks off recursion. This first call returns the height
        // and diameter of the whole tree.
        std::pair<int,int> p = heightDiameter(root);
        
        // returning the diameter value. Height was only necessary
        // to calculate in order to calculate the diameter.
        return p.second; 
    }    
};

int main()
{
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    TreeNode* root = new TreeNode(1);
    
    TreeNode* node2 = new TreeNode(2);
    root->left = node2;

    TreeNode* node3 = new TreeNode(3);
    root->right = node3;

    TreeNode* node4 = new TreeNode(4);
    node2->left = node4;

    TreeNode* node5 = new TreeNode(5);
    node2->right = node5;

    Solution soln;
    std::cout << "DIAM BETTER WAY: " << soln.diameterOfBinaryTreeBetterWay(root);  // 3
    
}