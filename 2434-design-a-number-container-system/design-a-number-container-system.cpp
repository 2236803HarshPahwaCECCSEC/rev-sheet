class NumberContainers {
public:
    NumberContainers() {
        
    }
    unordered_map<int,int> mp;//no to indices
    unordered_map<int,set<int>>map;
    void change(int index, int number) {
        if(mp.count(index)){//element already exists at the index;
            int prevNo=mp[index];
            map[prevNo].erase(index);
            if(map[prevNo].empty()){
                map.erase(prevNo);
            }
        }
        mp[index]=number;
        map[number].insert(index);
    }
    
    int find(int number) {
        return map.count(number) && !map[number].empty()?*map[number].begin():-1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */