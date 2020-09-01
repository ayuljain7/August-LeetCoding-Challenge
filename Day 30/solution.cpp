class Solution {
public:
    int Find(int x,vector<int> & parent)
    {
        if(parent[x]==-1)
            return x;
        parent[x]=Find(parent[x],parent);
        return parent[x];
    }
    void Union(int x,int y,vector<int> & parent)
    {
        int xp=Find(x,parent);
        int yp=Find(y,parent);
        if(xp!=yp)
        {
            parent[yp]=xp;
        }
    }
    int largestComponentSize(vector<int>& A) {
        int Max=0;
        for(int i=0;i<A.size();i++)
        {
            Max=max(Max,A[i]);
        }
       // cout<<Max<<" ";
        vector<int> parent(Max+1,-1);
        for(int i=0;i<A.size();i++)
        {
            for(int j=2;j<=sqrt(A[i]);j++)
            {
                if(A[i]%j==0)
                {
                    Union(j,A[i],parent);
                    Union(A[i],A[i]/j,parent);
                }
            }
        }
        unordered_map<int,int> Check;
        for(int i=0;i<A.size();i++)
        {
           // cout<<Find(A[i],parent)<<" ";
            if(Check.find(Find(A[i],parent))==Check.end())
               {
                   Check[Find(A[i],parent)]=1;
               }
             else
               {
                   Check[Find(A[i],parent)]++;
               }
        }
        Max=0;
        for(auto a:Check)
        {
              Max=max(Max,a.second);     
        }
        return Max;
    }
};