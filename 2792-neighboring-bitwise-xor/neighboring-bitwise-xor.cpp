class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        // int res=0;
        // for(auto el:derived){
        //     res^=el;
        // }
        // return res==0;

        int count=0;
        for(auto el:derived){
            if(el==1){
                count++;
            }
        }
        return (count%2==0?true:false);
    }
};