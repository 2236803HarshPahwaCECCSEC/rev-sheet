class Solution {
public:
    bool checkforbouquet(vector<int>bloomDay,int m,int k,int mid){
        int consecutive_count=0;
        int bouquet_count=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid) consecutive_count++;
            else consecutive_count=0;
            if(consecutive_count==k){
                bouquet_count++;
                consecutive_count=0;
            }
        }
        return (bouquet_count>=m?true:false);
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
       
        int start_day=0;
        int end_day=*max_element(bloomDay.begin(),bloomDay.end());
        int minDays=-1;
        while(start_day<=end_day){
            int mid=start_day+(end_day-start_day)/2;
            if(checkforbouquet(bloomDay,m,k,mid)){
                minDays=mid;
                end_day=mid-1;
            }else{
                start_day=mid+1;
            }
        }
        return minDays;
    }
};