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
    int maxLevelSum(TreeNode* root) {
        mx = 0;
        dfs(root,0);        
        for(int i=sum.size()-1;i>=0;i--){
            if(sum[i]>=sum[mx])mx = i;
        }
        return mx+1;
    }
private:
    int mx;
    vector<int> sum;
    void dfs(TreeNode* node,int level){
        if(node==nullptr)return;
        if(sum.size()<=level)sum.push_back(0);
        sum[level]+=node->val;
        dfs(node->left,level+1);
        dfs(node->right,level+1);
    }
};