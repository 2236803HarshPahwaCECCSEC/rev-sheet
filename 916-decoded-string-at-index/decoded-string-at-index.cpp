class Solution {
public:
    string decodeAtIndex(string s, int k) {
        // string finalres="";O(n*k) and space complexity also O(n*k) 
        // for(auto ch:s){
        //     if('a'<=ch&&ch<='z'){
        //         finalres+=ch;
        //     }else if('2'<=ch&&ch<='9'){
        //         int d=ch-'0';
        //         string temp=finalres;
        //         for(int i=1;i<d;i++){
        //             finalres+=temp;
        //         }
        //     }
        //     if(finalres.size()>=k){
        //         return string(1,finalres[k-1]);
        //     }
        // }
        // return "";

        //len is less than 2 to the power 63 so it can have greater length so chose long long
        long long size=0;
        for(auto ch:s){
            if(isdigit(ch)){
                size*=(ch-'0');
            }else{
                size++;
            }
        }
        int n=s.size();
        for(int i=n-1;i>=0;i--){
            if(isdigit(s[i])){
                size/=(s[i]-'0');//as repetition is there so reduce the length;
                k%=size;//reason is clear as size decreases we also need to handle the k factor
            }else{
                if(k==0 || k==size){
                    return string("")+s[i];
                }
                size--;
            }
            
        }
        return "";
    }
};