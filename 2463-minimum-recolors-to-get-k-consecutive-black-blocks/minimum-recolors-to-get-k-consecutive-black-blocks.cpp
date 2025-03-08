class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int countB=0;
        int minOperations=INT_MAX;
        for(int i=0;i<k;i++){
            if(blocks[i]=='B'){
                countB++;
            }
        }
        minOperations=min(minOperations,k-countB);
        for(int i=k;i<blocks.length();i++){
            if(blocks[i-k]=='B') countB--;
            if(blocks[i]=='B') countB++;
            minOperations=min(minOperations,k-countB);
        }
        return minOperations;
    }

};