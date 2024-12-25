#include<iostream>
#include<vector>

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // vector<int> index;
        int left=0;
        int right=numbers.size()-1;
        int sum=0;
        while(left<right){
            sum=numbers[left]+numbers[right];
            if(sum<target){left++;}
            else if(sum==target){return {left+1,right+1};}
            else{right--;}
        }
        return {-1,-1};
    }
};