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
    unordered_map<TreeNode*,int>memo;
    int dp(TreeNode* root){
        if(root==NULL)return 0;
        if(memo.find(root)!=memo.end())
        return memo[root];
        int include=root->val;

        if(root->left!=NULL){
        include+=dp(root->left->left)+dp(root->left->right);
        
        if(root->right!=NULL)
        include+=dp(root->right->left) + dp(root->right->right);
        }
    
        int exclude=dp(root->left)+dp(root->right);
        int ans=max(include, exclude);
        memo[root]=ans;
        return ans;
    }
    int rob(TreeNode* root) {
        return dp(root);
    }
};