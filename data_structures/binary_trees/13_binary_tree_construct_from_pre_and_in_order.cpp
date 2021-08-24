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
        
        // *** THIS IS RECURSION SO WE NEED A BASE CASE ***
        // *** BASE CASE FOR EMPTY ARRAY                *** also valid to check for preOrder array instead.
        if(inOrderArrayStartIndex > inOrderArrayEndIndex)
        {
            return NULL;
        }
        
        // finding the root data for the whole tree which is the start index of the
        // pre order array.
        int rootData = preOrderArray[preOrderArrayStartIndex];

        // finding the index root data in the in order array. We iterate over the in order
        // array and then assign the root index as the position at which we first find
        // the root data value.
        int rootIndex = -1;
        for(int i=inOrderArrayStartIndex; i<=inOrderArrayEndIndex; i++)
        {
            if(inOrderArray[i] == rootData) // assumes no duplicate values in tree ???
            {
                rootIndex = i;
                break; // after found, exit for loop.
            }
        }

        // Then we set the bounds for the subtrees:

        // LEFT SUBTREE:
        //
        // inOrder(L,D,R):
        // start index is the start of the inorder array.
        // end index is one before the root data.
        //
        // preOrder(D,L,R):
        // start index is one after the start index of the preorder array.
        // end index is calculated from equating number of elements in inorder and preorder array
        // and using the 3 values above.
        int leftInS = inOrderArrayStartIndex;
        int leftInE = rootIndex - 1;
        int leftPreS = preOrderArrayStartIndex + 1;
        int leftPreE = leftPreS + leftInE - leftInS;
        

        // RIGHT SUBTREE:
        //
        // inOrder(L,D,R):
        // start index is one after the root index.
        // end index is end of the inorder array.
        //
        // preOrder(D,L,R):
        // start index is one after the end of the left subtree
        // end index is end of preorder array.
        int rightInS = rootIndex + 1;
        int rightInE = inOrderArrayEndIndex;
        int rightPreS = leftPreE + 1;
        int rightPreE = preOrderArrayEndIndex;
        
        // create a new root node from the current root data found.
        TreeNode* root = new TreeNode(rootData);

        // call recursion to build left and right subtrees, passing in the portions of the
        // in/pre order arrays that we found above for the left and right subtrees.
        //
        // This recursively builds all the subtrees in the tree, creating all the nodes recursively.
        root->left = buildTreeHelper(inOrderArray, preOrderArray, leftInS, leftInE, leftPreS, leftPreE);
        root->right = buildTreeHelper(inOrderArray, preOrderArray, rightInS, rightInE, rightPreS, rightPreE);
        
        // at the end return the root of the whole tree.
        return root;  
    }

    TreeNode* buildTree(std::vector<int>& preOrderArray, std::vector<int>& inOrderArray) 
    {
        // runs the helper passing in the in and pre order arrays along with their start and and indexes.
        // The regressive calls will be kicked off inside this call.
        int numberOfNodes = inOrderArray.size();
        return buildTreeHelper(inOrderArray, preOrderArray, 0, numberOfNodes-1, 0, numberOfNodes-1);
    }
};

int main()
{
    //preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
    
    std::vector<int> inOrderArray = {9, 3, 15, 20, 7};
    std::vector<int> preOrderArray = {3, 9, 20, 15, 7};

    Solution soln;
    TreeNode* root = soln.buildTree(preOrderArray, inOrderArray);

    // as expected the constructed tree can be put back into
    // inorder to give the same order we started with.
    std::vector<std::vector<int>> constructedTree = soln.levelOrderTraversal(root);

    // OUTPUT:
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


}
