class Solution {
public:
    static bool Compare(vector<int> a,vector<int> b)
    {
        if(a[0]==b[0])
        {
            return a[1]<b[1];
        }
        return a[0]<b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),Compare);
        int pre=0,res=0;
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<intervals[pre][1])
            {
                res++;
                if(intervals[i][1]<intervals[pre][1])
                {
                    pre=i;
                }
            }
            else
            {
                pre=i;
            }
        }
        return res;
    }
};