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
    int sumOfLeftLeaves(TreeNode* root) {
        int result = 0;
        bool flag = false;
        sumOfLeftHelper(root,result,flag);
        return result;
    }
    
    void sumOfLeftHelper(TreeNode* root,int &result, bool &flag){
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL){
            if(flag == true){
                result += root->val;
                flag = false;
            }
        }
        if(root->left != NULL){
            flag = true;
            sumOfLeftHelper(root->left,result,flag);
        }
        if(root->right != NULL){
            flag = false;
            sumOfLeftHelper(root->right,result,flag);
        }
    }
};
