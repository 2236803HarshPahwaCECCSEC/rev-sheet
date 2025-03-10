class Solution {
public:
    bool canEatall(vector<int>&piles,int mid,int h){
        int actualHours=0;
        for(auto& x:piles){
            actualHours+=x/mid;//check waise ki kha pta h ekghante m ya jitna bhi time lagetga
            if(x%mid!=0){
                actualHours++;
            }
        }
        return (actualHours<=h);



        //lets suppse mid aata h 5 jo kehta h ki koko 5  banana kha leta h ek ghante mein 
        //array h 3,6,7,11 now 3/5 karoge toh zero aayega tohyeh 3 khayeg aur time lagega ek ghanta inn the case of 6 hum 5 pehle khayege jo ek ghanta add karega 6/5 jo hota h fir ek rehta huse hum ek ghante m khayenge so yaha total hours 3  next 7 hum 2 ghante m khayenge aur 11 hum 3 ghante me khayenge yeh adda up karke 8 ghante aate h but ans yeh nahi h ans 4  h kyuki hamme 4 khakar bhi 8 ghante hi lagte h toh hum minimum no of bananas ko return kar denge
     
    }   
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;//can eat one bananas a hour
        int r=*max_element(piles.begin(),piles.end());
        while(l<r){
            int mid=l+(r-l)/2;
            if(canEatall(piles,mid,h)){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};