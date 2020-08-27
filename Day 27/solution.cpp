class Solution {
public:
    static bool Compare(vector<int> a,vector<int> b)
    {
       return a[0]<b[0];
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> ans(intervals.size(),-1);
        unordered_map<int,int> Hash;
        for(int i=0;i<intervals.size();i++)
        {
            Hash[intervals[i][0]]=i;
        }
        sort(intervals.begin(),intervals.end(),Compare);
        for(int i=0;i<intervals.size()-1;i++)
        {
            int target=intervals[i][1];
            int l=i+1;
            int r=intervals.size()-1;
            int mid=0,val=INT_MAX;
            while(r>l)
            {
                mid=l+(r-l)/2;
                if(intervals[mid][0]<target)
                {
                    l=mid+1;
                }
                else
                {
                    r=mid;
                }
            }
            if(intervals[r][0]>=target)
            {
                ans[Hash[intervals[i][0]]]=Hash[intervals[r][0]];
            }
            
        }
        return ans;
    }
};