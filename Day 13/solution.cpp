class CombinationIterator {
public:
    vector<string> ans;
    int x=0;
    CombinationIterator(string characters, int combinationLength) {
        int k=combinationLength;
        int start=0;
        int end=0;
        for(int i=0;i<characters.size();i++)
        {
            if(i-characters.size()+1+k>0)
            {
                //cout<<i<<" ";
                start=start+pow(2,i);
            }
            if(k-i>0)
            {
                end=end+pow(2,i);
            }
        }
       // cout<<start<<" "<<end<<" ";
        while(start>=end)
        {
            string s1;
            int temp=start;
            int count1=0;
            while(temp>0)
            {
                if(temp%2==0)
                {
                    s1="0"+s1;
                }
                else
                {
                    count1++;
                    s1="1"+s1;
                }
                temp=temp/2;
                
            }
           // cout<<s1<<" ";
            while(s1.size()!=characters.size())
            {
                s1="0"+s1;
            }
            if(count1==k)
            {
                string s2;
                for(int i=0;i<s1.size();i++)
                {
                    if(s1[i]=='1')
                    {
                        s2=s2+characters[i];
                    }
                }
                ans.push_back(s2);
                
            }
            start--;
        }
        //cout<<ans[0]<<" ";
    }
    
    string next() {
        
        x++;
        return ans[x-1];
    }
    
    bool hasNext() {
        if(x<ans.size())
        {
            return true;
        }
        return false;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */