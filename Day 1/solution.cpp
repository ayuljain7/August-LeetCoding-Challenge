class Solution {
public:
    bool detectCapitalUse(string word) {
        int flag=0;
        if(word.size()>0)
        {
            if((int(word[0])-int('A')>26 || int(word[0])-int('A')<0) && ((int(word[0])-int('a')>26 ||                           int(word[0])-int('a')<0)))
               {
                   return false;
               }
        }
        if(word.size()>1)
        {
            if(int(word[0])-int('A')<26 && int(word[0])-int('A')>=0)
            {
                flag=1;
            }
            if((int(word[1])-int('A')>26 || int(word[1])-int('A')<0) && ((int(word[1])-int('a')>26 ||                             int(word[1])-int('a')<0)))
            {
              return false;
            }
            if(int(word[1])-int('A')<26  && int(word[1])-int('A')>=0 && flag==0)
            {
               // cout<<"here ";
                return false;
            }
            if(int(word[1])-int('a')<26 && int(word[1])-int('a')>=0)
            {
                flag=0;
            }
        }
        //cout<<"here ";
        if(flag==1)
        {
            for(int i=2;i<word.size();i++)
            {
                if(int(word[i])-int('A')>26 || int(word[i])-int('A')<0)
                    return false;
            }
        }
        //cout<<"here ";
        if(flag==0)
        {
            for(int i=2;i<word.size();i++)
            {
                if(int(word[i])-int('a')>26 || int(word[i])-int('a')<0)
                    return false;
            }
        }
       // cout<<"here ";
        return true;
    }
};