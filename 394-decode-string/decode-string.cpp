class Solution {
public:
    string decodeString(string s) {
        stack<string> ss;
        stack<int> nostack;
        string currstr="";
        int num=0;
        for(char c:s){
            if(isdigit(c)){
                num=num*10+(c-'0');
            }else if(c=='['){
                nostack.push(num);
                ss.push(currstr);
                num=0;
                currstr="";
            }else if(c==']'){
                int repeatcount=nostack.top();
                nostack.pop();
                string temp=currstr;
                currstr=ss.top();
                ss.pop();
                for(int i=1;i<=repeatcount;++i){
                    currstr+=temp;
                }
            }else{
                currstr+=c;
            }
        }
        return currstr;
    }
};