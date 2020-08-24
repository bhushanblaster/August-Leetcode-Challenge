/*
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void traverse(TreeNode* root,int &sum,bool& left)
    {
        if(root)
        {
            if(root->left == NULL && root->right == NULL && left)
            {
                sum+=root->val;
            }
            if(root->left)
            {
                left = true;
                traverse(root->left,sum,left);
            }
            if(root->right)
            {
                left = false;
                traverse(root->right,sum,left);    
            }
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        bool left = false;
        if(root)
        {
            traverse(root,sum,left);
        }
        return sum;
    }
};
