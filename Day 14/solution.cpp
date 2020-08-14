class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> Hash1;
        for(int i=0;i<s.size();i++)
        {
            if(Hash1.find(s[i])==Hash1.end())
            {
                Hash1[s[i]]=1;
            }
            else
            {
                Hash1[s[i]]++;
            }
        }
        //cout<<Hash1['a']<<" ";
        int count=0,flag=0;
        for(auto i:Hash1)
        {
            // while(i.second/2>0)
            // {
            //     if(flag==0 && i.second%2==1)
            //     {
            //         count++;
            //         flag=1;
            //     }
            //     count=count+2;
            //     i.second/=2;
            // }
            if(flag==0 && i.second%2==1)
            {
                count++;
                flag=1;
            }
            count=count+(i.second/2)*2;
            //cout<<count<<" ";
        }
        return count;
    }
};