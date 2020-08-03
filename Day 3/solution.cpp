class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size()==0)
        {
            return true;
        }
        string s1;
        for(int i=0;i<s.size();i++)
        {
            if((int(s[i])-int('a')<26 && int(s[i])-int('a')>=0)||
               (int(s[i])-int('A')<26 && int(s[i])-int('A')>=0) ||
               (int(s[i])-int('0')<10 && int(s[i])-int('0')>=0))
            {
                if((int(s[i])-int('A')<26 && int(s[i])-int('A')>=0))
                {
                    s1.push_back(char(int(s[i])-int('A')+int('a')));
                }
                else
                {
                    s1.push_back(s[i]);
                }
            }
        }
        cout<<s1<<" ";
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s1[s1.size()-1-i])
            {
                return false;
            }
        }
        return true;
        
    }
};