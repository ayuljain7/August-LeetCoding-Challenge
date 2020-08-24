class Trie{
    Trie *children[26];
    bool endOfWord;
public:
    Trie():endOfWord(false){
        for(int i = 0; i < 26; ++i) children[i] = nullptr;
    }
    
    void insert(string s){
        Trie *t1 = this;
        for(char c: s){
            if(t1->children[c-'a'] == nullptr)
                t1->children[c-'a'] = new Trie();
            t1 = t1->children[c-'a'];
        }
        t1->endOfWord = true;
    }
    
    bool search(deque<char>& s){
        Trie *t1 = this;
        for(char c: s){
            if(t1->children[c-'a'] == nullptr) return false;
            t1 = t1->children[c-'a'];
            if(t1->endOfWord) return true;
        }
        return false;
    }
};

class StreamChecker {
    Trie t1;
    deque<char> stream;
public:
    StreamChecker(vector<string>& words) {
        for(string& w: words){
            reverse(w.begin(), w.end());
            t1.insert(w);
        }
    }
    
    bool query(char letter) {
        stream.push_front(letter);
        return t1.search(stream);
    }
};
/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */