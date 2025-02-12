class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        //using min_heap
        // priority_queue<int,vector<int>,greater<int>> pq;
        // for(int i=0;i<arr.size();i++){
        //     pq.push(arr[i]);
        // }
        // while(--k){
        //     pq.pop();
        // }
        // return pq.top();
        
        priority_queue<int>pq;
        for(int i=0;i<k;i++){
            pq.push(arr[i]);
        }
        for(int i=k;i<arr.size();i++){
            
            if(pq.top()>arr[i]){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        return pq.top();
    }
};
