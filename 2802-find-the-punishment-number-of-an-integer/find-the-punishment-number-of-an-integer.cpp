class Solution {
public:
    // This function checks if there exist two integers that add up to n
    bool checkpairsum(int num,int target,int sum,int index,string&s){
        if(index==s.size()) return sum==target;
        int current=0;
        for(int i = index; i <s.size(); i++){
            current=current*10+(s[i]-'0');
            if(checkpairsum(num,target,sum+current,i+1,s)) return true;
        }
        return false;
    }

    int punishmentNumber(int n) {
        int sum = 0;
        for(int i = 1; i <= n; i++){
            int check = i * i;
            string s=to_string(check);
            
            if(checkpairsum(check,i,0,0,s)){
                sum += check;
            }
        }
        return sum;
    }
};
