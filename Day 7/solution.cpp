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
    void dfs(TreeNode *root,vector<vector<int>> &coord,int x,int y)
    {
        if(!root)
        {
            return;
        }
        vector<int> temp={x,y,root->val};
        coord.push_back(temp);
        dfs(root->left,coord,x-1,y+1);
        dfs(root->right,coord,x+1,y+1);
        return;
        
        
    }
    static bool Compare1(vector<int> a,vector<int> b)
    {
        return a[0]<b[0];
    }
    static bool Compare2(pair<int,int> a,pair<int,int> b)
    {
        if(a.first==b.first)
        {
            return a.second<b.second;
        }
        return a.first<b.first;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> coord;
        dfs(root,coord,0,0);
        sort(coord.begin(),coord.end(),Compare1);
       // return coord;
        vector<vector<pair<int,int>>> Coord;
        for(int i=0;i<coord.size();i++)
        {
            vector<pair<int,int>> temp;
            temp.push_back(make_pair(coord[i][1],coord[i][2]));
            int val=coord[i][0];
           // cout<<coord[i][2]<<" ";
            while(i<coord.size()-1 && coord[i+1][0]==val)
            {
                i++;
                temp.push_back((make_pair(coord[i][1],coord[i][2])));
               // cout<<coord[i][2]<<" ";
                
            }
           // cout<<coord[i][2]<<" ";
          //  cout<<temp.size()<<" ";
            sort(temp.begin(),temp.end(),Compare2);
            
            Coord.push_back(temp);
        }
        
         vector<vector<int>> ans;                      
        for(int i=0;i<Coord.size();i++)
        {
            vector<int> temp1;
            for(int j=0;j<Coord[i].size();j++)
            {
                temp1.push_back(Coord[i][j].second);
            }
            ans.push_back(temp1);
        }
        return ans;
    }
};