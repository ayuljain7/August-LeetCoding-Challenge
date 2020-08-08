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
    int Check(TreeNode * root,int sum)
    {

        if(!root)
        {
            return 0;
        }
        //cout<<root->val<<" ";
        if(sum==root->val)
        {
          //  cout<<sum<<" ";
            return 1+Check(root->left,sum-(root->val))+Check(root->right,sum-(root->val));
        }
        return Check(root->left,sum-(root->val))+Check(root->right,sum-(root->val));
    }
    int pathSum(TreeNode* root, int sum) {
        if(!root)
            return 0;
        // cout<<Check(root,sum)<<" "<<Check(root->right->right,sum);
         return Check(root,sum)+pathSum(root->left,sum)+pathSum(root->right,sum);
    }
};