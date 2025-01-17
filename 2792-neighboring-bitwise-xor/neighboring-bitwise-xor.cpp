class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int res=0;
        for(auto el:derived){
            res^=el;
        }
        return res==0;
    }
};