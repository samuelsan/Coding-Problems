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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!cover(root, p) || !cover(root, q)) return NULL;

        if(root == NULL) return NULL;
        
        if(root == p || root == q) return root;
        
        bool pOnLeftSide = cover(root->left, p);
        bool qOnLeftSide = cover(root->left, q);
        
        if(pOnLeftSide != qOnLeftSide) return root;
        
        if(pOnLeftSide){
            return lowestCommonAncestor(root->left, p, q);
        } else {
            return lowestCommonAncestor(root->right, p, q);
        }
    }
    
    bool cover(TreeNode* root, TreeNode* x){
        if(root == NULL) return root;
        if(root == x) return root;
        return cover(root->left, x) || cover(root->right, x);
    }
};