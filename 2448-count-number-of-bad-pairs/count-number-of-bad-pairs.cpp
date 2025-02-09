class Solution {
public:
    long long countBadPairs(vector<int>& nums) {

        //brute-forcce approach tle
        // long long count=0;
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if(j-i!=nums[j]-nums[i]){
        //             count++;
        //         }
        //     }
        // }
        // return count;

        long long n=nums.size();
        long long good_pairs=0;
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++){
            if(freq.count(i-nums[i]))
                good_pairs+=freq[i-nums[i]];
            freq[i-nums[i]]++;
        }
        long long int bad_pairs=(n*(n-1))/2 - good_pairs;
        return bad_pairs;
    }

};