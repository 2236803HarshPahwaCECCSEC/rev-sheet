class Solution {
public:
    string clearDigits(string s) {
        // int charindex=0;
        // while(charindex<s.size()){
        //     if(isdigit(s[charindex])){
        //         s.erase(charindex,1);
        //         if(charindex>0){
        //             s.erase(charindex-1,1);
        //             charindex--;
        //         }
        //     }else{
        //         charindex++;
        //     }
        // }
        // return s;

        string ans="";
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                ans.pop_back();
            }else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};