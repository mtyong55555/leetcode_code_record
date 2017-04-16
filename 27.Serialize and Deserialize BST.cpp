/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
         string result;
         pre_order(root,result);
         return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        vector<int> nodes;
        string val;
        while(getline(ss,val,'#')){
            nodes.push_back(atoi(val.c_str()));
        }
        TreeNode* root = con_bst(nodes);
        return root;
    }

private: 
    void pre_order(TreeNode* root, string& result){
        if(root == NULL) return;
        result = result + to_string(root->val) + "#";
        pre_order(root->left,result);
        pre_order(root->right,result);
    }
    
    TreeNode* con_bst(vector<int>& nodes){
        int size = nodes.size();
        if(nodes.size() == 0) return NULL;
        stack<TreeNode*> tree_nodes;
        TreeNode* root = new TreeNode(nodes[0]);
        if(size == 1) return root;
        tree_nodes.push(root);
        for(int i = 1; i < size; i++){
            TreeNode* node = NULL;
            while(!tree_nodes.empty() && nodes[i] > tree_nodes.top()->val){
                node = tree_nodes.top();
                tree_nodes.pop();
            }
            if(node != NULL){
                node->right = new TreeNode(nodes[i]);
                tree_nodes.push(node->right);
            }
            else{
                tree_nodes.top()->left = new TreeNode(nodes[i]);
                tree_nodes.push(tree_nodes.top()->left);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
