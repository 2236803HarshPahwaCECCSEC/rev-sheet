class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        if (nums.size() < 2) return 0;
        priority_queue<long, vector<long>, greater<long>> pq(nums.begin(), nums.end());

        int noofoperations = 0;
        while (pq.top()<k) {
            long val1 = pq.top(); pq.pop();
            long val2 = pq.top(); pq.pop();

            pq.push(val1*2+val2);
            noofoperations++;
        }
        return noofoperations;
    }
};
