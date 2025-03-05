class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26]={0};
        for(auto& task:tasks){
            freq[task-'A']++;
        }
        priority_queue<int>pq;
        for(int i=0;i<26;i++){
            if(freq[i]>0) pq.push(freq[i]);
        }
        int time=0;
        while(!pq.empty()){
            int cycle=n+1;//this cycle states that ki yeh tasks ek cycle ki form m kaam karenge
            int taskcount=0;
            vector<int> temp;//to store remaining frequencies
            while(!pq.empty()&&cycle--){
                if(pq.top()>1) temp.push_back(pq.top()-1);
                taskcount++;
                pq.pop();
            }
            for(auto i:temp){
                pq.push(i);
            }
            time+=(pq.empty())?taskcount:n+1;
        }
        return time;
    }
};