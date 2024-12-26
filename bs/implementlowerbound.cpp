int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here
	int l=0;
	int r=n-1;
	int res=n;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(arr[mid]>=x){res=mid;
		r=mid-1;}
		else{l=mid+1;}
	}
	return res;
}
/* this problem is a problem that sees finding a index i such that any element which is greater than x is the bound and the 
lower of the all bounds will be the result and if no such index is found then we return n*/