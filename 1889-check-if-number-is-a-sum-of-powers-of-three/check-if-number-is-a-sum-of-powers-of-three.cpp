class Solution {
public:
bool find(int power,int n){
    if(n==0) return true;
    if(pow(3,power)>n) return false;
    bool addPower=find(power+1,n-pow(3,power));
    bool skipPower=find(power+1,n);
    return addPower||skipPower;

}
    bool checkPowersOfThree(int n) {
        return (find(0,n));
    }
};