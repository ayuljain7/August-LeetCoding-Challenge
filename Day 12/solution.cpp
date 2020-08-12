class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // //Without optimisation ,Space=O(k^2)
        // vector<int> dp[rowIndex+1];
        // dp[0]={1};
        // if(rowIndex==0)
        // {
        //     return dp[0];
        // }
        // dp[1]={1,1};
        // for(int i=2;i<=rowIndex;i++)
        // {
        //     dp[i].push_back(1);
        //     for(int j=0;j<i-1;j++)
        //     {
        //         dp[i].push_back(dp[i-1][j]+dp[i-1][j+1]);
        //     }
        //     dp[i].push_back(1);
        // }
        // return dp[rowIndex];
        //----------------------------------------------
        vector<int> dp(rowIndex+1,0);
        //With optimisation ,Space=O(k)
        dp[0]=1;
        for(int i=1;i<=rowIndex;i++)
        {
            for(int j=i;j>0;j--)
            {
                dp[j]=dp[j]+dp[j-1];
            }
        }
        return dp;
    }
};