class Solution {
public:
    int find(vector<int>& arr){
        int n=arr.size();
        int prev=arr[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int pick=arr[i]+(i>1?prev2:0);
            int notpick=prev;
            int curr=max(pick,notpick);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> temp1(nums.begin()+1,nums.end());//excluding first element 
        vector<int> temp2(nums.begin(),nums.end()-1);//excluding last element 

        return max(find(temp1),find(temp2));
    }
};