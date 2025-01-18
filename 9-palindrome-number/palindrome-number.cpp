class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long long num=x;
        long long reverse=0;
        while(num>0){
            int digit=num%10;
            reverse=reverse*10+digit;
            num/=10;
        }
        return (x==reverse);
    }
};