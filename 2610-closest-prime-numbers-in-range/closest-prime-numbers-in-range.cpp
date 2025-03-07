class Solution {
public:
    bool isPrime(int num){
        if(num<2) return false;
        for(int i=2;i*i<=num;i++){
            if(num%i==0) return false;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        int prevPrime=-1,closestno1=-1,closestno2=-1;
        int mindiff=INT_MAX;
        for(int i=left;i<=right;i++){
            if(isPrime(i)){
                if(prevPrime!=-1){
                    int difference=i-prevPrime;
                    if(difference<mindiff){
                        mindiff=difference;
                        closestno1=prevPrime;
                        closestno2=i;
                    }
                    if(difference==2||difference==1) return {prevPrime,i};
                }
                prevPrime=i;
            }
        }
        return (closestno1==-1) ?vector<int>{-1,-1}:vector<int>{closestno1,closestno2};
    }
};