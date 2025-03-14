// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int solveUsingRecursion(int n,int k){
    if(n==1) return k;
    if(n==2) return (k+k*(k-1));
    int ans=(solveUsingRecursion(n-1,k)+solveUsingRecursion(n-2,k))*(k-1);
    return ans;
}
int solveUsingMemo(int n,int k,vector<int>& dp){
    if(n==1) return k;
    if(n==2) return (k+k*(k-1));
    if(dp[n]!=-1) return dp[n];
    dp[n]=(solveUsingMemo(n-1,k,dp)+solveUsingMemo(n-2,k,dp))*(k-1);
    return dp[n];
}
int solveUsingTabu(int n,int k){
    vector<int>dp(n+1,-1);
    dp[1]=k;
    dp[2]=(k+(k*(k-1)));
    for(int i=3;i<=n;i++){
        dp[i]=(dp[i-1]+dp[i-2])*(k-1);
    }
    return dp[n];
}
int solveUsingSpaceOptimization(int n,int k){
    if(n==1) return k;
    if(n==2) return (k+k*(k-1));
    int prev2=k;
    int prev=(k+k*(k-1));
    for(int i=3;i<=n;i++){
        int curr=(prev+prev2)*(k-1);
        prev2=prev;
        prev=curr;
    }
    return prev;
}
int main() {
    // Write C++ code here
    // std::cout << "Try programiz.pro";
    int n=3;
    int k=3;
    // int ans=solveUsingRecursion(n,k);
    // vector<int>dp(n+1,-1);
    // int ans=solveUsingMemo(n,k,dp);
    int ans=solveUsingSpaceOptimization(n,k);
    cout<<ans;
    return 0;
}
