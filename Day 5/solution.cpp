class TrieNode
    {
        public :
            TrieNode *child [26];
            bool isEndofWord; 
    };
class WordDictionary {
public:
    TrieNode *root =new TrieNode;
    /** Initialize your data structure here. */
    WordDictionary() {
        root->isEndofWord=false;
        for(int i=0;i<26;i++)
        {
            root->child[i]=nullptr;
        }
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *temp1=root;
        for(int i=0;i<word.size();i++)
        {
            int index=word[i]-'a';
           // cout<<index<<" ";
            if(temp1->child[index]==nullptr)
            {
                 temp1->child[index]= new TrieNode;
                for(int j=0;j<26;j++)
                {
                    temp1->child[index]->child[j]=NULL;
                }
                 temp1->child[index]->isEndofWord=false;  
            }
            temp1=temp1->child[index];
        }
        temp1->isEndofWord=true;
       // cout<<" here ";
        temp1=root;
        
    }
    bool search1(string word,int k,TrieNode * temp1)
    {
        TrieNode *temp=temp1;
        for(int i=k;i<word.size();i++)
        {
            if(word[i]=='.')
            {
                for(int j=0;j<26;j++)
                {
                    if(temp->child[j])
                    {
                        
                        if(search1(word,i+1,temp->child[j]))
                        {
                            return true;
                        }
                        
                    }
                }
                return false;
            }
            else
            {
                int index=word[i]-'a';
                cout<<index<<" ";
                if(!temp->child[index])
                {
                     return false;
                }
                temp=temp->child[index];
            }
        }
        if(temp->isEndofWord)
        {
            return true;
        }
        return false;
    }
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
         TrieNode *temp1=root;
       return search1(word,0,temp1);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */