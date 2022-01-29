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
    TreeNode* solve(int l,int r,vector<int>& v)
    {
        if(l > r)
            return NULL;
        int mid = (l + r) / 2;
        TreeNode* root=new TreeNode(v[mid]);
        root -> left = solve(l , mid - 1 , v);
        root -> right = solve(mid+1 , r , v);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return solve(0 , nums.size()-1 , nums);
        
    }
};