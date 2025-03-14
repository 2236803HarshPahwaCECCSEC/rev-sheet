class Solution {
public:
    bool checkComponent(vector<int>&candies,int mid,long long k){
        long long count=0;
        for(int candy:candies){
            count+=candy/mid;
            if(count>=k){
                return true;
            }
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
       long long  total_candies=accumulate(candies.begin(),candies.end(),0LL);
       if(total_candies<k)return 0;
       long long  low=1;
       long long  high=total_candies;
       long long maxDistributed=0;
       while(low<=high){
        long long  mid=low+(high-low)/2;
        if(checkComponent(candies,mid,k)){
            maxDistributed=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
       } 
       return (int)maxDistributed;
    }
};