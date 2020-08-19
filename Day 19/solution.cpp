class Solution {
public:
    string toGoatLatin(string S) {
        if(S.size()==0)
        {
            return S;
        }
        vector<string> s1;
        int i=0;
        string temp;
        while(i<S.size())
        {
            if(S[i]==' ')
            {
                s1.push_back(temp);
                temp.clear();
            }
            else
            {
                temp.push_back(S[i]);
            }
            i++;
        }
        s1.push_back(temp);
        for(int i=0;i<s1.size();i++)
        {
            string temp1;
            for(int j=0;j<=i;j++)
            {
                temp1.push_back('a');
            }
            if(s1[i][0]=='a'|| s1[i][0]=='e'|| s1[i][0]=='i' || s1[i][0]=='o' || s1[i][0]=='u'
              || s1[i][0]=='E'|| s1[i][0]=='A' || s1[i][0]=='I' || s1[i][0]=='O' || s1[i][0]=='U')
            {
                s1[i]=s1[i]+"ma"+temp1;
            }
            else
            {
                char beg=s1[i][0];
               // cout<<beg<<" ";
                s1[i].erase(s1[i].begin()+0);
                s1[i]=s1[i]+beg+"ma"+temp1;
            }
        }
        string ans;
        for(int i=0;i<s1.size()-1;i++)
        {
            ans=ans+s1[i]+" ";
        }
        ans=ans+s1[s1.size()-1];
        return ans;
    }
};