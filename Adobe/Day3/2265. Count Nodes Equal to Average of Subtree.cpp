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
public:int ans=0;
     pair<int,int> solve(TreeNode* root){
        if(root==NULL) return {0,0};
        auto left = solve(root->left);
        int lsum = left.first;
        int lcnt = left.second; 
        auto right = solve(root->right);
        int rsum = right.first; 
        int rcnt = right.second; 
        int sum = lsum + rsum + root->val;
        int cnt = 1+ lcnt + rcnt;
        if(root->val == sum/cnt) ans++;
        return {sum,cnt};
     }
    int averageOfSubtree(TreeNode* root) {
      
        solve(root);
        return ans;
    }
};