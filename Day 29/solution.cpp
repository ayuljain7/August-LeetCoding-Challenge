class Solution {
public:
    void swap(vector<int>& A,int index)
    {
        for(int j=0;j<=index/2;j++)
        {
                int temp=A[j];
                A[j]=A[index-j];
                A[index-j]=temp;
        }
        return;
    }
    bool checkSort(vector<int> sorted,vector<int> A)
    {
        for(int i=0;i<A.size();i++)
        {
            if(A[i]!=sorted[i])
            {
                return false;
            }
        }
        return true;
    }
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> ans;
        vector<int> sorted=A;
        sort(sorted.begin(),sorted.end());
        for(int i=0;i<A.size();i++)
        {
            if(checkSort(sorted,A))
            {
                return ans;
            }
            int Max=INT_MIN,index;
            for(int j=0;j<A.size()-i;j++)
            {
                Max=max(Max,A[j]);
                if(A[j]==Max)
                {
                    index=j;
                }
            }
           // cout<<Max<<" -- "<<index<<" ";
            ans.push_back(index+1);
            swap(A,index);
            ans.push_back(A.size()-i);
            swap(A,A.size()-1-i);
            // for(int j=0;j<A.size();j++)
            // {
            //     cout<<A[j]<<" ";
            // }
            // cout<<endl;
        }
        return ans;
    }
};