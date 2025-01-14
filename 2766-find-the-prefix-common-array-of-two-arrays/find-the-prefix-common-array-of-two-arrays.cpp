class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> res(A.size(),0);
        unordered_map<int,int> freq;
        for(int i=0;i<A.size();++i){
            for(int j=0;j<=i;++j){
                freq[A[j]]++;
            }
            int count=0;
            for(int j=0;j<=i;++j){
                if(freq[B[j]]>0){
                    count++;
                }
            }
            res[i]=count;
            freq.clear();
        }
        return res;
    }
};