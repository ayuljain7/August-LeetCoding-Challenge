class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<int> arr[10000];
    MyHashSet() {
        
    }
    
    void add(int key) {
        int i=-1,j=0;
        while(j<arr[key%10000].size())
        {
            if(arr[key%10000][j]==key)
            {
                i=j;
            }
            j++;
        }
        if(i==-1)
        {
            arr[key%10000].push_back(key);
        }
        
    }
    
    void remove(int key) {
        int i=-1,j=0;
        while(j<arr[key%10000].size())
        {
            if(arr[key%10000][j]==key)
            {
                i=j;
            }
            j++;
        }
        if(i!=-1)
        {
            arr[key%10000].erase(arr[key%10000].begin()+i);
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int i=-1,j=0;
        while(j<arr[key%10000].size())
        {
            if(arr[key%10000][j]==key)
            {
                i=j;
            }
            j++;
        }
        if(i!=-1)
        {
            return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */