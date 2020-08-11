class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int l=0,r=citations.size()-1;
        int ans=0;
         while(r>=l)
         {
             int mid=((r-l)/2 +l);
             if(citations[mid]>=citations.size()-mid)
             {
                 ans=citations.size()-mid;
                 r=mid-1;
             }
             else
             {
                 l=mid+1;
             }
         }
        return ans;
    }
};