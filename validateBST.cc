/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int leftData = NULL;

    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        
        if(isValidBST(root->left) == false) return false;
        
        if(root->val <= leftData && leftData != NULL) return false;
        
        leftData = root->val;
        
        if(isValidBST(root->right) == false) return false;
        
        return true;
    }
};