class Solution {
public:
    int titleToNumber(string s) {
        int num=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            num=num+(int(s[i])-int('A')+1)*pow(26,s.size()-1-i);
        }
        return num;
    }
};