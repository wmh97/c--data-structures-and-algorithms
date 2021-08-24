#include <iostream>
#include <vector>
#include <queue>

/// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Definition for a binary tree node.
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
    
    std::vector<std::vector<int>> levelOrderTraversal(TreeNode* root)
    {
        std::vector<std::vector<int>> vectorOfLevels;
        if(root==NULL)
        {
            return vectorOfLevels;
        }
        std::vector<int> currentLevel;   
        std::queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            TreeNode* frontOfQueue = q.front();
            q.pop();
            if(frontOfQueue == NULL)
            {
                vectorOfLevels.push_back(currentLevel);
                currentLevel.clear();
                if(!q.empty())
                {
                    q.push(NULL);
                }
            }
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
        return vectorOfLevels;
    }



    TreeNode* buildTreeHelper(std::vector<int> inOrderArray, 
                              std::vector<int> preOrderArray, 
                              int inOrderArrayStartIndex, 
                              int inOrderArrayEndIndex, 
                              int preOrderArrayStartIndex, 
                              int preOrderArrayEndIndex)
    {
        if(inOrderArrayStartIndex > inOrderArrayEndIndex)
        {
            return NULL;
        }

        int rootData = preOrderArray[preOrderArrayStartIndex];

        int rootIndex = -1;
        for(int i=inOrderArrayStartIndex; i<=inOrderArrayEndIndex; i++)
        {
            if(inOrderArray[i] == rootData) 
            {
                rootIndex = i;
                break; 
            }
        }

        int leftInS = inOrderArrayStartIndex;
        int leftInE = rootIndex - 1;
        int leftPreS = preOrderArrayStartIndex + 1;
        int leftPreE = leftPreS + leftInE - leftInS;

        int rightInS = rootIndex + 1;
        int rightInE = inOrderArrayEndIndex;
        int rightPreS = leftPreE + 1;
        int rightPreE = preOrderArrayEndIndex;

        TreeNode* root = new TreeNode(rootData);

        root->left = buildTreeHelper(inOrderArray, preOrderArray, leftInS, leftInE, leftPreS, leftPreE);
        root->right = buildTreeHelper(inOrderArray, preOrderArray, rightInS, rightInE, rightPreS, rightPreE);

        return root;  
    }

    TreeNode* buildTree(std::vector<int>& preOrderArray, std::vector<int>& inOrderArray) 
    {
        int numberOfNodes = inOrderArray.size();
        return buildTreeHelper(inOrderArray, preOrderArray, 0, numberOfNodes-1, 0, numberOfNodes-1);
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////

    TreeNode* buildTreeHelperInAndPostOrder(std::vector<int> inOrderArray, 
                              std::vector<int> postOrderArray, 
                              int inOrderArrayStartIndex, 
                              int inOrderArrayEndIndex, 
                              int postOrderArrayStartIndex, 
                              int postOrderArrayEndIndex)
    {
        if(inOrderArrayStartIndex > inOrderArrayEndIndex)
        {
            return NULL;
        }

        int rootData = postOrderArray[postOrderArrayStartIndex];

        int rootIndex = -1;
        for(int i=inOrderArrayStartIndex; i<=inOrderArrayEndIndex; i++)
        {
            if(inOrderArray[i] == rootData) 
            {
                rootIndex = i;
                break; 
            }
        }

        // SAME AS ABOVE BUT JUST MAKING SURE TO CHANGE THESE 8
        // VALUES ACCORDING TO THE POSITIONS OF THE DATA IN POST
        // ORDER. Recursion then works in the same way.
        int leftInS = inOrderArrayStartIndex;
        int leftInE = rootIndex - 1;
        int leftPostS = postOrderArrayStartIndex;
        int leftPostE = leftPostS + leftInE - leftInS;

        int rightInS = rootIndex + 1;
        int rightInE = inOrderArrayEndIndex;
        int rightPostS = leftPostE + 1;
        int rightPostE = postOrderArrayEndIndex-1;

        TreeNode* root = new TreeNode(rootData);

        root->left = buildTreeHelperInAndPostOrder(inOrderArray, postOrderArray, leftInS, leftInE, leftPostS, leftPostE);
        root->right = buildTreeHelperInAndPostOrder(inOrderArray, postOrderArray, rightInS, rightInE, rightPostS, rightPostE);

        return root;  
    }

    TreeNode* buildTreePostAndInOrder(std::vector<int>& postOrderArray, std::vector<int>& inOrderArray) 
    {
        int numberOfNodes = inOrderArray.size();
        return buildTreeHelperInAndPostOrder(inOrderArray, postOrderArray, 0, numberOfNodes-1, 0, numberOfNodes-1);
    }
};

int main()
{
    //preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
    
    std::vector<int> inOrderArray = {9, 3, 15, 20, 7};
    std::vector<int> preOrderArray = {3, 9, 20, 15, 7};
    std::vector<int> postOrderArray = {9, 15, 7, 20, 3};

    Solution soln;
    TreeNode* root = soln.buildTree(preOrderArray, inOrderArray);
    TreeNode* root2 = soln.buildTreePostAndInOrder(postOrderArray, inOrderArray);

    // as expected the constructed tree can be put back into
    // inorder to give the same order we started with.
    std::vector<std::vector<int>> constructedTree = soln.levelOrderTraversal(root);
    std::vector<std::vector<int>> constructedTreePostIn = soln.levelOrderTraversal(root);

    // OUTPUT PRE/IN:
    // Level 1: 3
    // Level 2: 9 20
    // Level 3: 15 7
    // AS EXPECTED - SO TREE WAS CREATED CORRECTLY
    int levelCounter = 0;
    for (std::vector<int> vector : constructedTree)
    {
       levelCounter++;
       std::cout << "Level " << levelCounter << ": ";
       for(int i : vector)
       {
          std::cout << i << " ";
       }
       std::cout << std::endl;
    }
    std::cout << std::endl << "##############################" << std::endl;

    // OUTPUT POST/IN:
    // Level 1: 3
    // Level 2: 9 20
    // Level 3: 15 7
    levelCounter = 0;
    for (std::vector<int> vector : constructedTreePostIn)
    {
       levelCounter++;
       std::cout << "Level " << levelCounter << ": ";
       for(int i : vector)
       {
          std::cout << i << " ";
       }
       std::cout << std::endl;
    }

}
