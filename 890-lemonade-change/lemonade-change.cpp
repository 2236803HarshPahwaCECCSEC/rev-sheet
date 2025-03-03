class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fivecount=0;
        int tencount=0;
        int n=bills.size();
        
        for(int i=0;i<n;i++){
            if(bills[i]==5){fivecount++;}
            else if(bills[i]==10){
                tencount++;
                if(fivecount==0) return false;
                fivecount--;
            }
            else{
                if(tencount>0&&fivecount>0){
                    tencount--;
                    fivecount--;
                }else if(fivecount>=3){
                    fivecount-=3;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};