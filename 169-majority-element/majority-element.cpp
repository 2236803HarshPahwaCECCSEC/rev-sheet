class Solution {
public:
    int majorityElement(vector<int>& nums) {
       
        //it uses map brute force o(n) space complexity
        // int n=(nums.size())/2;
        // map<int,int> mp;
        // int val=0;
        // for(int i=0;i<nums.size();i++){
        //     mp[nums[i]]++;
        // }
        // for(auto it:mp){
        //     if(it.second>n){
        //         val= it.first;
        //     }
        // }
        // return val;

        //boyer moore majiority voting algo
        //uses count and candidate and o(1) space complexity algo
        int n=nums.size();
        //initial setup
        int candidate=nums[0];
        int count=1;//as candidate exists
        //traversing through rest of array
        for(int i=1;i<n;i++){
            if(count==0){
                candidate=nums[i];
                count=1;
            }
            else if(nums[i]==candidate) count++;//if same element is found as candidate
            else count--; //if diff next element is found
        }
        //verification is required to check for the count
        count=0;
        for(auto num:nums){
            if(num==candidate) count++;
        }
        return (count>(n/2)?candidate:-1);

    }
};