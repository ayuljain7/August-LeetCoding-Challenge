class Solution {
public:
    void build(int N,int K,int num,vector<int> &ans)
    {
        if(N==0)
        {
            ans.push_back(num);
            return;
        }
        int digit=num%10;
        if(digit+K<=9)
        {
            build(N-1,K,10*num+digit+K,ans);
        }
        if(K!=0 && digit-K>=0)
        {
            build(N-1,K,10*num+digit-K,ans);
        }
        
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> ans;
        if(N==1)
        {
            ans.push_back(0);
        }
        for(int i=1;i<=9;i++)
        {
            build(N-1,K,i,ans);
        }
        return ans;
    }
};