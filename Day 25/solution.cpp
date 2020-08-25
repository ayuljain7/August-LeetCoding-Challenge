class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_map<int,int> Hash;
        for(int i=0;i<days.size();i++)
        {
            Hash[days[i]]=1;
        }
        vector<int> dp(days[days.size()-1]+1,0);
        for(int i=1;i<dp.size();i++)
        {
            if(Hash.find(i)==Hash.end())
            {
                dp[i]=dp[i-1];
            }
            else
            {
                dp[i]=min(dp[i-1]+costs[0],min(dp[max(0,i-7)]+costs[1],dp[max(0,i-30)]+costs[2]));
            }
        }
       // cout<<dp.size()-1<<" ";
        return dp[dp.size()-1];
    }
};