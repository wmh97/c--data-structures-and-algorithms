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
    
    // Going through each node - for each node we are doing
    // const amount of work so  T=O(N)
    //
    // 
    int height(TreeNode* root)
    {
        // base case - end of the tree where root is null.
        if(root==NULL)
        {
            return 0;
        }

        // return 1 for each level, plus all the 1s returned for the levels
        // below.
        return 1 + std::max(height(root->left), height(root->right));
    }
    
    // Going to each node and doing const amount of work AND
    // calling height() for each node which is const amount of work.
    // 
    // We then call diameter functions of the tree
    //
    // 1) If the tree is balanced (same no of nodes on L and R), we get:
    // T(n) = k(n-1) +    k    +   2T(n/2)
    //        [height] [basecase]  [call for L,R subtrees]
    // This is the same as the merge sort time complexity.
    // Time complexity is T=O(NlogN).
    //
    // 2) if we have all nodes to one side (ie all root->left) nodes
    //    all the way down, then
    // T(n) = k(N-1)   +  T(n-1)
    //        [height]    [diameter (no 2 factor because there is only one subtree side)]
    // So T(n)= NK + T(n-1)
    //    T=O(N^2) because we making n-1 calls for each node n, which
    //             is the same as the bubble sort case.
    //
    // Note height of the tree H=logN
    // so we have for the two cases:
    // T = NH (1) and T=N^2=NN=NH (2).
    //
    // SO OVERALL T=O(NH)
    //
    // TO IMPROVE this time complexity we want to make the call
    // to height and diameter at the same time so it is just one
    // call per node.
    // (See comments below).
    int diameterOfBinaryTree(TreeNode* root) 
    {
        // base case - end of the tree where root is null
        if(root==NULL)
        {
            return 0;
        }

        // height of left + height or right.
        int option1 = height(root->left) + height(root->right);
        
        // diameter of L/R subtrees:
        // TIME COMPLEXITY PROBLEM: We are repeating work here
        // as within these calls we duplicate the calls to height that
        // we made above.
        // As we go down the tree there will be more calls
        // for each node further down as the repeated work from
        // recursion overlaps more and more.
        int option2 = diameterOfBinaryTree(root->left);
        int option3 = diameterOfBinaryTree(root->right);
        
        return std::max(option1, std::max(option2, option3));
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
    std::cout << "DIAM: " << soln.diameterOfBinaryTree(root);  // 3
    
}