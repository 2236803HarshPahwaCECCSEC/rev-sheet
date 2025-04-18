class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // priority_queue<int> max_heap;
        // for(int num:nums){
        //     max_heap.push(num);
        // }
        // while(--k){
        //     max_heap.pop();
        // }
        // return max_heap.top();

        priority_queue<int,vector<int>,greater<int>> min_heap;
        for(int i=0;i<k;i++){
            min_heap.push(nums[i]);
        }
        for(int i=k;i<nums.size();i++){
            if(min_heap.top()<nums[i]){
                min_heap.pop();
                min_heap.push(nums[i]);
            }
        }
        return min_heap.top();
    }
};